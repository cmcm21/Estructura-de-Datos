/*************************************************************************************
*Autor: Correa Medina Carlos Miguel                                                  *
*VERSIÓN: 1.3                                                                        *
*                                                                                    *
*DESCRIPCIÓN: Diccionario realizado con la tabla hash abierta,                       *
*dicha tabla hash ocupa dos fuciones hash.                                           *
*Este diccionario contendra las palabras con su significado                          *
*                                                                                    *
*OBSERVACIONES: Es un programa dinámico que permite que el usuario de la aplicación  *
*agrege palabras al diccionario, que las busque entre otras.                         *
*                                                                                    *
*COMPILACIÓN: gcc Diccinario.c TADListasDobles.c TADTablaHash.c -o Diccionario       *
*Ejecucion: ./diccionario                                                            *
**************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "TADTablaHash.h"

/*prototipos de funciones*/
void menu(tabla *dic);
void cargar(tabla *dic);
void agregar(tabla *dic);
void BuscarPalabra(tabla *dic);
void modificar(tabla *dic);
void eliminarPalabra(tabla *dic);
void salir(void);
void TodasColisiones(tabla *dic);
void ImprimirporLetra(tabla *dic);

int main(int argc, char const *argv[])
{

	tabla diccionario;

	Inicializar(&diccionario);

	menu(&diccionario);

	return 0;
}
/*función que muestra las opciones de la aplicación "el menu"*/
void TodasColisiones(tabla *dic)
{
	int opc1;

	Colisiones();
	printf("\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","3.-Regresar","4.-salir" );
    scanf("%d",&opc1);

	if(opc1 == 3)
	    menu(dic);
	else
	   salir();
}
void menu(tabla *dicc)
{
	int opciones;
	system("clear");

	printf("\n\n\n\n\n\n\n\n");

	printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t",
		"1.-Cargar un archivo de deficiones",
		"2.-Agregar una palabra y su deficion",
		"3.-Buscar una palabra",
		"4.-Modificar una deficion",
		"5.-Eliminar una palabra",
		"6.-Salir",
		"7.-Colisiones",
		"8.-Imprimir por Letra");
	scanf("%d",&opciones);

	switch(opciones)
	{
		case 1: cargar(dicc); break;
		case 2: agregar(dicc); break;
		case 3: BuscarPalabra(dicc); break;
		case 4: modificar(dicc); break;
		case 5: eliminarPalabra(dicc); break;
		case 6: salir(); break;
		case 7: TodasColisiones(dicc); break;
		case 8: ImprimirporLetra(dicc); break;
	}
}
void ImprimirporLetra(tabla *dic)
{
	system("clear");
	int indice;
	elemento aux;
	int opc1;

	printf("\t\t\t\t%s\n\t\t\t\t","De que letra quiere Buscar:");
	scanf("%s",&aux.p);

	indice = FuncionH2(aux);
	if(indice >= 0 && indice <= ALFA )
	{
		ImprimeLista(&(dic->T[indice]));
		printf("\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","2.-Imprimir por Letra","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			ImprimirporLetra(dic);
		else
	   		salir();
	}
		
	else
	{
		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","No se puede Imprimir","2.-Imprimir por Letra","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			ImprimirporLetra(dic);
		else
	   		salir();
	}

}


/*funcion que se encarga de copiar el contenido de un archivo a la tabla*/
void cargar(tabla *dic)
{
	elemento e;          /*me ayuda a poder almacenar las palabras y definiciones del diccionario*/
	elemento aux;		/*funciona para borrar la informacion de e*/
	FILE *ptrf;           /*puntero para abrir archivo*/
	int i = -1,j = -1;            /*contador para capturar los caracteres del archivo*/
	int opc,opc1,opc2;           /*opción que escogerá el usuario*/
	char c = 0;						/*auxiliar*/	

    system("clear");

    printf("\n\n\n\n\n\n\n\n");

    printf("\t\t\t\t%s\n","Existen dos archivos de texto, ¿cuál quiere abrir y cargar\?:" );
    printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","1.-Glosario BIOQUANTUM.txt","2.-Lunfardo.txt","3.-Regresar");
    scanf("%d",&opc);

    if(opc < 3)
    {
	    switch(opc)/*solo ocupa una tabla. i.e., solo se puede cargar un diccionario, si la tabla ya tiene un diccionario, entonces lo sobreescribe*/
	    {
	    	case 1:
	    		system("clear");
	    		printf("\n\n\n\n\n\n\n\n");
	    		Inicializar(dic);
	    		if((ptrf = fopen("Glosario BIOQUANTUM.txt","rt")) == NULL) /*sí no puede abrir el archivo, se da la opción de regresar*/
	    		{
	    			printf("\t\t\t\t%s\n", "El archivo no pudo abrirse" );
	    			printf("\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","3.-Regresar","4.-salir" );
	    			scanf("%d",&opc1);

	    			if(opc1 == 3)
	    				cargar(dic);
	    			else
	    				salir();
	    		}
	    		else
	    		{
	    			while(!feof(ptrf))
	    			{
	    				while(c != ':')
	    				{
	    					fread(&c,sizeof(char),1,ptrf);
	    					if(c != ':')
	    					{
	    						i++;
	    						e.p[i] = c;
	    					}
	    				}
	    				fgets(e.d,250,ptrf);
	    				Insertar(dic,e);
	    				
	    				i = -1;
	    				e = aux;
	    				c = 0;
	    			}
	    			fclose(ptrf); /*cierra el archivo*/
	    			printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","3.-Regresar","4.-salir" );
	    			scanf("%d",&opc1);

	    			if(opc1 == 3)
	    				cargar(dic);
	    			else
	    				salir();
	    		}
	    		break;

	    	case 2:
	    		system("clear");
	    		printf("\n\n\n\n\n\n\n\n");
	    		Inicializar(dic);
	    		if((ptrf = fopen("Lunfardo.txt","rt")) == NULL) /*sí el archivo no puede abrirse, te da la opción de regresar*/
	    		{
	    			printf("\t\t\t\t%s\n", "El archivo no pudo abrirse" );
	    			printf("\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","3.-Regresar","4.-salir" );
	    			scanf("%d",&opc1);

	    			if(opc1 == 3)
	    				cargar(dic);
	    			else
	    				salir();
	    		}
	    		else
	    		{
	    			while(!feof(ptrf))
	    			{
	    				while(c != ':')
	    				{
	    					fread(&c,sizeof(char),1,ptrf);
	    					if(c != ':')
	    					{
	    						i++;
	    						e.p[i] = c;
	    					}
	    				}
	    				fgets(e.d,250,ptrf);
	    				
	    				Insertar(dic,e);
	    				i = -1;
	    				e = aux;
	    				c = 0;
	    			}
	    		}
	    		fclose(ptrf); /*cierra el archivo*/
    			printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","3.-Regresar","4.-salir" );
    			scanf("%d",&opc1);

	    		if(opc1 == 3)
	    			cargar(dic);
	    		else
	   				salir();

	    		break;
	    	default:
	    		cargar(dic);
	    }
	}    
	else
		menu(dic);
	return;
}
void agregar(tabla *dic)
{
	system("clear");

	printf("\n\n\n\n\n\n\n\n");

	elemento e; /*elemento auxliar que ayuda a pasarlo a la tabla hash*/
	int opc1; /*opcion que elige el usuario*/

	printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","Escriba la palabra que desea añadir",
						"(Empieze con mayuscula)" );
	scanf("%s",e.p);

	fflush(stdin);

	printf("\t\t\t\t%s\n\t\t\t\t","Escriba la definición de la palabra");
	scanf("%*c%[^\n]",e.d); /*forma de utilizar la función "scanf" para recibir cadenas con espacios*/

	Insertar(dic,e); /*inserta el elemento en la tabla*/

	printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","2.-Agregar","3.-Regresar","4.-salir" );
    scanf("%d",&opc1);

	if(opc1 == 3)
	   menu(dic);
	else if(opc1 == 2)
		agregar(dic);
	else
	   salir();

}
void BuscarPalabra(tabla *dic)
{
	system("clear");

	printf("\n\n\n\n\n\n\n\n");

	posicion aux;  /*recibe el elemento que se busca, en caso de que este exista*/
	elemento aux2; /*manda el elemento que se esta buscando a la función "Buscar"*/
	int opc1;     /*recibe la opción del usuario*/

	printf("\t\t\t\t%s\n\t\t\t\t","¿Qué palabra estas buscas (Mayusculas)?" );
	scanf("%*c%[^\n]",aux2.p); 

	aux = Buscar(*dic,aux2); /*busca la palabra en la tabla, sí no existe regresa NULL*/

	if(aux != NULL)
	{
		printf("\n\t\t\t\t%s:%s\n",aux->e.p,aux->e.d); 

		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","2.-Buscar","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			BuscarPalabra(dic);
		else
	   		salir();
	}
	else /*si la palabra no se encontro*/
	{
		printf("\n\t\t\t\t%s No se encuentra en el diccionario\n",aux2.p);
		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","2.-Buscar","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			BuscarPalabra(dic);
		else
	   		salir();
	}
	
}
void modificar(tabla *dic)
{
	system("clear");

	printf("\n\n\n\n\n\n\n\n");

	posicion aux;  /*recibe el elemento que se busca para modificarlo, en caso de que este exista*/
	elemento mod; /*manda el elemento que se esta buscando a la función "Buscar" y guarda la definicion que se quiere cambiar*/
	int opc1;     /*recibe la opción del usuario*/

	printf("\t\t\t\t%s\n\t\t\t\t","¿De qué palabra quiere modificar el significado?");
	scanf("%*c%[^\n]",mod.p); 

	aux = Buscar(*dic,mod); /*busca la palabra en la tabla, sí no existe regresa NULL*/

	if(aux != NULL)
	{
		printf("\n\t\t\t\tLa palabra \"%s\": %s",aux->e.p, aux->e.d);

		printf("\n\t\t\t\t%s\n\t\t\t\t","Cambie la deficion:" );
		scanf("%*c%[^\n]",mod.d);  

		Insertar(dic,mod);
		Eliminar(dic,aux->e);

		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","2.-modificar","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			modificar(dic);
		else
	   		salir();
	}
	else /*si la palabra no se encontro*/
	{
		printf("\n\t\t\t\t%s No se encuentra en el diccionario\n",mod.p);
		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","2.-modificar","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			modificar(dic);
		else
	   		salir();
	}
}
void eliminarPalabra(tabla *dic)
{
	system("clear");

	printf("\n\n\n\n\n\n\n\n");

	elemento aux2; /*manda el elemento que se quiere eliminiar"*/
	int opc1;     /*recibe la opción del usuario*/

	printf("\t\t\t\t%s\n\t\t\t\t","¿Qué palabra quiere Eliminar?" );
	scanf("%*c%[^\n]",aux2.p);

	if(Eliminar(dic,aux2))
	{
		printf("\t\t\t\tLa palabra \"%s\" ha sido eliminada\n",aux2.p); 

		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","¡LISTO!","2.-Eliminar","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			eliminarPalabra(dic);
		else
	   		salir();
	}
	else /*si la palabra no se encontro*/	
	{
		printf("\n\t\t\t\t%s No se encuentra en el diccionario\n",aux2.p);
		printf("\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\t\t\t\t","2.-Eliminar","3.-Regresar","4.-salir" );
    	scanf("%d",&opc1);

		if(opc1 == 3)
	   		menu(dic);
		else if(opc1 == 2)
			eliminarPalabra(dic);
		else
	   		salir();
	}

}
void salir(void)
{
	system("clear");
	printf("\n\t\t\t\t%s\n","MEGA-BYE xD");
	exit(0);
}
