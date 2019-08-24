#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "lectura.h"
#include "held_karp.h"
#include "matriz.h"
#include "salida.h"
#include "camino.h"

#include "time.h"

int main()
{
int begin = clock();

	int  n, **matrizAdyacente;
	char vertices[CANT_MAX_VERTICES][LONG_MAX_PALABRA];

	FILE * archivoGrafo = fopen(NOMBRE_ARCHIVO_ENTRADA, "r");

	//n representa la cantidad de vertices del grafo
	n = LeerCiudades(archivoGrafo, vertices);

	matrizAdyacente = InstanciarMatriz(n, n);
	LlenarMatrizN(matrizAdyacente, n, n, INT_MAX);

	LeerAristas(archivoGrafo, matrizAdyacente, vertices);

	fclose(archivoGrafo);


	int cantidadFilasHK = (1 << (n-1)) - 1,
		cantidadColumnasHK = n - 1;

	//la fila n representa el numero n en binario que representa el conjunto s
	//la columna n representa el vertice n sin contar el primer vertice
	int** matrizHeldKarp = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);
	int** matrizVertices = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);

	//camino de los vertices en orden a recorrer sin los extremos que serian el nodo de partida
	int caminoVertices[n - 1];

clock_t comienzo = clock();

	caminoVertices[0] = LlenarMatrizVertices(matrizVertices, matrizHeldKarp, matrizAdyacente, n);
	
clock_t fin = clock();
double tiempoParcial = (double)(fin - comienzo)/CLOCKS_PER_SEC;
printf("tiempo parcial: %lf\n", tiempoParcial);

	
	LlenarCaminoVertices(caminoVertices, matrizVertices, n);

	GenerarArchivoSalida(vertices, matrizAdyacente, caminoVertices, n);

/* clock_t end = clock();
double tiempo = (double)(end - begin)/CLOCKS_PER_SEC;
printf("tiempo total: %lf\n", tiempo);
 */
	return 0;
}
