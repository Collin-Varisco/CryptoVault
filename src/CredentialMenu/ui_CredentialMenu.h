/********************************************************************************
** Form generated from reading UI file 'CredentialMenuTouIJn.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREDENTIALMENUTOUIJN_H
#define CREDENTIALMENUTOUIJN_H

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
    QPushButton *ExportButton;
    QPushButton *AboutButton;
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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("CryptoVault"));
        Form->resize(1000, 750);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setStyleSheet(QString::fromUtf8("background: #152028;\n"
""));
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, -20, 70, 780));
        frame->setStyleSheet(QString::fromUtf8("background: #1F2933;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        VaultButton = new QPushButton(frame);
        VaultButton->setObjectName(QString::fromUtf8("VaultButton"));
        VaultButton->setGeometry(QRect(-10, 290, 91, 70));
        VaultButton->setStyleSheet(QString::fromUtf8("background: #EFEFEF;\n"
"border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/SideBar/vault.png"), QSize(), QIcon::Normal, QIcon::Off);
        VaultButton->setIcon(icon);
        VaultButton->setIconSize(QSize(50, 50));
        SettingsButton = new QPushButton(frame);
        SettingsButton->setObjectName(QString::fromUtf8("SettingsButton"));
        SettingsButton->setGeometry(QRect(11, 430, 51, 70));
        SettingsButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/SideBar/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsButton->setIcon(icon1);
        SettingsButton->setIconSize(QSize(58, 58));
        ExportButton = new QPushButton(frame);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setGeometry(QRect(0, 360, 81, 70));
        ExportButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: none;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/SideBar/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExportButton->setIcon(icon2);
        ExportButton->setIconSize(QSize(40, 40));
        AboutButton = new QPushButton(frame);
        AboutButton->setObjectName(QString::fromUtf8("AboutButton"));
        AboutButton->setGeometry(QRect(6, 700, 51, 70));
        AboutButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/SideBar/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutButton->setIcon(icon3);
        AboutButton->setIconSize(QSize(38, 38));
        CredentialTable = new QTableWidget(Form);
        if (CredentialTable->columnCount() < 3)
            CredentialTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(62, 76, 89));
        CredentialTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        CredentialTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        CredentialTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        CredentialTable->setObjectName(QString::fromUtf8("CredentialTable"));
        CredentialTable->setGeometry(QRect(105, 60, 820, 660));
        CredentialTable->setAutoFillBackground(false);
        CredentialTable->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;"));
        SearchBar = new QLineEdit(Form);
        SearchBar->setObjectName(QString::fromUtf8("SearchBar"));
        SearchBar->setGeometry(QRect(106, 15, 221, 28));
        SearchBar->setStyleSheet(QString::fromUtf8("border: 2px solid #323F4B;\n"
"background: #1F2933;"));
        frame_2 = new QFrame(Form);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(930, 190, 70, 391));
        frame_2->setStyleSheet(QString::fromUtf8("background: #152028;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        CopyButton = new QPushButton(frame_2);
        CopyButton->setObjectName(QString::fromUtf8("CopyButton"));
        CopyButton->setGeometry(QRect(0, 0, 71, 70));
        CopyButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/CredentialMenu/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/Images/copy.png"), QSize(), QIcon::Normal, QIcon::On);
        CopyButton->setIcon(icon4);
        CopyButton->setIconSize(QSize(50, 50));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(8, 70, 61, 17));
        AddButton = new QPushButton(frame_2);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(12, 90, 40, 70));
        AddButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/CredentialMenu/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon5);
        AddButton->setIconSize(QSize(54, 54));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 31, 16));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(4, 170, 61, 16));
        RemoveButton = new QPushButton(frame_2);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));
        RemoveButton->setGeometry(QRect(8, 190, 51, 70));
        RemoveButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Images/CredentialMenu/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        RemoveButton->setIcon(icon6);
        RemoveButton->setIconSize(QSize(44, 44));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 250, 51, 17));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 270, 51, 17));
        EditButton = new QPushButton(frame_2);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setGeometry(QRect(14, 298, 51, 51));
        EditButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Images/CredentialMenu/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon7);
        EditButton->setIconSize(QSize(44, 44));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(23, 350, 31, 17));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(5, 366, 61, 20));
        label_8 = new QLabel(Form);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(73, 0, 921, 61));
        AddCredentialFrame = new QFrame(Form);
        AddCredentialFrame->setObjectName(QString::fromUtf8("AddCredentialFrame"));
        AddCredentialFrame->setEnabled(true);
        AddCredentialFrame->setGeometry(QRect(270, 180, 500, 411));
        AddCredentialFrame->setStyleSheet(QString::fromUtf8("background: #152028;\n"
""));
        AddCredentialFrame->setFrameShape(QFrame::StyledPanel);
        AddCredentialFrame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(AddCredentialFrame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(120, 20, 261, 371));
        frame_3->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: 2px solid #323F4B;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        AddLabel = new QLabel(frame_3);
        AddLabel->setObjectName(QString::fromUtf8("AddLabel"));
        AddLabel->setGeometry(QRect(0, 30, 261, 51));
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
        label_8->raise();
        frame->raise();
        CredentialTable->raise();
        SearchBar->raise();
        frame_2->raise();
        AddCredentialFrame->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        VaultButton->setText(QString());
        SettingsButton->setText(QString());
        ExportButton->setText(QString());
        AboutButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = CredentialTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form", "Service", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = CredentialTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form", "Username/Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = CredentialTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form", "Password", nullptr));
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
        label_8->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic;\">Password Vault</span></p></body></html>", nullptr));
        AddLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic;\">Add Credential</span></p></body></html>", nullptr));
        AddService->setText(QString());
        AddService->setPlaceholderText(QCoreApplication::translate("Form", "Service Name", nullptr));
        AddUsername->setText(QString());
        AddUsername->setPlaceholderText(QCoreApplication::translate("Form", "Username or Email", nullptr));
        AddPassword->setText(QString());
        AddPassword->setPlaceholderText(QCoreApplication::translate("Form", "Password", nullptr));
        AddCredentialButton->setText(QCoreApplication::translate("Form", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREDENTIALMENUTOUIJN_H
