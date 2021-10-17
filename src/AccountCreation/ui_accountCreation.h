/********************************************************************************
** Form generated from reading UI file 'accountCreationBxsPSO.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ACCOUNTCREATIONBXSPSO_H
#define ACCOUNTCREATIONBXSPSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCreation
{
public:
    QLabel *label;
    QLabel *usernameError;
    QLabel *passwordError;
    QFrame *frame_4;
    QLabel *AddLabel_2;
    QPushButton *createButton;
    QLineEdit *UsernameInput;
    QLineEdit *EncryptionKeyInput;
    QLabel *LoginLabel_2;
    QLineEdit *EncryptionKeyInput_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(491, 636);
        Form->setStyleSheet(QString::fromUtf8("background: #152028;"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 550, 471, 81));
        usernameError = new QLabel(Form);
        usernameError->setObjectName(QString::fromUtf8("usernameError"));
        usernameError->setGeometry(QRect(0, 490, 491, 20));
        usernameError->setStyleSheet(QString::fromUtf8("color: red;"));
        passwordError = new QLabel(Form);
        passwordError->setObjectName(QString::fromUtf8("passwordError"));
        passwordError->setGeometry(QRect(0, 510, 491, 20));
        passwordError->setStyleSheet(QString::fromUtf8("color: red;"));
        frame_4 = new QFrame(Form);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(80, 70, 331, 391));
        frame_4->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid gray;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        AddLabel_2 = new QLabel(frame_4);
        AddLabel_2->setObjectName(QString::fromUtf8("AddLabel_2"));
        AddLabel_2->setGeometry(QRect(10, 10, 311, 101));
        AddLabel_2->setStyleSheet(QString::fromUtf8("border: none;"));
        createButton = new QPushButton(frame_4);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(120, 290, 91, 31));
        createButton->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: #1F2933;\n"
"border-radius: 15px;"));
        UsernameInput = new QLineEdit(frame_4);
        UsernameInput->setObjectName(QString::fromUtf8("UsernameInput"));
        UsernameInput->setGeometry(QRect(70, 160, 191, 31));
        UsernameInput->setFocusPolicy(Qt::ClickFocus);
        UsernameInput->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        UsernameInput->setEchoMode(QLineEdit::Normal);
        EncryptionKeyInput = new QLineEdit(frame_4);
        EncryptionKeyInput->setObjectName(QString::fromUtf8("EncryptionKeyInput"));
        EncryptionKeyInput->setGeometry(QRect(70, 200, 191, 31));
        EncryptionKeyInput->setFocusPolicy(Qt::ClickFocus);
        EncryptionKeyInput->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        EncryptionKeyInput->setEchoMode(QLineEdit::Password);
        LoginLabel_2 = new QLabel(frame_4);
        LoginLabel_2->setObjectName(QString::fromUtf8("LoginLabel_2"));
        LoginLabel_2->setGeometry(QRect(80, 115, 181, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat,sans-serif"));
        font.setBold(true);
        font.setWeight(75);
        LoginLabel_2->setFont(font);
        LoginLabel_2->setStyleSheet(QString::fromUtf8("font-family: 'Montserrat', sans-serif;\n"
"	height: 1000vh;\n"
"	margin: -20px 0 50px;\n"
"font-weight: bold;\n"
"margin: 0;\n"
"border: none;"));
        EncryptionKeyInput_2 = new QLineEdit(frame_4);
        EncryptionKeyInput_2->setObjectName(QString::fromUtf8("EncryptionKeyInput_2"));
        EncryptionKeyInput_2->setGeometry(QRect(70, 240, 191, 31));
        EncryptionKeyInput_2->setFocusPolicy(Qt::ClickFocus);
        EncryptionKeyInput_2->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        EncryptionKeyInput_2->setEchoMode(QLineEdit::Password);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        label->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:6pt; color:#efefef;\">Password will be encrypted and can not be recovered if you forget it.</span></p><p align=\"center\"><span style=\" font-size:6pt; color:#efefef;\">Write your password down and store it in a secure place if necessary.</span></p></body></html>", nullptr));
        usernameError->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\">Invalid Username</p></body></html>", nullptr));
        passwordError->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\">Passwords Must Match</p></body></html>", nullptr));
        AddLabel_2->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-style:italic; color:#efefef;\">CryptoVault</span></p></body></html>", nullptr));
        createButton->setText(QApplication::translate("Form", "Create", nullptr));
        UsernameInput->setPlaceholderText(QApplication::translate("Form", "Username", nullptr));
        EncryptionKeyInput->setPlaceholderText(QApplication::translate("Form", "Password", nullptr));
        LoginLabel_2->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:6pt; color:#efefef;\">Create Account</span></p></body></html>", nullptr));
        EncryptionKeyInput_2->setText(QString());
        EncryptionKeyInput_2->setPlaceholderText(QApplication::translate("Form", "Confirm password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCreation: public Ui_FormCreation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ACCOUNTCREATIONBXSPSO_H
