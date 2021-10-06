#include <string>
#include <iostream>
#include "ui_CredentialMenu.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
#include <vector>
QT_BEGIN_NAMESPACE
class CredentialMenu : public QMainWindow
{
	Q_OBJECT
	public:
		CredentialMenu(QFrame *parent = 0);
	private:
		Ui::Form ui;
		std::vector<std::string> services;
		std::vector<std::string> passwords;
		std::vector<std::string> usernames;
	public slots:
		void openAddCredentialPrompt();
		void closeAddCredentialPrompt();
};
