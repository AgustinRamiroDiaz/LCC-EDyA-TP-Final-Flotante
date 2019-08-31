#include "held_karp.h"
#include "constantes.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int MatrizHeldKarpMN(int** matrizHeldKarp, int** matrizAdyacente, int** matrizVertices, int n, int fila, int columna)
{
	if (matrizHeldKarp[fila][columna])
	{
		return matrizHeldKarp[fila][columna];
	}

	if (fila & (1 << columna)) return CAMINO_IMPOSIBLE;

	int subsetActual,
		distanciaActual,
		distanciaHK,
		subsetsPosibles = fila,
		minimoCamino = INT_MAX;

	for (int verticeAExcluir = 0; subsetsPosibles; verticeAExcluir++, subsetsPosibles = (subsetsPosibles >> 1))
	{
		if (subsetsPosibles & 1)
		{
			subsetActual = fila - (1 << verticeAExcluir);
			distanciaHK = MatrizHeldKarpMN(matrizHeldKarp, matrizAdyacente, matrizVertices, n, subsetActual, verticeAExcluir);

			if ((distanciaHK != CAMINO_IMPOSIBLE) && (matrizAdyacente[columna + 1][verticeAExcluir + 1] != CAMINO_IMPOSIBLE))
			{
				distanciaActual = distanciaHK + matrizAdyacente[columna + 1][verticeAExcluir + 1];

				if (distanciaActual < minimoCamino)
				{
					minimoCamino = distanciaActual;
					matrizVertices[fila][columna] = verticeAExcluir;
				}
			}
		}
	}

	if (minimoCamino == INT_MAX)
		minimoCamino = CAMINO_IMPOSIBLE;

	matrizHeldKarp[fila][columna] = minimoCamino;

	return minimoCamino;
}