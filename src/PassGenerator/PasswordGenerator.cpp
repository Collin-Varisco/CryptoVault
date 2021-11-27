#include <string>
#include <iostream>
#include <ctype.h>
#include <QDebug>
#include <QString>
#include "../Global/Global.h"
#include "../Global/ChangeGlobals.h"
#include "../JSON/SaveJson.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../Settings/Settings.h"
#include "../CredentialMenu/CredentialMenu.h"
#include <QTimer>
#include "PasswordGenerator.h"
#include <QGuiApplication>
#include <QScreen>
#include <stdlib.h>
#include <time.h>
#include <QClipboard>

PasswordGenerator::PasswordGenerator(QFrame *parent)
    : QMainWindow(parent)
{
    // loads prompt
    ui.setupUi(this);
    ui.IncludeExcludeFrame->hide();

    generatorActive = true;
    //[TODO] add functions to go to settings and vault menus and switch generatorActive to OFF

    connect(ui.SettingsButton, SIGNAL(clicked()), this, SLOT(launchSettings()));
    connect(ui.VaultButton, SIGNAL(clicked()), this, SLOT(launchVault()));
    
    connect(ui.IncludeButton, SIGNAL(clicked()), this, SLOT(openIncludePrompt()));
    connect(ui.ExcludeButton, SIGNAL(clicked()), this, SLOT(openExcludePrompt()));
    connect(ui.GenerateButton, SIGNAL(clicked()), this, SLOT(generatePassword()));
    connect(ui.CopyButton, SIGNAL(clicked()), this, SLOT(copyPassword()));
    connect(ui.AddCharactersButton, SIGNAL(clicked()), this, SLOT(addCharacters()));

	// Timer Initialization Variables
    SaveJson sj;
    inactivityTimerSet = sj.timerOn();
    if(inactivityTimerSet){
      ChangeGlobals cg;
      cg.setTimer(sj.timerLimit());
    }
   
    // Activity Timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkActivity()));
    timer->start(1000);
    // Update Cursor Position Timer
    QTimer *updateCursorTimer = new QTimer(this);
    connect(updateCursorTimer, SIGNAL(timeout()), this, SLOT(updateCursor()));
    updateCursorTimer->start(500);
}

void PasswordGenerator::launchSettings(){
  QWidget *set = new Settings();
  this->close();
  set->show();
}

void PasswordGenerator::launchVault(){
  QWidget *vault = new CredentialMenu();
  this->close();
  vault->show();
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
	QString itemText = ui.GeneratedPasswordLabel->text();
	QClipboard *clip = QGuiApplication::clipboard();
	clip->setText(itemText);
}


void PasswordGenerator::generatePassword()
{
	bool onlyLettersAndNumbers = ui.AlphaNumericBox->isChecked();
	bool specificLength = ui.NumberCharactersCheck->isChecked();
	std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	std::vector<char> cap_letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	std::vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	std::vector<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '=', '[', ']', '{', '}', '|', '?', '>', '<', ',', '.', '~'};
	int default_length = 14;
	int input_length;
	CrossPlatform x;
	if(specificLength && onlyLettersAndNumbers){
			// use a try catch for this to catch the error if a number is not entered
			try {
		        input_length = stoi(x.xString(ui.TotalCharactersLine->text()));
				default_length = input_length;
			} catch(int ex){
				default_length = 14;
            }
		
				std::string pass = "";
				for(int i = 0; i < default_length; i++){
						int characterSelection = rand() % 3;
						if(characterSelection == 0){
							int randomIndex = rand() % 26;
							pass += letters.at(randomIndex);
						} else if(characterSelection == 1){
							int randomIndex = rand() % 26;
							pass += cap_letters.at(randomIndex);
						} else if(characterSelection == 2){
							int randomIndex = rand() % 10;
							pass += numbers.at(randomIndex);
                        }
				}
				ui.GeneratedPasswordLabel->setText(QString::fromStdString(pass));
				std::cout << pass << std::endl;
		
	}

	else if(specificLength && !onlyLettersAndNumbers){
			try {
		        input_length = stoi(x.xString(ui.TotalCharactersLine->text()));
				default_length = input_length;
			} catch(int ex){
				default_length = 14;
            }
			std::string pass = "";
			for(int i = 0; i < default_length; i++){
				int characterSelection = rand() % 4;
				if(characterSelection == 0){
					int randomIndex = rand() % 26;
					pass += letters.at(randomIndex);
                } else if(characterSelection == 1){
					int randomIndex = rand() % 26;
					pass += cap_letters.at(randomIndex);
                } else if(characterSelection == 2){
					int randomIndex = rand() % 10;
					pass += numbers.at(randomIndex);
                } else if(characterSelection == 3){
					int randomIndex = rand() % symbols.size();
					pass += symbols.at(randomIndex);
                }
			}
			ui.GeneratedPasswordLabel->setText(QString::fromStdString(pass));
	}
    else if( !specificLength && !onlyLettersAndNumbers){
			std::string pass = "";
			for(int i = 0; i < default_length; i++){
				int characterSelection = rand() % 4;
				if(characterSelection == 0){
					int randomIndex = rand() % 26;
					pass += letters.at(randomIndex);
                } else if(characterSelection == 1){
					int randomIndex = rand() % 26;
					pass += cap_letters.at(randomIndex);
                } else if(characterSelection == 2){
					int randomIndex = rand() % 10;
					pass += numbers.at(randomIndex);
                } else if(characterSelection == 3){
					int randomIndex = rand() % symbols.size();
					pass += symbols.at(randomIndex);
                }
			}
			ui.GeneratedPasswordLabel->setText(QString::fromStdString(pass));
	}
	else if( onlyLettersAndNumbers && !specificLength ) {
			std::string pass = "";
			for(int i = 0; i < default_length; i++){
				int characterSelection = rand() % 3;
				if(characterSelection == 0){
					int randomIndex = rand() % 26;
					pass += letters.at(randomIndex);
                } else if(characterSelection == 1){
					int randomIndex = rand() % 26;
					pass += cap_letters.at(randomIndex);
                } else if(characterSelection == 2){
					int randomIndex = rand() % 10;
					pass += numbers.at(randomIndex);
                } 
			}
			ui.GeneratedPasswordLabel->setText(QString::fromStdString(pass));
    }
}



void PasswordGenerator::updateCursor(){
	cursorPosition = QCursor::pos();
}

void PasswordGenerator::checkActivity()
{
	if(inactivityTimerSet && generatorActive){
		qDebug() << global.inactiveTime;
		ChangeGlobals cg;
		
		if(rect().contains(mapFromGlobal(QCursor::pos()))){
			
			if(QCursor::pos().x() == cursorPosition.x() && QCursor::pos().y() == cursorPosition.y()){
				cg.incrementTimer();
			} else {
				cg.resetTimer();
			}
		} else {
				cg.incrementTimer();
		}

		
		if( global.inactiveTime >= global.timerLimit ){
			QCoreApplication::quit();
		}
	}
}

