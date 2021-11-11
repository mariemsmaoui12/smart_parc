#include "client.h"
#include"mainwindow.h"
Client::Client()
{
    idC=0;
    nom="";
    prenom="";
    Adresse_mail="";
    Age=0;
}
Client::Client(int id,QString n,QString p,QString A,int a)
{
    this->idC=id;
    this->nom=n;
    this->prenom=p;
    this->Adresse_mail=A;
    this->Age=a;
}
int Client::get_id(){return idC;}
QString Client::get_nom(){return nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_Adresse_mail(){return Adresse_mail;}
int Client::get_age(){return Age;}
void Client::set_id(int n){this->idC=n;}
void Client::set_nom(QString n){this->nom=n;}
void Client::set_prenom(QString p){this->prenom=p;}
void Client::set_Adresse_mail(QString A){this->Adresse_mail=A;}
void Client::set_age(int a){this->Age=a;}
bool Client::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(idC);
    QString age_string=QString::number(Age);
          query.prepare("INSERT INTO Gestion_client (idC, nom, prenom,Adresse_mail,Age) "
                        "VALUES (:idC, :nom, :prenom, :Adresse_mail,:Age)");
          query.bindValue(0, id_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, Adresse_mail);
          query.bindValue(4, age_string);
          query.exec();


}
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT* FROM Gestion_client");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("idC"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse_mail"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
    return model;
}
bool Client::supprimer(int idC)
{
    QSqlQuery query;
          query.prepare("Delete from Gestion_client where idC=:idC ");
          query.bindValue(0, idC);
          query.exec();
}
bool Client::modifier()
{

    QSqlQuery query;
    QString id_string=QString::number(idC);
    QString age_string=QString::number(Age);
        query.prepare("UPDATE Gestion_client SET nom=:nom,prenom=:prenom,Adresse_mail=:Adresse_mail,Age=:Age WHERE idC=:idC ");
        query.bindValue(":idC",id_string );
        query.bindValue(":nom",nom );
        query.bindValue(":prenom",prenom );
        query.bindValue(":Adresse_mail",Adresse_mail );
        query.bindValue(":Age", age_string);
         query.exec();

}

/*bool Client::rechercher(int idC)
{
    QSqlQuery query;
          query.prepare("SELECT * FROM Gestion_client where idC=:idC ");
          query.bindValue(0, idC);
          query.exec();

}*/
