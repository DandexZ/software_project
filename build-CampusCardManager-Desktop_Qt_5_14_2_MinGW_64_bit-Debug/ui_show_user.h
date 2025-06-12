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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_show_user
{
public:
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *show_user)
    {
        if (show_user->objectName().isEmpty())
            show_user->setObjectName(QString::fromUtf8("show_user"));
        show_user->resize(844, 587);
        show_user->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f0f4f8;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        tableView = new QTableView(show_user);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 60, 821, 511));
        lineEdit = new QLineEdit(show_user);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 10, 481, 41));
        pushButton = new QPushButton(show_user);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(690, 29, 91, 21));
        label = new QLabel(show_user);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 171, 41));

        retranslateUi(show_user);

        QMetaObject::connectSlotsByName(show_user);
    } // setupUi

    void retranslateUi(QWidget *show_user)
    {
        show_user->setWindowTitle(QCoreApplication::translate("show_user", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("show_user", "\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("show_user", "\350\276\223\345\205\245\346\237\245\350\257\242\347\232\204\347\224\250\346\210\267\344\277\241\346\201\257\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class show_user: public Ui_show_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_USER_H
