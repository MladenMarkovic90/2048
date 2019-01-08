#include "mainwindow.h"
#include <QApplication>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    srand(static_cast<uint>(time(nullptr)));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
