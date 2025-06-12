/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Usrname;
    QLineEdit *input_usr;
    QHBoxLayout *horizontalLayout_2;
    QLabel *code;
    QLineEdit *input_code;
    QLabel *label_image;
    QLabel *label_teamname;
    QLabel *label_load;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(780, 540);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 350, 111, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \346\234\250\350\264\250\347\272\271\347\220\206\345\272\225\350\211\262\357\274\214\344\270\216\350\257\276\346\241\214\351\242\234\350\211\262\345\215\217\350\260\203 */\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #d4a762,  /* \346\265\205\346\234\250\350\211\262 */\n"
"        stop:0.5 #b78a4a,  /* \344\270\255\347\255\211\346\234\250\350\211\262 */\n"
"        stop:1 #9c6e32);  /* \346\267\261\346\234\250\350\211\262 */\n"
"    \n"
"    /* \346\267\273\345\212\240\345\276\256\345\246\231\347\232\204\351\230\263\345\205\211\347\205\247\345\260\204\346\225\210\346\236\234 */\n"
"    border-top: 1px solid rgba(255, 236, 179, 0.7);\n"
"    border-left: 1px solid rgba(255, 236, 179, 0.5);\n"
"    \n"
"    /* \346\226\207\345\255\227\346\240\267\345\274\217 - \347\261\273\344\274\274\351\273\221\346\235\277\347\262\211\347\254\224\345\255\227 */\n"
"    color: #f5f5f5;\n"
"    font: bold 14pt \"Segoe UI\", sans-serif;\n"
"    text-shad"
                        "ow: 1px 1px 2px rgba(0,0,0,0.3);\n"
"    \n"
"    /* \350\276\271\346\241\206\345\222\214\345\234\206\350\247\222 - \347\261\273\344\274\274\346\225\231\345\256\244\345\221\212\347\244\272\347\211\214 */\n"
"    border-radius: 8px;\n"
"    border-bottom: 2px solid #7a5c32;\n"
"    border-right: 2px solid #7a5c32;\n"
"    padding: 6px 12px;\n"
"    \n"
"    /* \346\212\225\345\275\261\346\225\210\346\236\234 - \347\261\273\344\274\274\351\230\263\345\205\211\344\270\213\347\232\204\351\230\264\345\275\261 */\n"
"    box-shadow: 2px 2px 4px rgba(0,0,0,0.2);\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\346\225\210\346\236\234 - \347\261\273\344\274\274\351\230\263\345\205\211\345\242\236\345\274\272 */\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #e0b97e,\n"
"        stop:0.5 #c99d62,\n"
"        stop:1 #af8146);\n"
"    border-top-color: rgba(255, 246, 195, 0.9);\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\346\225\210\346\236\234 - \347\261"
                        "\273\344\274\274\351\273\221\346\235\277\346\214\211\345\216\213\346\204\237 */\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #9c6e32,\n"
"        stop:0.5 #8a612b,\n"
"        stop:1 #785424);\n"
"    border-bottom-color: #5d4525;\n"
"    border-right-color: #5d4525;\n"
"    padding-top: 7px;\n"
"    padding-left: 13px;\n"
"}\n"
"\n"
"/* \347\246\201\347\224\250\347\212\266\346\200\201 - \347\261\273\344\274\274\350\244\252\350\211\262\347\232\204\345\221\212\347\244\272 */\n"
"QPushButton:disabled {\n"
"    background-color: #e5d8c0;\n"
"    color: #aaaaaa;\n"
"    border: 1px solid #cccccc;\n"
"}"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 170, 341, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Usrname = new QLabel(layoutWidget);
        Usrname->setObjectName(QString::fromUtf8("Usrname"));
        Usrname->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));

        horizontalLayout->addWidget(Usrname);

        input_usr = new QLineEdit(layoutWidget);
        input_usr->setObjectName(QString::fromUtf8("input_usr"));
        input_usr->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));

        horizontalLayout->addWidget(input_usr);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        code = new QLabel(layoutWidget);
        code->setObjectName(QString::fromUtf8("code"));
        code->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\226\271\346\255\243\345\247\232\344\275\223\";"));

        horizontalLayout_2->addWidget(code);

        input_code = new QLineEdit(layoutWidget);
        input_code->setObjectName(QString::fromUtf8("input_code"));
        input_code->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        input_code->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(input_code);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_image = new QLabel(centralwidget);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(390, 0, 390, 540));
        label_teamname = new QLabel(centralwidget);
        label_teamname->setObjectName(QString::fromUtf8("label_teamname"));
        label_teamname->setGeometry(QRect(20, 20, 251, 41));
        label_teamname->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";"));
        label_load = new QLabel(centralwidget);
        label_load->setObjectName(QString::fromUtf8("label_load"));
        label_load->setGeometry(QRect(100, 100, 251, 51));
        label_load->setStyleSheet(QString::fromUtf8("font: 18pt \"\346\245\267\344\275\223\";\n"
"\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        Usrname->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        input_usr->setPlaceholderText(QCoreApplication::translate("MainWindow", "Please input your Id", nullptr));
        code->setText(QCoreApplication::translate("MainWindow", "  \345\257\206\347\240\201 ", nullptr));
        input_code->setText(QString());
        input_code->setPlaceholderText(QCoreApplication::translate("MainWindow", "Please input your password", nullptr));
        label_image->setText(QString());
        label_teamname->setText(QCoreApplication::translate("MainWindow", "By AAA\347\224\265\350\204\221\347\273\264\344\277\256", nullptr));
        label_load->setText(QCoreApplication::translate("MainWindow", "\346\240\241\345\233\255\345\215\241\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
