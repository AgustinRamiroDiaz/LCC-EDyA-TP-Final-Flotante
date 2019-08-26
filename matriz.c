#include "matriz.h"
#include "stdlib.h"
#include "stdio.h"

int** InstanciarMatriz(int m, int n)
{
	int** matriz = malloc(sizeof(int*) * m);
	for (int fila = 0; fila < m; fila++)
	{
		matriz[fila] = malloc(sizeof(int) * n);
	}
	return matriz;
}

void ImprimirMatriz(int** matriz, int m, int n)
{
	for (int fila = 0; fila < m; fila++)
	{
		for (int columna = 0; columna < n; columna++)
		{
			printf("%d  ", matriz[fila][columna]);
		}
		printf("\n");
	}
	printf("\n");
}

void LlenarMatrizN(int** matriz, int m, int n, int x)
{
	for (int fila = 0; fila < m; fila++)
	{
		for (int columna = 0; columna < n; columna++)
		{
			matriz[fila][columna] = x;
		}
	}
}

void LiberarMatriz(int** matriz, int cantidadFilas)
{
	for (int fila = 0; fila < cantidadFilas; fila++)
	{
		free(matriz[fila]);
	}
	free(matriz);
}