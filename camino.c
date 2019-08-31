#include "camino.h"
#include "held_karp.h"
#include "constantes.h"
#include "matriz.h"

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int LlenarMatrizVertices(int** matrizVertices, int** matrizAdyacente, int n)
{
	//la matriz Held-Karp tiene 2^(n-1) filas que representan 
	//todos los subconjuntos de los n-1 vertices excluyendo el primer vertice
	//y tiene n-1 columnas que representan los n-1 vertices excluyendo el primer vertice
	int cantidadFilasHK = (1 << (n-1)) - 1,
		cantidadColumnasHK = n - 1;

	//la fila n representa el numero n en binario que representa el conjunto s
	//la columna n representa el vertice n sin contar el primer vertice
	int** matrizHeldKarp = InstanciarMatriz(cantidadFilasHK, cantidadColumnasHK);

	int distanciaActual,
        subsetActual,
		distanciaHK,
        minimoCamino = INT_MAX,
        subsetsPosibles = cantidadFilasHK,
		verticeFinal;

	//lleno la matriz de 0
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
		distanciaHK = MatrizHeldKarpMN(matrizHeldKarp, matrizAdyacente, matrizVertices, n, subsetActual, verticeAExcluir);
		
		if ((distanciaHK != CAMINO_IMPOSIBLE) && (matrizAdyacente[0][verticeAExcluir + 1] != CAMINO_IMPOSIBLE))
		{
			distanciaActual = distanciaHK + matrizAdyacente[0][verticeAExcluir + 1];

			if (distanciaActual < minimoCamino)
			{
				verticeFinal = verticeAExcluir;
				minimoCamino = distanciaActual;
			}
		}
	}

	printf("%d\n", minimoCamino);

	LiberarMatriz(matrizHeldKarp, cantidadFilasHK);

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
