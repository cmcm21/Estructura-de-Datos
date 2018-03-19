/*
CABECERA DE  TABLA HASH ABIERTA(TADTablaHash.h)
AUTOR: Correa Medina Carlo Miguel.  Noviembre 4 2017
VERSIÓN: 2.0

DESCRIPCIÓN: TAD tablas hash o tablas de dispersión (Abierta).
Estructura de datos en la que se cumple:
Los elemtentos se insertar, eliminan y se buscan en una tabla
de dispersión con una complejidad n/m.
*/

#include "TADListasDoble.h" /*se ocupan listas doblemente enlazadas para crear la tabla hash*/

#define ALFA 26 /*tamaño de la tabla*/

/*estructura de una tabla hash*/

typedef struct tabla
{
	lista T[ALFA];    /*la tabla es del tamaño del número de letras del alfabeto*/
}tabla;


void Inicializar(tabla *H);			  /*inicializa las listas que se ocupan en la tabla*/	
posicion Buscar(tabla H,elemento x); /*busca al elemento "x" en la tabla*/
void Insertar(tabla *H,elemento y);   /*inserta al elemento "y" en la tabla*/
int FuncionH1(elemento k);			  /*primera función de disperción */
int FuncionH2(elemento k);			  /*segunda fución de dispesrción */		
int Eliminar(tabla *H,elemento z);   /*elimina al elemento "z" de la tabla*/
void Colisiones(void);   /*determino las colisiones de cada elemento de la tabla hash*/