#include "CredentialMenu.h"
#include <vector>
#include <string>
#include <fstream>
#include <QClipboard>
CredentialMenu::CredentialMenu(QFrame *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.CredentialTable->setColumnWidth(0, 260);
    ui.CredentialTable->setColumnWidth(1, 260);
    ui.CredentialTable->setColumnWidth(2, 260);
	ui.CredentialTable->setColumnWidth(3, 39);
    ui.AddCredentialFrame->setVisible(false);

    connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(openAddCredentialPrompt()));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(closeAddCredentialPrompt()));
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

