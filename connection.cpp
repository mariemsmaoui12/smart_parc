#include "connection.h"
#include<QDebug>
#include<QMessageBox>

using namespace std;
connection::connection()
{

}

bool connection::createconnection()
{      QSqlDatabase db;
       bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("test-bd");
       db.setUserName("yahya");
       db.setPassword("22980612");
       if(db.open()) test=true;
       return test;
   }

void connection::closeconnection()
{
    db.close();
}
