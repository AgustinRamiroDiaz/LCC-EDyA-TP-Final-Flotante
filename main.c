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
printf("lsafdoasig");
	//n representa la cantidad de ciudades
	n = LecturaDeDatos(argv, nombreArchivoSalida, vertices, &matrizAdyacente);
	//el tamaño de la matriz Held-Karp
	int cantidadFilasHK = (1 << (n-1)) - 1,
		cantidadColumnasHK = n - 1;

	//la matriz que representa que camino se tiene que utilizar desde cada posicion
	//de la matrizHK para conseguir el camino de menor costo
	int** matrizVertices = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);

printf("%s", nombreArchivoSalida);
	//camino de los vertices en orden a recorrer sin los extremos que serian el nodo de partida
	int caminoVertices[n - 1];

	//lleno la matriz de vertices y obtengo la primer ciudad a recorrer
	caminoVertices[0] = LlenarMatrizVertices(matrizVertices, matrizAdyacente, n);
	
	//consigo el camino optimo de ciudades con la informacion de la matrizVertices
	LlenarCaminoVertices(caminoVertices, matrizVertices, n);

	LiberarMatriz(matrizVertices, cantidadFilasHK);

	//genero la salida solicitada con el camino de vertices con los nombres adecuados y sus costos
	GenerarArchivoSalida(nombreArchivoSalida, vertices, matrizAdyacente, caminoVertices, n);

	LiberarMatriz(matrizAdyacente, n);
	
	return 0;
}
