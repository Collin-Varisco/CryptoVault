#include "CredentialMenu.h"
#include <nlohmann/json.hpp>
#include <QFileDialog>
#include <QDir>
#include <QTimer>
#include "../ExportCredentialsLoginChange/ExportLoginChange.h"
#include "../JSON/SaveJson.h"
#include "../Global/ChangeGlobals.h"
#include "../Global/Global.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../Settings/Settings.h"
#include <vector>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QDebug>
#include <iostream>
#include <QEvent>
#include <QKeyEvent>
#include <string>
#include <fstream>
#include <QClipboard>
#include <QGuiApplication>
#include <QScreen>
CredentialMenu::CredentialMenu(QFrame *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.SearchBar->installEventFilter(this);
    ui.CredentialTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.CredentialTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.ImportExportOptionsButton->installEventFilter(this);
    ui.ImportExportFrame->installEventFilter(this);
    ui.AddCredentialFrame->setVisible(false);
    ui.ImportExportFrame->setVisible(false);

	credentialMenuActive = true;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect geometry = screen->geometry();
    // Change to 70% of full screen size, then convert to 16:9 Aspect Ratio
    int width = geometry.width() * 0.7;
    int height = width * 0.68;
    // <Format To Screen Size>
    this->resize(width, height);
    // Format Table
    formatTable(ui.CredentialTable);
    formatFrame(ui.AddCredentialFrame);
    formatFrame(ui.frame_3);
    formatFrame(ui.frame_2);
    formatFrame(ui.frame);
    formatFrame(ui.ImportExportFrame);

    // Left Side Menu Bar Buttons
    formatButtonWithinFrame(ui.VaultButton, 70, 780, ui.frame);
    formatButtonWithinFrame(ui.ImportExportOptionsButton, 70, 780, ui.frame);
    formatButtonWithinFrame(ui.SettingsButton, 70, 780, ui.frame);

    // Import Export Menu Buttons
    formatButtonWithinFrame(ui.ImportButton, 161, 142, ui.ImportExportFrame);
    formatButtonWithinFrame(ui.ExportSelectedButton, 161, 142, ui.ImportExportFrame);
    formatButtonWithinFrame(ui.ExportAllButton, 161, 142, ui.ImportExportFrame);

    // Add/Edit Credential QLineEdits
    formatLineEditWithinFrame(ui.AddService, 261, 371, ui.frame_3);
    formatLineEditWithinFrame(ui.AddUsername, 261, 371, ui.frame_3);
    formatLineEditWithinFrame(ui.AddPassword, 261, 371, ui.frame_3);

    // Add/Edit Credential Buttons
    int frameX = this->width() * 0.36815;
    int frameY = this->height() * 0.2295;
    int frameWidth = this->width() * 0.2597;
    int frameHeight = this->height() * 0.6081;
    ui.AddCredentialButton->setGeometry(frameWidth*0.2799, frameHeight*0.72776, frameWidth*0.38697, frameHeight * 0.09164);
    ui.pushButton->setGeometry(frameWidth*0.32, frameHeight*0.8355, frameWidth*0.3103, frameHeight*0.09164);
    // Add Credential Label
    ui.AddLabel->setGeometry(0, frameHeight*0.0808, frameWidth, frameHeight*0.1374);

    // Vault Label
    ui.label_8->setGeometry(0, 0, this->width(), this->height()*0.11639);

    // Search Bar
    ui.SearchBar->setGeometry(this->width()*0.0895, this->height()*0.04918, this->width()*0.2199, this->height()*0.0459);


    // </endFormatting>

    connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(openAddCredentialPrompt()));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(closeAddCredentialPrompt()));
    connect(ui.AddCredentialButton, SIGNAL(clicked()), this, SLOT(addCredential()));
    connect(ui.SettingsButton, SIGNAL(clicked()), this, SLOT(openSettings()));
    connect(ui.CopyButton, SIGNAL(clicked()), this, SLOT(copySelectedCell()));
    connect(ui.RemoveButton, SIGNAL(clicked()), this, SLOT(removeSelectedCredential()));
    connect(ui.ExportSelectedButton, SIGNAL(clicked()), this, SLOT(exportSelectedCredentials()));
    connect(ui.EditButton, SIGNAL(clicked()), this, SLOT(openEditCredentialPrompt()));
    connect(ui.ExportAllButton, SIGNAL(clicked()), this, SLOT(exportAllCredentials()));

	SaveJson sj;
    inactivityTimerSet = sj.timerOn();
    if(inactivityTimerSet){
		ChangeGlobals cg;
		cg.setTimer(sj.timerLimit());
	}

    // Triggers the slot function every second this CredentialMenu window is open.
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkActivity()));
    timer->start(1000);

    // Updates where the cursor is every 0.5 seconds
    QTimer *updateCursorTimer = new QTimer(this);
    connect(updateCursorTimer, SIGNAL(timeout()), this, SLOT(updateCursor()));
    updateCursorTimer->start(500);

    // Stores initial position of cursor
    cursorPosition = QCursor::pos();

    loadCredentials();
}

