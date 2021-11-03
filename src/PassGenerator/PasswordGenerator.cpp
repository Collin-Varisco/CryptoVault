#include <string>
#include <iostream>
#include <ctype.h>
#include <QDebug>
#include <QString>
#include "../Global/Global.h"
#include "../Global/ChangeGlobals.h"
#include "../CrossPlatform/CrossPlatform.h"
#include <QTimer>
#include "PasswordGenerator.h"
#include <QGuiApplication>
#include <QScreen>

PasswordGenerator::PasswordGenerator(QFrame *parent)
    : QMainWindow(parent)
{
    // loads prompt
    ui.setupUi(this);
    ui.IncludeExcludeFrame->hide();

    // [TODO]
    // inactivityTimerSet = json.isTimerSet()
    inactivityTimerSet = false;

    connect(ui.IncludeButton, SIGNAL(clicked()), this, SLOT(openIncludePrompt()));
    connect(ui.ExcludeButton, SIGNAL(clicked()), this, SLOT(openExcludePrompt()));
    connect(ui.GenerateButton, SIGNAL(clicked()), this, SLOT(generatePassword()));
    connect(ui.CopyButton, SIGNAL(clicked()), this, SLOT(copyPassword()));
    connect(ui.AddCharactersButton, SIGNAL(clicked()), this, SLOT(addCharacters()));

    // Activity Timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkActivity()));
    timer->start(1000);
    // Update Cursor Position Timer
    QTimer *updateCursorTimer = new QTimer(this);
    connect(updateCursorTimer, SIGNAL(timeout()), this, SLOT(updateCursor()));
    updateCursorTimer->start(500);

	cursorPosition = QCursor::pos();
}

void PasswordGenerator::openIncludePrompt(){
	ui.AddCharactersButton->setText("Include Characters");
	ui.IncludeExcludeFrame->show();
}

void PasswordGenerator::openExcludePrompt(){
	ui.AddCharactersButton->setText("Exclude Characters");
	ui.IncludeExcludeFrame->show();
}


void PasswordGenerator::addCharacters(){
	if(ui.AddCharactersButton->text() == "Include Characters"){
		includeList.append(ui.IE_FIELD_1->text());
		includeList.append(ui.IE_FIELD_2->text());
		includeList.append(ui.IE_FIELD_3->text());
		includeList.append(ui.IE_FIELD_4->text());
		includeList.append(ui.IE_FIELD_5->text());
		includeList.append(ui.IE_FIELD_6->text());
	} else {
		excludeList.append(ui.IE_FIELD_1->text());
		excludeList.append(ui.IE_FIELD_2->text());
		excludeList.append(ui.IE_FIELD_3->text());
		excludeList.append(ui.IE_FIELD_4->text());
		excludeList.append(ui.IE_FIELD_5->text());
		excludeList.append(ui.IE_FIELD_6->text());
	}
	ui.IncludeExcludeFrame->hide();
}

void PasswordGenerator::copyPassword() {

}


void PasswordGenerator::generatePassword(){
	bool onlyLettersAndNumbers = ui.AlphaNumericBox->isChecked();
	bool specificLength = ui.NumberCharactersCheck->isChecked();
	int default_length = 14;
	if(onlyLettersAndNumbers){
		CrossPlatform x;
		int input_length;
		if(specificLength){
			// use a try catch for this to catch the error if a number is not entered
		        input_length = stoi(x.xString(ui.TotalCharactersLine->text()));
			// ____________________

			default_length = input_length;
		} else {
			// Generator Code
			// use variables: includeList and excludeList
		}
	}
	if(specificLength && !onlyLettersAndNumbers){
		qDebug() << "Just specific length chosen.";
	}
}


void PasswordGenerator::updateCursor(){
	cursorPosition = QCursor::pos();
}

void PasswordGenerator::checkActivity(){
	if(inactivityTimerSet){
		ChangeGlobals cg;
		// Checks if mouse is on the window
		if(rect().contains(mapFromGlobal(QCursor::pos()))){
			// Checks if the mouse is idle in place
			if(QCursor::pos().x() == cursorPosition.x() && QCursor::pos().y() == cursorPosition.y()){
				cg.incrementTimer();
			} else {
				cg.resetTimer();
			}
		} else {
			cg.incrementTimer();
		}

		// Quit the application once the amount of inactive time from the global header is equal to the timer limit in the global header
		if( global.inactiveTime >= global.timerLimit ){
			QCoreApplication::quit();
		}
	}
}
