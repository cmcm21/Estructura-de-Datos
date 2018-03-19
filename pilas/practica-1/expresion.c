/*libreria: expresion matematica
        autor:correa medina carlos miguel
version:2.6
DESCRIPCION: El programa recibirá una expresión matematica como cadena y esta será pasada
de infijo a posjijo,se revisaran el uso correcto de los parentesis
y posteriormente se evaluara la expresion en posfijo

OBSERVACIONES: Se ocupan pilas implementadas por el profesor "Edgardo Adrián Franco Martínez".

COMPILACIÓN DEL PROGRAMA: gcc expresion.c TADPilaEst.c -o pila
EJECUCIÓN DEL PROGRAMA
*/

/*librerias*/
#include<stdio.h>
#include<stdlib.h> /*para el uso de exit*/
#include<string.h>/*para ocupar srtlen*/
//#include"TADPilaEst.h"/*libreria de pila estatica*/
#include"TADPilaDin.h"/*libreria de pila dinamia*/
#define MAX 100 /*variable simbolica para ocupar en el arreglo de la cadena
que se va a recibir*/

/*prototipo de funciones*/
void convertir(const char cad[],char pos[]);
void parentesis(const char cad[]);
int prioridad(char);

/*funcion principal*/
int main ()
{
	char cadena[MAX]; /*arreglo que contendra la expresion a evaluar*/
	char posfijo[MAX]; /*arreglo que servira de apollo para convertir a posfijo la expresion*/
    int k; /*contador*/
    int i; /*variable que me indica si en la cadena ha parentesis*/
	int posicion = 0;

	printf("ingrese la expresion que quiere evaluar\n");
	while((cadena[posicion++]=getchar())!= '\n');/*ciclo para recibir la
		expresion en infijo*/
		cadena[--posicion] = '\0';
    for(k=0;k<strlen(cadena);k++)
    {/*inicia for*/
        if(cadena[k] == '(') /*si la cadena contiene parentesis */
        {
           i=-1;
		}
    }/*finaliza for*/
        if(i==-1)
        {
            parentesis(cadena);
        }

	convertir(cadena,posfijo);/*se manda a llamar a la funcion convertir
    con cadena y posfijo como parametros*/

	return 0;
}
/*int prioridad (char x)
Descripcion: le da valores de precedencia a los operadores y parencis
Devuelve: devuelve el valor de precedencia de dicho operador
Observaciones: sin el uso de esta función es difícil llevar el orden
de precendencia de los operadores*/
int prioridad(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' )
 return(2);
    if(x == '^')
 return(3);
}/*fin de funcion*/

