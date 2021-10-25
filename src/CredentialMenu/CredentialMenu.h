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
		bool eventFilter(QObject *obj, QEvent *event);
		bool inImportExportFrame = false;
		void formatFrame(QFrame *obj);
		void formatTable(QTableWidget *table);
		void formatButtonWithinFrame(QPushButton *button, int originalFrameWidth, int originalFrameLength, QFrame *frame);
		void formatLineEditWithinFrame(QLineEdit *line, int originalFrameWidth, int originalFrameLength, QFrame *frame);
		void search(std::string searchTerm);
		std::string toLowerCase(std::string words);
		void continueExport();
	private:
		Ui::Form ui;
		std::vector<std::string> services;
		std::vector<std::string> passwords;
		std::vector<std::string> usernames;
		QStringList exportServices;
		QStringList exportUsernames;
		QStringList exportPasswords;
		bool editing = false;
		void loadCredentials();
	public slots:
		void openAddCredentialPrompt();
		void closeAddCredentialPrompt();
		void addCredential();
		void openSettings();
		void copySelectedCell();
		void removeSelectedCredential();
		void exportSelectedCredentials();
		void loginChangeData(bool finished);


};
