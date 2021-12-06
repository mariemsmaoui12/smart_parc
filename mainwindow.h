#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots :
    void on_pb_enregistrer_clicked();
    void on_pushButton_2_clicked();
    void on_pb_supprimer_clicked();
void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pb_send_clicked();


void on_tabWidget_currentChanged(int index);


private:
    Ui::MainWindow *ui;
    menu tmpmenu;
};
#endif // MAINWINDOW_H
