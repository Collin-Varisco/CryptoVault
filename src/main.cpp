#include <QtGui>
#include <QFrame>
#include "Initial_Start_Menu/startScreen.h"
#include "Login/login.h"
#include "Global/Global.h"
#include "Global/ChangeGlobals.h"
#include "JSON/SaveJson.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    SaveJson sj;
    login log;
    startScreen s_screen;
   
    // Initialize whether unit testing is done
    bool unitTesting = false;

    if(unitTesting){
      ChangeGlobals cg;
      cg.setUnitTesting(true);
      system("cp ../unit-testing/initial-credentials/credentials.json ../build");
    }

    bool found = sj.checkForFile();
    if(!found){
	    s_screen.show();
    }
    else {
	log.show();
        if(unitTesting){
          log.unitTestLogin();
        }
    }
    app.exec();
}
