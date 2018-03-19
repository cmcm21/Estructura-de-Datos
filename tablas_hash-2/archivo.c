#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int cuenta;         /*numero de la cuenta*/
	char nombre[30];   /*nombre de la cuenta*/
	double saldo;     /*saldo de la cuenta*/

	FILE *ptrcf;  /*apuntadoe al archivo clientes*/

	system("clear");

	if((ptrcf = fopen("clientes.txt","w")) == NULL)
		printf("%s\n","EL ARCHIVO NO SE PUEDE ABRIR");

	else
	{
		printf("%s\n%s\n%s","Introduzca la cuenta, el nombre, y el saldo.\n",
				"Introduzca EOF al final de la entrada.","? " );
		scanf("%d%s%lf", &cuenta, nombre, &saldo);
	}

	while(!feof(stdin))
	{
		fprintf(ptrcf, "%d %s %.2f\n", cuenta , nombre , saldo);
		printf("%s","? " );
		scanf("%d%s%lf", &cuenta, nombre, &saldo);
	}

	fclose(ptrcf); /*fin de archivo*/

	return 0;
}