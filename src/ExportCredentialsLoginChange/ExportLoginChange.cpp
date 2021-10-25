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
}


void ExportLoginChange::changeLogin(){
    QWidget *mainMenu;
    Crypto crypt;
    CrossPlatform x;
    ChangeGlobals change;

    QString username = ui.UsernameInput->text();
    QString pass = ui.EncryptionKeyInput->text();
    QString combo = crypt.hash256(username) + crypt.hash256(pass);
    std::string entered = x.xString(crypt.hash256(combo));
    change.changeKey(x.xString(crypt.hash256(username)), true);
    change.changeIV(entered, true);
    sendFinished();
    this->close();
}

void ExportLoginChange::sendFinished(){
    emit sendFinishedSignal(true);
}

