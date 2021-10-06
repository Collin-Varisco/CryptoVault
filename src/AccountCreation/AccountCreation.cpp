#include "AccountCreation.h"
#include "../CredentialMenu/CredentialMenu.h"

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
        QWidget *mainMenu;
        CredentialMenu menu;
        mainMenu = new CredentialMenu();
        this->setCentralWidget(mainMenu);
        mainMenu->setFixedSize(1000, 750);
        this->adjustSize();
}
