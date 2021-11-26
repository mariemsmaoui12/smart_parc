#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include "popup.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_tri_par_age_clicked();

    void on_pb_envoyer_mail_clicked();
    void sendMail();
    void mailSent(QString);

    void on_pb_QR_code_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pb_supp2_clicked();



private:
    Ui::MainWindow *ui;
    Client C;
    PopUp *popUp;
};

#endif // MAINWINDOW_H
