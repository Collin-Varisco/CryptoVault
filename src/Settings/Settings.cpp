#include "Settings.h"
#include "../CredentialMenu/CredentialMenu.h"
#include <nlohmann/json.hpp>
#include "../JSON/SaveJson.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include "../ExportCredentialsLoginChange/ExportLoginChange.h"
#include "../Global/Global.h"
#include "../Global/ChangeGlobals.h"
#include <QTimer>
#include <vector>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QDebug>
#include <iostream>
#include "../PassGenerator/PasswordGenerator.h"
#include <string>
#include <fstream>
#include <QClipboard>
#include <QGuiApplication>
#include <QScreen>
Settings::Settings(QFrame *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.ImportExportOptionsButton->installEventFilter(this);
    ui.ImportExportFrame->installEventFilter(this);
    ui.ImportExportFrame->setVisible(false);
	ui.lineEdit->setPlaceholderText("5");
	
	settingsMenuActive = true;
	
    // Format Table
    formatFrame(ui.frame_2);
    formatFrame(ui.frame);
    formatFrame(ui.ImportExportFrame);

    // Left Side Menu Bar Buttons
    formatButtonWithinFrame(ui.VaultButton, 70, 780, ui.frame);
    formatButtonWithinFrame(ui.ImportExportOptionsButton, 70, 780, ui.frame);
    formatButtonWithinFrame(ui.SettingsButton, 70, 780, ui.frame);

    // Import Export Menu Buttons
    formatButtonWithinFrame(ui.ExportAllButton, 161, 142, ui.ImportExportFrame);


    // Add/Edit Credential Buttons
    int frameX = this->width() * 0.36815;
    int frameY = this->height() * 0.2295;
    int frameWidth = this->width() * 0.2597;
    int frameHeight = this->height() * 0.6081;

    // Vault Label
    ui.label_8->setGeometry(0, 0, this->width(), this->height()*0.11639);

    SaveJson sj;
    inactivityTimerSet = sj.timerOn();
    if(inactivityTimerSet){
		ui.radioButton->setChecked(true);
		ChangeGlobals cg;
		cg.setTimer(sj.timerLimit());
	}

    // </formatting>
    connect(ui.VaultButton, SIGNAL(clicked()), this, SLOT(vault()));
    connect(ui.GeneratorButton, SIGNAL(clicked()), this, SLOT(openGenerator()));
    // Activity Timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkActivity()));
    timer->start(1000);
    // Update Cursor Position Timer
    QTimer *updateCursorTimer = new QTimer(this);
    connect(updateCursorTimer, SIGNAL(timeout()), this, SLOT(updateCursor()));
    updateCursorTimer->start(500);
    connect(ui.radioButton, SIGNAL(clicked()), this, SLOT(updateTimer()));
    connect(ui.GeneratorButton_2, SIGNAL(clicked()), this, SLOT(resetPassword()));

}

void Settings::resetPassword(){

  #ifdef TARGET_OS_MAC
  system("rm ./credentials.json");
  #elif defined __linux__
  system("rm ./credentials.json");
  #elif defined _WIN32 || defined _WIN64
  system("del /f credentials.json");
  #else
  #error "unknown platform"
  #endif
  QWidget *changePassword = new ExportLoginChange();
  QObject::connect(changePassword, SIGNAL(sendFinishedSignal(QString)), this, SLOT(loginChangeData(QString)));
  changePassword->show();
}

void Settings::loginChangeData(QString hashedPass){
    using namespace nlohmann;
    json j;
    j["Credentials"] = {};
    CrossPlatform x;
    std::ofstream o(x.xString(".") + "/credentials.json");
    o << std::setw(4) << j << std::endl;

    std::ifstream jFile(x.xString(".") + "/credentials.json");
    json jPass = json::parse(jFile);

    json masterPass;
    masterPass["MasterPassword"] = {x.xString(hashedPass)};
    jPass["Credentials"].push_back(masterPass);
    std::ofstream oPass(x.xString(".") + "/credentials.json");
    oPass << std::setw(4) << jPass << std::endl;
    SaveJson sj;
    sj.addExportedCredentials(global.global_services, global.global_usernames, global.global_passwords, x.xString("."));

}

void Settings::updateTimer(){
	QString selectedUnit = ui.comboBox->currentText();
	CrossPlatform x;
	SaveJson sj;
	int num = 300; 
	bool filledNum = false;
	if(ui.lineEdit->text() == ""){
		filledNum = false;
	} else {
		filledNum = true;
	}
	// Switching Inactivity Timer Off
	if(!ui.radioButton->isChecked()){
		sj.setTimer(false, num);
	} 
	else {
		qDebug() << selectedUnit;
		// For Minutes Dropdown Tab
		if(selectedUnit == "Minutes"){
			if(filledNum){
				num = ui.lineEdit->text().toInt() * 60;
			}
		} 
		// For Hours dropdown tab
		else {
			if(filledNum){
				num = ui.lineEdit->text().toInt() * 3600;
			}
		}
		sj.setTimer(true, num);
		ChangeGlobals cg;
		cg.setTimer(num);
	}
}

