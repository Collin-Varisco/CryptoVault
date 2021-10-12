#include "startScreen.h"
#include "../AccountCreation/AccountCreation.h"
#include <QString>
#include <QFileDialog>

startScreen::startScreen(QFrame *parent)
    : QMainWindow(parent)
{
    // loads start screen
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(createAccount()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(recoverAccount()));
}

/* createAccount
 * calls account creation constructor to switch to the
 * account creation screen.
*/
void startScreen::createAccount(){
	QWidget *createAccount;
	createAccount = new AccountCreation();
        AccountCreation *AC = new AccountCreation();
	this->close();
	AC->show();
	//this->setCentralWidget(createAccount);
}

// [TODO]
/* recoverAccount()
 * Opens file dialog that allows user to select an existing credential file to recover their account
 *
 * Uses cross platform class importRecoveryCredentials(QString filePath, QString workingDirectory)
 * to copy the credential file to the working directory.
 * Pass the path to the file that is initialized from the QFileDialog.
 * Pass the executable working directory path as the second variable.
 * Once it has been copied initialize the login screen so the user can log in to their existing account.
*/
void startScreen::recoverAccount(){

}
