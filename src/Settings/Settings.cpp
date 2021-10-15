#include "Settings.h"
#include <nlohmann/json.hpp>
#include "../JSON/SaveJson.h"
#include "../Crypto/Crypto.h"
#include "../CrossPlatform/CrossPlatform.h"
#include <vector>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QDebug>
#include <iostream>

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
	


    // </endFormatting>



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
