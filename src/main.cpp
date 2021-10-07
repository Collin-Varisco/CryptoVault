#include <QtGui>
#include <QFrame>
#include "Initial_Start_Menu/startScreen.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    startScreen s_screen;
    s_screen.show();
    app.exec();
}
