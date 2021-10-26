/********************************************************************************
** Form generated from reading UI file 'PasswordGenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSGEN_H
#define UI_PASSGEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneratorForm
{
public:
    QFrame *frame;
    QPushButton *VaultButton;
    QPushButton *SettingsButton;
    QPushButton *ExportButton;
    QLabel *TitleLabel;
    QPushButton *CopyButton;
    QFrame *CenterFrame;
    QLabel *GeneratedPasswordLabel;
    QPushButton *GenerateButton;
    QLabel *CopyPasswordLabel;
    QFrame *GeneratorTweaksFrame;
    QCheckBox *NumberCharactersCheck;
    QLineEdit *TotalCharactersLine;
    QPushButton *IncludeButton;
    QPushButton *ExcludeButton;
    QFrame *IncludeExcludeFrame;
    QLabel *AddCharactersLabel;
    QLineEdit *IE_FIELD_1;
    QLineEdit *IE_FIELD_2;
    QLineEdit *IE_FIELD_3;
    QLineEdit *IE_FIELD_4;
    QLineEdit *IE_FIELD_5;
    QLineEdit *IE_FIELD_6;
    QPushButton *AddCharactersButton;
    QCheckBox *AlphaNumericBox;

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
""));
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 70, 610));
        frame->setStyleSheet(QString::fromUtf8("background: #1F2933;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        VaultButton = new QPushButton(frame);
        VaultButton->setObjectName(QString::fromUtf8("VaultButton"));
        VaultButton->setGeometry(QRect(-10, 210, 91, 70));
        VaultButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/SideBar/vault.png"), QSize(), QIcon::Normal, QIcon::Off);
        VaultButton->setIcon(icon);
        VaultButton->setIconSize(QSize(50, 50));
        SettingsButton = new QPushButton(frame);
        SettingsButton->setObjectName(QString::fromUtf8("SettingsButton"));
        SettingsButton->setGeometry(QRect(11, 350, 51, 70));
        SettingsButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/SideBar/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsButton->setIcon(icon1);
        SettingsButton->setIconSize(QSize(58, 58));
        ExportButton = new QPushButton(frame);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setGeometry(QRect(0, 290, 81, 70));
        ExportButton->setStyleSheet(QString::fromUtf8("background: #1F2933;\n"
"border: none;\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/SideBar/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExportButton->setIcon(icon2);
        ExportButton->setIconSize(QSize(40, 40));
        TitleLabel = new QLabel(Form);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(70, -10, 921, 151));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        TitleLabel->setFont(font);
        TitleLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        CopyButton = new QPushButton(Form);
        CopyButton->setObjectName(QString::fromUtf8("CopyButton"));
        CopyButton->setGeometry(QRect(750, 270, 51, 51));
        CopyButton->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/CredentialMenu/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/Images/copy.png"), QSize(), QIcon::Normal, QIcon::On);
        CopyButton->setIcon(icon3);
        CopyButton->setIconSize(QSize(50, 50));
        CenterFrame = new QFrame(Form);
        CenterFrame->setObjectName(QString::fromUtf8("CenterFrame"));
        CenterFrame->setGeometry(QRect(330, 250, 501, 151));
        CenterFrame->setFrameShape(QFrame::StyledPanel);
        CenterFrame->setFrameShadow(QFrame::Raised);
        GeneratedPasswordLabel = new QLabel(CenterFrame);
        GeneratedPasswordLabel->setObjectName(QString::fromUtf8("GeneratedPasswordLabel"));
        GeneratedPasswordLabel->setGeometry(QRect(10, 20, 381, 51));
        GeneratedPasswordLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"border: 2px solid white;"));
        GenerateButton = new QPushButton(CenterFrame);
        GenerateButton->setObjectName(QString::fromUtf8("GenerateButton"));
        GenerateButton->setGeometry(QRect(140, 100, 113, 32));
        GenerateButton->setStyleSheet(QString::fromUtf8("Color: white;\n"
"border: 2px solid white;"));
        CopyPasswordLabel = new QLabel(CenterFrame);
        CopyPasswordLabel->setObjectName(QString::fromUtf8("CopyPasswordLabel"));
        CopyPasswordLabel->setGeometry(QRect(410, 80, 81, 20));
        CopyPasswordLabel->setFont(font);
        CopyPasswordLabel->setStyleSheet(QString::fromUtf8("Color: white;"));
        GeneratorTweaksFrame = new QFrame(Form);
        GeneratorTweaksFrame->setObjectName(QString::fromUtf8("GeneratorTweaksFrame"));
        GeneratorTweaksFrame->setGeometry(QRect(80, 440, 331, 151));
        GeneratorTweaksFrame->setFrameShape(QFrame::StyledPanel);
        GeneratorTweaksFrame->setFrameShadow(QFrame::Raised);
        NumberCharactersCheck = new QCheckBox(GeneratorTweaksFrame);
        NumberCharactersCheck->setObjectName(QString::fromUtf8("NumberCharactersCheck"));
        NumberCharactersCheck->setGeometry(QRect(10, 10, 241, 20));
        NumberCharactersCheck->setStyleSheet(QString::fromUtf8("Color: white;"));
        TotalCharactersLine = new QLineEdit(GeneratorTweaksFrame);
        TotalCharactersLine->setObjectName(QString::fromUtf8("TotalCharactersLine"));
        TotalCharactersLine->setGeometry(QRect(260, 10, 61, 21));
        TotalCharactersLine->setStyleSheet(QString::fromUtf8("color: white;"));
        IncludeButton = new QPushButton(GeneratorTweaksFrame);
        IncludeButton->setObjectName(QString::fromUtf8("IncludeButton"));
        IncludeButton->setGeometry(QRect(13, 50, 181, 32));
        IncludeButton->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"color: white;"));
        ExcludeButton = new QPushButton(GeneratorTweaksFrame);
        ExcludeButton->setObjectName(QString::fromUtf8("ExcludeButton"));
        ExcludeButton->setGeometry(QRect(13, 100, 181, 32));
        ExcludeButton->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"color: white;"));
        IncludeExcludeFrame = new QFrame(Form);
        IncludeExcludeFrame->setObjectName(QString::fromUtf8("IncludeExcludeFrame"));
        IncludeExcludeFrame->setGeometry(QRect(350, 160, 341, 241));
        IncludeExcludeFrame->setStyleSheet(QString::fromUtf8("border: 2px solid white;"));
        IncludeExcludeFrame->setFrameShape(QFrame::StyledPanel);
        IncludeExcludeFrame->setFrameShadow(QFrame::Raised);
        AddCharactersLabel = new QLabel(IncludeExcludeFrame);
        AddCharactersLabel->setObjectName(QString::fromUtf8("AddCharactersLabel"));
        AddCharactersLabel->setGeometry(QRect(10, 30, 321, 20));
        AddCharactersLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"border: none;"));
        IE_FIELD_1 = new QLineEdit(IncludeExcludeFrame);
        IE_FIELD_1->setObjectName(QString::fromUtf8("IE_FIELD_1"));
        IE_FIELD_1->setGeometry(QRect(40, 70, 31, 21));
        IE_FIELD_1->setStyleSheet(QString::fromUtf8("color:white;"));
        IE_FIELD_2 = new QLineEdit(IncludeExcludeFrame);
        IE_FIELD_2->setObjectName(QString::fromUtf8("IE_FIELD_2"));
        IE_FIELD_2->setGeometry(QRect(160, 70, 31, 21));
        IE_FIELD_2->setStyleSheet(QString::fromUtf8("color:white;"));
        IE_FIELD_3 = new QLineEdit(IncludeExcludeFrame);
        IE_FIELD_3->setObjectName(QString::fromUtf8("IE_FIELD_3"));
        IE_FIELD_3->setGeometry(QRect(280, 70, 31, 21));
        IE_FIELD_3->setStyleSheet(QString::fromUtf8("color:white;"));
        IE_FIELD_4 = new QLineEdit(IncludeExcludeFrame);
        IE_FIELD_4->setObjectName(QString::fromUtf8("IE_FIELD_4"));
        IE_FIELD_4->setGeometry(QRect(40, 120, 31, 21));
        IE_FIELD_4->setStyleSheet(QString::fromUtf8("color:white;"));
        IE_FIELD_5 = new QLineEdit(IncludeExcludeFrame);
        IE_FIELD_5->setObjectName(QString::fromUtf8("IE_FIELD_5"));
        IE_FIELD_5->setGeometry(QRect(160, 120, 31, 21));
        IE_FIELD_5->setStyleSheet(QString::fromUtf8("color:white;"));
        IE_FIELD_6 = new QLineEdit(IncludeExcludeFrame);
        IE_FIELD_6->setObjectName(QString::fromUtf8("IE_FIELD_6"));
        IE_FIELD_6->setGeometry(QRect(280, 120, 31, 21));
        IE_FIELD_6->setStyleSheet(QString::fromUtf8("color:white;"));
        AddCharactersButton = new QPushButton(IncludeExcludeFrame);
        AddCharactersButton->setObjectName(QString::fromUtf8("AddCharactersButton"));
        AddCharactersButton->setGeometry(QRect(83, 170, 181, 32));
        AddCharactersButton->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"color: white;"));
        AlphaNumericBox = new QCheckBox(Form);
        AlphaNumericBox->setObjectName(QString::fromUtf8("AlphaNumericBox"));
        AlphaNumericBox->setGeometry(QRect(90, 420, 241, 20));
        AlphaNumericBox->setStyleSheet(QString::fromUtf8("Color: white;"));
        GeneratorTweaksFrame->raise();
        CenterFrame->raise();
        TitleLabel->raise();
        frame->raise();
        CopyButton->raise();
        AlphaNumericBox->raise();
        IncludeExcludeFrame->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        VaultButton->setText(QString());
        SettingsButton->setText(QString());
        ExportButton->setText(QString());
        TitleLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">Password Generator</span></p></body></html>", nullptr));
        CopyButton->setText(QString());
        GeneratedPasswordLabel->setText(QString());
        GenerateButton->setText(QCoreApplication::translate("Form", "Generate", nullptr));
        CopyPasswordLabel->setText(QCoreApplication::translate("Form", "Copy Password", nullptr));
        NumberCharactersCheck->setText(QCoreApplication::translate("Form", "Change Total Number Of Characters", nullptr));
        IncludeButton->setText(QCoreApplication::translate("Form", "Add Character To Include", nullptr));
        ExcludeButton->setText(QCoreApplication::translate("Form", "Add Character To Exclude", nullptr));
        AddCharactersLabel->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\">Use Fields To Add Characters</p></body></html>", nullptr));
        AddCharactersButton->setText(QCoreApplication::translate("Form", "Include/Exclude Characters", nullptr));
        AlphaNumericBox->setText(QCoreApplication::translate("Form", "Use Only Letters and Numbers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneratorForm: public Ui_GeneratorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSGEN_H
