/*
 * IMPLEMENTACIONES DE LA LIBRERIA DEL TAD COLA ESTÁTICA (colacircular.h)
 * AUTOR: Correa Medina Carlos Miguel
 * VERSIÓN: 1.0
 *
 * DESCRIPCIÓN: TAD cola o Queue.
 * Estructura de datos en la que se cumple:
 * Los elementos se añaden y se remueven por un solo extremo.
 * Este extremo es llamado “Frente” de la cola.
 *
 * OBSERVACIONES: Hablamos de una Estructura de datos estática cuando se le
 * asigna una cantidad fija de memoria para esa estructura
 * antes de la ejecución del programa.
 *
 * COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc -c colacircular.c
 */

/*librerias*/
#include "colacircular.h"
#include <stdio.h>
#define MAX 100

/*
int Next (int n);
Descripción: me ayuda a tener al elemento siguiente de final
Recibe: un entero n
Devuelve: un entero de la posicion siguiente de final
Observaciones: El usuario a creado una cola y talvez ocupe al siguiente
del final
*/
int Next(int n)
{
	return (n+1) % MAX;
}

/*
void Initialize(cola *s);
Descripción: Inicializar cola (Iniciar una cola para su uso) 
Recibe: cola *s (Referencia a la cola "s" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(cola *s)
{
	s->frente = 0;
	s->fin = MAX-1;
	s->tam = 0;
	return;
}
/*
void Queue(cola *s, elemento e);
Descripción: encolar (Introducir un elemento a la cola)
Recibe: cola *s (Referencia a la cola "s" a operar), elemento e (Elemento a introducir en la cola)
Devuelve:
Observaciones: Antes de que comience el proceso de inserción, el índice fin apunta al último
insertado; éste avanza circularmente y se sitúa el nuevo elemento.
*/
void Queue(cola *s, elemento e)
{
	if(Full(*s))
	{
		printf("%s\n","Desbordamiento de cola" );
		exit(1);
	}

	s -> fin = Next(s -> fin);
	s -> arreglo[s -> fin] = e;
	s->tam++;
}
/*elemento Unpack (cola *s);
Descripción: desencolar (saca un elemento de la cola).
Recibe: cola *s (Referencia a la cola "s" a operar).
Devuelve:una variable de tipo elemento que es el anterior frente de la cola
Observaciones: Esta operación retira el elemento del frente de la cola que, además,
es el resultado de la operación.
El índice frente avanza circularmente
*/
elemento Unpack (cola *s)
{
	elemento e;

	if(Empty(*s))
	{
		printf("%s\n","Subdesbordamiento de cola" );
		exit(1);
	}

	e = s -> arreglo[s->frente];
	/*frente avanza circularmente*/
	s->tam--;

	s -> frente = Next(s -> frente);
	return e;
}
/*elemento Front(cola s);	
Descripción: obtener el elemento de en frente de la cola sin modificar cola
Recibe: cola s (valor de la cola "s" a operar).
Devuelve:elemento que es el frente de la cola
Observaciones: Se pasa una copia de la cola, para que esta no se modifique
el elemento frente no se saca de la cola
*/
elemento Front(cola s)
{
	if(Empty(s))
	{
		printf("%s\n", "Se requiere el frente de una cola vacia");
		exit(1);
	}
	return s.arreglo[s.frente];
}
/*boolean Empty(cola s)
Descripción: Esta operación verifica el estado de la cola y prueba si
la cola no tiene elementos
Recibe: cola s (valor de la cola "s" a operar).
Devuelve:booleano
Observaciones: Se pasa una copia de la cola, para que esta no se modifique
*/
boolean Empty(cola s)
{ 
	return s.frente == Next(s.fin);
}
/*boolean Full (cola s);
Descripción: Esta operación verifica si la cola no puede contener mas elemento
Recibe: cola s (valor de la cola "s" a operar).
Devuelve:booleano
Observaciones: En el arreglo queda un posición no ocupada, y así se distingue
de la condición de cola vacía
*/
boolean Full (cola s)
{
	return s.frente == Next(Next(s.frente));
}
/*int Size(cola *s);
Descripción: Esta operación retorna el numero de elementos en la pila
Recibe: cola *s (referencia a la cola "s" a operar).
Devuelve:entero
Observaciones: devuelve la variable entera tam que se incrementa cada
que se encola un elemento
*/
int Size(cola *s)
{
	return s->tam;
}
