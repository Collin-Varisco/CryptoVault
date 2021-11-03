#include <string>
#include <iostream>
#include "ui_PassGen.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
QT_BEGIN_NAMESPACE
class PasswordGenerator : public QMainWindow
{
	Q_OBJECT
	public:
		PasswordGenerator(QFrame *parent = 0);
		QStringList includeList;
		QStringList excludeList;
		bool inactivityTimerSet;
		QPoint cursorPosition;
	private:
		Ui::GeneratorForm ui;
	public slots:
		void openIncludePrompt();
		void openExcludePrompt();
		void generatePassword();
		void copyPassword();
		void addCharacters();
		void checkActivity();
		void updateCursor();
};