/*void convertir (const char cad[],char pos[])
Descripción: con la ayuda de pilaConvertir pasa la expresion recibida en cadena
de infijo a posfijo y la imprime
Devuelve:
Observaciones: sin el uso de la función prioridad es muy sensible a errores,
como desbordamiento o subdesbordamientos*/
void convertir(const char cad[],char pos[])
{
    /*prototipo de funcion*/
    void evaluar(const char posfija[]);/*sigue el principio de menor privilegio
    ya que solo se ocupa dentro de esta funcion*/

    int priori;/*variable para recibir a la funcion prioridad*/
	int i; /*contador*/
	int j = 0;/*controla el subincide de pos*/
	int k;/*sirve para imprimir la pila*/
    pila pilaConvertir; /*declaro pilaConvertir del tipo pila*/
    elemento aux; /*auxiliar para pasar elementos a la pila*/


    /*ininicializó pilaConvertir*/
	Initialize(&pilaConvertir);

    /*recorro la expresion hasta donde termina*/
	for(i=0;i<strlen(cad);i++)
	{
		/*condicion que evalua si la expresion es un operando*/
		if(cad[i]>='A' && cad[i]<='Z')
		{
			pos[j]=cad[i]; /*si es un operando se asigna a posfijo*/
            j++;
		}
        else
        {/*si es un parentesis izquierdo se inserta en la pila*/
            if(cad[i]=='(')
            {
                aux.c = cad[i];
                Push(&pilaConvertir,aux);
            }
        /*si es un parentesis derecho se saca de la pila hata encontrar un '('*/
            if(cad[i]== ')')
            {
                do
                {
                    if(Empty(&pilaConvertir))/*si la pila esta vacia se rompe el ciclo*/
                    {
                        break;
                    }
                    aux = Pop(&pilaConvertir);
                    if(aux.c != '(') /*se el caracter no es ( se inserta en posfijo*/
                    {
                        pos[j] = aux.c;
                        j++;
                    }

                }while(aux.c != '(');
            }

            if(cad[i] == '^')/*cuando es este operando se inserta directamente a la pila*/
            {
               if(Empty(&pilaConvertir))
				{
					aux.c = cad[i];
					Push(&pilaConvertir,aux);
				}
				else
				{
					aux=Top(&pilaConvertir);
					priori = prioridad(aux.c);
					while(priori >= 3 && !Empty(&pilaConvertir))
					{
						aux = Pop(&pilaConvertir);
						if(aux.c != '(')
						{
							pos[j]= aux.c;
							j++;
						}
						aux = Top(&pilaConvertir);
						priori = prioridad(aux.c);
						if(Empty(&pilaConvertir))
							break;
					}
					aux.c= cad[i];
					Push(&pilaConvertir,aux);
				}
            }
             /*evalua los operandos */
            if(cad[i] == '*' || cad[i] == '/')
            {
               if(Empty(&pilaConvertir))/*si la pila esta vacia se inserta derectamene el operando*/
               {
                    aux.c = cad[i];
                    Push(&pilaConvertir,aux);
               }
               else/*si no esta vacia se rebisa la precedencia de operadores*/
               {
                    aux = Top(&pilaConvertir);
                    priori = prioridad(aux.c);
                    while(priori >= 2 && !Empty(&pilaConvertir))
                    {
                        aux = Pop(&pilaConvertir);
                        if(aux.c != '(')/*si no es '(' se inserta en posfijo*/
                        {
                            pos[j] = aux.c; /*error detectado y modificado*/
                            j++;
                        }
                        aux = Top(&pilaConvertir);
                        priori = prioridad(aux.c);
						if(Empty(&pilaConvertir));/*error encontrado y
modificado*/				break;
                    }/*si el tope de la pila es de menor precedencia se inserta el operandor*/
                    aux.c = cad[i];
                    Push(&pilaConvertir,aux);
               }/*fin else*/
            }/*fin caso de operadores * y / */
            /*se revisan los operadores + y - */
            if(cad[i]== '+' || cad[i]=='-')
            { /*si esta vacia la pila se inserta el operador*/
                if(Empty(&pilaConvertir))
               {
                    aux.c = cad[i];
                    Push(&pilaConvertir,aux);
               }
               else /*si no esta vacia se rebisa la precedencia de operadores*/
               {
                    aux = Top(&pilaConvertir);
                    priori = prioridad(aux.c);
                    while(priori >= 1 && !Empty(&pilaConvertir))
                    {
                        aux = Pop(&pilaConvertir);
                        if(aux.c != '(') /*si no es un '(' se inserta en posfijo*/
                        {
                            pos[j] = aux.c;
                            j++;
                        }
                        if(Empty(&pilaConvertir))
                        {
                            break;
                        }
                        aux = Top(&pilaConvertir);
                        priori = prioridad(aux.c);
                    }
                    aux.c = cad[i];
                    Push(&pilaConvertir,aux);
               }/*fin else*/
            }/*fin caso de operadores + y -*/
        }/*fin de else*/
	}/*fin for*/
    while(!Empty(&pilaConvertir)) /*se encarga de vaciar los operadores que quedaron en la pila*/
    {
        aux = Pop(&pilaConvertir);
        if(aux.c != '(')
        {/*si no es '(' se inserta en posfijo*/
            pos[j] = aux.c;
            j++;
        }
    }
    printf("\nCadena en posfijo:\n");
/*imprime la cadena posfijo*/
   for(k=0;k<strlen(pos);k++)
   {
    printf("%c ",pos[k]);
   }
   evaluar(pos);/*manda la cadena posfijo a la funcion evaluar*/
   return;
}/*fin de funcion convertir*/

