/********************************************************************************
** Form generated from reading UI file 'CredentialMenulkGcTf.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREDENTIALMENULKGCTF_H
#define CREDENTIALMENULKGCTF_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QFrame *frame;
    QPushButton *VaultButton;
    QPushButton *SettingsButton;
    QPushButton *ImportExportOptionsButton;
    QTableWidget *CredentialTable;
    QLineEdit *SearchBar;
    QFrame *frame_2;
    QPushButton *CopyButton;
    QLabel *label;
    QPushButton *AddButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *RemoveButton;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *EditButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QFrame *AddCredentialFrame;
    QFrame *frame_3;
    QLabel *AddLabel;
    QLineEdit *AddService;
    QLineEdit *AddUsername;
    QLineEdit *AddPassword;
    QPushButton *AddCredentialButton;
    QPushButton *pushButton;
    QFrame *ImportExportFrame;
    QPushButton *ImportButton;
    QPushButton *ExportSelectedButton;
    QPushButton *ExportAllButton;

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
        VaultButton->setStyleSheet(QString::fromUtf8("background: #EFEFEF;\n"
"border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/SideBar/vault.png"), QSize(), QIcon::Normal, QIcon::Off);
        VaultButton->setIcon(icon);
        VaultButton->setIconSize(QSize(50, 50));
        SettingsButton = new QPushButton(frame);
        SettingsButton->setObjectName(QString::fromUtf8("SettingsButton"));
        SettingsButton->setGeometry(QRect(0, 360, 71, 70));
        SettingsButton->setStyleSheet(QString::fromUtf8("\n"
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
        CredentialTable = new QTableWidget(Form);
        CredentialTable->setObjectName(QString::fromUtf8("CredentialTable"));
        CredentialTable->setGeometry(QRect(90, 70, 834, 511));
        CredentialTable->setMaximumSize(QSize(834, 511));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        CredentialTable->setFont(font);
        CredentialTable->setAutoFillBackground(false);
        CredentialTable->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        SearchBar = new QLineEdit(Form);
        SearchBar->setObjectName(QString::fromUtf8("SearchBar"));
        SearchBar->setGeometry(QRect(90, 30, 221, 28));
        SearchBar->setStyleSheet(QString::fromUtf8("border: 2px solid #323F4B;\n"
"background: #1F2933;\n"
"color: white;"));
        frame_2 = new QFrame(Form);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(930, 130, 70, 391));
        frame_2->setStyleSheet(QString::fromUtf8("background: #152028;\n"
"color: white;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        CopyButton = new QPushButton(frame_2);
        CopyButton->setObjectName(QString::fromUtf8("CopyButton"));
        CopyButton->setGeometry(QRect(0, 0, 71, 70));
        CopyButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/CredentialMenu/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/Images/copy.png"), QSize(), QIcon::Normal, QIcon::On);
        CopyButton->setIcon(icon3);
        CopyButton->setIconSize(QSize(50, 50));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(8, 70, 61, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        label->setFont(font1);
        AddButton = new QPushButton(frame_2);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(12, 90, 40, 70));
        AddButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/CredentialMenu/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon4);
        AddButton->setIconSize(QSize(54, 54));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 31, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(3, 170, 71, 20));
        label_3->setFont(font1);
        RemoveButton = new QPushButton(frame_2);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));
        RemoveButton->setGeometry(QRect(8, 190, 51, 70));
        RemoveButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/CredentialMenu/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        RemoveButton->setIcon(icon5);
        RemoveButton->setIconSize(QSize(44, 44));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 250, 51, 17));
        label_4->setFont(font1);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 270, 51, 17));
        label_5->setFont(font1);
        EditButton = new QPushButton(frame_2);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setGeometry(QRect(14, 298, 51, 51));
        EditButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Images/CredentialMenu/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon6);
        EditButton->setIconSize(QSize(44, 44));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(23, 350, 31, 17));
        label_6->setFont(font1);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(3, 366, 71, 20));
        label_7->setFont(font1);
        label_8 = new QLabel(Form);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(93, 0, 821, 71));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        AddCredentialFrame = new QFrame(Form);
        AddCredentialFrame->setObjectName(QString::fromUtf8("AddCredentialFrame"));
        AddCredentialFrame->setEnabled(true);
        AddCredentialFrame->setGeometry(QRect(340, 120, 321, 411));
        AddCredentialFrame->setStyleSheet(QString::fromUtf8("background: #152028;\n"
""));
        AddCredentialFrame->setFrameShape(QFrame::StyledPanel);
        AddCredentialFrame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(AddCredentialFrame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(30, 20, 261, 371));
        frame_3->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        AddLabel = new QLabel(frame_3);
        AddLabel->setObjectName(QString::fromUtf8("AddLabel"));
        AddLabel->setGeometry(QRect(0, 30, 261, 51));
        AddLabel->setFont(font1);
        AddLabel->setStyleSheet(QString::fromUtf8("color: white;"));
        AddService = new QLineEdit(frame_3);
        AddService->setObjectName(QString::fromUtf8("AddService"));
        AddService->setGeometry(QRect(20, 110, 221, 28));
        AddService->setStyleSheet(QString::fromUtf8("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        AddUsername = new QLineEdit(frame_3);
        AddUsername->setObjectName(QString::fromUtf8("AddUsername"));
        AddUsername->setGeometry(QRect(20, 160, 221, 28));
        AddUsername->setStyleSheet(QString::fromUtf8("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        AddPassword = new QLineEdit(frame_3);
        AddPassword->setObjectName(QString::fromUtf8("AddPassword"));
        AddPassword->setGeometry(QRect(20, 210, 221, 28));
        AddPassword->setStyleSheet(QString::fromUtf8("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        AddCredentialButton = new QPushButton(frame_3);
        AddCredentialButton->setObjectName(QString::fromUtf8("AddCredentialButton"));
        AddCredentialButton->setGeometry(QRect(80, 270, 101, 34));
        AddCredentialButton->setStyleSheet(QString::fromUtf8("background: #152028;\n"
""));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 310, 81, 34));
        ImportExportFrame = new QFrame(Form);
        ImportExportFrame->setObjectName(QString::fromUtf8("ImportExportFrame"));
        ImportExportFrame->setGeometry(QRect(70, 270, 161, 142));
        ImportExportFrame->setStyleSheet(QString::fromUtf8("border: 1px solid Black;\n"
"background: #152028;"));
        ImportExportFrame->setFrameShape(QFrame::StyledPanel);
        ImportExportFrame->setFrameShadow(QFrame::Raised);
        ImportButton = new QPushButton(ImportExportFrame);
        ImportButton->setObjectName(QString::fromUtf8("ImportButton"));
        ImportButton->setGeometry(QRect(10, 10, 141, 34));
        ImportButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        ExportSelectedButton = new QPushButton(ImportExportFrame);
        ExportSelectedButton->setObjectName(QString::fromUtf8("ExportSelectedButton"));
        ExportSelectedButton->setGeometry(QRect(10, 54, 141, 34));
        ExportSelectedButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        ExportAllButton = new QPushButton(ImportExportFrame);
        ExportAllButton->setObjectName(QString::fromUtf8("ExportAllButton"));
        ExportAllButton->setGeometry(QRect(10, 98, 141, 34));
        ExportAllButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        label_8->raise();
        frame->raise();
        CredentialTable->raise();
        SearchBar->raise();
        frame_2->raise();
        AddCredentialFrame->raise();
        ImportExportFrame->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        VaultButton->setText(QString());
        SettingsButton->setText(QString());
        ImportExportOptionsButton->setText(QString());
        SearchBar->setText(QString());
        SearchBar->setPlaceholderText(QCoreApplication::translate("Form", "Search...", nullptr));
        CopyButton->setText(QString());
        label->setText(QCoreApplication::translate("Form", "Copy Cell", nullptr));
        AddButton->setText(QString());
        label_2->setText(QCoreApplication::translate("Form", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Credential", nullptr));
        RemoveButton->setText(QString());
        label_4->setText(QCoreApplication::translate("Form", "Remove", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Selected", nullptr));
        EditButton->setText(QString());
        label_6->setText(QCoreApplication::translate("Form", "Edit", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "Credential", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">Vault</span></p></body></html>", nullptr));
        AddLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Add Credential</span></p></body></html>", nullptr));
        AddService->setText(QString());
        AddService->setPlaceholderText(QCoreApplication::translate("Form", "Service Name...", nullptr));
        AddUsername->setText(QString());
        AddUsername->setPlaceholderText(QCoreApplication::translate("Form", "Username or Email...", nullptr));
        AddPassword->setText(QString());
        AddPassword->setPlaceholderText(QCoreApplication::translate("Form", "Password", nullptr));
        AddCredentialButton->setText(QCoreApplication::translate("Form", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
        ImportButton->setText(QCoreApplication::translate("Form", "Import Credentials", nullptr));
        ExportSelectedButton->setText(QCoreApplication::translate("Form", "Export Selected", nullptr));
        ExportAllButton->setText(QCoreApplication::translate("Form", "Export All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREDENTIALMENULKGCTF_H
