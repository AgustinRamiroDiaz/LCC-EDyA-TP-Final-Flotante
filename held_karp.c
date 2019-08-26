#include "held_karp.h"
#include "constantes.h"

#include <stdio.h>
#include <stdlib.h>

int MatrizHeldKarpMN(int** matrizHeldKarp, int** matrizAdyacente, int** matrizVertices, int n, int fila, int columna)
{

	if (matrizHeldKarp[fila][columna])
	{
		return matrizHeldKarp[fila][columna];
	}

	if (fila & (1 << columna)) return INT_MAX;

	int subsetActual,
		distanciaActual,
		subsetsPosibles = fila,
		minimoCamino = INT_MAX;

	for (int verticeAExcluir = 0; subsetsPosibles; verticeAExcluir++, subsetsPosibles = (subsetsPosibles >> 1))
	{
		if (subsetsPosibles & 1)
		{
			subsetActual = fila - (1 << verticeAExcluir);
			distanciaActual = 
				MatrizHeldKarpMN(matrizHeldKarp, matrizAdyacente, matrizVertices, n, subsetActual, verticeAExcluir) 
				+ matrizAdyacente[columna + 1][verticeAExcluir + 1];

			if (distanciaActual < minimoCamino)
			{
				minimoCamino = distanciaActual;
				matrizVertices[fila][columna] = verticeAExcluir;
			}
		}
	}

	matrizHeldKarp[fila][columna] = minimoCamino;

	return minimoCamino;
}