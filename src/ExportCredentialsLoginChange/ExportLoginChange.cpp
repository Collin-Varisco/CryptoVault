#include <string>
#include <iostream>
#include <ctype.h>
#include <QString>
#include "ExportLoginChange.h"
#include "../CredentialMenu/CredentialMenu.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../Global/ChangeGlobals.h"
#include "../Global/Global.h"
#include <QGuiApplication>
#include <QScreen>

ExportLoginChange::ExportLoginChange(QFrame *parent)
    : QMainWindow(parent)
{
    // loads prompt
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(changeLogin()));
    if(global.unit_testing){
      ui.UsernameInput->setText("exportUser1");
      ui.EncryptionKeyInput->setText("exportPass1");
      ui.pushButton->animateClick();
    }
}


void ExportLoginChange::changeLogin(){
    QWidget *mainMenu;
    Crypto crypt;
    CrossPlatform x;
    ChangeGlobals change;

    QString username = ui.UsernameInput->text();
    QString pass = ui.EncryptionKeyInput->text();
    QString combo = crypt.hash256(username + pass);
    change.changeKey(x.xString(crypt.hash256(username)), true);

    QString saltedHashPass = crypt.hash256(crypt.hash256(username) + crypt.hash256(pass));

    change.changeIV(x.xString(crypt.hash256(combo)), true);
    sendFinished(saltedHashPass);
    this->close();
}

void ExportLoginChange::sendFinished(QString hashedPass){
    emit sendFinishedSignal(hashedPass);
}

