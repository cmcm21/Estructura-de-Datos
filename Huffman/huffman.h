#define BYTE 32

typedef struct tablaBIN
{
	char l;
	char combin[BYTE];
}tablaBIN;


/* funciones que ocuparan la implementacion del algoritmo de huffman*/
void huffman(char nombre[]);
void CrearArbol(elemento tablaFR[]);
void OrdernarAR(arbol_bin ramas[],int t);
void correrAR(arbol_bin ramas[],int tam);
void generarCodigo(arbol_bin *A,char arr[], int tope,posicion p);
void insertarTab(char c,char a[],int cima);
int funcionHash(char caracter);
void Comprimir(char chadena[]);
void imprimirHuffman(void);
void arbolhuffman(void);
void Descomprimir(char cadena[]);