void CredentialMenu::openSettings() {
	credentialMenuActive = false;
	QWidget* settings;
	settings = new Settings();
	this->close();
	settings->show();

}

void CredentialMenu::openEditCredentialPrompt(){
	editing = true;
	QList<QTableWidgetItem*> items = ui.CredentialTable->selectedItems();
	if(items.size() > 0){
		ui.AddLabel->setTextFormat(Qt::RichText);
		ui.AddLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic;\">Edit Credential</span></p></body></html>", nullptr));

		QTableWidgetItem *selected = ui.CredentialTable->selectedItems().first();
		int row = ui.CredentialTable->row(selected);
		ui.AddService->setText(ui.CredentialTable->item(row, 0)->text());
		ui.AddUsername->setText(ui.CredentialTable->item(row, 1)->text());
		ui.AddPassword->setText(ui.CredentialTable->item(row, 2)->text());
		ui.AddCredentialButton->setText("Change");
		ui.AddCredentialFrame->setVisible(true);
	}
}



/* Inactivity will be detected in two ways.
 * 1. If the mouse is not on the window.
 * 2. If the mouse is on the window, but not moving.
 * If either of these conditions is met in the checkActivity function which is called once every second,
 * then the global.inactiveTime variable will be incremented by 1 (1 second).
 * If checkActivity() is called and it finds that the amount of inactive time is equal to the time limit,
 * the application will close.
*/
void CredentialMenu::updateCursor(){
	cursorPosition = QCursor::pos();
}

void CredentialMenu::checkActivity(){
	if(inactivityTimerSet && credentialMenuActive){
		qDebug() << global.inactiveTime;
		ChangeGlobals cg;
		// Checks if mouse is on the window
		if(rect().contains(mapFromGlobal(QCursor::pos()))){
			// Checks if the mouse is idle in place
			if(QCursor::pos().x() == cursorPosition.x() && QCursor::pos().y() == cursorPosition.y() && credentialMenuActive){
				cg.incrementTimer();
			} else {
				cg.resetTimer();
			}
		} else {
			if(credentialMenuActive){
				cg.incrementTimer();
			}
		}

		// Quit the application once the amount of inactive time from the global header is equal to the timer limit in the global header
		if( global.inactiveTime >= global.timerLimit ){
			QCoreApplication::quit();
		}
	}
}


void CredentialMenu::formatButtonWithinFrame(QPushButton *button, int originalWidth, int originalLength, QFrame *frame){
	int buttonWidth = button->width();
	int buttonHeight = button->height();
	int buttonX = button->x();
	int buttonY = button->y();
	int frameWidth = originalWidth;
	int frameHeight = originalLength;

	double xRatio = (double)buttonX / (double)frameWidth;
	int finalX = frame->width() * xRatio;

	double yRatio = (double)buttonY / (double)frameHeight;
	int finalY = frame->height() * yRatio;

	double widthRatio = (double)buttonWidth / (double)frameWidth;
	int finalWidth = frame->width() * widthRatio;

	double heightRatio = (double)buttonHeight / (double)frameHeight;
	int finalHeight = frame->height() * heightRatio;

	button->setGeometry(finalX, finalY, finalWidth, finalHeight);
}


