/*
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2012
VERSIÓN: 1.3

DESCRIPCIÓN: Ejemplo de la aplicación de la pila, 
el cuál resuelve el problema de la evaluacione de los 
parentesis escritos de manera correcta en una expresión.

OBSERVACIONES: Se emplea la libreria TADPilaDin.h o TADPilaEst.h implementadas
en clase. Ambas estructuras elemento, ya sea la de la implementación estática o dinámica deberán tener un campo char c;

COMPILACIÓN: 	Si se tiene el objeto de la implementación
				gcc EvaluaParentesis.c TADPila(Din|Est).o -o EvaluaParentesis
				
				Si se tiene el fuente de la implementación
				gcc EvaluaParentesis.c TADPila(Din|Est).c -o EvaluaParentesis

EJECUCIÓN: EvaluaParentesis.exe (En Windows) - ./EvaluaParentesis (En Linux)
*/

//LIBRERAS
#include <stdio.h>
#include <stdlib.h>	//Para usar exit()
#include <string.h> //Para usar strlen()
//#include "TADPila/TADPilaEst.h" //Inclusión de la libreria del TAD Pila Estática (Si se desea usar una pila estática)
#include "TADPilaDin.h" //Inclusión de la libreria del TAD Pila Dinámica (Si se desea usar una pila dinámica)

//DEFINICIONES

//PROGRAMA PRINCIPAL
int main(void)
{
	int num,i;	
	pila mi_pila;
	elemento e1;	

	Initialize(&mi_pila);
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		Push(&mi_pila,e1);
	}
	
	printf("\nTamaño: %d",Size(&mi_pila));
		
	//Destruir los elementos de la pila
	Destroy(&mi_pila);	

	exit(0); //Terminar el programa sin errores
}

