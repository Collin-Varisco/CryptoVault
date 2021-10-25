#include <string>
#include <iostream>
#include "ui_ExportCredentialsLoginChange.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
QT_BEGIN_NAMESPACE
class ExportLoginChange : public QMainWindow
{
	Q_OBJECT
	public:
		ExportLoginChange(QFrame *parent = 0);
		void sendFinished(QString hashedPass);
	private:
		Ui::LoginChangeForm ui;
    public slots:
        void changeLogin();
	signals:
		void sendFinishedSignal(QString hashedPass);
};
