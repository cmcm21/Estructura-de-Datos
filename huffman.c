#include <stdlib.h>
#include <stdio.h>
#include "TADArbolBin.h"
#include "huffman.h"
#define TAM 255

/*RECIBE: el nombre del archivo
Devuelve:nada 
esta función se encarga de sacar las frecuencias de los simbolos de los archivos*/
void tablaFR(char nombre[])
{
	elemento temp; /*variable que sirve como auxiliar en el método burbuja*/
	elemento tabla[TAM]; /*si estan todos los simbolos*/
	double frecuencia[TAM] = {0}; /*si la frecuencia llega a ser muy elevada*/
	char aux;
	int k,i,j;
	FILE *ptra;

	if((ptra = fopen(nombre,"r")) != NULL)
	{
		while (!feof(ptra))
		{
			fread(&aux ,sizeof(char) ,1 ,ptra);
			++frecuencia[aux];
		}
		
		for (i = 0; i < TAM; ++i)
		{
			tabla[i].entero = frecuencia[i];
			tabla[i].c = (char)i;
		}
		/*metodo burbuja para ordenar los datos de menor a mayor*/
		for (i = 1;i < TAM;i++)
		{
       		for (j=0; j <= TAM-i ;j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
       		{
          		if (tabla[j].entero > tabla[j+1].entero)//Condicion mayor-menor
          		{
            		temp = tabla[j];
            		tabla[j] = tabla[j+1];
            		tabla[j+1] = temp;
          		}
       		}
		}
    }
    else
    {
    	printf("%s\n","no se puede abrir el archivo" );
    }
    fclose(ptra);
	CrearArbol(tabla);
	return;
}
/*RECIBE:tabla de frecuencia.
DEVUELVE:nada.
esta función se encarga de crear un arbol por cada simbolo diferente y los junta hasta que acomplete el arbol binario*/
void CrearArbol(elemento tablaFR[])
{
	arbol_bin hojas[TAM]; /*si se ocuparan todos los simbolos de ASCCI*/
	arbol_bin unir;
	boolean bandera;
	elemento temp,t1,t2;
	int subindices[255] = {0};
	int i,j,k; 			/*contadores*/
	posicion aux,p;    /*auxilares para tener una posicion*/
	int contador = 0; /*para saber cuando ya termine de unir todos los arboles*/
	int num_arboles;

	k = 0;
	for (j = 0; j < TAM; ++j)
	{
		if(tablaFR[j].entero != 0)
		{
			contador++;
			subindices[k] = j;
			k++;
		}		
	}
	i = 0;
	while(i < contador)
	{
		Initialize(&hojas[i]);
		NewRightSon(&hojas[i],aux,tablaFR[subindices[i]]);/*como el arbol esta vacio se convierte en raiz*/
		aux = Root(&hojas[i]);
		PreOrden(&hojas[i],aux);  
		i++;
	}
	
	while(!bandera)
	{
		Initialize(&unir);
		p = Root(&hojas[0]); /*obtengo la posicion de la hoja con menos peso*/
		t1 = ReadNode(&hojas[0],p); /*leeo el nodo hoja y lo guardo en t1*/
		
		p = Root(&hojas[1]); /*obtengo la posicion de la segunda hoja con menos peso*/
		t2 = ReadNode(&hojas[1],p); /*leeo el nodo de la hoja y lo guardo en t2*/

		temp.entero= t1.entero + t2.entero; /*se suma los enteros de las hojas*/
		
		/*creo el nuevo arbol que tiene como raiz la suma de los enteros*/
		p = Root(&unir);
		NewRightSon(&unir,p,temp);
		unir->izq = hojas[0];  /*conecto al hijo izquierdo con el arbol más pequeño*/
		unir->der = hojas[1];  /*conecto al hijo derecho con el segundo arbol más pequeño*/
		/*remplazo el primer nodo con unir*/
		hojas[0] = unir;
		i=0;
		
		printf("----------------");
		correrAR(hojas,contador); 
		contador--;
		OrdernarAR(hojas,contador);
		
		while(i<contador)
		{
			printf("\n");
			aux = Root(&hojas[i]);
			PreOrden(&hojas[i],aux);
			i++;
		}
		
		/*verifico si hay mas de un arbol*/
		p = Root(&hojas[1]);
		bandera = NullNode(&hojas[1],p);
		
	}

	return;
}
/*RECIBE:Un arreglo de arboles, y el tamaño del arreglo
DEVUELVE:nada
esta función se encarga de ordenar de menor a mayor el arreglo de arboles, mediante el mértodo burbuja*/
void OrdernarAR(arbol_bin ramas[],int t)
{
	int i,j;
	elemento a1,a2,temp;
	posicion p;
	arbol_bin aux;

	Initialize(&aux);

	for (i=1;i <t-1;i++)
	{
       for (j=0; j <=t-1-i;j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
       {
       		p = Root(&ramas[j]); /*obtengo la posicion de la hoja con menos peso*/
			a1 = ReadNode(&ramas[j],p);
			p = Root(&ramas[j+1]); /*obtengo la posicion de la segunda hoja con menos peso*/
			a2 = ReadNode(&ramas[j+1],p);


          	if (a1.entero > a2.entero)//Condicion mayor-menor
          	{
           		aux = ramas[j];
            	ramas[j] = ramas[j+1];
            	ramas[j+1] = aux;
          	}
       }
	}
	return;
}
/*Recibe: un arreglo de arboles
Devuelve: nada
se encarga de recorrer los lugares de los arboles en el arreglo*/
void correrAR(arbol_bin ramas[],int tam)
{
	int i;
	for (i = 1; i < tam; i++)
	{	
		ramas[i] = ramas[i+1];
	}
	return;
}
FILE Comprimir(FILE *original);
FILE Descomprimir(FILE *nuevo);
