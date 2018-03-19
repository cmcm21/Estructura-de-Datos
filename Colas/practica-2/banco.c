/*Autor: Correa Medina Carlos Miguel. 30 de Septiembre del 2017.
 Version: 1.0.
 Descripción: Simulación de un banco con prioridades.
 Cada sierto tiempo llegar un cliente, este puede ser, cliente de preferencia, cliente, o
 alguien que no tiene cuenta en el banco 
 Compilación: gcc banco.c TADColaEst.c -o banco / gcc banco.c TADColaDin.c -o banco
 Ejecución: ./cola (linux) para que funcione con windows se tiene que cambiar libreria unistd 
 por windows y cambiar las funciones usleep por sleep,aparte,el TIEMPO_BASE se tiene que
 dividir entre 1000.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <curses.h>
 #include "TADColaEst.h"

 #define TIEMPO_BASE 100000
 #define MAX 9
 #define LIBRE 0
 #define OCUPADO 1

 /*variable global para recorrer la fila en los gráficos*/
 int bandera = 0;

 /*estructura de datos que contiene los datos que son necesarios para cada cliente*/
 typedef struct clientes
 {
 	cola fila;
 	int num_cliente;
 	int tiempo;
 	int tiempo_contador;

 }clientes;


int disponible(char cajeras[],int num);
void Marco(void);
void salir(void);
void Formar(char cliente, int tipo,int numero);
void borrarfila(int tipo);
void atender(char cliente,int caje,int numero);

int main ()
{
   /*declaracion de estructuras que contienen los datos necesarios del cliente*/
	clientes preferentes;
	clientes usuarios;
	clientes normales; 
	elemento aux,aux2;

	int num_caj;
	int tiempo = 0;
	int tiempo_caj;
	char cajeras[MAX] = {0};
	int prioridad = 0;
	int i,j,k; /*contadores*/
	int prioridad_cliente = 0;
	int bandera;
	
	system("clear");

	printf("%s\n","Ingrese numero de cajeras que ocupara");
	scanf("%d",&num_caj);

	printf("Ingrese el tiempo de los cajeros:\n");
	scanf("%d",&tiempo_caj);

	printf("%s\n","Ingrese el tiempo de llegada de los usuarios:" );
	scanf("%d",&usuarios.tiempo);

	printf("%s\n","Ingrese el tiempo de llegada de los clietes:" );
	scanf("%d",&normales.tiempo);

	printf("%s\n","Ingrese el tiempo de llegada de los preferentes:" );
	scanf("%d",&preferentes.tiempo);

	/*inicializacion de las colas*/
	Initialize(&preferentes.fila);
	Initialize(&usuarios.fila);
	Initialize(&normales.fila);

	/*inicializar contadores de las estructuraras*/
	preferentes.tiempo_contador = 0;
	usuarios.tiempo_contador = 0;
	normales.tiempo_contador = 0;
	preferentes.num_cliente = 0;
	usuarios.num_cliente = 0;
	normales.num_cliente = 0;

	k=0;/*contador para manejar el tiempo de atencion de cada caja*/
	
	system("clear");
	Marco();

	while(1)
	{
		usleep(TIEMPO_BASE);
		/*estos condadores sirven para saber cada cuando se forman en la fila los clientes*/
		if(bandera == 0)
			tiempo++;
		
		preferentes.tiempo_contador++;
		normales.tiempo_contador++;
		usuarios.tiempo_contador++;
   	    /*si el tiempo del contador es igual al tiempo que tarada en llegar el cliente, estonces 
   	    se forma al cliente y se reinicia el contador la condicion es la misma en los tres if
   		con la diferencia de que es diferente tipo de cliente*/
		if(preferentes.tiempo_contador == preferentes.tiempo)
		{
			preferentes.num_cliente++;
			aux.n = preferentes.num_cliente;
			Queue(&preferentes.fila,aux);
			preferentes.tiempo_contador = 0;
			Formar('P',48,aux.n);
		}

		if(normales.tiempo_contador == normales.tiempo)
		{
			normales.num_cliente++;
			aux.n = normales.num_cliente;
			Queue(&normales.fila,aux);
			normales.tiempo_contador = 0;
			Formar('C',53,aux.n);
		}

		if(usuarios.tiempo_contador == usuarios.tiempo)
		{
			usuarios.num_cliente++;
			aux.n = usuarios.num_cliente;
			Queue(&usuarios.fila,aux);
			usuarios.tiempo_contador = 0;
			Formar('U',58,aux.n);
		}

		if (!Empty(&preferentes.fila) || !Empty(&normales.fila) || !Empty(&usuarios.fila))
		{
			bandera = 0;
			j = disponible(cajeras,num_caj);

			if (j >= 0) /*si la caja esta libre*/
			{
				if (prioridad < 5 && !Empty(&preferentes.fila) && prioridad_cliente == 0)
				{
					aux2 = Dequeue(&preferentes.fila);
					borrarfila(48);
					cajeras[j] = OCUPADO;
					atender('P',j,aux2.n);
					prioridad++;
					if(!Empty(&normales.fila))
						prioridad_cliente++;
				}
			    else if (prioridad < 5 && !Empty(&normales.fila))
				{
					aux2 = Dequeue(&normales.fila);
					borrarfila(53);
					cajeras[j] = OCUPADO;
					atender('C',j,aux2.n);
					prioridad++;
					prioridad_cliente = 0;
				}
				/*checar condicional*/
				else if (Empty(&normales.fila) && Empty(&preferentes.fila) && !Empty(&usuarios.fila))
				{
					aux2 = Dequeue(&usuarios.fila);
					borrarfila(58);
					cajeras[j] = OCUPADO;
					atender('U',j,aux2.n);
				}

				else if (prioridad == 5 && Empty(&usuarios.fila))
					prioridad = 0;

				else if (prioridad == 5 && !Empty(&usuarios.fila))
				{
					aux2 = Dequeue(&usuarios.fila);
					borrarfila(58);
					cajeras[j] = OCUPADO;
					atender('U',j,aux2.n);
					prioridad = 0;
				}
			}
			
		}	

		if (tiempo % tiempo_caj == 0) 
			{
				cajeras[k] = LIBRE;
				cajeras[k+1] = LIBRE;
				tiempo = 0;
				k++;
				if (k >= num_caj)
					k = 0;
			}
	}
	salir();
	return 0;
}
/**************************FIN DEL MAIN*******************************************/
/**/
int disponible(char cajeras[],int num)
{
	int dis = -1;
	int j;

	for (j = 0; j < num; j++)
	{
		if (cajeras[j] == LIBRE)
		{
			dis = j;
			break;
		}

	}
	return dis;
}

