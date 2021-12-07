#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "connection.h"
#include <QString>
#include<QMessageBox>
#include <iostream>
#include <QTabWidget>
#include<QIntValidator>
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMediaPlayer>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include"smtp.h"
#include"qcustomplot.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menus->setModel((tmpmenu.afficher()));
    ui->prix->setValidator(new QIntValidator(0,9999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_enregistrer_clicked()
{
     QString id = ui->ref->text();
    QString nom = ui->nom->text();
    float prix = ui->prix->text().toFloat();
    QString etat = ui->etat->text();
    menu m(id,nom,prix,etat);
    QString email= ui->lineEdit->text();
    if  (bool test=m.ajouter()==false ||(email.isEmpty()))

                     {
                         QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{

        QMessageBox::critical(0,qApp->tr("success"),qApp->tr(" menu ajouté et un mail a éte envoyé au chef "),QMessageBox::Ok);
        ui->menus->setModel(tmpmenu.afficher());
        Smtp* smtp = new Smtp("yahyafhima1@gmail.com", "Hackerway01", "smtp.gmail.com", 465);
         connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
         QString m1=ui->lineEdit->text();
         smtp->sendMail("yahyafhima1@gmail.com",m1, "Smart Park, menu!","Bienvenue! Vous-avez un nouveau menu!");
ui->lineEdit->clear();
         ui->ref->clear();
         ui->nom->clear();
          ui->prix->clear();
           ui->etat->clear();


    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QString id = ui->ref->text();
   QString nom = ui->nom->text();
   float prix = ui->prix->text().toFloat();
   QString etat = ui->etat->text();

   if (id.isEmpty() || nom.isEmpty() || prix==0.0f ||etat.isEmpty()  )

                    {
                        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                    }
   else{


menu me(id,nom,prix,etat);
me.modifier();

             QMessageBox::critical(0,qApp->tr("success"),qApp->tr(" menu a été modifiée."),QMessageBox::Yes);
             ui->menus->setModel(tmpmenu.afficher());
             ui->menus->clearSelection();
               ui->ref->clear();
                 ui->nom->clear();
                   ui->prix->clear();
                     ui->etat->clear();
         }


}
void MainWindow::on_pb_supprimer_clicked()
{
    QString ref = ui->lineEdit_3->text();
    if(ref.isEmpty())
        {
            QMessageBox::critical(0,qApp->tr("erreur"),
                                  qApp->tr("veillez donner l identifiant du menu a supprimer"),QMessageBox::Cancel);
        }
    else
    {
        QMessageBox::critical(0,qApp->tr("attention"),
                              qApp->tr("voulez vous supprimer cette menu?"),QMessageBox::Yes,QMessageBox::No);
        if(QMessageBox::Yes)
        {
            bool test= tmpmenu.supprimer(ref);
            if (test)
            {
                ui->menus->setModel(tmpmenu.afficher());
                ui->menus->clearSelection();
            }
        }

    }

}
void MainWindow::on_pushButton_clicked()

{
    QSqlDatabase db;
                QTableView table_menu;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM menu ");
                 qry.exec();
                 Modal->setQuery(qry);
                 table_menu.setModel(Modal);


                 db.close();

                 QString strStream;
                 QTextStream out(&strStream);


                 const int rowCount = table_menu.model()->rowCount();
                 const int columnCount =  table_menu.model()->columnCount();

                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                         "<img src='C:/Users/21622/Pictures/Camera Roll/harley-quinn-bad-girl-cs.jpg' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des menus")
                    <<"<br>"

                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!table_menu.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(table_menu.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!table_menu.isColumnHidden(column)) {
                             QString data = table_menu.model()->data(table_menu.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"

                     "</body>\n"
                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/menu.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                 delete document;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->menus->setModel(tmpmenu.trie_menuprix());

  }
void MainWindow::on_pushButton_5_clicked()
{
    QString id = ui->ref1->text();
    ui->menus->setModel(tmpmenu.rechercher(id));

  }



    void MainWindow::on_tabWidget_currentChanged(int index)
    {


                          QLinearGradient gradient(0, 0, 0, 400);
                          gradient.setColorAt(0, QColor(90, 90, 90));
                          gradient.setColorAt(0.38, QColor(0, 220, 220));
                          gradient.setColorAt(1, QColor(190, 120, 60));
                          ui->plot->setBackground(QBrush(gradient));

                          QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                          amande->setAntialiased(false);
                          amande->setStackingGap(1);

                          amande->setName("Menu");
                          amande->setPen(QPen(QColor(100,
                                                     9, 205).lighter(130)));
                          amande->setBrush(QColor(180, 170, 255));


                          QVector<double> ticks;
                          QVector<QString> labels;
                          tmpmenu.statistique(&ticks,&labels);

                          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                          textTicker->addTicks(ticks, labels);
                          ui->plot->xAxis->setTicker(textTicker);
                          ui->plot->xAxis->setTickLabelRotation(60);
                          ui->plot->xAxis->setSubTicks(false);
                          ui->plot->xAxis->setTickLength(0, 4);
                          ui->plot->xAxis->setRange(0, 8);
                          ui->plot->xAxis->setBasePen(QPen(Qt::white));
                          ui->plot->xAxis->setTickPen(QPen(Qt::white));
                          ui->plot->xAxis->grid()->setVisible(true);
                          ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                          ui->plot->xAxis->setTickLabelColor(Qt::white);
                          ui->plot->xAxis->setLabelColor(Qt::white);


                          ui->plot->yAxis->setRange(0,100);
                          ui->plot->yAxis->setPadding(5);
                          ui->plot->yAxis->setLabel("Statistiques");
                          ui->plot->yAxis->setBasePen(QPen(Qt::white));
                          ui->plot->yAxis->setTickPen(QPen(Qt::white));
                          ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                          ui->plot->yAxis->grid()->setSubGridVisible(true);
                          ui->plot->yAxis->setTickLabelColor(Qt::white);
                          ui->plot->yAxis->setLabelColor(Qt::white);
                          ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                          ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                          QVector<double> PlaceData;
                          QSqlQuery q1("select prix from MENU where prix>10");
                          while (q1.next()) {
                                        int  nbr_fautee = q1.value(0).toInt();
                                        PlaceData<< nbr_fautee;
                                          }
                          amande->setData(ticks, PlaceData);

                          ui->plot->legend->setVisible(true);
                          ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                          ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                          ui->plot->legend->setBorderPen(Qt::NoPen);
                          QFont legendFont = font();
                          legendFont.setPointSize(5);
                          ui->plot->legend->setFont(legendFont);
                          ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    }
