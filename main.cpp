#include "mainwindow.h"
#include"connection.h"
#include"menu.h"
#include<QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;
    w.show();
    if(test)
    {

    QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("connection successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                       QObject::tr("connection failed\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
