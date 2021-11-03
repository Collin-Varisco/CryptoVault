#include "Settings.h"
#include "../CredentialMenu/CredentialMenu.h"
#include <nlohmann/json.hpp>
#include "../JSON/SaveJson.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
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

    // [TODO]
    // inactivityTimerSet = json.isTimerSet();
    inactivityTimerSet = false;

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

	cursorPosition = QCursor::pos();

}

void Settings::openGenerator(){
	QWidget *set = new PasswordGenerator();
	this->close();
	set->show();
}

void Settings::updateCursor(){
	cursorPosition = QCursor::pos();
}

void Settings::checkActivity(){
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
