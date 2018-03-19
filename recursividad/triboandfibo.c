#include <stdlib.h>
#include <stdio.h>

	int Tribonacci (int n);
	int Fibonacci (int n);

int main ()
{
	system("clear");
	int n, serie, i, j;
	printf ("\tIndique la posicion del valor que desea obtener :      ");
	scanf ("%d", &n);
	printf ("\tDe cual serie desea el valor: \n\n1.\t Fibonacci \n2.\t Tribonacci\n\n\t\t");
	scanf ("%d", &serie);
	
	if (serie ==1)
	{
		i=Fibonacci(n);	
		printf ("El valor de la serie indicada es:  [ %d ]\n", i);
	}
	else if (serie==2)
	{
		j=Tribonacci(n);
		printf ("El valor de la serie indicada es: [ %d ]\n", j);	
	}
	
}

int Fibonacci (int n)
{
	int i;
	int F[10000];
	
	for (i=0; i<10000; i++)
	{
		F[i]=-1;
	}
	
	F[0]=0;
	F[1]=1;
	// /*
	F[2]=1;
	F[3]=2;
	F[4]=3;
	F[5]=5;
	F[6]=8;
	F[7]=13;
	F[8]=21;
	F[9]=34;
	F[10]=55;
	F[11]=89;
	F[12]=144;
	F[13]=233;
	F[14]=377;
	F[15]=610;
	F[16]=987;
	F[17]=1597;
	F[18]=2584;
	F[19]=4181;
	F[20]=6765;
	//*/
	
	if (n<2)
		return F[n];
	if (F [n]=!-1)
		return F[n];
	else		
	{
		if (F [n-1]==-1)
			F[n-1]=Fibonacci(n-1);
		if (F [n-2] ==-1)
			F[n-2]= Fibonacci(n-2);
		F[n]= F[n-1]+ F[n-2];
		return F[n];
	}
}
	
int Tribonacci (int n)
{
	int j;
	int T[10000];
	
	for (j=0; j<10000; j++)
	{
		T[j]=-1;
	}
	
	T[0]=0;
	T[1]=1;
	T[2]=1;
	///*
	T[3]=2;
	T[4]=4;
	T[5]=7;
	T[6]=13;
	T[7]=24;
	T[8]=44;
	T[9]=81;
	T[10]=149;
	T[11]=274;
	T[12]=504;
	T[13]=927;
	T[14]=1705;
	T[15]=3136;
	T[16]=5768;
	T[17]=10609;
	T[18]=19513;
	T[19]=35890;
	T[20]=66012;
	//
			
	if ((n<3))
		return T[n];
	if (T [n]!=-1)
		return T[n];
	else		
	{
		if (T [n-1]==-1)
			T[n-1]=Tribonacci(n-1);
		if (T [n-2] ==-1)
			T[n-2]= Tribonacci (n-2);
		if (T[n-3]==-1)
			T[n-3]=Tribonacci (n-3);
		T[n]= T[n-1]+ T[n-2]+ T[n-3];
		return T[n];
	}
}