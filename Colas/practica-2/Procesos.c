/*autor: Correa Medina Carlos Miguel. 26 de Septiembre del 2017.
 Version: 1.3.
 Descripción: Simulación de precesos de un monoprocesador(un proceso a la vez).
 Cada sierto tiemo X se realizará un proceso en la cola "ejecución" y este cambiara 
 de cola a "terminado", si el proceso esta en espera, se tendra en la cola "lista".
 Compilación: gcc Procesos.c TADColaEst.c -o cola / gcc Procesos.c TADColaDin.c -o cola
 Ejecución: ./cola (linux) para que funcione con windows se tiene que cambiar libreria unistd 
 por windows y cambiar las funciones usleep por sleep.
 */
#include <stdio.h>
#include "TADColaEst.h"
#include <stdlib.h>
#include <unistd.h>/*libreria no ansi c para ocupar sleep en linux*/

typedef struct sistema
{
	//Variables de la estructura
    char nombre[45];
	char actividad[100];
	char ID[45];
	int tiempo_listo;
	int tiempo_ejec;
	int tiempo_total;

} sistema;

int main (void)
{
	cola lista; 
	cola terminado;
	sistema procesos[10];
	elemento aux,aux2;
	int num_pros;
	int tiempo = 0;
	int i,j,k;

	system("clear");

	printf("%s\n","Introduzca la canditad de procesos que se realizaran");
	scanf("%d",&num_pros);
	/*se reserva memoria para la variable procesos y timepo_pros segun el num_pros 
	que existan*/

	/*se piden los datos de cada proceso*/
	for (i = 0; i < num_pros; ++i)
	{

		system("clear");

		printf("Escriba el nombre proceso %d \n", i + 1);
		scanf("%*c%[^\n]",procesos[i].nombre);

		printf("Escriba la actividad proceso %d\n", i + 1);
		scanf("%*c%[^\n]",procesos[i].actividad);

		printf("Escriba el ID proceso %d\n", i + 1);
		scanf("%*c%[^\n]",procesos[i].ID);

		printf("Escriba el tiempo proceso %d (segundos)\n", i+1);
		scanf("%d",&procesos[i].tiempo_listo);
	}
	/*inicialización de la colas con la que se trabajaran, no vi necesario trabajar con una cola
	de ejecutar, a como entendi el problema en ejecutar siempre habra solo un elemento*/
    Initialize(&lista);
    Initialize(&terminado);
    /*encolo los procesos en lista*/
    for(k = 0; k < num_pros; k++)
    {
    	procesos[k].tiempo_ejec = 0;
	    procesos[k].tiempo_total = 0;
    	aux.n = k;
    	Queue(&lista,aux);
    }

    system("clear");

    k=0;/*contador que servirá para condicionar*/

	/*ciclo que se repite hasta que la cola lista este vacia*/
    while(Size(&lista) != 0)
    {
    	sleep(1);/*pausa de 1 segundo para la ejecución*/
  
    	aux2 = Dequeue(&lista);	/*desencolo de la lista con la ayuda de un axuliar*/
    	/**imprimo los dato de el proceso que se desencolo*/
    	printf("  \nProceso:%s     ",procesos[aux2.n].nombre);
	    printf("  Actividad:%s   ",procesos[aux2.n].actividad);
	    printf("  ID:%s     ",procesos[aux2.n].ID);
	    procesos[aux2.n].tiempo_ejec++; /*aumento el tiempo de ejecución del proceso desencolado*/
	    printf("  Tiempo ejecutandose:%ds\n",procesos[aux2.n].tiempo_ejec);
	    procesos[aux2.n].tiempo_total++;/*incremento el tiempo total que en realidad no es el total*/
	    procesos[aux2.n].tiempo_listo--; /*reduzco el tiempo de listo del proceso desencolado*/

	    /*si la cola lista no esta vacia y no es el primer elemento desencolado, saco el final
	    de la lista, que es el elemento que se ejecutó anteriormente*/
	    if (!Empty(&lista) && k != 0)
	    {
	    	aux = Final(&lista);
	    	printf("  Anterior:%s    ",procesos[aux.n].nombre);
	    	printf("  ID:%s    ", procesos[aux.n].ID);
	    	printf("  Tiempo para terminar:%ds\n",procesos[aux.n].tiempo_listo);
	    }
	    /*si la cola lista no esta vacia saco el frente de la cola el cual será el siguiente
	    elemento que se ejecutara*/
	     if(!Empty(&lista))
	    {
	    	aux = Front(&lista);
	    	printf("  Siguiente:%s    ",procesos[aux.n].nombre);
	    	printf("  ID:%s    ", procesos[aux.n].ID);
	    	printf("  Tiempo para terminar:%ds\n",procesos[aux.n].tiempo_listo);

	    }

	    /*si el tiempo listo del proceso es mayor a cero, este proceso aun no termina y se vuelve
	    a encolar*/
	    if(procesos[aux2.n].tiempo_listo > 0)	
	    	Queue(&lista,aux2);
	    /*en el caso contrario, el proceso ya finalizó, y se encola en terminados*/
    	else
    		Queue(&terminado,aux2);

    	k++;/*contador para detectar si el elemento en ejecucion es el primero que se ejecuta*/
    }/*termina ciclo while*/
	
	/*ciclo que sirve para imprimir la cola de termidados, la cual esta en orden segun
	el tiempo de listo del proceso*/
	for(j = 0;j < num_pros; j++)
	{
		aux2 = Dequeue(&terminado);/*desencolo de la cola terminados con la ayuda de un axuliar*/
		printf("\n  El proceso:%s ha terminado    ",procesos[aux2.n].nombre);
		printf("  ID:%s    ",procesos[aux2.n].ID);
    	printf("  Tiempo total:%ds", procesos[aux2.n].tiempo_ejec + procesos[aux2.n].tiempo_total);
	}	

	printf("\n%s\n","   **********TODOS LOS PROCESOS HAN TERMINADO***********\n\n");

	return 0;
}
