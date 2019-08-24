#include "camino.h"
#include "held_karp.h"
#include "constantes.h"
#include "matriz.h"

#include <stdlib.h>
#include <stdio.h>

int LlenarMatrizVertices(int** matrizVertices, int** matrizHeldKarp, int** matrizAdyacente, int n)
{
	int cantidadFilasHK = (1 << (n-1)) - 1,
        cantidadColumnasHK = n - 1,
        distanciaActual,
        subsetActual,
        minimoCamino = INT_MAX,
        subsetsPosibles = cantidadFilasHK,
		verticeFinal;

	LlenarMatrizN(matrizHeldKarp, cantidadFilasHK, cantidadColumnasHK, 0);

	//lleno la primera fila de HK con los valores de la matriz adyacente
	for (int columna = 0; columna < (n - 1); columna++)
	{
		matrizHeldKarp[0][columna] = matrizAdyacente[0][columna + 1];
	}

	//calculo el ultimo nivel llamando a la funcion recursiva
	for (int verticeAExcluir = 0; subsetsPosibles; verticeAExcluir++, subsetsPosibles = (subsetsPosibles >> 1))
	{
		subsetActual = cantidadFilasHK - (1 << verticeAExcluir);
		distanciaActual = 
			MatrizHeldKarpMN(matrizHeldKarp, matrizAdyacente, matrizVertices, n, subsetActual, verticeAExcluir) 
			+ matrizAdyacente[0][verticeAExcluir + 1];

		if (distanciaActual < minimoCamino)
		{
			verticeFinal = verticeAExcluir;
			minimoCamino = distanciaActual;
		}
	}
	printf("%d\n", minimoCamino);

	return verticeFinal;
}


void LlenarCaminoVertices(int* caminoVertices, int** matrizVertices, int n)
{
	int verticesARecorrer = (1 << (n-1)) - 1;
	for (int vertice = 1; vertice < n - 1; vertice++)
	{
		verticesARecorrer -= 1 << caminoVertices[vertice - 1];
		caminoVertices[vertice] = matrizVertices[verticesARecorrer][caminoVertices[vertice - 1]];
	}

}
