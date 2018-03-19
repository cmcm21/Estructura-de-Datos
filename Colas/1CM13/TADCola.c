/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD COLA ESTATICA (TADColaEst.h)
AUTOR: Edgardo Adrián Franco Martínez (C) XXXXXXX AÑOXXXX
VERSIÓN: XXXX.XXXX

DESCRIPCIÓN: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c TADColaDin.c
*/

//LIBRERAS
#include "TADColaDin.h"
#include <stdio.h>
#include <stdlib.h>

/*
void Initialize(cola *c);
Descripción: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(cola * c)
{

	return;
}

/*
void Queue(cola * c, elemento e);
Descripción: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Queue(cola * c, elemento e)
{

	return;
}

/*
elemento Dequeue(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al 
frente de esta, quitándolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado una cola y la cola tiene elementos, si no 
se genera un error y se termina el programa.
*/
elemento Dequeue(cola * c)
{
	elemento e;	//Elemento a retornar
	
	
	//Retornar al elemento desencolado
	return e;
}


/*
boolean Empty(cola * c);
Descripción: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada
*/
boolean Empty(cola * c)
{
	boolean b;	//Booleano a retorna	
	
	//Retornar booeleano
	return b;
}

/*
elemento Front(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Front(cola * c)
{
	elemento e;	//Elemento a retornar
	
	
	//Retornar al elemento del frente
	return e;
}

/*
elemento Final(cola * c);
Descripción: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Final(cola * c)
{
	elemento e;	//Elemento a retornar
	
	
	//Retornar al elemento del final
	return e;
}

/*
int Size(cola * c);
Descripción: Recibe una cola y devuelve el número de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tamaño de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
*No se modifica el TAD
*/
int Size(cola * c)
{
	int n;	//Entero para almacenar el tamaño
	
	
	//Retornar a n
	return n;
}

/*
void Element(cola * c, int i);
Descripción: Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición.
Devuelve: elemento en la posicion i de la cola
Observaciones: El número i debera estar entre 1 y el tamaño de la cola, si esta es vacia o mas pequeña se provoca un error.
*/
elemento Element(cola * c, int i)
{
	elemento e;	//Elemento a retornar
	
	
	//Retornar al elemento desencolado
	return e;
}

/*
void Destroy(cola * c);
Descripción: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.
*/
void Destroy(cola * c)
{
	
	return;
}
