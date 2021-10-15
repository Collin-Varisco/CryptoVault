/********************************************************************************
** Form generated from reading UI file 'startScreenbyXibZ.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STARTSCREENBYXIBZ_H
#define STARTSCREENBYXIBZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartForm
{
public:
    QFrame *frame;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *LoginLabel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(514, 640);
        Form->setStyleSheet(QString::fromUtf8("background: #152028;"));
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 60, 431, 541));
        frame->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid gray;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 430, 140, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: #1F2933;\n"
"border-radius: 15px;"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 430, 140, 50));
        pushButton->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: #1F2933;\n"
"border-radius: 15px;"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 120, 281, 281));
        label->setStyleSheet(QString::fromUtf8("border: none;"));
        LoginLabel = new QLabel(Form);
        LoginLabel->setObjectName(QString::fromUtf8("LoginLabel"));
        LoginLabel->setGeometry(QRect(50, 90, 411, 71));
        LoginLabel->setStyleSheet(QString::fromUtf8("font-family: 'Montserrat', sans-serif;\n"
"height: 1000vh;\n"
"margin: -20px 0 50px;\n"
"font-weight: bold;\n"
"color: #efefef;\n"
"margin: 0;\n"
"background: #1F2933;"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "Import Credentials File", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Create New Account", nullptr));
        label->setText(QCoreApplication::translate("Form", "<html><head/><body><p><img src=\":/Images/shield.png\"/></p></body></html>", nullptr));
        LoginLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-style:italic; color:#efefef;\">CryptoVault</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartForm: public Ui_StartForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STARTSCREENBYXIBZ_H
