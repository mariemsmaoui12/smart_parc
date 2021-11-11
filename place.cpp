#include "place.h"
#include <QMessageBox>
#include <QUrl>
#include <QSqlRecord>
#include <QTableView>

place::place(int num,QString type ,QString etat)
{
    this->num=num;
    this->type=type;
    this->etat=etat;

}
bool place ::ajouter()
{
    QSqlQuery query;
    QString res = QString :: number(num);
    query.prepare("insert into GESTION_PLACE_PARKING(num,type,etat)""values(:num,:type,:etat)");
    query.bindValue(":num",res);
    query.bindValue(":type",type);
    query.bindValue(":etat",etat);


    return query.exec();
}
QSqlQueryModel * place :: afficher()
{

QSqlQueryModel * model=new QSqlQueryModel ();
//model->setQuery("select * from place");
model->setQuery("select * from GESTION_PLACE_PARKING");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT"));

return model;
}
bool place ::supprimer(int num)
{
QSqlQuery query;
QString res=QString ::number(num);
query.prepare("delete from GESTION_PLACE_PARKING where num= :num");
query.bindValue(":num",res);
return query.exec();
}
bool place:: modifier(int num)
{
    QSqlQuery query;
    QString res=QString ::number(num);

    query.prepare("UPDATE GESTION_PLACE_PARKING SET num=:num,type=:type,etat=:etat where num=:num");
    query.bindValue(":num",res);
    query.bindValue(":type",type);
    query.bindValue(":etat",etat);


    return query.exec();
}
QSqlQueryModel * place::recherche_place(int num)
{
QSqlQuery q;
q.prepare("select * from GESTION_PLACE_PARKING where num=:num");
q.bindValue(":num", num);
q.exec();
QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery(q);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));

QSqlRecord rec = model->record(0);
int nou = rec.value("num").toInt();
if( nou ==num ){
    return model;
  }
return nullptr;
}

QSqlQueryModel* place::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from GESTION_PLACE_PARKING order by num");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));


   return model;

}

