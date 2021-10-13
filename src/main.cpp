#include <QtGui>
#include <QFrame>
#include "Initial_Start_Menu/startScreen.h"
#include "Login/login.h"
#include "JSON/SaveJson.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    SaveJson sj;
    login log;
    startScreen s_screen;
    bool found = sj.checkForFile();
    if(!found){
	    s_screen.show();
    }
    else {
	log.show();
    }
    app.exec();
}
