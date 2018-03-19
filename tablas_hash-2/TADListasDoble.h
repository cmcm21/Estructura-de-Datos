/*
IMPLEMENTACIONES DEL TAD LISTA (TADListaDoble.h)
AUTOR: Correa Medina Carlos Miguel
VERSIÓN: 1.0

DESCRIPCIÓN: TAD lista enlazada
Estructura de datos en la que se cumple:
los elemenos se pueden agregar al final o al inicio o en cualquier parte de la lista,
los nodos de los elementos hacen referencia tanto a su anterior como a su siguiente

OBSERVACIONES: Este archivo solo incluye las estructuras, tipos de datos y
declaración de las operaciones del TAD  Lista enlazada.

EL CODIGO QUE IMPLEMENTA LAS FUNCIONES ES EL ARCHIVO: TADListaDoble.c
*/
#define TRUE 1
#define FALSE 0

typedef unsigned int boolean; /*representacion de booleano*/

/*componentes de un elemnto*/
typedef struct elemento
{
 	char p[50];   /*palabras*/
 	char d[251]; /*Definición*/
}elemento;

/*componentes de un nodo de lista doblemente ligada*/
typedef struct nodo
{
	elemento e;      /*elemento que contiene el nodo*/
	struct nodo *siguiente; /*refrencia al siguiente nodo*/
	struct nodo *anterior;  /*referencia al nodo anterior*/
}nodo;

/*una posicion es un puntero a nodo*/
typedef nodo* posicion;

/*elemnto que tiene una lista*/
typedef struct lista
{
	posicion final; /*final de lista*/
	posicion inicio; /*inicio de lista*/
	int tam;
}lista;

//Operaciones de construcción
void Initialize(lista *l);
void Destroy(lista *l);
//Operaciones de posicionamiento y busqueda
posicion Final(lista *l);
posicion First(lista *l);
posicion Following(lista *l, posicion p);
posicion Previous(lista *l, posicion p);
posicion Search(lista *l, elemento e);
//Operación de consulta
elemento Position(lista *l, posicion p);
boolean ValidatePosition(lista *l, posicion p);
elemento Element(lista *l, int n);
posicion ElementPosition(lista *l, int n);
int Size(lista *l);
boolean Empty(lista *l);
//Operaciones de modificación
void Add(lista *l,elemento e);
void Insert(lista *l, elemento e, posicion p,boolean b);
void Remove(lista *l,posicion p);
void Replace(lista *l,posicion p, elemento e);
void ImprimeLista(lista *l);