void Marco(void)
{
   void crearCajas(void);
   void crearfilas(void);
   
   int i;char c;
   initscr();   
   /*Esta función  inicializa  ncurses. Para todos los programas
                  debemos siempre inicializar  ncurses y luego finalizarla, como
                 veremos adelante.*/
   c='*';//caracter ascci horizontal
   for(i=0;i<=111;i++)
   {
      //linea horizontal inferior
      move(27,i);  //Aqui estamos moviendo el cursor para a linea 40 columna i.
      printw("%c",c);  //Imprimimos un  texto en la posición establecida.
   }
    //caracter ascci vertical
   for(i=0;i<=27;i++)
   {
      //linea vertical izquierda
      move(i,0);
      printw("%c",c);
      //linea vertical derecha
      move(i,111);
      printw("%c",c);
   }

   move(18,80);
   printw("BANCO BBUBA BANCOMECZ");

   crearCajas();
   crearfilas();

   refresh();
   return;
   
}

void salir()
{
   endwin(); /*Siempre que finalizamos un programa con una biblioteca curses,
                    debemos ejecutar este comando.*/
   exit(0);
}

void crearCajas(void)
{
   int i,j,k,h,m;
   
   h=14;
   m=8;

   for(k=0; k<9; k++)
   {
      for (i = m; i <= h ; ++i)
      {
         move(1,i);
         printw("%c",'+');

         move(6,i);
         printw("%c",'+');
      }
      	move(0,m);
        printw("caja %d",k+1);

        move(5,m+1);
        printw("(*U*)");

      for (j = 1; j <=6 ; ++j)
      {
         move(j,h);
         printw("%c",'+');

         move(j,m);
         printw("%c",'+');
      }
      h += 11;
      m += 11;
   }
   return;
}

void crearfilas(void)
{
   int i,j,k,h,c;

   c = 47;
   h = 52;

   for (int i = 0; i < 3; ++i)
   {
      for (j = 17; j < 27; ++j)
      {
         move(j,c);
         printw("%c",'|');

         move(j,h);
         printw("%c",'|');
      }
      c += 5;
      h += 5;
   }
   return;
}

void Formar(char cliente,int tipo,int numero)
{
	static int p = 16;
	static int c = 16;
	static int u = 16;
	int i,j;
    
    if(cliente == 'P')
    {
    	i=p;
    	p++;
    }
    	
    if(cliente == 'C')
    {
    	i=c;
    	c++;
    }
    if(cliente == 'U')
    {
    	i=u;
    	u++;
    }
	if(i < 27 && bandera < 1)
	{
		move(i,tipo);
		printw("%d%c", numero, cliente);
	}
	if (bandera  > 1 )
	{
		for (j = 0; j < numero; ++j)
		{
			move(16+j,tipo);
			if(16+j < 27)
				printw("%d%c", numero+j, cliente);
		}
	}

	refresh();
	return;
}

void borrarfila(int tipo)
{
	bandera++;
	move(16,tipo);
	printw("    ");
	return;
}
void atender(char cliente,int caje,int numero)
{
	move(7,(11*(caje+1)));

	printw("%d%c", numero,cliente);
	return;
}
