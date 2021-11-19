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
		bool credentialMenuActive = false;
		bool inImportExportFrame = false;
		void formatFrame(QFrame *obj);
		void formatTable(QTableWidget *table);
		void formatButtonWithinFrame(QPushButton *button, int originalFrameWidth, int originalFrameLength, QFrame *frame);
		void formatLineEditWithinFrame(QLineEdit *line, int originalFrameWidth, int originalFrameLength, QFrame *frame);
		void search(std::string searchTerm);
		std::string toLowerCase(std::string words);
		void continueExport();
		QString export_selected_dir;
		QList<QString> exportServices;
		QList<QString> exportUsernames;
		QList<QString> exportPasswords;
		QPoint cursorPosition;
	        bool inactivityTimerSet;

                // Unit test vars
                int exportTestNum = 0; 
                void checkCredential(QString serv, QString user, QString pass, int index);
                  
                void editCredential();
                void editCredentialTest(std::string service, std::string username, std::string password);
                void checkLastCredential(QString serv, QString user, QString pass);

	private:
		Ui::Form ui;
		std::vector<std::string> services;
		std::vector<std::string> passwords;
		std::vector<std::string> usernames;
		std::vector<std::string> temp_services;
		std::vector<std::string> temp_passwords;
		std::vector<std::string> temp_usernames;
		bool editing = false;
		void loadCredentials();
	public slots:      
        void openEditCredentialPrompt();
		void openAddCredentialPrompt();
		void closeAddCredentialPrompt();
		void addCredential();
		void openSettings();
		void copySelectedCell();
		void removeSelectedCredential();
		void exportSelectedCredentials();
		void loginChangeData(QString hashedPass);
		void exportAllCredentials();
		void checkActivity();
		void updateCursor();
		void importCredentials();
		void jsonImport(std::string auth);


};
