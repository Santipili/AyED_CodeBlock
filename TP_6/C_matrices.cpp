#include <iostream>
using namespace std;
#include <iomanip>

const int dim = 100;
typedef int tMatriz[dim][dim];

int chooseOption();
void matrizAdd (int dimention, tMatriz matrixA, tMatriz matrixB, tMatriz& matrixResult);
void matrizSubstract (int dimention, tMatriz matrixA, tMatriz matrixB, tMatriz& matrixResult);
void matrizMultiply (int dimention, tMatriz matrixA, tMatriz matrixB, tMatriz& matrixResult);
void matrizTranspose (int dimention, tMatriz& matrixA);
int higherInRow (tMatriz matrixA, int dimention, int fila);
int minumInColumn (tMatriz matrixA, int dimention, int columna);
int searchChairPoint (tMatriz matrixA, int dimention, int& fila, int& columna);
void createMatrix (tMatriz& matrix, int dimention);
void showMatrix (tMatriz matrix, int dimention);

int main()
{
   tMatriz matrixA, matrixB, matrixC ;
   int option, dimention, puntoSilla, filaSilla, columnaSilla;

    do 
    {
        option = chooseOption();

        switch (option)
        {
            case 1:
            {
                cout << "Ingrese la dimencion (cuadrada) de las matrices: ";
                cin >> dimention;
                cout << endl;

                cout << "Datos de la primer matriz" << endl;
                createMatrix(matrixA, dimention);
                cout << endl;

                cout << "Datos de la segunda matriz" << endl;
                createMatrix(matrixB, dimention);
                cout << endl;

                matrizAdd(dimention, matrixA, matrixB, matrixC);

                cout << "La suma es:" << endl;
                showMatrix(matrixC, dimention);
            } break;
            
            case 2:
            {
                cout << "Ingrese la dimencion (cuadrada) de las matrices: ";
                cin >> dimention;
                cout << endl;

                cout << "Datos de la primer matriz" << endl;
                createMatrix(matrixA, dimention);
                cout << endl;

                cout << "Datos de la segunda matriz" << endl;
                createMatrix(matrixB, dimention);
                cout << endl;

                matrizSubstract(dimention, matrixA, matrixB, matrixC);

                cout << "La resta es:" << endl;
                showMatrix(matrixC, dimention);
            } break;

            case 3:
            {
                cout << "Ingrese la dimencion (cuadrada) de las matrices: ";
                cin >> dimention;
                cout << endl;

                cout << "Datos de la primer matriz" << endl;
                createMatrix(matrixA, dimention);
                cout << endl;

                cout << "Datos de la segunda matriz" << endl;
                createMatrix(matrixB, dimention);
                cout << endl;

                matrizMultiply(dimention, matrixA, matrixB, matrixC);

                cout << "La multiplicacion es:" << endl;
                showMatrix(matrixC, dimention);
            } break;

            case 4:
            {
                cout << "Ingrese la dimencion (cuadrada) de las matrices: ";
                cin >> dimention;
                cout << endl;

                cout << "Datos de la primer matriz" << endl;
                createMatrix(matrixA, dimention);
                cout << endl;

                matrizTranspose(dimention, matrixA);

                cout << "La matriz traspuesta es:" << endl;
                showMatrix(matrixA, dimention);
            } break;

            case 5:
            {
                cout << "Ingrese la dimencion (cuadrada) de las matrices: ";
                cin >> dimention;
                cout << endl;

                cout << "Datos de la primer matriz" << endl;
                createMatrix(matrixA, dimention);
                cout << endl;

                puntoSilla = searchChairPoint(matrixA, dimention, filaSilla, columnaSilla);

                if (puntoSilla != -222222222)
                {
                    cout << "El punto silla de la matriz es: " << puntoSilla << endl;
                    cout << "Su posicion es (" << filaSilla << "," << columnaSilla << ")" << endl;
                }
                else
                {
                    cout << "La matriz no contiene un punto silla" << endl;
                }
            }   
        }

        cout << endl;
    } while ((option > 0) && (option < 6));

    return 0;
}

