#include <string>
#include <iostream>
#include <ctype.h>
#include <QString>
#include "login.h"
#include "../CredentialMenu/CredentialMenu.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../Global/ChangeGlobals.h"
#include "../Global/Global.h"
#include "../JSON/SaveJson.h"

login::login(QFrame *parent)
    : QMainWindow(parent)
{
    // loads login prompt
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
}


void login::attemptLogin(){
        QWidget *mainMenu;
        CredentialMenu menu;
	Crypto crypt;
	CrossPlatform x;
	SaveJson sj;
	ChangeGlobals change;

	QString username = ui.UsernameInput->text();
	QString pass = ui.EncryptionKeyInput->text();
	QString combo = username + pass;
	std::string entered = x.xString(crypt.hash256(combo));
	std::string passHash = sj.loadMasterPassword();

	if(entered == passHash){
		change.changeKey(x.xString(crypt.hash256(username)));
		change.changeIV(x.xString(crypt.hash256(pass)));

		mainMenu = new CredentialMenu();
		this->setCentralWidget(mainMenu);
		mainMenu->setFixedSize(1005, 610);
		this->adjustSize();
	}
}
