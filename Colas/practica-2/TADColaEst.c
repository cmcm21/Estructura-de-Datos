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
#include "TADColaEst.h"
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
	c->frente=-1;
	c->final=-1;
	c->num_elem=0;
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
	if (Empty (c))
	{
		c->frente=0;
		c->final=0;
	}
	else
	{
		c->final++;
	}
	if(c->final>=MAX_ELEMENT)
	{
		printf ("ERROR: Desbordamiento de cola");
		
		exit (1);
	}
	c->elementos[c->final]=e;
	c->num_elem++;
	
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
	int i;
	if(Empty(c))
	{
		printf("\n\tERROR: Subdesbordamiento de cola\n");
		exit(1);
	}
	e = c -> elementos[c -> frente];
	if(c -> num_elem == 1)
	{
		c -> frente = -1;
		c -> final = -1;
	}
	else
	{
		for(i = 0; i <= c -> num_elem -1; i++)
		{
			c -> elementos[i] = c -> elementos[i + 1];
		}
		c->final--;
	}
	c -> num_elem--;
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
	if(c->num_elem==0)
		b=TRUE;
	else
		b=FALSE;
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
	if(Empty(c))
	{
		printf("ERROR: Cola vacia. Operacion Front invalida");
		exit(1);
	}
	e = c->elementos[c->frente];
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
	if(Empty(c))
	{
		printf("ERROR: Cola vacia. Operacion Final invalida");
		exit(1);
	}
	e = c->elementos[c->final];
	
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
	
	n = c-> num_elem;
	
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
	if(!(i>0 && i<=c->num_elem))
	{
		printf("ERROR: Indice i fuera del rango. Operacion Element invalida");
		exit(1);
	}
	else
	{
		e=c->elementos[i+1];
	}
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
	Initialize(c);
	return;
}
