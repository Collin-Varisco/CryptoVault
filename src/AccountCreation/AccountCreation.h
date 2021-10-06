#include <string>
#include <iostream>
#include "ui_accountCreation.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
QT_BEGIN_NAMESPACE
class AccountCreation : public QMainWindow
{
	Q_OBJECT
	public:
		AccountCreation(QFrame *parent = 0);

	private:
		Ui::FormCreation ui;
    public slots:
        void verify();
};