#include "client.h"

Client::Client()
{
    idC=0;
    nom="";
    prenom="";
    Adresse_mail="";
    age=0;
}
Client::Client(int id,QString n,QString p,QString A,int a)
{
    this->idC=id;
    this->nom=n;
    this->prenom=p;
    this->Adresse_mail=A;
    this->age=a;
}
int Client::get_id(){return idC;}
QString Client::get_nom(){return nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_Adresse_mail(){return Adresse_mail;}
int Client::get_age(){return age;}
void Client::set_id(int n){this->idC=n;}
void Client::set_nom(QString n){this->nom=n;}
void Client::set_prenom(QString p){this->prenom=p;}
void Client::set_Adresse_mail(QString A){this->Adresse_mail=A;}
void Client::set_age(int a){this->age=a;}
bool Client::ajouter()
{
    bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(idC);
          query.prepare("INSERT INTO  (id, nom, prenom) "
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(":id", id_string);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.exec();

    return test;
}
