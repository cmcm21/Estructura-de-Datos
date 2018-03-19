/*Libreria: cabecera de TADcolacircular
 Author: Carlos Miguel Correa Medina
 version: 1.0

 Descripción: Estrcutura de datos cola.
 En esta estructura se cumple que el primero que entra
 es el primero en salir.

 Observaciones: La estructura se implementa de forma estaica,
 mediante un arreglo, se visualiza a este como un circulo
 de ahí el nombre de cola circular
 */

#include <stdlib.h>
#include <stdio.h>

#define MAXTAM 100
/*constantes simbolicas*/
#define TRUE	1
#define FALSE	0

typedef unsigned char boolean;

/*declaro mi tipo de elemento*/
typedef struct elemento
{
	char c;
	int n;
	float f;
}elemento;
/*declaro mi tipo de dato pila*/
typedef struct cola
{
	elemento arreglo[MAXTAM];
	int frente;
	int fin;
	int tam;
}cola;

/*DECLARACIÓN DE FUNCIONES*/
void Initialize(cola *s);	/*Inicializar pila (Iniciar una pila para su uso*/
void Queue(cola *s, elemento e);/*Encolar (Introducir un elemento a la cola)*/
elemento Unpack (cola *s);/*Desencolar (Extraer el elemento del frente de la cola)*/
boolean Empty(cola s);	/*Vacia (Preguntar si la cola esta vacia)*/
boolean Full (cola s); /*me verifica si la cola esta llena*/
elemento Front(cola s);	/*Front (Obtener el "elemento" del frente de la cola)*/
int Size(cola *s);	   /*Tamaño de la cola (Obtener el número de elementos en la cola)*/
int Next(int n); /*retorna el siguiente espacio en el arreglo de final*/
