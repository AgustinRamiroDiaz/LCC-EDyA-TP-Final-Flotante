#include "salida.h"
#include "constantes.h"
#include <stdio.h>

void GenerarArchivoSalida(char vertices[][LONG_MAX_PALABRA], int** matrizAdyacente, int* caminoVertices, int n)
{
	FILE * archivo = fopen(NOMBRE_ARCHIVO_SALIDA, "w");

	fprintf(archivo, "%s,%s,%d\n", vertices[0], vertices[caminoVertices[0] + 1], matrizAdyacente[0][caminoVertices[0] + 1]);
	for (int i = 1; i < n - 1; i++)
	{
		fprintf(archivo, "%s,%s,%d\n", vertices[caminoVertices[i - 1] + 1], vertices[caminoVertices[i] + 1], matrizAdyacente[caminoVertices[i - 1] + 1][caminoVertices[i] + 1]);
	}
	fprintf(archivo, "%s,%s,%d\n", vertices[caminoVertices[n - 2] + 1], vertices[0], matrizAdyacente[0][caminoVertices[n - 2] + 1]);

	fclose(archivo);

/*  */
	for (int i = 0; i < n - 1; i++) {
		printf("%s ", vertices[caminoVertices[i] + 1]);
	}
	printf("\n");
/*  */
}