void CredentialMenu::formatLineEditWithinFrame(QLineEdit *button, int originalWidth, int originalLength, QFrame *frame){
	int buttonWidth = button->width();
	int buttonHeight = button->height();
	int buttonX = button->x();
	int buttonY = button->y();
	int frameWidth = originalWidth;
	int frameHeight = originalLength;

	double xRatio = (double)buttonX / (double)frameWidth;
	int finalX = frame->width() * xRatio;

	double yRatio = (double)buttonY / (double)frameHeight;
	int finalY = frame->height() * yRatio;

	double widthRatio = (double)buttonWidth / (double)frameWidth;
	int finalWidth = frame->width() * widthRatio;

	double heightRatio = (double)buttonHeight / (double)frameHeight;
	int finalHeight = frame->height() * heightRatio;

	button->setGeometry(finalX, finalY, finalWidth, finalHeight);
}

void CredentialMenu::formatFrame(QFrame *obj){
	int objWidth = obj->width();
	int objHeight = obj->height();
	int objX = obj->x();
	int objY = obj->y();
	int originalWidth = 1005;
	int originalHeight = 610;
	int window_Height = this->height();
	int window_Width = this->width();
	double xRatio = (double)objX / (double)originalWidth;
	int finalX = window_Width * xRatio;

	double yRatio = (double)objY / (double)originalHeight;
	int finalY  = window_Height * yRatio;

	double widthRatio = (double)objWidth / (double)originalWidth;
	int finalWidth = window_Width * widthRatio;

	double heightRatio = (double)objHeight / (double)originalHeight;
	int finalHeight = window_Height * heightRatio;

	obj->setGeometry(finalX, finalY, finalWidth, finalHeight);
}

void CredentialMenu::formatTable(QTableWidget *obj){
	int objWidth = obj->width();
	int objHeight = obj->height();
	int objX = obj->x();
	int objY = obj->y();
	int originalWidth = 1005;
	int originalHeight = 610;
	int window_Height = this->height();
	int window_Width = this->width();
	double xRatio = (double)objX / (double)originalWidth;
	int finalX = window_Width * xRatio;

	double yRatio = (double)objY / (double)originalHeight;
	int finalY  = window_Height * yRatio;

	double widthRatio = (double)objWidth / (double)originalWidth;
	int finalWidth = window_Width * widthRatio;

	double heightRatio = (double)objHeight / (double)originalHeight;
	int finalHeight = window_Height * heightRatio;

	obj->setGeometry(finalX, finalY, finalWidth, finalHeight);
}

void CredentialMenu::openAddCredentialPrompt(){
	ui.AddLabel->setTextFormat(Qt::RichText);
	ui.AddLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic;\">Add Credential</span></p></body></html>", nullptr));
	ui.AddCredentialButton->setText("Add");
	ui.AddService->setText("");
	ui.AddService->setPlaceholderText("Service Name");
	ui.AddPassword->setText("");
	ui.AddPassword->setPlaceholderText("Password");
	ui.AddUsername->setText("");
	ui.AddUsername->setPlaceholderText("Username or Email");
	ui.AddCredentialFrame->setVisible(true);
}

void CredentialMenu::closeAddCredentialPrompt(){
	ui.AddCredentialFrame->setVisible(false);
}


void CredentialMenu::addCredential(){
    // Code to add credential to JSON
    if(!editing){
	    CrossPlatform x;
	    Crypto cr;
	    SaveJson sj;
	    QString service =  ui.AddService->text();
	    QString username = ui.AddUsername->text();
	    QString password = ui.AddPassword->text();
	    sj.addCredentials(service, username, password);
            closeAddCredentialPrompt();
	    ui.CredentialTable->clear();
	    loadCredentials();
    }
    else {
		editCredential();
    }
}

