#include <string>
#include <iostream>
#include <ctype.h>
#include <QString>
#include "login.h"
#include "../CredentialMenu/CredentialMenu.h"

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
        mainMenu = new CredentialMenu();
        this->setCentralWidget(mainMenu);
        mainMenu->setFixedSize(1000, 600);
        this->adjustSize();
}
