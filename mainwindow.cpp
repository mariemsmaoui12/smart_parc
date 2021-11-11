 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "place.h"
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <QMediaPlayer>
#include <QSqlTableModel>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(ptmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valider_clicked()
{
    {
        int num=ui->lineEdit_num->text().toInt();
        QString type=ui->lineEdit_type->text();
        QString etat=ui->lineEdit_etat->text();

        //
        place p(num,type,etat);
        //
        bool test=p.ajouter ();
       click = new QMediaPlayer();
            click->setMedia(QUrl("C:/Users/Nour Saidi/Desktop/projet QT/projet c++/click.mp3"));
             click->play();
        if (test)
        { ui->tableView->setModel(ptmp.afficher());
            QMessageBox :: information (nullptr, QObject ::tr("OK"),
                         QObject ::tr("Ajout effectué\n"
                                      "click cancel to exit"),
                    QMessageBox:: Cancel);

    }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("try again.\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
        }
}}


void MainWindow::on_pushButton_sup_clicked()
{


     QItemSelectionModel *select = ui->tableView->selectionModel();
        int num =select->selectedRows(0).value(0).data().toInt();
   bool test=ptmp.supprimer(num);

    click = new QMediaPlayer();
        click->setMedia(QUrl("C:/Users/Nour Saidi/Desktop/projet QT/projet c++/click.mp3"));
         click->play();
    if (test)
    { QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("suppression effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);

   }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }
}





void MainWindow::on_pushButton_recherche_clicked()
{
    if (ui->checkBox_search_num->isChecked())
    {
    int num = ui->lineEdit_recherche->text().toInt();
        QSqlQueryModel * test=ptmp.recherche_place(num);
        if (ui->pushButton_recherche->isChecked()){
            ui->pushButton_recherche->setText("En cours");
            click = new QMediaPlayer();
                click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                 click->play();
            if(test != nullptr)
        {
            QMessageBox::information(nullptr, QObject::tr("chercher une place"),
                        QObject::tr("place trouvé.\n"
                                    "Click ok to get informations."), QMessageBox::Ok);
                ui->tableView->setModel(test);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher une place"),
                        QObject::tr("Erreur , place introuvable !.\n"
                                    "Click cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(test);

    }}
            else
            {
                ui->pushButton_recherche->setText("Recherche");
                ui->tableView->setModel(ptmp.afficher());
                click = new QMediaPlayer();
                    click->setMedia(QUrl("C:/Users/user/Desktop/click.mp3"));
                     click->play();

            }
     }

}

void MainWindow::on_pushButton_modifier_clicked()
{
    int num=ui->num_mod->text().toInt();
    QString type =ui->type_mod->text();
    QString etat=ui->etat_mod->text();

       place p(num,type,etat);
        bool test=p.modifier(num);
        if (test)
        {
               ui->tableView->setModel(ptmp.afficher());
            QMessageBox :: information (nullptr, QObject ::tr("OK"),
                         QObject ::tr("modifier effectué\n"
                                      "click cancel to exit"),
                    QMessageBox:: Cancel);

    }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("try again.\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tableView->setModel(ptmp.tri());
}