void CredentialMenu::editCredential()
{
	    CrossPlatform x;
	    Crypto cr;
	    SaveJson sj;
	    QString service = ui.AddService->text();
	    QString username = ui.AddUsername->text();
	    QString password = ui.AddPassword->text();
	    removeSelectedCredential();
	    sj.addCredentials(service, username, password);
    	closeAddCredentialPrompt();
	    editing = false;
	    loadCredentials();
}



void CredentialMenu::loadCredentials(){
    ui.CredentialTable->clear();
	ui.CredentialTable->setColumnCount(4);
	ui.CredentialTable->setRowCount(1);
    ui.CredentialTable->verticalHeader()->setVisible(false);
	ui.CredentialTable->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.CredentialTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

	QString service("Service");
	QString username("Username/Email");
	QString password("Password");
	QString selection("Export");
	QTableWidgetItem* serviceHeader = new QTableWidgetItem(service);
	
	QTableWidgetItem* usernameHeader = new QTableWidgetItem(username);
	usernameHeader->setForeground(Qt::black);
	QTableWidgetItem* passwordHeader = new QTableWidgetItem(password);
	passwordHeader->setForeground(Qt::black);
	QTableWidgetItem* exportHeader = new QTableWidgetItem(selection);
	#ifdef __linux__
	exportHeader->setForeground(Qt::white);
	usernameHeader->setForeground(Qt::white);
	passwordHeader->setForeground(Qt::white);
	serviceHeader->setForeground(Qt::white);
	#elif defined TARGET_OS_MAC
	exportHeader->setForeground(Qt::white);
	usernameHeader->setForeground(Qt::white);
	passwordHeader->setForeground(Qt::white);
	serviceHeader->setForeground(Qt::white);
	#elif defined WIN32_ || WIN64_
	exportHeader->setForeground(Qt::black);
	usernameHeader->setForeground(Qt::black);
	passwordHeader->setForeground(Qt::black);
	serviceHeader->setForeground(Qt::black);
	#else
	#error "Not a valid OS"
	#endif
	ui.CredentialTable->setHorizontalHeaderItem(0, serviceHeader);
	ui.CredentialTable->setHorizontalHeaderItem(1, usernameHeader);
	ui.CredentialTable->setHorizontalHeaderItem(2, passwordHeader);
	ui.CredentialTable->setHorizontalHeaderItem(3, exportHeader);
	int width;
	for (int s = 0; s < ui.CredentialTable->horizontalHeader()->count(); ++s) {
		//ui.CredentialTable->horizontalHeader()->setSectionResizeMode(s, QHeaderView::Stretch);
		if (s < 3) {
			width = ui.CredentialTable->width() * 0.30;
			ui.CredentialTable->horizontalHeader()->resizeSection(s, width);
		}
		else {
			ui.CredentialTable->horizontalHeader()->setStretchLastSection(true);
		}
	}

    Crypto crypt;
    using namespace nlohmann;
    std::ifstream jFile("./credentials.json");
    json j = json::parse(jFile);

    int size = j["Credentials"][0]["Entries"].size();
	services.clear();
	passwords.clear();
	usernames.clear();
    for(int i = 0; i < size; i++){
        services.push_back(crypt.decryptValue(QString::fromStdString(j["Credentials"][0]["Entries"][i]["service"])));
        passwords.push_back(crypt.decryptValue(QString::fromStdString(j["Credentials"][0]["Entries"][i]["password"])));
        usernames.push_back(crypt.decryptValue(QString::fromStdString(j["Credentials"][0]["Entries"][i]["username"])));
    }

    ui.CredentialTable->setRowCount(services.size());
    for(int row=0; row < services.size(); row++){
        QTableWidgetItem *serviceItem = new QTableWidgetItem(QString::fromStdString(services.at(row)));
        ui.CredentialTable->setItem(row, 0, serviceItem);

        QTableWidgetItem *userItem = new QTableWidgetItem(QString::fromStdString(usernames.at(row)));
        ui.CredentialTable->setItem(row, 1, userItem);

        QTableWidgetItem *passItem = new QTableWidgetItem(QString::fromStdString(passwords.at(row)));
        ui.CredentialTable->setItem(row, 2, passItem);

		QWidget* checkItem = new QWidget();
		QCheckBox *checkBox = new QCheckBox();
		QHBoxLayout *layout = new QHBoxLayout(checkItem);
		layout->addWidget(checkBox);
		layout->setAlignment(Qt::AlignCenter);
		layout->setContentsMargins(0, 0, 0, 0);
		checkItem->setLayout(layout);
		ui.CredentialTable->setCellWidget(row, 3, checkItem);
    }
}

