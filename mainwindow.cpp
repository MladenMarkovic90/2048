#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "convert.h"
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arrayFileds.push_back(ui->polje01);
    arrayFileds.push_back(ui->polje02);
    arrayFileds.push_back(ui->polje03);
    arrayFileds.push_back(ui->polje04);
    arrayFileds.push_back(ui->polje05);
    arrayFileds.push_back(ui->polje06);
    arrayFileds.push_back(ui->polje07);
    arrayFileds.push_back(ui->polje08);
    arrayFileds.push_back(ui->polje09);
    arrayFileds.push_back(ui->polje10);
    arrayFileds.push_back(ui->polje11);
    arrayFileds.push_back(ui->polje12);
    arrayFileds.push_back(ui->polje13);
    arrayFileds.push_back(ui->polje14);
    arrayFileds.push_back(ui->polje15);
    arrayFileds.push_back(ui->polje16);

    QAction * action = new QAction(this);
    action->setText("New game");
    connect(action, &QAction::triggered, this, &MainWindow::NewGame);

    QMenu * menuNewGame = new QMenu(this);
    menuNewGame->setTitle("Menu");
    menuNewGame->addAction(action);

    menuBar()->addMenu(menuNewGame);

    NewGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NewGame()
{
    for (uint i = 0; i < arrayFileds.size(); i++)
    {
        QLabel * tmp = arrayFileds[i];
        tmp->setText("");
    }

    NizUMatricu(arrayFileds, matrica);
    ubaciNovi(matrica);
    ubaciNovi(matrica);
    MatricuUNiz(matrica, arrayFileds);

    kopirajMatricu(matrica, lastMatrica);
    newRand = lastRand = rand();
}

void MainWindow::on_dugmeGore_clicked()
{
    PrepareReturnMove();
    NizUMatricu(arrayFileds, matrica);
    dugmeGore(matrica);
    MatricuUNiz(matrica, arrayFileds);
    SaveRand();
}

void MainWindow::on_dugmeDesno_clicked()
{
    PrepareReturnMove();
    NizUMatricu(arrayFileds, matrica);
    dugmeDesno(matrica);
    MatricuUNiz(matrica, arrayFileds);
    SaveRand();
}

void MainWindow::on_dugmeDole_clicked()
{
    PrepareReturnMove();
    NizUMatricu(arrayFileds, matrica);
    dugmeDole(matrica);
    MatricuUNiz(matrica, arrayFileds);
    SaveRand();
}

void MainWindow::on_dugmeLevo_clicked()
{
    PrepareReturnMove();
    NizUMatricu(arrayFileds, matrica);
    dugmeLevo(matrica);
    MatricuUNiz(matrica, arrayFileds);
    SaveRand();
}

void MainWindow::SaveRand()
{
    newRand = rand();
}

void MainWindow::PrepareReturnMove()
{
    srand(static_cast<uint>(newRand));
    lastRand = newRand;
    kopirajMatricu(matrica, lastMatrica);
}

void MainWindow::ReturnMove()
{
    srand(static_cast<uint>(lastRand));
    newRand = lastRand;
    kopirajMatricu(lastMatrica, matrica);
    MatricuUNiz(matrica, arrayFileds);
}
