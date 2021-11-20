/********************************************************************************
** Form generated from reading UI file 'loginccIRpv.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINCCIRPV_H
#define LOGINCCIRPV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLogin
{
public:
    QFrame *frame_3;
    QLabel *AddLabel;
    QPushButton *pushButton;
    QLineEdit *UsernameInput;
    QLineEdit *EncryptionKeyInput;
    QLabel *LoginLabel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->setWindowModality(Qt::WindowModal);
        Form->resize(470, 640);
        Form->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"QLineEdit {\n"
" border: 2px solid gray;\n"
" border-radius: 10px;\n"
"}"));
        frame_3 = new QFrame(Form);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setEnabled(true);
        frame_3->setGeometry(QRect(70, 125, 331, 391));
        frame_3->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid gray;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Plain);
        AddLabel = new QLabel(frame_3);
        AddLabel->setObjectName(QString::fromUtf8("AddLabel"));
        AddLabel->setGeometry(QRect(0, 0, 331, 51));
        AddLabel->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 245, 91, 31));
        pushButton->setFocusPolicy(Qt::TabFocus);
        pushButton->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: #1F2933;\n"
"border-radius: 15px;"));
        UsernameInput = new QLineEdit(frame_3);
        UsernameInput->setObjectName(QString::fromUtf8("UsernameInput"));
        UsernameInput->setGeometry(QRect(70, 160, 191, 31));
        UsernameInput->setFocusPolicy(Qt::ClickFocus);
        UsernameInput->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        UsernameInput->setEchoMode(QLineEdit::Normal);
        EncryptionKeyInput = new QLineEdit(frame_3);
        EncryptionKeyInput->setObjectName(QString::fromUtf8("EncryptionKeyInput"));
        EncryptionKeyInput->setGeometry(QRect(70, 200, 191, 31));
        EncryptionKeyInput->setFocusPolicy(Qt::TabFocus);
        EncryptionKeyInput->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        EncryptionKeyInput->setEchoMode(QLineEdit::Password);
        LoginLabel = new QLabel(frame_3);
        LoginLabel->setObjectName(QString::fromUtf8("LoginLabel"));
        LoginLabel->setGeometry(QRect(80, 115, 181, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Montserrat"));
        font.setPointSize(6);
        font.setBold(true);
        font.setWeight(75);
        LoginLabel->setFont(font);
        LoginLabel->setStyleSheet(QString::fromUtf8("font-family: 'Montserrat', sans-serif;\n"
"	height: 1000vh;\n"
"	margin: -20px 0 50px;\n"
"font-weight: bold;\n"
"margin: 0;\n"
"border: none;"));
        AddLabel->raise();
        pushButton->raise();
        EncryptionKeyInput->raise();
        LoginLabel->raise();
        UsernameInput->raise();
        QWidget::setTabOrder(UsernameInput, EncryptionKeyInput);
        QWidget::setTabOrder(EncryptionKeyInput, pushButton);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        AddLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic;\">CryptoVault</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Login", nullptr));
        UsernameInput->setPlaceholderText(QCoreApplication::translate("Form", "   Username", nullptr));
        EncryptionKeyInput->setPlaceholderText(QCoreApplication::translate("Form", "   Password", nullptr));
        LoginLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; color:#efefef;\">Login</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormLogin: public Ui_FormLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINCCIRPV_H
