#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

private slots:
    void on_dugmeGore_clicked();
    void on_dugmeDesno_clicked();
    void on_dugmeDole_clicked();
    void on_dugmeLevo_clicked();

private:
    void ReturnMove();
    void PrepareReturnMove();
    void NewGame();
    void SaveRand();
    Ui::MainWindow * ui;
    std::vector<QLabel*> arrayFileds;
    int matrica[4][4];
    int lastMatrica[4][4];
    int lastRand;
    int newRand;
};

#endif // MAINWINDOW_H
