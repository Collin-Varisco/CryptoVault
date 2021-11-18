#include <string>
#include <iostream>
#include "ui_authorization.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>
QT_BEGIN_NAMESPACE
class authorization : public QMainWindow
{
	Q_OBJECT
	public:
		authorization(QFrame *parent = 0);
		void sendFinished(std::string auth);
	private:
		Ui::AuthForm ui;
    public slots:
        void attemptLogin();
	signals:
		void sendFinishedSignal(std::string authorized);
};
