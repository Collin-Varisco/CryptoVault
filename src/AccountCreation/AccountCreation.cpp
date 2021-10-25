#include "AccountCreation.h"
#include "../CredentialMenu/CredentialMenu.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../JSON/SaveJson.h"
#include "../Crypto/Crypto.h"
#include "../Global/ChangeGlobals.h"
#include "../Global/Global.h"
#include <QGuiApplication>
#include <QScreen>

AccountCreation::AccountCreation(QFrame *parent)
    : QMainWindow(parent)
{
    // loads login prompt
    ui.setupUi(this);

    // Error Prompts that will be set to visible when necessary
    ui.usernameError->setVisible(false);
    ui.passwordError->setVisible(false);

    // Account Creation Button Listener
    connect(ui.createButton, SIGNAL(clicked()), this, SLOT(verify()));
}

void AccountCreation::verify(){
        CrossPlatform x;
        QString username = ui.UsernameInput->text();
        QString key_1 = ui.EncryptionKeyInput->text();
        QString key_2 = ui.EncryptionKeyInput_2->text();

        bool error = false;
        QString blank("");
        if(username == blank){
            ui.usernameError->setVisible(true);
            error = true;
        } else if(key_1 != key_2){
            ui.passwordError->setVisible(true);
            error = true;
        } else if(key_1 == blank || key_2 == blank){
            error = true;
        }

        if(!error){
            Crypto crypt;
            ChangeGlobals change;
            QString combo = username + key_1;

            change.changeKey(x.xString(crypt.hash256(username)), false);
            QString saltedPass = crypt.hash256(username) + crypt.hash256(key_1);
            change.changeIV(x.xString(crypt.hash256(saltedPass)), false);

            SaveJson sj;
            sj.createJSON();
            sj.setMasterPassword(x.xString(crypt.hash256(combo)));

            QWidget *mainMenu;
            mainMenu = new CredentialMenu();
	    this->close();
	    mainMenu->show();
        }
}
