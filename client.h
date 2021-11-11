#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDebug>
#include<qsqlquerymodel.h>

class Client
{
private:
    int idC;
    QString nom;
    QString prenom;
    QString Adresse_mail;
    int Age;

public:
    Client();
    Client(int,QString,QString,QString,int);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_Adresse_mail();
    int get_age();
    void set_id(int);
    void set_nom(QString);
    void set_prenom(QString);
    void set_Adresse_mail(QString);
    void set_age(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    bool rechercher(int idC);
};

#endif // CLIENT_H
