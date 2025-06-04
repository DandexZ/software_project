/********************************************************************************
** Form generated from reading UI file 'usrwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRWINDOW_H
#define UI_USRWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsrWindow
{
public:
    QLabel *hint;
    QPushButton *ChangePassword;
    QPushButton *SearchTransactions;
    QLabel *label_image;
    QLabel *label;
    QLabel *number;
    QLabel *numberMessage;
    QLabel *nameMessage;
    QLabel *name;
    QLabel *moneyMessage;
    QLabel *money;

    void setupUi(QWidget *UsrWindow)
    {
        if (UsrWindow->objectName().isEmpty())
            UsrWindow->setObjectName(QString::fromUtf8("UsrWindow"));
        UsrWindow->resize(780, 520);
        hint = new QLabel(UsrWindow);
        hint->setObjectName(QString::fromUtf8("hint"));
        hint->setGeometry(QRect(410, 0, 271, 71));
        hint->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        ChangePassword = new QPushButton(UsrWindow);
        ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->setGeometry(QRect(620, 330, 121, 41));
        SearchTransactions = new QPushButton(UsrWindow);
        SearchTransactions->setObjectName(QString::fromUtf8("SearchTransactions"));
        SearchTransactions->setGeometry(QRect(440, 330, 111, 41));
        label_image = new QLabel(UsrWindow);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(0, 0, 390, 520));
        label = new QLabel(UsrWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 100, 211, 51));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        number = new QLabel(UsrWindow);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(460, 200, 51, 41));
        number->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        numberMessage = new QLabel(UsrWindow);
        numberMessage->setObjectName(QString::fromUtf8("numberMessage"));
        numberMessage->setGeometry(QRect(510, 200, 201, 41));
        numberMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        nameMessage = new QLabel(UsrWindow);
        nameMessage->setObjectName(QString::fromUtf8("nameMessage"));
        nameMessage->setGeometry(QRect(510, 160, 201, 41));
        nameMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        name = new QLabel(UsrWindow);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(460, 160, 51, 41));
        name->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        moneyMessage = new QLabel(UsrWindow);
        moneyMessage->setObjectName(QString::fromUtf8("moneyMessage"));
        moneyMessage->setGeometry(QRect(510, 240, 201, 41));
        moneyMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        money = new QLabel(UsrWindow);
        money->setObjectName(QString::fromUtf8("money"));
        money->setGeometry(QRect(460, 240, 51, 41));
        money->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));

        retranslateUi(UsrWindow);

        QMetaObject::connectSlotsByName(UsrWindow);
    } // setupUi

    void retranslateUi(QWidget *UsrWindow)
    {
        UsrWindow->setWindowTitle(QCoreApplication::translate("UsrWindow", "Form", nullptr));
        hint->setText(QCoreApplication::translate("UsrWindow", "\345\260\212\346\225\254\347\232\204\347\224\250\346\210\267:", nullptr));
        ChangePassword->setText(QCoreApplication::translate("UsrWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        SearchTransactions->setText(QCoreApplication::translate("UsrWindow", "\346\237\245\350\257\242\346\265\201\346\260\264", nullptr));
        label_image->setText(QString());
        label->setText(QCoreApplication::translate("UsrWindow", "\346\202\250\347\232\204\344\277\241\346\201\257\345\246\202\344\270\213\346\211\200\347\244\272\357\274\232", nullptr));
        number->setText(QCoreApplication::translate("UsrWindow", "\345\255\246\345\217\267", nullptr));
        numberMessage->setText(QString());
        nameMessage->setText(QString());
        name->setText(QCoreApplication::translate("UsrWindow", "\345\247\223\345\220\215", nullptr));
        moneyMessage->setText(QString());
        money->setText(QCoreApplication::translate("UsrWindow", "\344\275\231\351\242\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsrWindow: public Ui_UsrWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRWINDOW_H
