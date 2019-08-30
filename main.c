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

int main(int argc, char const* argv[])
{
	int  n, **matrizAdyacente;
	char vertices[CANT_MAX_VERTICES][LONG_MAX_PALABRA];
	char const * nombreArchivoSalida;

	n = LecturaDeDatos(argc, argv, nombreArchivoSalida, vertices, &matrizAdyacente);

	int cantidadFilasHK = (1 << (n-1)) - 1,
		cantidadColumnasHK = n - 1;

	int** matrizVertices = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);

	//camino de los vertices en orden a recorrer sin los extremos que serian el nodo de partida
	int caminoVertices[n - 1];


	caminoVertices[0] = LlenarMatrizVertices(matrizVertices, matrizAdyacente, n);
	
	LlenarCaminoVertices(caminoVertices, matrizVertices, n);

	LiberarMatriz(matrizVertices, cantidadFilasHK);

	GenerarArchivoSalida(nombreArchivoSalida, vertices, matrizAdyacente, caminoVertices, n);

	LiberarMatriz(matrizAdyacente, n);
	
	return 0;
}
