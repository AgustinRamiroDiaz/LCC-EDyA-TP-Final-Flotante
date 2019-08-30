#include <assert.h>

#include "lectura.h"
#include "string.h"
#include "matriz.h"

int LeerCiudades(FILE * archivoGrafo, char vertices[CANT_MAX_VERTICES][LONG_MAX_PALABRA])
{
	int cantidadDeVertices = 0;
	char buffer [LONG_MAX_PALABRA];

	//salteo la primer linea "Ciudades"
	fscanf(archivoGrafo, "%s\r\n", buffer);

	for (; fscanf(archivoGrafo, "%[^,\r\n], ", vertices[cantidadDeVertices]); cantidadDeVertices++)
	{
		vertices[cantidadDeVertices][strlen(vertices[cantidadDeVertices])] = '\0';
	}

	return cantidadDeVertices;
}

void LeerAristas(FILE * archivoGrafo, int ** matrizAdyacente, char vertices[][LONG_MAX_PALABRA])
{
	char verticeA [LONG_MAX_PALABRA];
	char verticeB [LONG_MAX_PALABRA];
	int peso, posicionA, posicionB;

	//salteo la linea "Costos"
	fscanf(archivoGrafo, "%s\r\n", verticeA);

	do
	{
		fscanf(archivoGrafo, "%[^,],%[^,],%d\r\n", verticeA, verticeB, &peso);
		for(posicionA = 0; strcmp(vertices[posicionA], verticeA); posicionA++);
		for(posicionB = 0; strcmp(vertices[posicionB], verticeB); posicionB++);

		matrizAdyacente[posicionA][posicionB] = peso;
		matrizAdyacente[posicionB][posicionA] = peso;
	}
	while (!feof(archivoGrafo));
}

int LecturaDeDatos(int argc, char const* argv[], char const* nombreArchivoSalida, char vertices[][LONG_MAX_PALABRA], int*** matrizAdyacente)
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

	*matrizAdyacente = InstanciarMatriz(n, n);
	LlenarMatrizN(*matrizAdyacente, n, n, INT_MAX);

	LeerAristas(archivoGrafo, *matrizAdyacente, vertices);

	fclose(archivoGrafo);

	return n;
}
