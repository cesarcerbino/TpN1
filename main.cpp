/* 
! Programar 2 funciones
! 1. revertir que recibe un arreglo enteros de cualquier dimensión y lo revierte, es decir, lo que está
! en el primer elemento lo intercambia con el último, el segundo con el ante último y así
! sucesivamente.
! 2. Transpuesta recibe una matriz cuadrada y la convierte en su transpuesta. Como en matrices no
! podemos hacerlo genérico, la haremos para el caso de dimensión 5x5
*/

#include <iostream>

using namespace std;

void mostrarvec(int vec[], int dim);
void mostrarmat(int m[][5], int dfil);

void ArregloInvertido(int Arr[], int dim);
void TransponerMatriz(int Matriz[][5], int dim);

int main()
{
    const int dim5{5};
    const int dim10{10};

    int vec5[dim5]{4, 11, 19, 8, 3};

    cout << " Vector de 5 elementos:" << endl;
    cout << "Normal:" << endl;
    mostrarvec(vec5, dim5);
    ArregloInvertido(vec5, dim5);
    cout << "Vector alterado:" << endl;
    mostrarvec(vec5, dim5);
    cout << "==================" << endl;

    int vec10[dim10]{23, 15, 1, 7, 6, 27, 2, 14, 12, 9};
    cout << " Vector de 10 elementos:" << endl;
    cout << "Normal:" << endl;
    mostrarvec(vec10, dim10);
    ArregloInvertido(vec10, dim10);
    cout << "Vector alterado:" << endl;
    mostrarvec(vec10, dim10);

    int matriz[dim5][dim5]{36, 7, 19, 28, 45,
                           17, 33, 42, 3, 25,
                           22, 41, 32, 11, 9,
                           39, 47, 14, 4, 23,
                           16, 38, 8, 27, 44};
    cout << "Matriz Sin alterar:" << endl;
    mostrarmat(matriz, dim5);
    TransponerMatriz(matriz, dim5);
    cout << "Matriz Traspuesta:" << endl;
    mostrarmat(matriz, dim5);

    return 0;
}

void ArregloInvertido(int Arr[], int dim)
{
    int final = dim - 1; // !  Se usa para el intercambio de valores
    for (int i = 0; i < dim / 2; i++)
    {
        if (Arr[i] != Arr[final])
        {
            swap(Arr[i], Arr[final]);
        }
        final--;
    }
}

void TransponerMatriz(int Matriz[][5], int dim)
{
    // ! Al ser una matriz cuadrada la diagonal principal se mantiene igual
    // ! por eso en el segundo loop uso i+1
    for (int i = 0; i < dim; i++)
    {
        for (int b = i + 1; b < dim; b++)
        {
            if (Matriz[i][b] != Matriz[b][i])
                swap(Matriz[i][b], Matriz[b][i]);
        }
    }
}

void mostrarvec(int vec[], int dim)
{
    for (int i = 0; i < dim; ++i)
        cout << vec[i] << '\t';
    cout << endl;
}

void mostrarmat(int m[][5], int dfil)
{
    const int dcol = 5; // solo por prolijidad

    for (int i = 0; i < dfil; ++i)
    {
        for (int j = 0; j < dcol; ++j)
            cout << m[i][j] << '\t';
        cout << endl;
    }
}
