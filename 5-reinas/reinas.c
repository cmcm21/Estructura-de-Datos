/*Autor: Correa Medina Carlos Miguel. 13 de noviembre del 2017.
 Version: 2.0.
 Descripción: se eligira un numero de reinas y estas se acomodaran en un tablero 
 sin que se puedan atacar.
 Compilación: gcc reinas.c -lncurses -o reinas
 Ejecución: ./reinas
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define true 1
#define false 0
#define TIEMPO_BASE 100000
#define N 10

typedef int boolean;

 
void Imprimir(int tablero[N][N]);
boolean guardar(int tablero[N][N], int fil, int col);
boolean Resolver(int tablero[N][N], int col);
boolean resolverNR(void);


int main()
{
    if(resolverNR())
        return 0;
    else
        exit(1);
}
/*esta funcion se encarga de recorrer el arreglo bidimensional e imprimirlo
no regrasa nada y resibe el arreglo bidemensional con su respectivo tamaño*/
void Imprimir(int tablero[N][N])
{
    system("clear");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
          if(tablero[i][j] == 0)
            printf("|-|");
          else if(tablero[i][j] == 1)
            printf("|*|");
        }
           
        printf("\n");
    }
}
/*esta función se encarga de que las reinas no esten en la misma fila ni en la 
misma columna, y va imprimiendo el procedimiento
recibe el arreglo bidimensional el entero de filas y el entero de columnas y 
retorna un boleano tambien se encarga de revisar las diagonales*/
boolean guardar(int tablero[N][N], int fil, int col)
{
    int i, j;

    Imprimir(tablero);
 
    for (i = 0; i < col; i++)
        if (tablero[fil][i])
            return false;
 
    for (i=fil, j=col; i>=0 && j>=0; i--, j--)
        if (tablero[i][j])
            return false;
 
    for (i=fil, j=col; j>=0 && i<N; i++, j--)
        if (tablero[i][j])
            return false;
 
    return true;
}
/*esta funcion se encarga de recorrer el arreglo y buscar otra posicion si 
en la posicion en la que esta la reina es invalida, para realizar esta operacion
ocupa recursividad que tiene la mima funcion que una pila
recibe el arreglo bidimensional y el número de columna
regresa un boleano que significa si la posicion es la que esta la reina es valida o no */
boolean Resolver(int tablero[N][N], int col)
{
    if (col >= N)
        return true;
 
    for (int i = 0; i < N; i++)
    {
        usleep(TIEMPO_BASE);
        if ( guardar(tablero, i, col) )
        {
            tablero[i][col] = 1;

            if ( Resolver(tablero, col + 1) )
                return true;
 
            tablero[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}
/*Esta funcion se encarga de declarar el arreglo , y de llamar a la funcion resolver
para que empieze a resolver el tablero no recibe nada y regresa un boleano que indica 
si se puede o no poner a las reinas*/
boolean resolverNR(void)
{
    int tablero[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( Resolver(tablero, 0) == false )
    {
      printf("no existe solucion\n");
      return false;
    }
 
    Imprimir(tablero);
    return true;
}
 
