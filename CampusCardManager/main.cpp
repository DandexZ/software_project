#include "mainwindow.h"
#include "DatabaseManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DatabaseManager m("E:\\softwork\\soft_work1\\software_project\\CampusCardManager\\database\\data.db");
    w.show();
    return a.exec();
}
