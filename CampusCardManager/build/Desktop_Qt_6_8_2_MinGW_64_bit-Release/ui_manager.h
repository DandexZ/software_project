/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manager
{
public:
    QPushButton *SearchTransactions;
    QLabel *hint;
    QPushButton *ChangePassword;
    QSplitter *splitter;
    QLabel *name;
    QLabel *nameMessage;
    QSplitter *splitter_2;
    QLabel *number;
    QLabel *numberMessage;

    void setupUi(QWidget *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName("Manager");
        Manager->resize(726, 411);
        SearchTransactions = new QPushButton(Manager);
        SearchTransactions->setObjectName("SearchTransactions");
        SearchTransactions->setGeometry(QRect(210, 290, 111, 41));
        hint = new QLabel(Manager);
        hint->setObjectName("hint");
        hint->setGeometry(QRect(80, 80, 421, 51));
        ChangePassword = new QPushButton(Manager);
        ChangePassword->setObjectName("ChangePassword");
        ChangePassword->setGeometry(QRect(380, 290, 121, 41));
        splitter = new QSplitter(Manager);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(190, 160, 271, 41));
        splitter->setOrientation(Qt::Horizontal);
        name = new QLabel(splitter);
        name->setObjectName("name");
        splitter->addWidget(name);
        nameMessage = new QLabel(splitter);
        nameMessage->setObjectName("nameMessage");
        splitter->addWidget(nameMessage);
        splitter_2 = new QSplitter(Manager);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setGeometry(QRect(190, 200, 271, 31));
        splitter_2->setOrientation(Qt::Horizontal);
        number = new QLabel(splitter_2);
        number->setObjectName("number");
        splitter_2->addWidget(number);
        numberMessage = new QLabel(splitter_2);
        numberMessage->setObjectName("numberMessage");
        splitter_2->addWidget(numberMessage);

        retranslateUi(Manager);

        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QWidget *Manager)
    {
        Manager->setWindowTitle(QCoreApplication::translate("Manager", "Form", nullptr));
        SearchTransactions->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        hint->setText(QCoreApplication::translate("Manager", "\345\260\212\346\225\254\347\232\204\347\256\241\347\220\206\345\221\230\357\274\214\346\202\250\347\232\204\344\277\241\346\201\257\345\246\202\344\270\213\346\211\200\347\244\272\357\274\232", nullptr));
        ChangePassword->setText(QCoreApplication::translate("Manager", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        name->setText(QCoreApplication::translate("Manager", "\345\247\223\345\220\215", nullptr));
        nameMessage->setText(QString());
        number->setText(QCoreApplication::translate("Manager", "ID", nullptr));
        numberMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
