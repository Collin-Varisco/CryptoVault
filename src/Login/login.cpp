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
#include <QGuiApplication>
#include <QScreen>

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
	QString combo = crypt.hash256(username + pass);
	std::string entered = x.xString(crypt.hash256(crypt.hash256(username) + crypt.hash256(pass)));
	std::string passHash = sj.loadMasterPassword();

	if(entered == passHash){
		change.changeKey(x.xString(crypt.hash256(username)), false);
        change.changeIV(x.xString(crypt.hash256(combo)), false);

		mainMenu = new CredentialMenu();
		QScreen *screen = QGuiApplication::primaryScreen();
		QRect geometry = screen->geometry();
		// Make 70% of full screen, then change to 16:9 aspect ratio.
		int width = geometry.width() * 0.7;
		int height = width * 0.68;
		this->close();
		mainMenu->setFixedSize(width, height);
		mainMenu->show();
	}
}
