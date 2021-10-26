#include <string>
#include <iostream>
#include <ctype.h>
#include <QDebug>
#include <QString>
#include "../CrossPlatform/CrossPlatform.h"
#include "PasswordGenerator.h"
#include <QGuiApplication>
#include <QScreen>

PasswordGenerator::PasswordGenerator(QFrame *parent)
    : QMainWindow(parent)
{
    // loads prompt
    ui.setupUi(this);
    ui.IncludeExcludeFrame->hide();

    connect(ui.IncludeButton, SIGNAL(clicked()), this, SLOT(openIncludePrompt()));
    connect(ui.ExcludeButton, SIGNAL(clicked()), this, SLOT(openExcludePrompt()));
    connect(ui.GenerateButton, SIGNAL(clicked()), this, SLOT(generatePassword()));
    connect(ui.CopyButton, SIGNAL(clicked()), this, SLOT(copyPassword()));
    connect(ui.AddCharactersButton, SIGNAL(clicked()), this, SLOT(addCharacters()));
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
