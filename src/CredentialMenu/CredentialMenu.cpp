#include "CredentialMenu.h"
#include <nlohmann/json.hpp>
#include "../JSON/SaveJson.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include <vector>
#include <QHBoxLayout>
#include <QCheckBox>

#include <string>
#include <fstream>
#include <QClipboard>
CredentialMenu::CredentialMenu(QFrame *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.ImportExportOptionsButton->installEventFilter(this);
    ui.ImportExportFrame->installEventFilter(this);
    ui.AddCredentialFrame->setVisible(false);
    ui.ImportExportFrame->setVisible(false);

    connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(openAddCredentialPrompt()));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(closeAddCredentialPrompt()));
    connect(ui.AddCredentialButton, SIGNAL(clicked()), this, SLOT(addCredential()));
    loadCredentials();

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
}
