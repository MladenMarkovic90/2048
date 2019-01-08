#ifndef CONVERT_H
#define CONVERT_H

#include <vector>
#include <QLabel>
#include <cstdlib>
#include "matrice.h"

QString colorStyle(int broj);

void NizUMatricu(std::vector<QLabel *> niz, int matrica[4][4])
{
    for (uint i = 0; i < niz.size(); i++)
    {
        QLabel * tmp = niz[i];
        matrica[i / 4][i % 4] = atoi(tmp->text().toStdString().c_str());
    }
}

void MatricuUNiz(int matrica[4][4], std::vector<QLabel *> niz)
{
    for (uint i = 0; i < 4; i++)
    {
        for (uint j = 0; j < 4; j++)
        {
            uint index = i * 4 + j;
            QLabel * tmp = niz[index];

            if (matrica[i][j] == 0) tmp->setText("");
            else tmp->setText(QString("%1").arg(matrica[i][j]));

            tmp->setStyleSheet(colorStyle(matrica[i][j]));
        }
    }
}

QString colorStyle(int broj)
{
    QString style = QString("border:1px solid;border-color:black;border-radius:10px;background-color:");

    switch (broj)
    {
    case 2:
        style.append("rgb(255,255,255);");
        break;
    case 4:
        style.append("rgb(240,255,240);");
        break;
    case 8:
        style.append("rgb(225,255,225);");
        break;
    case 16:
        style.append("rgb(195,255,195);");
        break;
    case 32:
        style.append("rgb(135,255,135);");
        break;
    case 64:
        style.append("rgb(135,255,200);");
        break;
    case 128:
        style.append("rgb(135,220,255);");
        break;
    case 256:
        style.append("rgb(135,180,255);");
        break;
    case 512:
        style.append("rgb(150,150,255);");
        break;
    case 1024:
        style.append("rgb(100,100,255);");
        break;
    default:
        if (broj > 2047) style.append("rgb(50,50,255);");
        else style.append("rgb(255,255,255);");
        break;
    }

    if (broj > 2047) style.append("color:rgb(241,233,122);");
    else style.append("color:rgb(0,0,0);");

    return style;
}

#endif // CONVERT_H
