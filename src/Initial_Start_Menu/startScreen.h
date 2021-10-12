#include <string>
#include <iostream>
#include "ui_startScreen.h"
#include <QWidget>
#include <QMainWindow>
#include <QFrame>
#include <QString>

QT_BEGIN_NAMESPACE
class startScreen : public QMainWindow
{
	Q_OBJECT
	public:
		startScreen(QFrame *parent = 0);
	private:
		Ui::StartForm ui;
	public slots:
		void createAccount();
		void recoverAccount();
};
