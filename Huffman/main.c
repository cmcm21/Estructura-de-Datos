#include <stdio.h>
#include <stdlib.h>
#include "TADArbolBin.h"
#include "huffman.h"

char cadena2[] = "Glosario BIOQUANTUM.txt";
char cadena3[] = "Lunfardo.txt";
char cadena4[] = "comprimido.txt";

int main (void)
{
	Comprimir(cadena3);
	arbolhuffman();
	imprimirHuffman();
	Descomprimir(cadena4);
	return 0;
}
