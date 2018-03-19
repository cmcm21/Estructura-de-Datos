/*
LIBRERIA: Cabecera de el TAD PILA DINÁMICA
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2016
VERSIÓN: 1.0

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos DINÁMICA cuando se le 
asigna una cantidad de memoria dinámica para esa estructura 
durante la ejecución del programa. 
*/

//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	char c;
	float f;
	//***
	//***
	//***
}elemento;

typedef struct nodo
{
	elemento e;
	struct nodo *abajo;
}nodo;


//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila
{		
	nodo * tope; 	
	//El tope es un entero (Indice del arreglo de elementos)
	int tam;
}pila;

//DECLARACIÓN DE FUNCIONES
void Initialize(pila *s);			//Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e);		//Empilar (Introducir un elemento a la pila)
elemento Pop (pila *s);				//Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s);				//Vacia (Preguntar si la pila esta vacia)
elemento Top(pila *s);				//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
int Size(pila *s);					//Tamaño de la pila (Obtener el número de elementos en la pila)
void Destroy(pila *s);				//Elimina pila (Borra a todos los elementos y a la pila de memoria)
