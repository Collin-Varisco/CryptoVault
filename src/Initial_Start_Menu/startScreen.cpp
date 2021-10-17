#include "startScreen.h"
#include "../AccountCreation/AccountCreation.h"
#include "../CrossPlatform/CrossPlatform.h"
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include "../Login/login.h"

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
 * copies file over to the working directory of the application.
*/
void startScreen::recoverAccount(){

}
