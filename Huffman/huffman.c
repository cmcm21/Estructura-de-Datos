#include <stdlib.h>
#include <stdio.h>
#include "TADArbolBin.h"
#include "huffman.h"
#define TAM 256

tablaBIN mi_tabla[TAM];  /*estructura donde guardo la letra y su codigo huffman*/
int topes[BYTE];        /*topes de arreglo de bytes*/
arbol_bin huffmantree;  /*arbol de huffman ya terminado*/

/*RECIBE: el nombre del archivo
Devuelve:nada 
esta función se encarga de sacar las frecuencias de los simbolos de los archivos
se llama huffman porque es la que se encarga de empezar el algortimo de huffman*/
void huffman(char nombre[])
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
	arbol_bin unir; /*arbol auxiliar que me ayuda a unir a los arboles del arreglo */
	boolean bandera;
	elemento temp,t1,t2;
	int subindices[TAM] = {0};
	int i,j,k; 			/*contadores*/
	posicion aux,p;    /*auxilares para tener una posicion*/
	int contador = 0; /*para saber cuando ya termine de unir todos los arboles*/
	char bits[BYTE];

	k = 0;
	for (j = 0; j <= TAM; ++j)
	{
		if(tablaFR[j].entero != 0)
		{
			contador++;
			subindices[k] = j;
			k++;
		}		
	}
	i = 0;
	while(i < contador) //ciclo para crear el arreglo de arboles
	{
		Initialize(&hojas[i]);
		NewRightSon(&hojas[i],aux,tablaFR[subindices[i]]);/*como el arbol esta vacio se convierte en raiz*/
		aux = Root(&hojas[i]);
		InOrden(&hojas[i],aux);
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
		
		correrAR(hojas,contador); 
		contador--;
		OrdernarAR(hojas,contador);
		
		/*verifico si hay mas de un arbol*/
		p = Root(&hojas[1]);
		bandera = NullNode(&hojas[1],p);
	}
	huffmantree = hojas[0];
	p = Root(&hojas[0]);
	generarCodigo(&hojas[0],bits,0,p);
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
	Destroy(&ramas[i+1]);
	return;
}
/*RECIBE: el arbol en el que se genera el codigo, el arreglo que funciona como 
auxiliar y asigna los 0's y 1's en el arbol, el tope del arreglo, y la poscion en la que se encuentra.
DEVUELVE: nada
esta funcion se encarga de recorrer el arbol y de etiquetar con 0's y 1's hijos izquierdos y
hijos derechos, hasta llegar a un nodo hoja*/
void generarCodigo(arbol_bin *A, char arr[], int tope,posicion p)
{
	elemento e;
    // asigna 0 a posicion izquierda y recursividad
    if (p->izq)
    {
        arr[tope] = 0;
        generarCodigo(A, arr, tope + 1,p->izq);
    }
    // asigna 1 a posicion derecha y recursividad
    if (p->der)
    {
        arr[tope] = 1;
        generarCodigo(A, arr, tope + 1,p->der);
    }
    /*si el un nodo hoja imprime su carcter con su correspondiente codigo
    guardado en el arreglo*/
    if (isLeaf(A,p))
    {
    	e=ReadNode(A,p);
    	insertarTab(e.c,arr,tope);
    }
}
/*
RECIBE:El simbolo,al arreglo que contiene el codigo huffman y el tope del arreglo
DEVUELVE:nada
funcion que se encarga de guardar la letra con su codigo huffman*/
void insertarTab(char c,char a[],int cima)
{
	int i;
	int aux;
	aux = funcionHash(c);
	mi_tabla[aux].l = c;
	
	for (i = 0; i < cima; i++)
		mi_tabla[aux].combin[i] = a[i];

	topes[aux] = cima;  /*guardo el tope del arreglo de "bytes"*/
}
/*
RECIBE:el caracter al que se le aplicara la funcion
DEVUELVE:el numero de subindice
funcion que se encarga de sacar el subindice de la tabla*/
int funcionHash(char caracter)
{
	return TAM - caracter;
}
/*RECIBE: el nombre del archivo a comprimir
Devuleve: nada
se encarga de crear un nuevo archivo que representa al archivo original comprimido*/
void Comprimir(char cadena[])
{
	huffman(cadena);
	/*-------------------------------------------*/
	FILE *original;
	FILE *nuevo;
	char com[] = "comprimido.txt";
	char aux;
	int i;
	int indice;
	original = fopen(cadena,"rb");
	nuevo = fopen(com,"wb");
	
	if(original == NULL || nuevo == NULL)
		printf("%s\n","no se pueden abrir los archivos");

	else
	{
		while(!feof(original))
		{
			fread(&aux,sizeof(char),1,original);
			indice = funcionHash(aux);
			i = 0;
			if(indice >= 0 && indice < TAM)
			{
				while(i < topes[indice])
				{
					fprintf(nuevo,"%u",mi_tabla[indice].combin[i]);	
					i++;
				}
			}
		}
	}
	fclose(original);
	fclose(nuevo);
}
/*RECIBE:EL nombre de la cadena que va a decodificar
DEVUELVE:nada
esta función se encarga de descomprimir y guardar en un nuevo archivo la informacion
del archivo comprimido*/
void Descomprimir(char cadena[])
{
	FILE *cod;
	FILE *des;
	posicion p;
	elemento e;
	unsigned char otroaux;
	p = Root(&huffmantree);

	des = fopen("original.txt","wb");
	cod = fopen(cadena,"rb");
	if(des != NULL && cod != NULL)
	{
		while(!feof(cod))
		{
			fread(&otroaux,sizeof(char),1,cod);
			if(isLeaf(&huffmantree,p))
			{
				e = ReadNode(&huffmantree,p);
				fprintf(des,"%c",e.c);
				p = Root(&huffmantree);
			}
			if(otroaux == 49) /*49 = 1 valor ascci*/
				p = p->der;
			if(otroaux == 48) /*48 = 0 valor ascci*/
				p = p->izq;
		}
	}
	else
		printf("%s\n","no se pudó abrir el archivo");
	
	fclose(cod);
	fclose(des);
}
/*RECIBE: nada
DEVUELVE: nada
Esta funcion se encarga de que imprimir el codigo de huffman de cada
simbolo que hay en el arbol de huffman*/
void imprimirHuffman(void)
{
	int i;
	int j;
	int k;
	printf("\n");
	for (i = 0; i < 40; ++i)
		printf("*");
	printf("%s","CODIGO HUFFMAN");
	for (i = 0; i < 58; ++i)
		printf("*");
	printf("\n");

	for (i = 0; i < TAM; ++i)
	{
		if (mi_tabla[i].l != '\0')
		{
			j = 0;
			printf("\t\t\t\t\t\t%c:",mi_tabla[i].l);
			k = funcionHash(mi_tabla[i].l);
			while(j < topes[k])
			{
				printf("%d",mi_tabla[i].combin[j]);
				j++;
			}
			printf("\n");
		}
	}
}
/*RECIBE:nada
DEVUELVE:nada
esta funcion se encarga de imprimir en preorden al arbol final
que es el arbol huffman*/
void arbolhuffman(void)
{
	int i;
	posicion p;
	p = Root(&huffmantree);
	printf("\n");
	for (i = 0; i < 40; ++i)
		printf("*");
	printf("%s","ARBOL HUFFMAN EN PREORDEN");
	for (i = 0; i < 47; ++i)
		printf("*");
	printf("\n");
	PreOrden(&huffmantree,p);
}