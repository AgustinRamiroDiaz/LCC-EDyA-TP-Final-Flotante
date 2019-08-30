#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "constantes.h"
#include "lectura.h"
#include "held_karp.h"
#include "matriz.h"
#include "salida.h"
#include "camino.h"

#include "time.h"


int LecturaDeDatos(int argc, char const *argv[], char const *nombreArchivoSalida, char vertices[][LONG_MAX_PALABRA], int **matrizAdyacente)
{
    char const * nombreArchivoEntrada;

    if (argc > 2) {
        nombreArchivoEntrada = argv[1];
		nombreArchivoSalida = argv[2];
    } else {
        assert(0 && "Debe ingresar los nombres de los archivos de entrada y salida");
    }

    FILE * archivoGrafo = fopen(nombreArchivoEntrada, "r");

	//n representa la cantidad de vertices del grafo
	int n = LeerCiudades(archivoGrafo, vertices);

	matrizAdyacente = InstanciarMatriz(n, n);
	LlenarMatrizN(matrizAdyacente, n, n, INT_MAX);

	LeerAristas(archivoGrafo, matrizAdyacente, vertices);

	fclose(archivoGrafo);

	return n;
}

int main(int argc, char const *argv[])
{
	int  n, **matrizAdyacente;
	char vertices[CANT_MAX_VERTICES][LONG_MAX_PALABRA];
	char const * nombreArchivoSalida;

	n = LecturaDeDatos(argc, argv, nombreArchivoSalida, vertices, matrizAdyacente);

	//la matriz Held-Karp tiene 2^(n-1) filas que representan 
	//todos los subconjuntos de los n-1 vertices excluyendo el primer vertice
	//y tiene n-1 columnas que representan los n-1 vertices excluyendo el primer vertice
	int cantidadFilasHK = (1 << (n-1)) - 1,
		cantidadColumnasHK = n - 1;

	//la fila n representa el numero n en binario que representa el conjunto s
	//la columna n representa el vertice n sin contar el primer vertice
	int** matrizHeldKarp = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);
	int** matrizVertices = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);

	//camino de los vertices en orden a recorrer sin los extremos que serian el nodo de partida
	int caminoVertices[n - 1];


	caminoVertices[0] = LlenarMatrizVertices(matrizVertices, matrizHeldKarp, matrizAdyacente, n);
	
	LiberarMatriz(matrizHeldKarp, cantidadFilasHK);

	LlenarCaminoVertices(caminoVertices, matrizVertices, n);

	LiberarMatriz(matrizVertices, cantidadFilasHK);

	GenerarArchivoSalida(nombreArchivoSalida, vertices, matrizAdyacente, caminoVertices, n);

	LiberarMatriz(matrizAdyacente, n);
	
	return 0;
}
