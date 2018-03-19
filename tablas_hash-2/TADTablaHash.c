/*
IMPLEMENTACIONES DEl TABLA HASH ABIERTA(TADTablaHash.h)
AUTOR: Correa Medina Carlo Miguel.  Noviembre 4 2017
VERSIÓN: 2.0

DESCRIPCIÓN: TAD tablas hash o tablas de dispersión (Abierta).
Estructura de datos en la que se cumple:
Los elemtentos se insertar, eliminan y se buscan en una tabla
de dispersión con una complejidad n/m.
. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADTablaHash.c
*/
#include "TADTablaHash.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define Aura 0.618034

int colisiones[ALFA];

void Inicializar(tabla *H)
{
	int i; /*contador*/
	for (i = 0; i < ALFA; i++)
	{
		Initialize(&(H->T[i]));  /*inicializó las listas de la tabla hash*/
		colisiones[i] = 0;
	}
}
int FuncionH1(elemento k) /*metodo de la multiplicación*/
{
	double t;
	int v;
	t = Aura * k.p[0] - floor(Aura * k.p[0]);  /*me da la parte decimal*/
	v = (int) ALFA * t;
	return v;
}
int FuncionH2(elemento k)
{
	if(k.p[0] >= 'A' && k.p[0] <= 'Z')
		return k.p[0] - 'A';  /*Funcion hash que depende de la primera letra de la palabra*/
	else
		return -1;	
}
/*para acceder a al tabla hash es un orden constante, para buscar en la lista 
se ocupa un algoritmo de orden lineal, i.e.,
el orden de busqueda es m/n*/				  	
posicion Buscar(tabla H,elemento x)
{
	posicion aux;                     /*guarda el retorno de la posicion del elemento que se busca*/
	int indice;                     /*inice de la tabla hash*/

	indice = FuncionH2(x);         /*me retorna el valor del indice de la tabla*/

	if(indice >= 0 && indice <= 26)
	{
		aux = Search(&(H.T[indice]),x); /*busca en la lista el elemento x*/
		//ImprimeLista(&(H.T[indice]));
		if(ValidatePosition(&(H.T[indice]),aux))
			return aux;
	}
	else
	{
		printf("%s\n","el indice no existe" );
		return NULL;
	}
} 
void Insertar(tabla *H,elemento y)
{
	int indice;        /*indice de la tabla hash*/

	indice = FuncionH2(y);
	if(indice >= 0 && indice <= 26)
	{	
		Add(&(H->T[indice]),y);
		colisiones[indice]++;
	}
	return;
}   
int Eliminar(tabla *H,elemento z)
{
	posicion aux;       /*auxliar que funciona para poder guardar al elemento que se busca*/
	int indice;        /*indice de la tabla hash*/

	indice = FuncionH2(z);
	if(indice >= 0 && indice <= 26)
	{

		aux = Search(&(H->T[indice]),z);   /*busca el elemento que se quiere eliminar*/
		if(aux != NULL)
		{

			Remove(&(H->T[indice]),aux);  /*remueve el  elemento */
			colisiones[indice]--;

		}
		return 1;
	}
		
	else
	{
		printf("%s\n","EL indice no existe" );
		return 0;
	}
		
} 
void Colisiones(void)
{ 	
	system("clear");
	printf("\n\n");
	int i;
	int contador = 0;

	for (i = 0; i < ALFA; ++i) /*ciclo que recorre la tabla y revisa las colisiones de cada elemento*/
	{
		printf("\n\t\t\t\tindice:%c\tcolisiones:%d",'A'+i,colisiones[i]);
		contador = colisiones[i] + contador;
	}
		
	printf("\n\t\t\t\tColisiones:%d\n\t\t\t\t",contador);
}