#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const int papier = 0;
    const int kamien = 1;
    const int nozycze = 2;
    int gracz;
    int komputer;
    int wynik; // 3 stany, 0 - remis, 1 - wygrał gracz, 2 - wygrał komputer
    int Pgracz; // punkty gracza
    int Pkomputer; // punkty komputera
    int runda;
    QString nazwaK;
    QString nazwaG;

    void losowanie();

    void gra(int g);
private slots:
    void on_Papier_clicked();

    void on_Kamien_clicked();

    void on_Nozyce_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
