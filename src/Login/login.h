#include <string>
#include <iostream>
#include "ui_login.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
QT_BEGIN_NAMESPACE
class login : public QMainWindow
{
	Q_OBJECT
	public:
		login(QFrame *parent = 0);
                void unitTestLogin();
	private:
		Ui::FormLogin ui;
    public slots:
        void attemptLogin();
};
