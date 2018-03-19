/*
EJEMPLO DE USO DE LA LIBRERIA DEL TAD LISTA (TADListaSL.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2017
VERSIÓN: 1.7

DESCRIPCIÓN: TAD lista
Estructura de datos lineal en la que se cumple:
Los elementos se insertan, eliminan o renplazan en cualquier extremo o posicion de esta.

OBSERVACIONES: Una Lista es una Estructura de datos dinámica (se le asigna memoria a medida que es necesitada,
durante la ejecución del programa).

COMPILACIÓN PARA GENERAR EL EJECUTABLE: gcc Prueba.c TADListaSL.o | TADListaSL.c
*/

//LIBRERAS
#include <stdio.h>
#include "TADListasDoble.h"


//CONSTANTES
#define  TAM_ALPHABET 25


//PROTOTIPOS/DECLARACIÓN DE FUNCIONES
//Función para imprimir el elemento de la lista con base en mi estructura elemento
void ImprimeLista(lista *l);

//PROGRAMA PRINCIPAL
int main (void)
{
	lista mi_lista; //Mi lista
	posicion aux;	//Posición auxiliar para manejar la lista
	elemento e;		//Elemento e

	int i;			//Para manejar los ciclos

	Initialize(&mi_lista); //Inicializar la lista

	//Insertar 25 elementos al frente o atras de la lista "Caracteres 'A', 'B', 'C', ..."
	for(i=0;i<=TAM_ALPHABET;i++)
	{
		//Llenar el elemento
		e.c='A'+i;

		/*Insertar al frente de la lista
		aux=First(&mi_lista);
		Insert(&mi_lista,e,aux,TRUE);
		*/
		//Insertar al final de la lista
		Add(&mi_lista,e);
	}
	printf("%d",Size(&mi_lista));

	//Ver la lista******************
	printf("\nLista Inicial");
	ImprimeLista(&mi_lista);
	//******************************

	//Eliminar el primero de la lista y el ultimo
	ImprimeLista(&mi_lista);

	aux=Final(&mi_lista);
	Remove(&mi_lista,aux);

	aux=First(&mi_lista);
	Remove(&mi_lista,aux);



	//Ver la lista******************
	printf("\nLista despues de eliminar al primero y al ultimo");
	ImprimeLista(&mi_lista);
	//******************************


	//Remover al elemento 10 de la lista si existe
	aux=First(&mi_lista);
	for(i=1;i<10;i++)
	{
		aux=Following(&mi_lista,aux);
	}

	if(ValidatePosition(&mi_lista,aux))
		Remove(&mi_lista,aux);

	//Ver la lista******************
	printf("\nLista despues de remover al elemento 10 de la lista si existe");
	ImprimeLista(&mi_lista);
	//******************************


	//Remover al elemento 5 de la lista si existe
	e=Element(&mi_lista,5);
	printf("\nEl elemento 5 es:\t%c",e.c);

	aux=Search(&mi_lista,e);
	if(ValidatePosition(&mi_lista,aux))
		Remove(&mi_lista,aux);

	//Ver la lista******************
	printf("\nLista despues de remover al elemento 5 de la lista si existe");
	ImprimeLista(&mi_lista);


	//Remplazar a un elemento con el caracter 'T' si existe
	e.c='T';
	//e.n=0;
	aux=Search(&mi_lista,e);
	if(ValidatePosition(&mi_lista,aux))
	{
		e.c='t';
		Replace(&mi_lista,aux,e);
	}

	//Ver la lista**********
	//Lista despues de remplazar al elemento con un char 'T' de la lista si existe
	ImprimeLista(&mi_lista);

	Destroy(&mi_lista);
	ImprimeLista(&mi_lista);

	return 0;
}


//DEFINICIÓN DE FUNCIONES

//Función para imprimir el elemento de la lista con base en mi estructura elemento
void ImprimeLista(lista *l)
{
	posicion p;
	elemento e;
	int i,num_elem;
	num_elem=Size(l);

	if(num_elem>0)
	{
		//Mientras la posición sea valida
		for(i=1;i<=num_elem;i++)
		{
			e=Element(l,i);
			printf("\nElemento %d\t%c",i,e.c);
		}
	}
	else
	{
		printf("\nLista Vacia\n");
	}
	return;
}
