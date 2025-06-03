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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsrWindow
{
public:
    QLabel *hint;
    QPushButton *ChangePassword;
    QPushButton *SearchTransactions;
    QSplitter *splitter;
    QLabel *name;
    QLabel *nameMessage;
    QSplitter *splitter_2;
    QLabel *number;
    QLabel *numberMessage;
    QSplitter *splitter_3;
    QLabel *money;
    QLabel *moneyMessage;
    QLabel *label_image;

    void setupUi(QWidget *UsrWindow)
    {
        if (UsrWindow->objectName().isEmpty())
            UsrWindow->setObjectName(QString::fromUtf8("UsrWindow"));
        UsrWindow->resize(780, 520);
        hint = new QLabel(UsrWindow);
        hint->setObjectName(QString::fromUtf8("hint"));
        hint->setGeometry(QRect(430, 80, 441, 61));
        ChangePassword = new QPushButton(UsrWindow);
        ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->setGeometry(QRect(620, 330, 121, 41));
        SearchTransactions = new QPushButton(UsrWindow);
        SearchTransactions->setObjectName(QString::fromUtf8("SearchTransactions"));
        SearchTransactions->setGeometry(QRect(440, 330, 111, 41));
        splitter = new QSplitter(UsrWindow);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(460, 160, 271, 41));
        splitter->setOrientation(Qt::Horizontal);
        name = new QLabel(splitter);
        name->setObjectName(QString::fromUtf8("name"));
        splitter->addWidget(name);
        nameMessage = new QLabel(splitter);
        nameMessage->setObjectName(QString::fromUtf8("nameMessage"));
        nameMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        splitter->addWidget(nameMessage);
        splitter_2 = new QSplitter(UsrWindow);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(460, 200, 271, 41));
        splitter_2->setOrientation(Qt::Horizontal);
        number = new QLabel(splitter_2);
        number->setObjectName(QString::fromUtf8("number"));
        splitter_2->addWidget(number);
        numberMessage = new QLabel(splitter_2);
        numberMessage->setObjectName(QString::fromUtf8("numberMessage"));
        numberMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        splitter_2->addWidget(numberMessage);
        splitter_3 = new QSplitter(UsrWindow);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(460, 240, 271, 41));
        splitter_3->setOrientation(Qt::Horizontal);
        money = new QLabel(splitter_3);
        money->setObjectName(QString::fromUtf8("money"));
        splitter_3->addWidget(money);
        moneyMessage = new QLabel(splitter_3);
        moneyMessage->setObjectName(QString::fromUtf8("moneyMessage"));
        moneyMessage->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        splitter_3->addWidget(moneyMessage);
        label_image = new QLabel(UsrWindow);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(0, 0, 390, 520));

        retranslateUi(UsrWindow);

        QMetaObject::connectSlotsByName(UsrWindow);
    } // setupUi

    void retranslateUi(QWidget *UsrWindow)
    {
        UsrWindow->setWindowTitle(QCoreApplication::translate("UsrWindow", "Form", nullptr));
        hint->setText(QCoreApplication::translate("UsrWindow", "\345\260\212\346\225\254\347\232\204\347\224\250\346\210\267\357\274\214\346\202\250\347\232\204\344\277\241\346\201\257\345\246\202\344\270\213\346\211\200\347\244\272\357\274\232", nullptr));
        ChangePassword->setText(QCoreApplication::translate("UsrWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        SearchTransactions->setText(QCoreApplication::translate("UsrWindow", "\346\237\245\350\257\242\346\265\201\346\260\264", nullptr));
        name->setText(QCoreApplication::translate("UsrWindow", "\345\247\223\345\220\215", nullptr));
        nameMessage->setText(QString());
        number->setText(QCoreApplication::translate("UsrWindow", "\345\255\246\345\217\267", nullptr));
        numberMessage->setText(QString());
        money->setText(QCoreApplication::translate("UsrWindow", "\344\275\231\351\242\235", nullptr));
        moneyMessage->setText(QString());
        label_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UsrWindow: public Ui_UsrWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRWINDOW_H
