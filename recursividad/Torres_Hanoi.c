/*
ESTRUCTURAS DE DATOS 
Desarrolladores:
	Correa medina Carlos miguel

	Noviembre  2017
COMPILACION: gcc Torres_Hanoi.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void hanoi ( char varinicial, char varfinal, char varcentral, int n);

int main()
{
	system("clear");

	char varinicial, varfinal,varcentral;
	int discos,mov;
	
	varinicial='A';
	varfinal=  'C';
	varcentral='B';
	
	printf("Determine el numero de discos con lo que quiere usar la torre de Hanoi\n\n\t\t");
	scanf ("%d",&discos);
	
	hanoi(varinicial,varfinal,varcentral,discos);
	mov=pow(2,discos)-1;
	
	printf("\n Movimientos totales:  [  %d ] \n",mov);
	
	getchar();
	
	return 0;
}

/*
	La función Hanói, será una función recursiva. En esta se planteará el caso base: el cual se basará en una condición y es que si el número de discos (n) es igual a 1 pasar de la varilla de origen (puede ser A o B) a la varilla final C directamente.
	En el caso contrario, que le número de discos sea mayor a 1, cada disco se enumerara 1 a n, y entonces la función Hanói se llamara a sí misma, con los parámetros (varilla inicial, varilla central, varilla final, n-1), es decir ahora el disco de análisis será el disco que se encuentra debajo del último. ahora bien, una vez hecho esto se imprimirá el recorrido que recorrerá el disco, es decir cual será su varilla de origen y la de destino.
	Posteriormente, se hará otra llamada a la misma función, pero ahora como varilla de origen o inicial será la varilla central, la varilla final se mantendrá constante, mientras que la varilla auxiliar o central será la varilla inicial o varilla A, y se repetirá el análisis del disco n-1
	RECIBE: tres variables de tipo char varilla inicial, varilla final o de destino, y la varilla central o auxiliar y el número n de discos ingresado por el usuario 
*/

void hanoi ( char varinicial, char varfinal, char varcentral, int n)
{
	if (n==1)
		printf("Mover disco %d desde varilla %c a varilla %c \n",n,varinicial,varfinal);
	else
	{
		hanoi (varinicial, varcentral,varfinal, n-1);
		
		printf("Mover disco %d desde varilla %c a varilla %c \n",n,varinicial,varfinal);
		
		hanoi (varcentral,varfinal,varinicial,n-1);
	}
}