int chooseOption()
{
    int option;

    do
    {
        cout << "Menu" << endl;
        cout << "1.- Sumar matrices" << endl;
        cout << "2.- Restar matrices" << endl;
        cout << "3.- Multiplicacion de matrices" << endl;
        cout << "4.- Matriz traspuesta" << endl;
        cout << "5.- Punto Silla de una matriz" << endl;
        cout << "0.- Salir" << endl;
        cout << endl;

        cin >> option;
    } while ((option < 0) || (option > 5));
    
    return option;
}

void matrizAdd (int dimention, tMatriz matrixA, tMatriz matrixB, tMatriz& matrixResult)
{
    for (int i = 0; i < dimention; i++)
    {
        for (int j = 0; j < dimention; j++)
        {
            matrixResult[i][j]= matrixA[i][j] + matrixB[i][j];
        }
    }
}

void matrizSubstract (int dimention, tMatriz matrixA, tMatriz matrixB, tMatriz& matrixResult)
{
    for (int i = 0; i < dimention; i++)
    {
        for (int j = 0; j < dimention; j++)
        {
            matrixResult[i][j]= matrixA[i][j] - matrixB[i][j];
        }
    }
}

void matrizMultiply (int dimention, tMatriz matrixA, tMatriz matrixB, tMatriz& matrixResult)
{
    for (int i = 0; i < dimention; i++)
    {
        for (int j = 0; j < dimention; j++)
        {
            matrixResult[i][j]= 0;

            for (int k = 0; k < dimention; k++)
            {
                matrixResult[i][j]+= (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }
}

void matrizTranspose (int dimention, tMatriz& matrixA)
{
    int aux;

    for (int i = 0; i < dimention; i++)
    {
        for (int j = 0; j < i; j++)
        {
            aux= matrixA[i][j];
            matrixA[i][j]= matrixA[j][i];
            matrixA[j][i]= aux;
        }
    }
}

int higherInRow (tMatriz matrixA, int dimention, int fila) // devuelve la columna del valor mas grande en X fila
{
    int aux, column;
    
    aux = matrixA[fila][0];
    column = 0;

    for (int j=1; j < dimention; j++)
    {
        if (matrixA[fila][j] > aux)
        {
            aux = matrixA[fila][j];
            column = j;
        }
    }

    return column;
}

int minumInColumn (tMatriz matrixA, int dimention, int columna) // devuelve la fila del valor mas chico en X columna
{
    int aux, row;

    row = 0;
    aux = matrixA[0][columna];

    for (int i=1; i < dimention; i++)
    {
        if (matrixA[i][columna] < aux)
        {
            aux = matrixA[i][columna];
            row = i;
        }
    }

    return row;
}

int searchChairPoint (tMatriz matrixA, int dimention, int& fila, int& columna)
{
    int pSilla, sillaRow, sillaColumn, i;

    i=-1;

    do   
    {
        i++;
        if (i < dimention)
        {
            sillaColumn = higherInRow (matrixA, dimention, i);
            sillaRow = minumInColumn (matrixA, dimention, sillaColumn);
        }
    
    } while ((sillaRow != i) && (i < dimention));

    if (sillaRow == i)
    {
        pSilla = matrixA[sillaRow][sillaColumn];
        fila = sillaRow + 1;
        columna = sillaColumn + 1;
    }
    else 
    {
        pSilla = -222222222;
        fila = columna = 0;
    }
    
    return pSilla;
}

void createMatrix (tMatriz& matrix, int dimention)
{
    for (int i=0; i<dimention; i++)
    {
        for (int j=0; j<dimention; j++)
        {
            cout << "ingrese el elemento (" << i+1 << "," << j+1 << ") = ";
            cin >> matrix[i][j];
        }
    }
}

void showMatrix (tMatriz matrix, int dimention)
{
    for (int i=0; i<dimention; i++)
    {
        for (int j=0; j<dimention; j++)
        {
            cout << setw(4) << matrix[i][j];
        }

        cout << endl;
    }
}
