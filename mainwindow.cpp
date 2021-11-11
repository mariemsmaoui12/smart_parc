#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_CIN->setValidator(new QIntValidator(0 , 9999999, this));
    ui->tab_client->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_CIN->text().toInt();
    QString n=ui->le_NOM->text();
    QString p=ui->le_Prenom->text();
    QString A=ui->le_Adresse_mail->text();
    int a=ui->le_Age->text().toInt();

    Client C(id,n,p,A,a);
    bool test=C.ajouter();
    QMessageBox msgBox;
        if(test){
            msgBox.setText("ajout avec succes");
        ui->tab_client->setModel(C.afficher());
        }
            else
            msgBox.setText(("echec d'ajout"));

            msgBox.exec();


}

void MainWindow::on_pb_supp_clicked()
{
    Client C1;
    C1.set_id(ui->le_CIN_supp->text().toInt());
    bool test=C1.supprimer(C1.get_id());
    QMessageBox msgBox;
        if(test){
            msgBox.setText("suppresion avec succes");
            ui->tab_client->setModel(C.afficher());
        }
            else
            msgBox.setText(("echec de suppresion"));

            msgBox.exec();

}



void MainWindow::on_pb_modifier_clicked()
{

    int id=ui->ln_modifier_id->text().toInt();
    QString n=ui->ln_modifier_nom->text();
    QString p=ui->ln_modifier_prenom->text();
    QString A=ui->ln_modifier_Adresse_mail->text();
    int a=ui->ln_modifier_Age->text().toInt();

    Client C(id,n,p,A,a);
    bool test=C.modifier();

        QMessageBox msgBox;
            if(test){
                msgBox.setText("modification avec succes");
                ui->tab_client->setModel(C.afficher());
            }
                else
                msgBox.setText(("echec de modification"));

                msgBox.exec();

}
