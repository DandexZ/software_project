/********************************************************************************
** Form generated from reading UI file 'show_user.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_USER_H
#define UI_SHOW_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_show_user
{
public:
    QTableView *tableView;

    void setupUi(QWidget *show_user)
    {
        if (show_user->objectName().isEmpty())
            show_user->setObjectName(QString::fromUtf8("show_user"));
        show_user->resize(827, 538);
        show_user->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f0f4f8;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        tableView = new QTableView(show_user);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(15, 11, 791, 511));

        retranslateUi(show_user);

        QMetaObject::connectSlotsByName(show_user);
    } // setupUi

    void retranslateUi(QWidget *show_user)
    {
        show_user->setWindowTitle(QCoreApplication::translate("show_user", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show_user: public Ui_show_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_USER_H
