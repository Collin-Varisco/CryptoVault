/********************************************************************************
** Form generated from reading UI file 'SettingsJXcHiV.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETTINGSJXCHIV_H
#define SETTINGSJXCHIV_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QFrame *frame;
    QPushButton *VaultButton;
    QPushButton *SettingsButton;
    QPushButton *ImportExportOptionsButton;
    QLabel *label_8;
    QFrame *ImportExportFrame;
    QPushButton *ExportAllButton;
    QFrame *SettingsFrame;
    QPushButton *GeneratorButton;
    QPushButton *GeneratorButton_2;
    QFrame *frame_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QRadioButton *radioButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1000, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"\n"
""));
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, -20, 70, 780));
        frame->setStyleSheet(QString::fromUtf8("background: #1F2933;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        VaultButton = new QPushButton(frame);
        VaultButton->setObjectName(QString::fromUtf8("VaultButton"));
        VaultButton->setGeometry(QRect(-10, 210, 91, 70));
        VaultButton->setStyleSheet(QString::fromUtf8("QPushButton#VaultButton {\n"
"	background: #1F2933;\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton#VaultButton:hover {\n"
"	background:  #152028;;\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton#VaultButton:pressed {\n"
"	border: none;\n"
"	background: white;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/SideBar/vault.png"), QSize(), QIcon::Normal, QIcon::Off);
        VaultButton->setIcon(icon);
        VaultButton->setIconSize(QSize(50, 50));
        SettingsButton = new QPushButton(frame);
        SettingsButton->setObjectName(QString::fromUtf8("SettingsButton"));
        SettingsButton->setGeometry(QRect(0, 360, 71, 70));
        SettingsButton->setStyleSheet(QString::fromUtf8("background: #EFEFEF;\n"
"QPushButton#SettingsButton {\n"
"	background: #1F2933;\n"
"	border: none;\n"
"}\n"
"QPushButton#SettingsButton:hover {\n"
"	background:  #152028;;\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton#SettingsButton:pressed {\n"
"	border: none;\n"
"	background: white;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/SideBar/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsButton->setIcon(icon1);
        SettingsButton->setIconSize(QSize(58, 58));
        ImportExportOptionsButton = new QPushButton(frame);
        ImportExportOptionsButton->setObjectName(QString::fromUtf8("ImportExportOptionsButton"));
        ImportExportOptionsButton->setGeometry(QRect(0, 290, 81, 70));
        ImportExportOptionsButton->setStyleSheet(QString::fromUtf8("QPushButton#ImportExportOptionsButton {\n"
"	background: #1F2933;\n"
"	border: none;\n"
"}\n"
"QPushButton#ImportExportOptionsButton:hover {\n"
"	background:  #152028;;\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton#ImportExportOptionsButton:pressed {\n"
"	border: none;\n"
"	background: white;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/SideBar/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImportExportOptionsButton->setIcon(icon2);
        ImportExportOptionsButton->setIconSize(QSize(40, 40));
        label_8 = new QLabel(Form);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(3, 0, 991, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: white;"));
        ImportExportFrame = new QFrame(Form);
        ImportExportFrame->setObjectName(QString::fromUtf8("ImportExportFrame"));
        ImportExportFrame->setGeometry(QRect(70, 270, 161, 68));
        ImportExportFrame->setStyleSheet(QString::fromUtf8("border: 1px solid Black;\n"
"background: #152028;"));
        ImportExportFrame->setFrameShape(QFrame::StyledPanel);
        ImportExportFrame->setFrameShadow(QFrame::Raised);
        ExportAllButton = new QPushButton(ImportExportFrame);
        ExportAllButton->setObjectName(QString::fromUtf8("ExportAllButton"));
        ExportAllButton->setGeometry(QRect(10, 18, 141, 34));
        ExportAllButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        SettingsFrame = new QFrame(Form);
        SettingsFrame->setObjectName(QString::fromUtf8("SettingsFrame"));
        SettingsFrame->setGeometry(QRect(160, 70, 711, 511));
        SettingsFrame->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid white;\n"
""));
        SettingsFrame->setFrameShape(QFrame::StyledPanel);
        SettingsFrame->setFrameShadow(QFrame::Raised);
        GeneratorButton = new QPushButton(SettingsFrame);
        GeneratorButton->setObjectName(QString::fromUtf8("GeneratorButton"));
        GeneratorButton->setGeometry(QRect(240, 210, 191, 61));
        GeneratorButton->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        GeneratorButton_2 = new QPushButton(SettingsFrame);
        GeneratorButton_2->setObjectName(QString::fromUtf8("GeneratorButton_2"));
        GeneratorButton_2->setGeometry(QRect(240, 120, 191, 61));
        GeneratorButton_2->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        frame_2 = new QFrame(SettingsFrame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(190, 300, 311, 80));
        frame_2->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #1F2933;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(190, 31, 91, 22));
        comboBox->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: white;"));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 33, 51, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: white;"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 111, 51));
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        radioButton = new QRadioButton(frame_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(5, 38, 62, 16));
        radioButton->raise();
        comboBox->raise();
        label->raise();
        lineEdit->raise();
        frame_2->raise();
        GeneratorButton->raise();
        GeneratorButton_2->raise();
        SettingsFrame->raise();
        label_8->raise();
        frame->raise();
        ImportExportFrame->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        VaultButton->setText(QString());
        SettingsButton->setText(QString());
        ImportExportOptionsButton->setText(QString());
        label_8->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">Settings</span></p></body></html>", nullptr));
        ExportAllButton->setText(QApplication::translate("Form", "Export All", nullptr));
        GeneratorButton->setText(QApplication::translate("Form", "Password Generator", nullptr));
        GeneratorButton_2->setText(QApplication::translate("Form", "Reset Password", nullptr));
        comboBox->setItemText(0, QApplication::translate("Form", "Minutes", nullptr));
        comboBox->setItemText(1, QApplication::translate("Form", "Hours", nullptr));

        label->setText(QApplication::translate("Form", "Automatically Log Out After", nullptr));
        radioButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETTINGSJXCHIV_H