void CredentialMenu::exportAllCredentials(){	
	QString export_all_dir = QFileDialog::getExistingDirectory(this, tr("Choose Directory For Exported Credentials File"), QDir::currentPath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	CrossPlatform x;
	QString workingPath = qApp->applicationDirPath() + "/credentials.json";
	std::string copy;
	std::string cmd;
	#if defined __linux__  
	copy = "cp ";
	cmd = copy + x.xString(workingPath) + " " + x.xString(export_all_dir);
	#elif defined TARGET_OS_MAC
	copy = "cp ";
	cmd = copy + x.xString(workingPath) + " " + x.xString(export_all_dir);	
	#elif defined _WIN32 || defined _WIN64
	copy = "copy ";
	cmd = copy + x.xString(workingPath) + " " + x.xString(export_all_dir);
	std::replace(cmd.begin(), cmd.end(), '/', '\\');
	#else
	#error "unknown platform"
	#endif

	const char* c;
	c = cmd.c_str();
	system(c);
	
	
}

void CredentialMenu::exportSelectedCredentials(){
	exportServices.clear();
	exportUsernames.clear();
	exportPasswords.clear();
	// QFolderDialog asking where to save the file to
	export_selected_dir = QFileDialog::getExistingDirectory(this, tr("Choose Directory For Exported Credentials File"),
                                             QDir::currentPath(),
                                             QFileDialog::ShowDirsOnly
                                             | QFileDialog::DontResolveSymlinks);
	for(int row = 0; row < services.size(); row++){
		QWidget *checkWidget = (QWidget *)ui.CredentialTable->cellWidget(row, 3);
		QCheckBox *box = (QCheckBox *)checkWidget->children().at(1);
		if(box->isChecked()){
			exportServices.append(ui.CredentialTable->item(row, 0)->text());
			exportUsernames.append(ui.CredentialTable->item(row, 1)->text());
			exportPasswords.append(ui.CredentialTable->item(row, 2)->text());
		}
	}

	// Spawn prompt asking for different login credentials to access the selected credentials file that will be exported.
	QWidget *logChange = new ExportLoginChange();
	QObject::connect(logChange, SIGNAL(sendFinishedSignal(QString)), this, SLOT(loginChangeData(QString)));
	logChange->show();
}

void CredentialMenu::loginChangeData(QString hashedPass){
    using namespace nlohmann;
    json j;
    j["Credentials"] = {};
	CrossPlatform x;
    std::ofstream o(x.xString(export_selected_dir) + "/credentials.json");
    o << std::setw(4) << j << std::endl;

	std::ifstream jFile(x.xString(export_selected_dir) + "/credentials.json");
    json jPass = json::parse(jFile);

    json masterPass;
    masterPass["MasterPassword"] = {x.xString(hashedPass)};
    jPass["Credentials"].push_back(masterPass);
    std::ofstream oPass(x.xString(export_selected_dir) + "/credentials.json");
    oPass << std::setw(4) << jPass << std::endl;
	SaveJson sj;
	sj.addExportedCredentials(exportServices, exportUsernames, exportPasswords, x.xString(export_selected_dir));
}




bool CredentialMenu::eventFilter(QObject *obj, QEvent *event)
{
	if(obj == (QObject*)ui.ImportExportOptionsButton) {
		if(event->type() == QEvent::HoverEnter)
		{
		    ui.ImportExportFrame->setVisible(true);
		}
		if(event->type() == QEvent::HoverLeave && !inImportExportFrame)
		{
		    ui.ImportExportFrame->setVisible(false);
		}
		else {
			return QWidget::eventFilter(obj, event);
		}
	}
	if(obj == (QObject*)ui.ImportExportFrame) {
		if(event->type() == QEvent::Enter)
		{
		    inImportExportFrame = true;
		    ui.ImportExportFrame->setVisible(true);
		}
		if(event->type() == QEvent::Leave)
		{
		    inImportExportFrame = false;
		    ui.ImportExportFrame->setVisible(false);
		}
		else {
	        	return QWidget::eventFilter(obj, event);
		}
	}

	// search bar listener
	CrossPlatform cross;
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* enteredKey = static_cast<QKeyEvent*>(event);
		QString key = enteredKey->text();
		QString newEditedText;
		if (key == "\b") {
			std::string lineText(cross.xString(ui.SearchBar->text()));
			lineText.pop_back();
			newEditedText = QString::fromStdString(lineText);
		}
		else {
			newEditedText = ui.SearchBar->text() + key;
		}
		ui.SearchBar->setText(newEditedText);
		search(cross.xString(newEditedText.toUtf8().constData()));
		return true;
	}
	else {
		return QObject::eventFilter(obj, event);
	}
}

