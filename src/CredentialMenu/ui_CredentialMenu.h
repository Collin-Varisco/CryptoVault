/********************************************************************************
** Form generated from reading UI file 'CredentialMenuVDNIno.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREDENTIALMENUVDNINO_H
#define CREDENTIALMENUVDNINO_H

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
            Form->setObjectName(QStringLiteral("Form"));
        //Form->resize(1000, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setStyleSheet(QLatin1String("background: #152028;\n"
"\n"
""));
        frame = new QFrame(Form);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, -20, 70, 780));
        frame->setStyleSheet(QStringLiteral("background: #1F2933;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        VaultButton = new QPushButton(frame);
        VaultButton->setObjectName(QStringLiteral("VaultButton"));
        VaultButton->setGeometry(QRect(-10, 210, 91, 70));
        VaultButton->setStyleSheet(QLatin1String("background: #EFEFEF;\n"
"border: none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/SideBar/vault.png"), QSize(), QIcon::Normal, QIcon::Off);
        VaultButton->setIcon(icon);
        VaultButton->setIconSize(QSize(50, 50));
        SettingsButton = new QPushButton(frame);
        SettingsButton->setObjectName(QStringLiteral("SettingsButton"));
        SettingsButton->setGeometry(QRect(0, 360, 71, 70));
        SettingsButton->setStyleSheet(QLatin1String("\n"
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
        icon1.addFile(QStringLiteral(":/Images/SideBar/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsButton->setIcon(icon1);
        SettingsButton->setIconSize(QSize(58, 58));
        ImportExportOptionsButton = new QPushButton(frame);
        ImportExportOptionsButton->setObjectName(QStringLiteral("ImportExportOptionsButton"));
        ImportExportOptionsButton->setGeometry(QRect(0, 290, 81, 70));
        ImportExportOptionsButton->setStyleSheet(QLatin1String("QPushButton#ImportExportOptionsButton {\n"
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
        icon2.addFile(QStringLiteral(":/Images/SideBar/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImportExportOptionsButton->setIcon(icon2);
        ImportExportOptionsButton->setIconSize(QSize(40, 40));
        CredentialTable = new QTableWidget(Form);
        CredentialTable->setObjectName(QStringLiteral("CredentialTable"));
        CredentialTable->setGeometry(QRect(90, 70, 834, 511));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        CredentialTable->setFont(font);
        CredentialTable->setAutoFillBackground(true);
        CredentialTable->setStyleSheet(QLatin1String("\n"
"\n"
"QTableWidget {\n"
"	background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;\n"
"}\n"
"\n"
"horizontalHeader {\n"
"	background: #1F2933;\n"
"	border: 2px solid #323F4B;\n"
"	color: white;\n"
"}"));
        CredentialTable->horizontalHeader()->setDefaultSectionSize(77);
        CredentialTable->verticalHeader()->setVisible(true);
        SearchBar = new QLineEdit(Form);
        SearchBar->setObjectName(QStringLiteral("SearchBar"));
        SearchBar->setGeometry(QRect(90, 30, 221, 28));
        SearchBar->setStyleSheet(QLatin1String("border: 2px solid #323F4B;\n"
"background: #1F2933;\n"
"color: white;"));
        frame_2 = new QFrame(Form);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(930, 130, 70, 391));
        frame_2->setStyleSheet(QLatin1String("background: #152028;\n"
"color: white;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        CopyButton = new QPushButton(frame_2);
        CopyButton->setObjectName(QStringLiteral("CopyButton"));
        CopyButton->setGeometry(QRect(0, 0, 71, 70));
        CopyButton->setStyleSheet(QLatin1String("\n"
"border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/CredentialMenu/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/Images/copy.png"), QSize(), QIcon::Normal, QIcon::On);
        CopyButton->setIcon(icon3);
        CopyButton->setIconSize(QSize(50, 50));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(8, 70, 61, 17));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        label->setFont(font1);
        AddButton = new QPushButton(frame_2);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(12, 90, 40, 70));
        AddButton->setStyleSheet(QLatin1String("\n"
"border: none;\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/CredentialMenu/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon4);
        AddButton->setIconSize(QSize(54, 54));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 31, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(3, 170, 71, 20));
        label_3->setFont(font1);
        RemoveButton = new QPushButton(frame_2);
        RemoveButton->setObjectName(QStringLiteral("RemoveButton"));
        RemoveButton->setGeometry(QRect(8, 190, 51, 70));
        RemoveButton->setStyleSheet(QLatin1String("\n"
"border: none;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/CredentialMenu/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        RemoveButton->setIcon(icon5);
        RemoveButton->setIconSize(QSize(44, 44));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 250, 51, 17));
        label_4->setFont(font1);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 270, 51, 17));
        label_5->setFont(font1);
        EditButton = new QPushButton(frame_2);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        EditButton->setGeometry(QRect(14, 298, 51, 51));
        EditButton->setStyleSheet(QLatin1String("\n"
"border: none;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/CredentialMenu/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon6);
        EditButton->setIconSize(QSize(44, 44));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(23, 350, 31, 17));
        label_6->setFont(font1);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(3, 366, 71, 20));
        label_7->setFont(font1);
        label_8 = new QLabel(Form);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(93, 0, 821, 71));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        AddCredentialFrame = new QFrame(Form);
        AddCredentialFrame->setObjectName(QStringLiteral("AddCredentialFrame"));
        AddCredentialFrame->setEnabled(true);
        AddCredentialFrame->setGeometry(QRect(340, 120, 321, 411));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        AddCredentialFrame->setFont(font2);
        AddCredentialFrame->setAutoFillBackground(true);
        AddCredentialFrame->setStyleSheet(QLatin1String("background: #152028;\n"
""));
        AddCredentialFrame->setFrameShape(QFrame::StyledPanel);
        AddCredentialFrame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(AddCredentialFrame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(30, 20, 261, 371));
        frame_3->setStyleSheet(QLatin1String("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        AddLabel = new QLabel(frame_3);
        AddLabel->setObjectName(QStringLiteral("AddLabel"));
        AddLabel->setGeometry(QRect(0, 30, 261, 51));
        AddLabel->setFont(font1);
        AddLabel->setStyleSheet(QStringLiteral("color: white;"));
        AddService = new QLineEdit(frame_3);
        AddService->setObjectName(QStringLiteral("AddService"));
        AddService->setGeometry(QRect(20, 110, 221, 28));
        AddService->setStyleSheet(QLatin1String("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        AddUsername = new QLineEdit(frame_3);
        AddUsername->setObjectName(QStringLiteral("AddUsername"));
        AddUsername->setGeometry(QRect(20, 160, 221, 28));
        AddUsername->setStyleSheet(QLatin1String("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        AddPassword = new QLineEdit(frame_3);
        AddPassword->setObjectName(QStringLiteral("AddPassword"));
        AddPassword->setGeometry(QRect(20, 210, 221, 28));
        AddPassword->setStyleSheet(QLatin1String("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        AddCredentialButton = new QPushButton(frame_3);
        AddCredentialButton->setObjectName(QStringLiteral("AddCredentialButton"));
        //AddCredentialButton->setGeometry(QRect(80, 270, 101, 34));
        AddCredentialButton->setStyleSheet(QLatin1String("background: #152028;\n"
""));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 310, 81, 34));
        ImportExportFrame = new QFrame(Form);
        ImportExportFrame->setObjectName(QStringLiteral("ImportExportFrame"));
        ImportExportFrame->setGeometry(QRect(70, 270, 161, 142));
        ImportExportFrame->setStyleSheet(QLatin1String("border: 1px solid Black;\n"
"background: #152028;"));
        ImportExportFrame->setFrameShape(QFrame::StyledPanel);
        ImportExportFrame->setFrameShadow(QFrame::Raised);
        ImportButton = new QPushButton(ImportExportFrame);
        ImportButton->setObjectName(QStringLiteral("ImportButton"));
        ImportButton->setGeometry(QRect(10, 10, 141, 34));
        ImportButton->setStyleSheet(QLatin1String("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        ExportSelectedButton = new QPushButton(ImportExportFrame);
        ExportSelectedButton->setObjectName(QStringLiteral("ExportSelectedButton"));
        ExportSelectedButton->setGeometry(QRect(10, 54, 141, 34));
        ExportSelectedButton->setStyleSheet(QLatin1String("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        ExportAllButton = new QPushButton(ImportExportFrame);
        ExportAllButton->setObjectName(QStringLiteral("ExportAllButton"));
        ExportAllButton->setGeometry(QRect(10, 98, 141, 34));
        ExportAllButton->setStyleSheet(QLatin1String("background: #1F2933;\n"
"border: 2px solid #323F4B;\n"
"color: white;"));
        CredentialTable->raise();
        label_8->raise();
        frame->raise();
        SearchBar->raise();
        frame_2->raise();
        AddCredentialFrame->raise();
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
        SearchBar->setText(QString());
        SearchBar->setPlaceholderText(QApplication::translate("Form", "Search...", nullptr));
        CopyButton->setText(QString());
        label->setText(QApplication::translate("Form", "Copy Cell", nullptr));
        AddButton->setText(QString());
        label_2->setText(QApplication::translate("Form", "Add", nullptr));
        label_3->setText(QApplication::translate("Form", "Credential", nullptr));
        RemoveButton->setText(QString());
        label_4->setText(QApplication::translate("Form", "Remove", nullptr));
        label_5->setText(QApplication::translate("Form", "Selected", nullptr));
        EditButton->setText(QString());
        label_6->setText(QApplication::translate("Form", "Edit", nullptr));
        label_7->setText(QApplication::translate("Form", "Credential", nullptr));
        label_8->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">Vault</span></p></body></html>", nullptr));
        AddLabel->setText(QApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Add Credential</span></p></body></html>", nullptr));
        AddService->setText(QString());
        AddService->setPlaceholderText(QApplication::translate("Form", "Service Name...", nullptr));
        AddUsername->setText(QString());
        AddUsername->setPlaceholderText(QApplication::translate("Form", "Username or Email...", nullptr));
        AddPassword->setText(QString());
        AddPassword->setPlaceholderText(QApplication::translate("Form", "Password", nullptr));
        AddCredentialButton->setText(QApplication::translate("Form", "Add", nullptr));
        pushButton->setText(QApplication::translate("Form", "Cancel", nullptr));
        ImportButton->setText(QApplication::translate("Form", "Import Credentials", nullptr));
        ExportSelectedButton->setText(QApplication::translate("Form", "Export Selected", nullptr));
        ExportAllButton->setText(QApplication::translate("Form", "Export All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREDENTIALMENUVDNINO_H
