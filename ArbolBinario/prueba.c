#include <stdio.h>
#include "TADArbolBin.h"
/*este programa fue hecho por el profesor edgardo */
int main (void)
{
	arbol_bin a;
	elemento e;
	posicion p;

	Initialize(&a);		
	e.c='A';
	NewRightSon(&a,p,e);
	
	p=Root(&a);
	
	e.c='C';
	NewRightSon(&a,p,e);
		
	e.c='B';
	NewLeftSon(&a,p,e);
		
	p=RightSon(&a,p);	
	e.c='D';
	NewLeftSon(&a,p,e);
	e.c='E';
	NewRightSon(&a,p,e);
	
	p=Root(&a);
	PreOrden(&a,p);
	printf("\n");
	InOrden(&a,p);
	printf("\n");
	PostOrden(&a,p);
	
	Destroy(&a);
	
	return 0;
}