#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pgracz = 0;
    Pkomputer = 0;
    runda = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::losowanie()
{
    komputer = QRandomGenerator::global()->bounded(3);
    if(komputer == 0)
    {
        nazwaK = "papier";
    }
    else if(komputer == 1)
    {
        nazwaK = "kamień";
    }
    else
    {
        nazwaK = "nożycze";
    }
}

void MainWindow::gra(int g) // g - wybór gracza
{
    if(g == komputer)
    {
        wynik = 0;
    }
    else if((g == papier && komputer == kamien) || (g == kamien && komputer == nozycze) || (g == nozycze && komputer == papier))
    {
        wynik = 1;
    }
    else
    {
        wynik = 2;
    }


    if(wynik == 1)
    {
        Pgracz++;
        QMessageBox::information(this, "Wygrałeś!", "Komputer wybrał " + nazwaK, QMessageBox::Ok);
    }
    else if(wynik == 2)
    {
        Pkomputer++;
        QMessageBox::information(this, "Przegrałeś!", "Komputer wybrał " + nazwaK, QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Remis!", "Komputer wybrał to samo co ty", QMessageBox::Ok);
    }

    ui->Papier->setStyleSheet("background-color: rgb(255, 255, 41)");
    ui->Kamien->setStyleSheet("background-color: rgb(255, 255, 41)");
    ui->Nozyce->setStyleSheet("background-color: rgb(255, 255, 41)");

    ui->wynik->setText(QString::number(Pgracz) + ":" + QString::number(Pkomputer));
    ui->historia->setPlainText(ui->historia->toPlainText() + "Runda " + QString::number(runda) + ": gracz - [" + nazwaG + "] | komputer - [" + nazwaK + "]\n");
    runda++;
}

void MainWindow::on_Papier_clicked()
{
    gracz = papier;
    ui->Papier->setStyleSheet("background-color: red");
    nazwaG = "papier";
    losowanie();
    gra(gracz);
}

void MainWindow::on_Kamien_clicked()
{
    gracz = kamien;
    ui->Kamien->setStyleSheet("background-color: red");
    nazwaG = "kamień";
    losowanie();
    gra(gracz);
}

void MainWindow::on_Nozyce_clicked()
{
    gracz = nozycze;
    ui->Nozyce->setStyleSheet("background-color: red");
    nazwaG = "nożycze";
    losowanie();
    gra(gracz);
}


