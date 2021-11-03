#include <string>
#include <iostream>
#include "ui_Settings.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
#include <vector>
QT_BEGIN_NAMESPACE
class Settings : public QMainWindow
{
	Q_OBJECT
	public:
		Settings(QFrame *parent = 0);
		bool eventFilter(QObject *obj, QEvent *event);
		bool settingsMenuActive = false;
		bool inImportExportFrame = false;
		void formatFrame(QFrame *obj);
		void formatButtonWithinFrame(QPushButton *button, int originalFrameWidth, int originalFrameLength, QFrame *frame);
		void formatLineEditWithinFrame(QLineEdit *line, int originalFrameWidth, int originalFrameLength, QFrame *frame);
		bool inactivityTimerSet;
		QPoint cursorPosition;
	private:
		Ui::FormSettings ui;
		std::vector<std::string> services;
		std::vector<std::string> passwords;
		std::vector<std::string> usernames;
		bool editing = false;
	public slots:
		void vault();
		void openGenerator();
		void checkActivity();
		void updateCursor();
		void updateTimer();


};
