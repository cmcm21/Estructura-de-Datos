/*
 Alumno: Correa Medina Carlos Miguel. Octubre 21 del 2017.
 Version: 1.4.
 Descripción: Implementación de una lista doblemente ligada.
 Los nodos de la lista tendrán un apuntador que hace referencia tanto
 al nodo de adelante  de él como al nodo de atrás, aparte del 
 elemento que contiene.
 Compilación:gcc TADListasDobles.c -c
 */
#include "TADListasDoble.h"
#include <stdio.h>
#include <stdlib.h>

/*Operaciones de construcción*/
void Initialize(lista *l)
{
	l->inicio = NULL;
	l->final = NULL;
	l->tam = 0;
	return;
}
void Destroy(lista *l)
{
	posicion aux;
	while(l->inicio != NULL)
	{
		aux = l->inicio->siguiente;
		free(l->inicio);
		l->inicio=aux;
	}
	l->final=NULL;
	l->tam=0;
	return;
}
posicion Final(lista *l)
{
	return l->final;
}
posicion First(lista *l)
{
	return l->inicio;
}
posicion Following(lista *l, posicion p)
{
	if(ValidatePosition(l,p))
	{
		return p->siguiente;
	}
	else
	{
		printf("ERROR: Following (P es INVALIDA)");
		exit(1);
	}
}
posicion Previous(lista *l, posicion p)
{
	posicion aux;
	if(ValidatePosition(l,p))
	{
		return p->anterior;
	}
	else
	{
		printf("ERROR: Previus (P es INVALIDA)");
		exit(1);
	}
}
posicion Search(lista *l, elemento e)
{
	posicion aux=l->inicio;
	while(aux != NULL)
	{
		if(memcmp(&e,&(aux->e),sizeof(elemento))==0)
		{
			return aux;
		}
		aux=aux->siguiente;
	}
	return NULL;
}
//Operación de consulta
elemento Position(lista *l, posicion p)
{
	if(ValidatePosition(l,p))
	{
		return p->e;
	}
	else
	{
		printf("ERROR (Position): La Posicion p es invalida");
		exit(1);
	}
}

boolean ValidatePosition(lista *l, posicion p)
{
	posicion aux;
	aux=l->inicio;
	boolean b=FALSE;

	while(aux != NULL && b==FALSE)
	{
		if(aux==p)
		{
			b=TRUE;
		}
		else
		{
			aux=aux->siguiente;
		}
	}
	return b;
}
elemento Element(lista *l, int n)
{
	int i;
	posicion aux;

	aux=l->inicio;

	if(n>=1 && n<=Size(l))
	{
		for(i=1;i<n;i++)
			aux=aux->siguiente;

		return aux->e;
	}
	else
	{
		printf("ERROR (Element): El parametro n es invalido");
		exit(1);
	}
}
posicion ElementPosition(lista *l, int n)
{
	int i;
	posicion aux = l->inicio;

	if(n >= 1 && n <= Size(l))
	{
		for(i=2;i<=n;i++)
			aux=aux->siguiente;
		return aux;
	}
	else
	{
		printf("ERROR (ElementPosition): El parametro n es invalido");
		exit(1);
	}

}
int Size(lista *l)
{
	return l->tam;
}
boolean Empty(lista *l)
{
	return (Size(l)==0)?TRUE:FALSE;
}
//Operaciones de modificación
void Insert(lista *l, elemento e, posicion p,boolean b)
{
	posicion aux,aux2;
	aux = malloc(sizeof(nodo));

	if(aux!=NULL)
	{
		aux->e=e;

		if(ValidatePosition(l,p))
		{
			if(b==TRUE)//Se inserta antes de P
			{
				if(p != l->inicio)
				{ 
					aux->siguiente=p;
					aux2 = p->anterior;
					aux2->siguiente=aux;
					aux->anterior = aux2;
					p->anterior = aux;

				}
				else
				{
					aux->siguiente = p;
					l->inicio = aux;
					p->anterior = aux;
					aux->anterior = NULL;
				}
			}
			else	//Se inserta despues de P
			{
				if(p != l->final)
				{
					aux2 = p->siguiente;
					aux->siguiente = aux2;
					p->siguiente=aux;
					aux2->anterior = aux;
					aux->anterior = p;
				}
				else
				{
					aux->siguiente = NULL;
					l->final = aux;
					aux->anterior = p;
					p->siguiente = aux;
				}
			}
		}
		else
		{//Insertar al frente de la lista
			aux2 = l->inicio;
			aux->siguiente = l->inicio;
			l->inicio = aux;
			aux->anterior = NULL;

			if(l->final == NULL)
			{
				l->final=aux;
				aux->siguiente = NULL;
			}
			else
			{
				aux->siguiente = aux2;
			    aux2->anterior = aux;
			}
				
		}
		l->tam++;
	}
	else
	{
		printf("ERROR (Insert): No se pudo crear un nuevo elemento");
		exit(1);
	}
}

void Add(lista *l,elemento e)
{
	posicion aux,aux2;
	aux=malloc(sizeof(nodo));

	aux->e=e;

	if(aux != NULL)
	{
		//Se insertará al final
		aux->siguiente=NULL;

		if(l->final==NULL)//Si la lista estaba vacia
		{
			l->inicio=aux;
			l->final=aux;
			aux->anterior = NULL;
		}
		else //Si no estaba vacia
		{
			aux2 = l->final;
			l->final->siguiente=aux;
			l->final=aux;
			aux->anterior = aux2;
		}
		l->tam++;
	}
	else
	{
		printf("ERROR (Add): No se pudo crear un nuevo elemento");
		exit(1);
	}
}
void Remove(lista *l,posicion p)
{
	posicion aux, aux2;

	if(ValidatePosition(l,p))
	{
		if(p == l->inicio)
		{
			aux = p->siguiente;
			free(p);
			l->inicio = aux;
			aux->anterior = NULL;

			if(p == l->final)
				l->final=NULL;
		}
		else if(p == l->final)
		{
			aux2 = p->anterior;
			aux2->siguiente = NULL;
			l->final = aux2;
			free(p);
		}
		else
		{
			aux2 = p->anterior;
			aux = p->siguiente;
			aux2->siguiente = aux;
			aux->anterior = aux2;
			free(p);
		}
		l->tam--;
	}

	else
	{
		printf("ERROR (Remove): P inexistente");
		exit(1);
	}
}
void Replace(lista *l,posicion p, elemento e)
{
	if(ValidatePosition(l,p))
	{
		p->e=e;
	}
	else
	{
		printf("ERROR (Replace): P inexistente");
		exit(1);
	}
}

