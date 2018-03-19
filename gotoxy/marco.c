/* Autor: Edgardo Adrián Franco Martínez
Versión 1.0 (11 de Septiembre 2012)
Descripción: Programa que dibuja un bloque de "*" cuadrado de ANCHO * ALTO en la
consola

El programa imprime ALTO filas de *'s columna por columna hasta la columna
ANCHO.

Observaciones: El programa requerira de la libreria "presentacion.h", la cuál
tiene las implementaciones
para mover el cursor de la pantalla, esperar un tiempo y borrar pantalla, la
compilación debera incluir
las definiciones de las funciones según la plataforma que se este utilizando
(Windows o Linux)

Compilación: 	gcc -o marco marco.c presentacion(Win|Lin).o) (Win si se correra
en Windows | Lin si se ejecutará en Linux)  "Si se tiene el código objeto"
				gcc -o marco marco.c presentacion(Win|Lin).c) (Win si se correra
en Windows | Lin si se ejecutará en Linux)  "Si se tiene el código fuente"
Ejecución: Windows marco.exe  &  Linux ./marco
*/
//LIBRERIAS
#include<stdio.h>
#include "presentacion.h"

//CONSTANTES
#define ALTO 24 //Se piensa en un pantalla de 24 filas x 79 columnas
#define ANCHO 79

#define TIEMPO_BASE 60 //Tiempo base en milisegundos

//PROGRAMA PRINCIPAL
main (void)
{
	int fila,columna;
	//Borrar la pantalla
	BorrarPantalla();

	//Recorrer cada columna
	for(columna=1;columna<ANCHO;columna++)
	{
		//Recorrer cada fila
		for(fila=1;fila<ALTO;fila++)
		{
			//Mover el cursor, dibujar un * y esperar TIEMPO_BASE milisegundos
			MoverCursor(columna,fila);
			printf("*");
			EsperarMiliSeg(TIEMPO_BASE);
		};
	};
	return 0;
}
