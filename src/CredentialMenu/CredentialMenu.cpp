#include "CredentialMenu.h"
#include <nlohmann/json.hpp>
#include "../JSON/SaveJson.h"
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
    ui.ImportExportOptionsButton->installEventFilter(this);
    ui.ImportExportFrame->installEventFilter(this);
    ui.AddCredentialFrame->setVisible(false);
    ui.ImportExportFrame->setVisible(false);

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
    loadCredentials();
}

void CredentialMenu::openSettings() {
	QWidget* settings;
	settings = new Settings();
	this->close();
	settings->show();

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
		// editCredential();
    }
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
	serviceHeader->setForeground(Qt::black);
	QTableWidgetItem* usernameHeader = new QTableWidgetItem(username);
	usernameHeader->setForeground(Qt::black);
	QTableWidgetItem* passwordHeader = new QTableWidgetItem(password);
	passwordHeader->setForeground(Qt::black);
	QTableWidgetItem* exportHeader = new QTableWidgetItem(selection);
	exportHeader->setForeground(Qt::black);
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