void Settings::openGenerator(){
	settingsMenuActive = false;
	QWidget *set = new PasswordGenerator();
	this->close();
	set->show();
}

void Settings::updateCursor(){
	cursorPosition = QCursor::pos();
}

void Settings::checkActivity(){
	qDebug() << global.inactiveTime;
	if(inactivityTimerSet){
		ChangeGlobals cg;
		// Checks if mouse is on the window
		if(rect().contains(mapFromGlobal(QCursor::pos()))){
			// Checks if the mouse is idle in place
			if(QCursor::pos().x() == cursorPosition.x() && QCursor::pos().y() == cursorPosition.y() && settingsMenuActive){
				cg.incrementTimer();
			} else {
				cg.resetTimer();
			}
		} else {
			if(settingsMenuActive){
				cg.incrementTimer();
			}
		}

		// Quit the application once the amount of inactive time from the global header is equal to the timer limit in the global header
		if( global.inactiveTime >= global.timerLimit ){
			QCoreApplication::quit();
		}
	}
}


void Settings::formatButtonWithinFrame(QPushButton *button, int originalWidth, int originalLength, QFrame *frame){
	int buttonWidth = button->width();
	int buttonHeight = button->height();
	int buttonX = button->x();
	int buttonY = button->y();
	int frameWidth = originalWidth;
	int frameHeight = originalLength;

	double xRatio = (double)buttonX / (double)frameWidth;
	int finalX = frame->width() * xRatio;

	double yRatio = (double)buttonY / (double)frameHeight;
	int finalY = frame->height() * yRatio;

	double widthRatio = (double)buttonWidth / (double)frameWidth;
	int finalWidth = frame->width() * widthRatio;

	double heightRatio = (double)buttonHeight / (double)frameHeight;
	int finalHeight = frame->height() * heightRatio;

	button->setGeometry(finalX, finalY, finalWidth, finalHeight);
}


void Settings::formatLineEditWithinFrame(QLineEdit *button, int originalWidth, int originalLength, QFrame *frame){
	int buttonWidth = button->width();
	int buttonHeight = button->height();
	int buttonX = button->x();
	int buttonY = button->y();
	int frameWidth = originalWidth;
	int frameHeight = originalLength;

	double xRatio = (double)buttonX / (double)frameWidth;
	int finalX = frame->width() * xRatio;

	double yRatio = (double)buttonY / (double)frameHeight;
	int finalY = frame->height() * yRatio;

	double widthRatio = (double)buttonWidth / (double)frameWidth;
	int finalWidth = frame->width() * widthRatio;

	double heightRatio = (double)buttonHeight / (double)frameHeight;
	int finalHeight = frame->height() * heightRatio;

	button->setGeometry(finalX, finalY, finalWidth, finalHeight);
}

void Settings::formatFrame(QFrame *obj){
	int objWidth = obj->width();
	int objHeight = obj->height();
	int objX = obj->x();
	int objY = obj->y();
	int originalWidth = 1005;
	int originalHeight = 610;
	int window_Height = this->height();
	int window_Width = this->width();
	double xRatio = (double)objX / (double)originalWidth;
	int finalX = window_Width * xRatio;

	double yRatio = (double)objY / (double)originalHeight;
	int finalY  = window_Height * yRatio;

	double widthRatio = (double)objWidth / (double)originalWidth;
	int finalWidth = window_Width * widthRatio;

	double heightRatio = (double)objHeight / (double)originalHeight;
	int finalHeight = window_Height * heightRatio;

	obj->setGeometry(finalX, finalY, finalWidth, finalHeight);
}

void Settings::vault(){
	settingsMenuActive = false;
	QWidget *vault;
	vault = new CredentialMenu();
	this->close();
	vault->show();
}



bool Settings::eventFilter(QObject *obj, QEvent *event)
{
	if(obj == (QObject*)ui.ImportExportOptionsButton) {
		if(event->type() == QEvent::HoverEnter)
		{
		    ui.ImportExportFrame->setVisible(true);
		}
		if(event->type() == QEvent::HoverLeave && !inImportExportFrame)
		{
		    ui.ImportExportFrame->setVisible(false);
		}
		else {
			return QWidget::eventFilter(obj, event);
		}
	}
	if(obj == (QObject*)ui.ImportExportFrame) {
		if(event->type() == QEvent::Enter)
		{
		    inImportExportFrame = true;
		    ui.ImportExportFrame->setVisible(true);
		}
		if(event->type() == QEvent::Leave)
		{
		    inImportExportFrame = false;
		    ui.ImportExportFrame->setVisible(false);
		}
		else {
	        	return QWidget::eventFilter(obj, event);
		}
	}
}
