#include <stdlib.h>
#include<stdio.h>
#include "TADPilaDin.h"

void Initialize(pila *s)
{
	(*s).tope=NULL;
	s->tam=0;
	return;
}

void Push(pila *s, elemento e)
{
	nodo *aux;
	aux=malloc(sizeof(nodo));
	if(aux!=NULL)
	{
		(*aux).e=e; //aux->e=e;
		aux->abajo=s->tope; //El nuevo nodo en su apuntador abajo apunta al que antes estaba en el tope de la pila;
		s->tope=aux;
		s->tam++;
	}
	else
	{
		printf("\nERROR: Desbordamiento de Pila");
		exit(1);
	}
	return;
}

elemento Pop (pila *s)
{
	elemento e;
	nodo * aux;
	if(!Empty(s))
	{
		//Pop
		e=s->tope->e;//e=(*(s->tope)).e;
		aux=s->tope;
		s->tope=s->tope->abajo;
		free(aux);
		s->tam--;
	}
	else
	{
		printf("\nERROR: Subdesbordamiento de Pila");
		exit(1);
	}

	return e;
}

boolean Empty(pila *s)
{
	boolean b;
	if(s->tope==NULL)
		b=TRUE;
	else
		b=FALSE;
	return b;
}

elemento Top(pila *s)
{
	elemento e;
	e=s->tope->e;
	return e;
} 

int Size(pila *s)
{	
	/*int tam=0;
	nodo *aux;
	aux=s->tope;
	while(aux!=NULL)
	{
		tam++;
		aux=aux->abajo;
	}
	return tam;*/
	return s->tam;
}

void Destroy(pila *s)
{
	nodo *aux;
	if(!Empty(s))
	{
		aux=s->tope->abajo;
		while(s->tope!=NULL)
		{
			free(s->tope);
			s->tope=aux;
			if(aux!=NULL)
				aux=aux->abajo;
		}
	}
	s->tam=0;
	return;
}
