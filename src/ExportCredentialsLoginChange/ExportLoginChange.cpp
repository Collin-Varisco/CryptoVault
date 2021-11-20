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
    QString combo = crypt.hash256(username + pass);
    
    // This is for temporary swap when exporting selecting credentials with different credentials.
    change.changeKey(x.xString(crypt.hash256(username)), true); 
    // This is to allow decrypting of credentials on the same session that a user changes their password.
    change.changeKey(x.xString(crypt.hash256(username)), false);

    QString saltedHashPass = crypt.hash256(crypt.hash256(username) + crypt.hash256(pass));
    
    // This is for temporary swap when exporting selecting credentials with different credentials.
    change.changeIV(x.xString(crypt.hash256(combo)), true);
    // This is to allow decrypting of credentials on the same session that a user changes their password.
    change.changeIV(x.xString(crypt.hash256(combo)), false);
    
    sendFinished(saltedHashPass);
    this->close();
}

void ExportLoginChange::sendFinished(QString hashedPass){
    emit sendFinishedSignal(hashedPass);
}

