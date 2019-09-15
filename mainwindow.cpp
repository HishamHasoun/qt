#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":icon.png"));
    ui->actiongeld->setIcon(QIcon(":icon1.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Server get Mitglied";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("verwaltung");
    if(db.open()){
        qDebug()<< "Database connected";
        QString str = "select * from person";
        QSqlQuery qry;
        qry.prepare(str);
        if(!qry.exec()){
            qDebug () << qry.lastError().text();
        }else{
            while(qry.next()){
                /*Mitglied m(qry.value(0).toInt());
                m.set_vorname(qry.value(1).toString())
                        ->set_nachname(qry.value(2).toString())
                        ->set_betrag(qry.value(3).toDouble())
                        ->set_geburts_datum(QDate::fromString(qry.value(10).toString(),"yyyy-MM-dd"))
                        ->set_mitglied_datum(QDate::fromString(qry.value(9).toString(),"yyyy-MM-dd"))
                        ->set_last_payment(QDate::fromString(qry.value(11).toString(),"yyyy-MM-dd"))
                        ->set_telefon(qry.value(4).toString())
                        ->set_ort(qry.value(5).toString())
                        ->set_PLZ(qry.value(6).toString())
                        ->set_hausNr(qry.value(8).toString())
                        ->set_Strasse(qry.value(7).toString());
                //this->set_mitglied(m);
                mitglied_list.push_back(m);*/
             }
        }
    }else{
        qDebug() << db.lastError().text();
    }
    db.close();
}
