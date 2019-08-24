#include "lectura.h"
#include "string.h"

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