#include "TADListaSL.h"
#include <stdio.h>
#include <stdlib.h>

//Operaciones de construcción
void Initialize(lista *l)
{
	l->frente=NULL;
	l->final=NULL;
	l->tam=0;
	return;
}
void Destroy(lista *l)
{
	posicion aux;
	while(l->frente!=NULL)
	{
		aux=l->frente->siguiente;
		free(l->frente);
		l->frente=aux;
	}
	l->final=NULL;
	l->tam=0;
	return;
}

//Operaciones de posicionamiento y busqueda
posicion Final(lista *l)
{
	return l->final;
}
posicion First(lista *l)
{
	return l->frente;
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
	posicion aux,anterior=NULL;
	if(ValidatePosition(l,p))
	{
		aux=l->frente;
		while(aux!=NULL)
		{
			if(aux==p)
				return anterior;
			anterior=aux;
			aux=aux->siguiente;
		}
	}
	else
	{
		printf("ERROR: Previus (P es INVALIDA)");
		exit(1);
	}
}


posicion Search(lista *l, elemento e)
{
	posicion aux=l->frente;
	while(aux!=NULL)
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
	aux=l->frente;
	boolean b=FALSE;
	while(aux!=NULL&&b==FALSE)
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

	aux=l->frente;

	if(n>=1&&n<=Size(l))
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
	posicion aux=l->frente;
	if(n>=1&&n<=Size(l))
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
	posicion aux,p_ant;
	aux=malloc(sizeof(nodo));
	if(aux!=NULL)
	{
		aux->e=e;
		if(ValidatePosition(l,p))
		{
			if(b==TRUE)//Se inserta antes de P
			{
				if(p!=l->frente)
				{
					aux->siguiente=p;
					p_ant=Previous(l,p);
					p_ant->siguiente=aux;
				}
				else
				{
					aux->siguiente=p;
					l->frente=aux;
				}
			}
			else	//Se inserta despues de P
			{
				if(p!=l->final)
				{
					aux->siguiente=p->siguiente;
					p->siguiente=aux;
				}
				else
				{
					aux->siguiente=NULL;
					l->final=aux;
				}
			}
		}
		else
		{//Insertar al frente de la lista
			aux->siguiente=l->frente;
			l->frente=aux;
			if(l->final==NULL)
			{
				l->final=aux;
				aux->siguiente = NULL;
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
	posicion aux;
	aux=malloc(sizeof(nodo));
	aux->e=e;
	if(aux!=NULL)
	{
		//Se insertará al final
		aux->siguiente=NULL;
		if(l->final==NULL)//Si la lista estaba vacia
		{
			l->frente=aux;
			l->final=aux;
		}
		else //Si no estaba vacia
		{
			l->final->siguiente=aux;
			l->final=aux;
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
	posicion aux, ant_p;
	if(ValidatePosition(l,p))
	{
		if(p==l->frente)
		{
			aux=p->siguiente;
			free(p);
			l->frente=aux;
			if(p==l->final)
				l->final=NULL;
		}
		else if(p==l->final)
		{
			ant_p=Previous(l,p);
			ant_p->siguiente=NULL;
			l->final=ant_p;
			free(p);
		}
		else
		{
			ant_p=Previous(l,p);
			ant_p->siguiente=p->siguiente;
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
