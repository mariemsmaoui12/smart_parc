/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionpar_alphabet;
    QAction *actionPrix;
    QAction *actiontendance;
    QAction *actionid;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pb_enregistrer;
    QLabel *label;
    QLineEdit *ref;
    QLabel *label_3;
    QLineEdit *nom;
    QLabel *label_4;
    QLineEdit *prix;
    QLabel *label_5;
    QLabel *label_10;
    QLineEdit *etat;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QListView *menus;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuOption;
    QMenu *menuRecherche;
    QMenu *menuPar_nom;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(898, 621);
        actionpar_alphabet = new QAction(MainWindow);
        actionpar_alphabet->setObjectName(QStringLiteral("actionpar_alphabet"));
        actionPrix = new QAction(MainWindow);
        actionPrix->setObjectName(QStringLiteral("actionPrix"));
        actiontendance = new QAction(MainWindow);
        actiontendance->setObjectName(QStringLiteral("actiontendance"));
        actionid = new QAction(MainWindow);
        actionid->setObjectName(QStringLiteral("actionid"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 871, 571));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pb_enregistrer = new QPushButton(tab);
        pb_enregistrer->setObjectName(QStringLiteral("pb_enregistrer"));
        pb_enregistrer->setGeometry(QRect(20, 390, 93, 28));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 171, 111));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        ref = new QLineEdit(tab);
        ref->setObjectName(QStringLiteral("ref"));
        ref->setGeometry(QRect(150, 170, 113, 22));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 170, 81, 21));
        nom = new QLineEdit(tab);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(150, 220, 113, 22));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 220, 81, 21));
        prix = new QLineEdit(tab);
        prix->setObjectName(QStringLiteral("prix"));
        prix->setGeometry(QRect(150, 270, 113, 22));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 270, 81, 21));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 320, 81, 21));
        etat = new QLineEdit(tab);
        etat->setObjectName(QStringLiteral("etat"));
        etat->setGeometry(QRect(150, 320, 113, 22));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 390, 93, 28));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 390, 93, 28));
        menus = new QListView(tab);
        menus->setObjectName(QStringLiteral("menus"));
        menus->setGeometry(QRect(320, 130, 511, 401));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(620, 110, 81, 21));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(330, 100, 71, 41));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(460, 110, 111, 21));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(770, 100, 71, 41));
        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(320, 99, 511, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 898, 26));
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuRecherche = new QMenu(menubar);
        menuRecherche->setObjectName(QStringLiteral("menuRecherche"));
        menuPar_nom = new QMenu(menuRecherche);
        menuPar_nom->setObjectName(QStringLiteral("menuPar_nom"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuOption->menuAction());
        menubar->addAction(menuRecherche->menuAction());
        menuOption->addAction(actionpar_alphabet);
        menuOption->addAction(actionPrix);
        menuOption->addAction(actiontendance);
        menuRecherche->addAction(menuPar_nom->menuAction());
        menuRecherche->addAction(actionid);
        menuPar_nom->addSeparator();
        menuPar_nom->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionpar_alphabet->setText(QApplication::translate("MainWindow", "A..Z", Q_NULLPTR));
        actionPrix->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        actiontendance->setText(QApplication::translate("MainWindow", "tendance", Q_NULLPTR));
        actionid->setText(QApplication::translate("MainWindow", "id ", Q_NULLPTR));
        pb_enregistrer->setText(QApplication::translate("MainWindow", "enregistrer", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "     MENU", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "NOM :", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "prix :", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "etat :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Mettre a jour", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "prix", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "reference", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Nom de menu", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "etat", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Creation", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        menuRecherche->setTitle(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        menuPar_nom->setTitle(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
