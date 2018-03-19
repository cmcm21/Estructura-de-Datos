/* 
AUTOR: "Los romancitos" septiembre 2017
VERSION: 1.3

DESCRIPCION:Ejemplo de atencion de 4 colas de clientes, simulacion de tiempo se realiza con la funcion sleep, cada x tiempo de llegada 
de un cliente se escoge pseudoaleatoriemente una cola y el tiempo de atencion es y.

OBSERVACIONES:Se puede emplear la libreria TADColaEst.h, TADPilaEstCir.h o TADColaDin.h implementadas
en clase. Ambas estructuras elemento, ya sea la de las implementaciónes estáticas o dinámica deberán 
tener un campo int n;

COMPILACIÓN: 	gcc -o simulacion simulacion.c TADCola/TADCola(Din|Est|EstCirc).o (Si se tiene el objeto de la implementación)
				gcc -o Cajeras Cajeras.c TADCola/TADCola(Din|Est|EstCirc).c (Si se tiene el fuente de la implementación)

EJECUCIÓN: ./simulacion

*/

//librerias
#include <stdio.h> //para el printf
#include <ncurses.h> //libreria para la simulación
#include <stdlib.h> //libreria para el malloc y srand
#include <unistd.h> //para la funcion usleep
#include "TADColaEst.h" //Segun la implementacion que usemos

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE 100000 //Tiempo base en micros
#define TIEMPO_CLIENTE 2 //tiempo base en micros * 2
#define TIEMPO_CAJA_1 3 //Tiempo base en micros * 3
#define TIEMPO_CAJA_2 4 //Tiempo base en micros * 4
#define TIEMPO_CAJA_3 5 //Tiempo base en micros * 5
#define TIEMPO_CAJA_4 6 //Tiempo base en micros * 6

int main (void)
{
	unsigned int tiempo=0;
	unsigned int cliente=0;
	int i,fila;
	elemento e;
	//Inicializar la funcion rand	
	srand(time(NULL));
	
	//Crear 4 colas
	cola cajera[5];

	//Inicializar las colas 
	Initialize(&cajera[0]);
	Initialize(&cajera[1]);
	Initialize(&cajera[2]);
	Initialize(&cajera[3]);
	Initialize(&cajera[4]);
	
	//Ciclo hasta tener 100 clientes
	while(cliente<=100)
	{
		usleep(TIEMPO_BASE); //Esperar tiempo base
		tiempo++; //incrementar el tiempo

		//Si el tiempo es multiplo de TIEMPO_CAJA_1
		if(tiempo % TIEMPO_CAJA_1 ==0)
		{
			//Cajera 0
			if (!Empty(&cajera[0]))
			{
				e = Dequeue(&cajera[0]);
				printf("\n\n\nAtendi a: %d en caja 0", e.n);
			}
			else
			{
				printf("\n\n\nNo hay alguien por atender en caja 0");
			}
		}
		//Si el tiempo es multiplo de TIEMPO_CAJA_2
		if(tiempo % TIEMPO_CAJA_2 ==0)
		{	
			//Cajera 1
			if (!Empty(&cajera[1]))
			{
				e = Dequeue(&cajera[1]);
				printf("\n\n\nAtendi a: %d en caja 1", e.n);
			}
			else
			{
				printf("\n\n\nNo hay alguien por atender en caja 1");
			}

		}

		//Si el tiempo es multiplo de TIEMPO_CAJA_3
		if(tiempo % TIEMPO_CAJA_3 ==0)
		{
			//Cajera 2
			if (!Empty(&cajera[2]))


			{
				e = Dequeue(&cajera[2]);
				printf("\n\n\nAtendi a: %d en caja 2", e.n);
			}
			else
			{
				printf("\n\n\nNo hay alguien por atender en caja 2");
			}
		}
		//Si el tiempo es multiplo de TIEMPO_CAJA_4
		if(tiempo % TIEMPO_CAJA_4 ==0)			
		{
			//Cajera 3
			if (!Empty(&cajera[3]))
			{
				e = Dequeue(&cajera[3]);
				printf("\n\n\nAtendi a: %d en caja 3", e.n);
			}
			else
			{
				printf("\n\n\nNo hay alguien por atender en caja 3");
			}
		}

		
		//Si el tiempo es multiplo del de llegada de los clientes
		if (tiempo % TIEMPO_CLIENTE == 0)
		{
			cliente++;				//Incrementar el numero de clientes
			e.n = cliente;			//Dar el numero que identifica al cliente
			fila=rand()%4;	//Escoger la fila para formarse aleatoriamente 					
			Queue(&cajera[fila], e);//Formarse en la fila seleccionada
			printf("\n\n\nLlego el cliente: %d a la cola de la caja %d \n", e.n,fila);
		}
		
		//imprimir encabezados
		printf("ESCOMmarket \n"); //nombre del supermercado
		printf("4 \n"); //numero de cajeras
		printf("300\n400\n500\n600\n"); //tiempo que tardan en atender en ms
		printf("200 \n"); //tiempo que tarda en llegar el cliente en ms
		
		//Mostrar los clientes en cada cola
		printf("\n\n%d clientes en cola 0: [",Size(&cajera[0]));
		for (i=1;i<=Size(&cajera[0]);i++)
		{
			e=Element(&cajera[0],i);
			printf("%d\t", e.n);
		}
		printf("]");
		
		
		printf("\n\n%d clientes en cola 1: [",Size(&cajera[1]));
		for (i=1;i<=Size(&cajera[1]);i++)
		{
			e=Element(&cajera[1],i);
			printf("%d\t", e.n);
		}
		printf("]");


		printf("\n\n%d clientes en cola 2: [",Size(&cajera[2]));
		for (i=1;i<=Size(&cajera[2]);i++)
		{
			e=Element(&cajera[2],i);
			printf("%d\t", e.n);
		}
		printf("]");


		printf("\n\n%d clientes en cola 3: [",Size(&cajera[3]));
		for (i=1;i<=Size(&cajera[3]);i++)
		{
			e=Element(&cajera[3],i);
			printf("%d\t", e.n);
		}
		printf("]");

	}
	return 0;
}
