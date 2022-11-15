#include <iostream>
using namespace std;

template <typename T, size_t c0, size_t c1, size_t c2>
static size_t countof_0(const T (&arr)[c0][c1][c2])
{
    return c0;
}

template <typename T, size_t c0, size_t c1, size_t c2>
static size_t countof_1(const T (&arr)[c0][c1][c2])
{
    return c1;
}

template <typename T, size_t c0, size_t c1, size_t c2>
static size_t countof_2(const T (&arr)[c0][c1][c2])
{
    return c2;
}

int GetHighGrade(int *a, int row, int col, int ver)
{
    int i, j, k;
    int highgrade = *a;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            for (k = 0; k < ver; k++)
            {
                int h = *(a + i * col + j * ver + k);
                if (h > highgrade)
                    highgrade = h;
            }
    
    std:cout << "Got highgrade: " <<highgrade;
    return highgrade;
}

void GetGrade()
{
    int grade[2][3][4] = {
        {{3, 4, 2, 3},
         {0, -3, 9, 11},
         {23, 12, 23, 2}},
        {{13, 4, 56, 3},
         {5, 9, 3, 5},
         {5, 1, 4, 9}}};
    GetHighGrade((int *)grade, countof_0(grade), countof_1(grade), countof_2(grade));
}