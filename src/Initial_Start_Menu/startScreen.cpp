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

/* recoverAccount()
 * Opens file dialog that allows user to select an existing credential file to recover their account
 * copies file over to the working directory of the application.
*/
void startScreen::recoverAccount(){
	CrossPlatform x;
	QString workingDirectory = qApp->applicationDirPath();
	QString filePath = QFileDialog::getOpenFileName(this, "Open Account JSON", workingDirectory, "JSON File (*.json)");
	std::string copy;
	std::string cmd;
	#if defined __linux__  
	copy = "cp ";
	cmd = copy + x.xString(filePath) + " " + x.xString(workingDirectory);
	#elif defined TARGET_OS_MAC
	copy = "cp ";
	cmd = copy + x.xString(filePath) + " " + x.xString(workingDirectory);	
	#elif defined _WIN32 || defined _WIN64
	copy = "copy ";
	cmd = copy + x.xString(filePath) + " " + x.xString(workingDirectory);
	std::replace(cmd.begin(), cmd.end(), '/', '\\');
	#else
	#error "unknown platform"
	#endif

	const char* c;
	c = cmd.c_str();
	system(c);
	QWidget* log;
	log = new login();
	this->close();
	log->show();
}
