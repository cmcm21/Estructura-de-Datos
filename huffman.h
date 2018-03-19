/* funciones que ocupara la implementacion del algoritmo de huffman*/

void tablaFR(char nombre[]);
void CrearArbol(elemento tablaFR[]);
void OrdernarAR(arbol_bin ramas[],int t);
void correrAR(arbol_bin ramas[],int tam);
FILE Comprimir(FILE *original);
FILE Descomprimir(FILE *nuevo);