/********************************************************************************
** Form generated from reading UI file 'show_usr_money.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_USR_MONEY_H
#define UI_SHOW_USR_MONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_show_usr_money
{
public:
    QTableView *tableView;

    void setupUi(QWidget *show_usr_money)
    {
        if (show_usr_money->objectName().isEmpty())
            show_usr_money->setObjectName(QString::fromUtf8("show_usr_money"));
        show_usr_money->resize(827, 538);
        tableView = new QTableView(show_usr_money);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 811, 521));

        retranslateUi(show_usr_money);

        QMetaObject::connectSlotsByName(show_usr_money);
    } // setupUi

    void retranslateUi(QWidget *show_usr_money)
    {
        show_usr_money->setWindowTitle(QCoreApplication::translate("show_usr_money", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show_usr_money: public Ui_show_usr_money {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_USR_MONEY_H
