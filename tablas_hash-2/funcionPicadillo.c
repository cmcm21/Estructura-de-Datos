#include <stdio.h>
#include <string.h> //para la funcion strlen
#include <math.h> //para lafuncion de pow

int Ascii (char a[]);

int main (void)
{
	char Palabra[25];//la palabra mas larga del español tiene 23 letras
	double final;

	printf("inserta la palabra \n");
	scanf("%[^\n]",Palabra);
	final=Ascii(Palabra);/*%307 Ó 2027;DEPENDIENDO CUAL DE LAS DOS LISTAS, ES
MODULO EL NUMERO
						  PRIMO MAYOR QUE EL NUMERO DE PALABRAS QUE TIENE*/
	printf("el valor ascii de cada letra final es: %f \n",final);
 	printf ("\nes:%.0f\n",pow(2,2));
	return 0;
}

int Contar (char a[])
{
	int n=0;
	n=strlen(a); //obtengo el numero de letras
        return n;
}

int Ascii (char a[])
{
	int i; //contador
	int tam=Contar(a);//obtengolas letras de la palabra
	double res=0; //variable que guarda el resultado

        for(i=1;i<=tam;i++) //ciclo hasta que sea menor igual al numero de letras
	{
 		res+= pow( a[i-1],i);
	}
	return res;
}
