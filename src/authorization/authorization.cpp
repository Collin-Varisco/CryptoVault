#include <string>
#include <QDebug>
#include <iostream>
#include <ctype.h>
#include <QString>
#include "authorization.h"
#include "../CredentialMenu/CredentialMenu.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../Global/ChangeGlobals.h"
#include "../Global/Global.h"
#include "../JSON/SaveJson.h"
#include <QGuiApplication>
#include <QScreen>

authorization::authorization(QFrame *parent)
    : QMainWindow(parent)
{
    // loads authorization prompt
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
    if(global.unit_testing){
      qDebug() << "Authorizing Credential File Import";
      qDebug() << "Username: u2 ; Password: p2";
      ui.UsernameInput->setText("u2");
      ui.EncryptionKeyInput->setText("p2");
      ui.pushButton->animateClick();
    }
}


void authorization::attemptLogin(){
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
    std::string filePass = sj.loadImportFilePassword(global.global_import_path);

    if(entered == filePass){
            change.changeKey(x.xString(crypt.hash256(username)), true);
            change.changeIV(x.xString(crypt.hash256(combo)), true);
            sendFinished(global.temp_key);
            this->close();
    }
}

void authorization::sendFinished(std::string authorized){
    emit sendFinishedSignal(authorized);
}
