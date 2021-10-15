#include "CredentialMenu.h"
#include <nlohmann/json.hpp>
#include "../JSON/SaveJson.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include <vector>
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
    ui.CredentialTable->setColumnCount(3);
    ui.CredentialTable->verticalHeader()->setVisible(false);
    QStringList headers;
    headers << "Service" << "Username/Email" << "Password";
    ui.CredentialTable->setHorizontalHeaderLabels(headers);

    Crypto crypt;
    using namespace nlohmann;
    std::ifstream jFile("./credentials.json");
    json j = json::parse(jFile);

    int size = j["Credentials"][0]["Entries"].size();
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
    }

    ui.CredentialTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui.CredentialTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.CredentialTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
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
