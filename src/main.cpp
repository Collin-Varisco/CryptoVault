#include <QtGui>
#include <QFrame>
#include "AccountCreation/AccountCreation.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    AccountCreation accountCreation;
    accountCreation.show();
    app.exec();
}
