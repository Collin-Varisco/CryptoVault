/********************************************************************************
** Form generated from reading UI file 'authorizationSHOwuS.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef AUTHORIZATIONSHOWUS_H
#define AUTHORIZATIONSHOWUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthForm
{
public:
    QFrame *frame_3;
    QLabel *AddLabel;
    QPushButton *pushButton;
    QLineEdit *UsernameInput;
    QLineEdit *EncryptionKeyInput;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(470, 245);
        Form->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"QLineEdit {\n"
" border: 2px solid gray;\n"
" border-radius: 10px;\n"
"}"));
        frame_3 = new QFrame(Form);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(70, 30, 331, 191));
        frame_3->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid gray;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        AddLabel = new QLabel(frame_3);
        AddLabel->setObjectName(QString::fromUtf8("AddLabel"));
        AddLabel->setGeometry(QRect(0, 0, 331, 51));
        AddLabel->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 140, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: #1F2933;\n"
"border-radius: 15px;"));
        UsernameInput = new QLineEdit(frame_3);
        UsernameInput->setObjectName(QString::fromUtf8("UsernameInput"));
        UsernameInput->setGeometry(QRect(70, 60, 191, 31));
        UsernameInput->setFocusPolicy(Qt::ClickFocus);
        UsernameInput->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        UsernameInput->setEchoMode(QLineEdit::Normal);
        EncryptionKeyInput = new QLineEdit(frame_3);
        EncryptionKeyInput->setObjectName(QString::fromUtf8("EncryptionKeyInput"));
        EncryptionKeyInput->setGeometry(QRect(70, 100, 191, 31));
        EncryptionKeyInput->setFocusPolicy(Qt::ClickFocus);
        EncryptionKeyInput->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: #efefef;\n"
"border: 2px solid #1F2933;\n"
"border-radius: 15px;\n"
""));
        EncryptionKeyInput->setEchoMode(QLineEdit::Password);

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
    } // retranslateUi

};

namespace Ui {
    class AuthForm: public Ui_AuthForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // AUTHORIZATIONSHOWUS_H
