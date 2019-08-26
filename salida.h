#ifndef SALIDA
#define SALIDA

#include "constantes.h"

//genera el archivo de salida a partir del camino optimo generado
void GenerarArchivoSalida(char vertices[][LONG_MAX_PALABRA], int** matrizAdyacente, int* caminoVertices, int n);

#endif