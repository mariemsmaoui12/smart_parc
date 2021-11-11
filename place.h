#ifndef PLACE_H
#define PLACE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QSqlTableModel>
#include <QUrl>
#include <QSqlRecord>
class place
{
    int num;

    QString type,etat;

public:
    place (){}
    place(int,QString,QString);
    //
    int  getnum(){return num;}
    QString getetat(){return etat;}
    QString gettype (){return type;}


    //

    void setetat(QString e){etat=e;}
    void settype(QString t){type=t;}
    void setnum(int n){num=n;}


    //
    QSqlQueryModel * afficher();
    bool ajouter();
    bool modifier (int num);
    bool supprimer (int num);
    QSqlQueryModel * recherche_place(int num);
    QSqlQueryModel *tri();
};

#endif // PLACE_H
