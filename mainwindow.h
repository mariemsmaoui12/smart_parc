#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "place.h"
#include <QMainWindow>
#include <QSqlTableModel>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_valider_clicked();






    void on_pushButton_sup_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_tri_clicked();

private:
    Ui::MainWindow *ui;
    place ptmp;
    QMediaPlayer *click;
};
#endif // MAINWINDOW_H