std::string CredentialMenu::toLowerCase(std::string words) {
	std::string str = words;
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) {
			return std::tolower(c);
		});
	return str;
}

void CredentialMenu::search(std::string searchTerm) {
	std::vector<int> resultIndexes;
	std::string searchWord = toLowerCase(searchTerm);
	for (int i = 0; i < services.size(); i++) {
		if (toLowerCase(services.at(i)).find(searchWord) != std::string::npos) {
			resultIndexes.push_back(i);
		}
	}
	ui.CredentialTable->clear();
	ui.CredentialTable->setRowCount(resultIndexes.size());
	for (int i = 0; i < resultIndexes.size(); i++) {
		QTableWidgetItem* serviceItem = new QTableWidgetItem(QString::fromStdString(services.at(resultIndexes.at(i))));
		ui.CredentialTable->setItem(i, 0, serviceItem);
		QTableWidgetItem* userItem = new QTableWidgetItem(QString::fromStdString(usernames.at(resultIndexes.at(i))));
		ui.CredentialTable->setItem(i, 1, userItem);
		QTableWidgetItem* passItem = new QTableWidgetItem(QString::fromStdString(passwords.at(resultIndexes.at(i))));
		ui.CredentialTable->setItem(i, 2, passItem);
	}
}

void CredentialMenu::copySelectedCell(){
	QTableWidgetItem *selected = ui.CredentialTable->selectedItems().first();
	int row = ui.CredentialTable->row(selected);
	int column = ui.CredentialTable->column(selected);
	QString itemText = ui.CredentialTable->item(row, column)->text();
	QClipboard *clipboard = QGuiApplication::clipboard();
	clipboard->setText(itemText);
}

void CredentialMenu::removeSelectedCredential(){
	QTableWidgetItem *selected = ui.CredentialTable->selectedItems().first();
	int row = ui.CredentialTable->row(selected);
	CrossPlatform x;

	QString service =   ui.CredentialTable->item(row, 0)->text();
	QString username =  ui.CredentialTable->item(row, 1)->text();
	QString pass =      ui.CredentialTable->item(row, 2)->text();
	SaveJson sj;
	sj.removeCredential(service, username, pass);
	loadCredentials();
}
