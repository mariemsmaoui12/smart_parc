#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}
