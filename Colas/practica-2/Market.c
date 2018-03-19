/*autor: Correa Medina Carlos Miguel. 15 Septiembre del 2017.
 Version: 1.0.
 Descripción: Simulación de un mercado en el que se utilizara una cola ya sea estática,
 estática circular o dinámica. La simulación se realizara de forma gráfica con ayuda de funciones
 de ncurses.
 Cada X tiempo llegara un cliente a la tienda,y cierto tiempo Y sera atendido,hasta que 
 se atiendan 100 clientes y no haya ningun cliente en alguna caja, se puede cerrar la tienda.
 Compilación: gcc Market.c TADColaEst.c -o cola / gcc Market.c TADColaDin.c -o cola
 Ejecución: ./cola (linux) para que funcione con windows se tiene que cambiar libreria unistd 
 por windows y cambiar las funciones usleep por sleep,aparte,el TIEMPO_BASE se tiene que
 dividir entre 1000 y en vez de ncurses,usar winsows con sus respectivas funciones.
 */
 #include <stdio.h>
 #include <unistd.h> /*libreria no ansi c que se ocupa para el usleep*/
 #include "TADColaEst.h"
 #include <stdlib.h> /*para ocupar system Y random*/

 #define MAX 100 
 #define CAJAS 9
 #define TIEMPO_BASE 100000 /*10 ms*/
 #define TRUE 1
 #define FALSE 0
 
 int main ()
 {
 	char nombre[MAX];
 	cola cajeras[MAX];
 	int time_caja[MAX];
 	int time_cliente;
 	int cliente = 0;
 	int tiempo1 = 0;
 	int tiempo2 = 0;
 	int i,j,k;
 	int num_cajas;
 	elemento aux;
 	boolean bandera2 = TRUE;

 	system("clear");

 	printf("%s\n","Introduzca el nombre de la tienda: " );
 	scanf("%s",nombre);

 	printf("%s\n","Introduzca el numero de cajas:\n(Maximo 9 cajas)" );
 	scanf("%d",&num_cajas);

 	/*con el numero de cajas se solicita el espacio para las variables de cada caja
	cajeras=malloc(num_cajas*sizeof(cola));
	time_caja=malloc(num_cajas*sizeof(int));
	*/
 	for(i=0;i<num_cajas;i++)
 	{
 		printf("Introduzca el tiempo en atender de la caja[%d] \n",i+1);
 		scanf("%d",&time_caja[i]);
 		time_caja[i] = (time_caja[i]/10);
 		Initialize(&cajeras[i]);
 	}

 	printf("%s\n","Introduzca el tiempo en el que llegan los clientes");
 	scanf("%d",&time_cliente);
 	time_cliente = time_cliente/10;

 	srand(time(NULL));

 	while( cliente < 101)
 	{
 		usleep(TIEMPO_BASE);
 		tiempo1++;

 		j = rand() % (num_cajas);


 		if(time_caja[j] % tiempo1 == 0)
 		{	
 			if (!Empty(&cajeras[j]))
			{
				aux = Dequeue(&cajeras[j]);
				printf("\nAtendi a: %d en caja %d",aux.n,j+1);
			}
			//Si la cola es vacia
			else
			{
				printf("\nNo hay alguien por atender");
			}
 		
		}

		if (tiempo1 % time_cliente == 0)
 		{
			cliente++;			//Incrementar el numero de clientes que se ha formado
			aux.n = cliente;		//Introducir el numero del cliente en un elemento
			Queue(&cajeras[j],aux);	//Encolar al nuevo cliente
			printf("\nLlego el cliente: %d",aux.n);	
			printf("\nEl cliente %d se formo en la caja %d\n",aux.n,j+1);
			tiempo1 = 0;
 		}

 	}
 	printf("Atendi a: %d en caja: %d\n",cliente,j+1);
 	printf("\n%s\n","YA ESTA CERRADO CARNAL, LLEGA MAS TEMPRA :(" );

    return 0;
 }
/*
boolean Gerente(cola cajas[],int numcajas)
{
	int i;
	int j = TRUE;
	int k = 0;
	for (i = 0; i <numcajas ; i++)
	{
		if(Empty(&cajas[i]))
			k++;
	}
	if(k+1 == numcajas)
		j = FALSE;
	return j;
}*/