/*void evaluar(const char posfija[])
Descripción: funcion que recibe la cadena en posfijo y la evalua con
valores proporcionados por el usuario e imprime el resultado
Devuelve:
Observaciones: al momento de evaluar los operadores hay que tener en cuenta que
estos estan en una pila, por lo tanto sale el ultimo que entro
tambien con el operador  ^ no se pudó ocupar la libreria math.h por lo
tanto se  utilizó una función propia */
void evaluar(const char posfija[])
{  /*prototipo de función*/
    float potencia(float x,float y);/*respeta el principio de menor privilegio*/

    pila pilaevaluar;/*pila a ocupar para evaluar expresion en posfijo*/
    elemento aux2,a,b;/*se utilizar para realizar las operaciones*/
    int k,i; /*contador*/
    int n; /*ayuda a definir el tamaño del arreglos variables de forma exacta*/
    int indice; /*controla el indice de valor*/
    float valor[26] = {0};/*guarda el valor de la variable*/
   /*inicializa la pila*/
    Initialize(&pilaevaluar);
   /*recorre toda la cadena posfijo*/

    for(k=0;k<strlen(posfija);k++)
    {

        if(posfija[k] >= 'A' && posfija[k] <= 'Z')/*si es un operando lo agrega a variables*/
        {
          indice = posfija[k]-'A';
          if(valor[indice]==0)
          {
            printf("\n%c = ",posfija[k]);
            scanf("%f",&valor[indice]);
          }
        }
    }
    for(k=0;k<strlen(posfija);k++)
    {
        if(posfija[k] >= 'A' && posfija[k] <= 'Z')
        {
            indice = posfija[k]-'A';/*misma tabla hash*/
            aux2.f=valor[indice];
            Push(&pilaevaluar,aux2);
        }
        else /*si no, saca los dos ultimos elementos y los evalua segun el operador*/
        {
            a = Pop(&pilaevaluar);
            b = Pop(&pilaevaluar);

            switch(posfija[k])
            {
                case '*':
                    aux2.f = a.f * b.f;
                    Push(&pilaevaluar,aux2);
                    break;

                case '/':
                    if (a.f != 0) /*si el denominador es diferente de cero
                    realiza la división*/
                    {
                        aux2.f = b.f / a.f;
                        Push(&pilaevaluar,aux2);
                    }
                    else /*si no, sale del programa con error*/
                    {
                        printf("\nDIVISION ENTRE CERO ERROR:\n");
                        exit(1);
                    }
                    break;
                case '^':
                    aux2.f = potencia(b.f,a.f);/*ocupa funcion potencia para
sacar la potencia de los operandos*//*otro error encontrado*/
                    Push(&pilaevaluar,aux2);
                    break;

                case '+':
                    aux2.f = b.f + a.f;
                    Push(&pilaevaluar,aux2);
                    break;

                case '-':
                    aux2.f = b.f - a.f;
                    Push(&pilaevaluar,aux2);
                    break;
            }/*fin de switch*/
        }/*fin de else*/
    }/*fin de for*/
   /*saca el resultado y lo guarda en aux2*/
    aux2 = Pop(&pilaevaluar);
    printf("\nResultado = %.2f \n",aux2.f);/*imprime resultado*/

    return;
}/*fin de funcion*/

/*float potencia (float x,float y)
Descrpción: saca la potencia de x^y
Devuelve: x^y
Observaciones: recibe dos flotantes y regresa un flotante
no funciona con otros tipos de datos*/
float potencia(float x,float y)
{
   int i;
   float acum=1;
   for(i=1;i<=y;i++)
   acum*=x;
   return(acum);
}/*fin de función*/
/*void parentesis(const char cad[])
Descripción: recive la cadena y evalua si los parentesis estan de forma correcta
y sale del programa si no es así
Devuelve:
Observacion: ocupa un pila para realizar su tarea,*/
void parentesis(const char cad[])
{
    pila miPila;/*pila utilizada para evaluar parentesis*/
    elemento caracteres;/*elemento caracteres utilizado como auxiliar*/
    int i; /*contador*/

    Initialize(&miPila); /*inicializa mipila*/

    for(i=0;i<MAX;i++)/*recorre la cadena*/
    {
        if(cad[i] == '(') /*evalua si la cadena abre parentesis*/
        {
            caracteres.c = cad[i]; /*le da valor a caracteres tipo char*/
            Push(&miPila,caracteres);
        }

        if(cad[i] == ')')/*evalua si la cadena cierra parentesis ')' = 41*/
        {

            Pop(&miPila); /* en este momento no importa el elemento que que retorne pop*/
        }
    }

    if(Empty(&miPila)) /*evalua si miPila esta vacia*/
    {
        printf("parentesis correctos\n");
    }

    if(Size(&miPila) > 0)
    {
        printf("mas parentesis que abren que los que cierran\n");
        exit(1);
    }

    if(Size(&miPila) < 0)
    {
        printf("mas parentesis que cierran que los que abren\n");
        exit(1);
    }
    return;
}/*fin de funcion*/

