/*FUNCION PRINCIPAL DEL TAD PILA  ESTATICa
EQUIPO: CARLOS MIGUEL CORREA MEDINA
VERSION:1.0

DESCRIPCIÓN: EVALUACION DE PARENTESIS CORRECTOS

COMPILACION PARA CONSTRUIR PROGRAMA: gcc TADmainEst.c TADpilaEst.c -o pilaEst
 */
//bibliotecas
#include"TADPilaEst.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//main
int main()
{

	pila miPila;
	elemento caracteres;
	char cadena[MAX];//arreglo que contiene a la cadena a evaluar
	int i; //contador

	printf("Introduce la cadena a evaluar\n");
	scanf("%s",cadena);

	Initialize(&miPila); //inicializa mipila

	for(i=0;i<MAX;i++)//recorre la cadena
	{
		if(cadena[i] == 40) //evalua si la cadena abre parentesis '('= 40 segun ascii
		{
			 caracteres.c = cadena[i]; //le da valor a caracteres tipo char
			Push(&miPila,caracteres);
		}
			
		if(cadena[i] == 41)//evalua si la cadena cierra parentesis ')' = 41
		{
		
		    Pop(&miPila); // en este momento no importa el elemento que que retorne pop
		}
	}

	if(Empty(&miPila)) //evalua si miPila esta vacia
	{
		printf("parentesis correctos\n");
	}

	if(Size(&miPila) > 0)
	{
     	printf("mas parentesis que abren que los que cierran\n");
	}

	if(Size(&miPila) < 0)
	{
		printf("mas parentesis que cierran que los que abren\n");
	}


	return 0;
}