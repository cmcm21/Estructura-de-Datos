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
#define TAM_CADENA 100 //Tamaño maximo de la cadena a evaluar considerando el '\0'

//PROGRAMA PRINCIPAL
int main(void)
{
	int tam_cadena;
	int i,j;
	char cadena[TAM_CADENA];
	
	//Se declara una pila "mi_pila"
	pila mi_pila;
	//Declaro un elemento "e1"
	elemento e1;	
	//Inicialización de "mi_pila"
	Initialize(&mi_pila);
	
	//Leer cadena a evaluar sus parentesis
	scanf("%s",cadena);
	
	//Medir el tamaño de la cadena
	tam_cadena=strlen(cadena);
	
	//Recorrer cada caracter de la cadena 
	for(i=0;i<tam_cadena;i++)
	{
		//Si el caracter es ( introducirlo a la pila
		if(cadena[i]=='(')
			{
				e1.c='(';
				Push(&mi_pila,e1);
			}
		
		//Si el caracter es ) realizar un Pop a la pila		
		else if(cadena[i]==')')
			{
				//Si se intenta extraer un elemento y la pila es vacia Error: P.g. (a+b)*c)
				if(Empty(&mi_pila))
				{
					printf("ERROR: Existen mas parentesis que cierran de los que abren");
					exit(1); //Salir del programa con error
				}
				e1=Pop(&mi_pila);
			}
	}
	
	//Si al terminar de revisar la expresión aún hay elementos en la pila Error: P.g. (a+b)*c(a-c
	if(!Empty(&mi_pila))
	{
		printf("ERROR: Existen mas parentesis que abren de los que cierran");
		exit(1); //Salir del programa con error
	}
	
	//Si la ejecución termina de manera correcta
	printf("EXCELENTE: Expresion correcta");
	
	//Destruir los elementos de la pila
	Destroy(&mi_pila);	
	exit(0); //Terminar el programa sin errores
}

