/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manager
{
public:
    QLabel *hint_2;
    QPushButton *ChangePassword;
    QLabel *hint;
    QPushButton *Sign_up;
    QPushButton *update_money;
    QPushButton *destroy_user;
    QLabel *name_label;
    QPushButton *userdb;
    QPushButton *moneydb;

    void setupUi(QWidget *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName(QString::fromUtf8("Manager"));
        Manager->resize(780, 520);
        hint_2 = new QLabel(Manager);
        hint_2->setObjectName(QString::fromUtf8("hint_2"));
        hint_2->setGeometry(QRect(70, 110, 221, 61));
        hint_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        ChangePassword = new QPushButton(Manager);
        ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->setGeometry(QRect(530, 290, 121, 41));
        hint = new QLabel(Manager);
        hint->setObjectName(QString::fromUtf8("hint"));
        hint->setGeometry(QRect(30, 30, 191, 61));
        hint->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        Sign_up = new QPushButton(Manager);
        Sign_up->setObjectName(QString::fromUtf8("Sign_up"));
        Sign_up->setGeometry(QRect(120, 290, 111, 41));
        update_money = new QPushButton(Manager);
        update_money->setObjectName(QString::fromUtf8("update_money"));
        update_money->setGeometry(QRect(390, 290, 121, 41));
        destroy_user = new QPushButton(Manager);
        destroy_user->setObjectName(QString::fromUtf8("destroy_user"));
        destroy_user->setGeometry(QRect(250, 290, 121, 41));
        name_label = new QLabel(Manager);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(220, 30, 211, 61));
        name_label->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        userdb = new QPushButton(Manager);
        userdb->setObjectName(QString::fromUtf8("userdb"));
        userdb->setGeometry(QRect(180, 350, 141, 51));
        moneydb = new QPushButton(Manager);
        moneydb->setObjectName(QString::fromUtf8("moneydb"));
        moneydb->setGeometry(QRect(450, 350, 141, 51));

        retranslateUi(Manager);

        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QWidget *Manager)
    {
        Manager->setWindowTitle(QCoreApplication::translate("Manager", "Form", nullptr));
        hint_2->setText(QCoreApplication::translate("Manager", "\350\257\267\351\200\211\346\213\251\346\202\250\347\232\204\346\223\215\344\275\234\357\274\232", nullptr));
        ChangePassword->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        hint->setText(QCoreApplication::translate("Manager", "\345\260\212\346\225\254\347\232\204\347\256\241\347\220\206\345\221\230", nullptr));
        Sign_up->setText(QCoreApplication::translate("Manager", "\346\263\250\345\206\214\347\224\250\346\210\267", nullptr));
        update_money->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271\344\275\231\351\242\235", nullptr));
        destroy_user->setText(QCoreApplication::translate("Manager", "\346\263\250\351\224\200\347\224\250\346\210\267", nullptr));
        name_label->setText(QString());
        userdb->setText(QCoreApplication::translate("Manager", "\346\237\245\350\257\242\347\224\250\346\210\267\346\225\260\346\215\256\345\272\223", nullptr));
        moneydb->setText(QCoreApplication::translate("Manager", "\346\237\245\350\257\242\346\265\201\346\260\264\346\225\260\346\215\256\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
