/********************************************************************************
** Form generated from reading UI file 'new_user.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_USER_H
#define UI_NEW_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_user
{
public:
    QLabel *hint;
    QLabel *name_hint;
    QLabel *code_hint;
    QLabel *number_hint;
    QLabel *code_hint2;
    QPushButton *sureButton;
    QLabel *card_hint;
    QLineEdit *name;
    QLineEdit *number;
    QLineEdit *card;
    QLineEdit *code;
    QLineEdit *code_2;

    void setupUi(QWidget *new_user)
    {
        if (new_user->objectName().isEmpty())
            new_user->setObjectName(QString::fromUtf8("new_user"));
        new_user->resize(780, 520);
        hint = new QLabel(new_user);
        hint->setObjectName(QString::fromUtf8("hint"));
        hint->setGeometry(QRect(50, 30, 231, 71));
        name_hint = new QLabel(new_user);
        name_hint->setObjectName(QString::fromUtf8("name_hint"));
        name_hint->setGeometry(QRect(200, 120, 51, 41));
        name_hint->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        code_hint = new QLabel(new_user);
        code_hint->setObjectName(QString::fromUtf8("code_hint"));
        code_hint->setGeometry(QRect(200, 240, 51, 41));
        code_hint->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        number_hint = new QLabel(new_user);
        number_hint->setObjectName(QString::fromUtf8("number_hint"));
        number_hint->setGeometry(QRect(200, 160, 51, 41));
        number_hint->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        code_hint2 = new QLabel(new_user);
        code_hint2->setObjectName(QString::fromUtf8("code_hint2"));
        code_hint2->setGeometry(QRect(110, 280, 141, 41));
        code_hint2->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        sureButton = new QPushButton(new_user);
        sureButton->setObjectName(QString::fromUtf8("sureButton"));
        sureButton->setGeometry(QRect(280, 350, 121, 31));
        card_hint = new QLabel(new_user);
        card_hint->setObjectName(QString::fromUtf8("card_hint"));
        card_hint->setGeometry(QRect(200, 200, 51, 41));
        card_hint->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));
        name = new QLineEdit(new_user);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(250, 120, 211, 41));
        name->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        number = new QLineEdit(new_user);
        number->setObjectName(QString::fromUtf8("number"));
        number->setGeometry(QRect(252, 159, 211, 41));
        number->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        card = new QLineEdit(new_user);
        card->setObjectName(QString::fromUtf8("card"));
        card->setGeometry(QRect(252, 199, 211, 41));
        card->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        code = new QLineEdit(new_user);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(252, 239, 211, 41));
        code->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        code_2 = new QLineEdit(new_user);
        code_2->setObjectName(QString::fromUtf8("code_2"));
        code_2->setGeometry(QRect(252, 279, 211, 41));
        code_2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));

        retranslateUi(new_user);

        QMetaObject::connectSlotsByName(new_user);
    } // setupUi

    void retranslateUi(QWidget *new_user)
    {
        new_user->setWindowTitle(QCoreApplication::translate("new_user", "Form", nullptr));
        hint->setText(QCoreApplication::translate("new_user", "\350\257\267\350\276\223\345\205\245\345\276\205\346\263\250\345\206\214\347\224\250\346\210\267\347\232\204\344\277\241\346\201\257\357\274\232", nullptr));
        name_hint->setText(QCoreApplication::translate("new_user", "\345\247\223\345\220\215", nullptr));
        code_hint->setText(QCoreApplication::translate("new_user", "\345\257\206\347\240\201", nullptr));
        number_hint->setText(QCoreApplication::translate("new_user", "\345\255\246\345\217\267", nullptr));
        code_hint2->setText(QCoreApplication::translate("new_user", "    \345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        sureButton->setText(QCoreApplication::translate("new_user", "\347\241\256\345\256\232", nullptr));
        card_hint->setText(QCoreApplication::translate("new_user", "\345\215\241\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_user: public Ui_new_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_USER_H
