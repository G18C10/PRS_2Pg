#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Pgracz = 0;
    Pkomputer = 0;
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
        nazwa = "papier";
    }
    else if(komputer == 1)
    {
        nazwa = "kamień";
    }
    else
    {
        nazwa = "nożycze";
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
        QMessageBox::information(this, "Wygrałeś!", "Komputer wybrał " + nazwa, QMessageBox::Ok);
    }
    else if(wynik == 2)
    {
        Pkomputer++;
        QMessageBox::information(this, "Przegrałeś!", "Komputer wybrał " + nazwa, QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Remis!", "Komputer wybrał to samo co ty", QMessageBox::Ok);
    }

    ui->Papier->setEnabled(1);
    ui->Kamien->setEnabled(1);
    ui->Nozyce->setEnabled(1);
}

void MainWindow::on_Papier_clicked()
{
    gracz = papier;
    ui->Kamien->setDisabled(1);
    ui->Nozyce->setDisabled(1);
    losowanie();
    gra(gracz);
}

void MainWindow::on_Kamien_clicked()
{
    gracz = kamien;
    ui->Papier->setDisabled(1);
    ui->Nozyce->setDisabled(1);
    losowanie();
    gra(gracz);
}

void MainWindow::on_Nozyce_clicked()
{
    gracz = nozycze;
    ui->Papier->setDisabled(1);
    ui->Kamien->setDisabled(1);
    losowanie();
    gra(gracz);
}
