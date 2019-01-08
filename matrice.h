#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
#include <unistd.h>

using namespace std;

#define MAX 4

void kopirajMatricu(int original[MAX][MAX], int kopirana[MAX][MAX]);
int ubaciNoviBroj();
void swap(int &first, int &second);

void ispisiMatricu(int m[MAX][MAX])
{
    cout << "Matrica " << MAX << "x" << MAX << ":" << endl;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << m[i][j] << " ";
        }

        cout << endl;
    }
}

void ucitajMatricu(int m[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> m[i][j];
        }
    }
}

void ucitajNulaMatricu(int m[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            m[i][j] = 0;
        }
    }
}

int prebrojiMatricu(int m[MAX][MAX])
{
    int count = 0;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (m[i][j] != 0) count++;
        }
    }

    return count;
}

void rotirajMatricuDesno(int m[MAX][MAX])
{
    int rotirana[MAX][MAX];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            rotirana[j][MAX - 1 - i] = m[i][j];
        }
    }

    kopirajMatricu(rotirana, m);
}

void rotirajMatricuLevo(int m[MAX][MAX])
{
    rotirajMatricuDesno(m);
    rotirajMatricuDesno(m);
    rotirajMatricuDesno(m);
}

void kopirajMatricu(int original[MAX][MAX], int kopirana[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            kopirana[i][j] = original[i][j];
        }
    }
}

bool ubaciNovi(int m[MAX][MAX])
{
    int count = prebrojiMatricu(m);

    if (count == MAX * MAX) return false;

    while (true)
    {
        int i = rand() % MAX;
        int j = rand() % MAX;

        if (m[i][j] == 0)
        {
            m[i][j] = ubaciNoviBroj();
            break;
        }
    }

    return true;
}

int ubaciNoviBroj()
{
    int broj = rand() % 100;
    if (broj < 15) return 4;
    return 2;
}

bool pomeriLevo(int m[MAX][MAX])
{
    bool promena = false;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0, k = 0; j < MAX; j++, k++)
        {
            if ((m[i][j] == 0 && m[i][k] != 0) || (m[i][j] != 0 && m[i][k] == 0))
            {
                promena = true;
            }

            swap(m[i][j], m[i][k]);

            if (m[i][k] == 0) k--;
        }
    }

    return promena;
}

bool spojiLevo(int m[MAX][MAX])
{
    bool promena = false;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 1, k = 0; j < MAX; j++, k++)
        {
            if (m[i][j] == m[i][k] && m[i][j] != 0)
            {
                m[i][k] += m[i][j];
                m[i][j] = 0;
                promena = true;
            }
        }
    }

    return promena;
}

bool obradiLevo(int m[MAX][MAX])
{
    bool promena = false;

    if (pomeriLevo(m) | spojiLevo(m)) promena = true;

    pomeriLevo(m);

    return promena;
}

void swap(int & first, int & second)
{
    int tmp = first;
    first = second;
    second = tmp;
}

void dugmeLevo(int m[MAX][MAX])
{
    if (obradiLevo(m)) ubaciNovi(m);
}

void dugmeDole(int m[MAX][MAX])
{
    rotirajMatricuDesno(m);
    dugmeLevo(m);
    rotirajMatricuLevo(m);
}

void dugmeDesno(int m[MAX][MAX])
{
    rotirajMatricuDesno(m);
    rotirajMatricuDesno(m);
    dugmeLevo(m);
    rotirajMatricuDesno(m);
    rotirajMatricuDesno(m);
}

void dugmeGore(int m[MAX][MAX])
{
    rotirajMatricuLevo(m);
    dugmeLevo(m);
    rotirajMatricuDesno(m);
}

#endif //MATRICE_H
