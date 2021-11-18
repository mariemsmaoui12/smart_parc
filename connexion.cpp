#include "connexion.h"
#include <QMessageBox>

connexion::connexion() {}

bool connexion::createconnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test.bd");
    db.setUserName("nour");
    db.setPassword("nour");

    if (db.open())
        test=true;

    return test;

}
void connexion ::closeconnexion(){}
