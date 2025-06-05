/********************************************************************************
** Form generated from reading UI file 'show_money.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_MONEY_H
#define UI_SHOW_MONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_show_money
{
public:
    QTableView *tableView;

    void setupUi(QWidget *show_money)
    {
        if (show_money->objectName().isEmpty())
            show_money->setObjectName(QString::fromUtf8("show_money"));
        show_money->resize(827, 538);
        tableView = new QTableView(show_money);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 811, 521));

        retranslateUi(show_money);

        QMetaObject::connectSlotsByName(show_money);
    } // setupUi

    void retranslateUi(QWidget *show_money)
    {
        show_money->setWindowTitle(QCoreApplication::translate("show_money", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show_money: public Ui_show_money {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_MONEY_H
