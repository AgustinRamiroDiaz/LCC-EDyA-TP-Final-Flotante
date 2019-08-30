#ifndef LECTURA
#define LECTURA

#include <stdio.h>
#include "constantes.h"

//guarda los nombres de las ciudades en "vertices" y retorna la cantidad
int LeerCiudades(FILE * archivoGrafo, char vertices[CANT_MAX_VERTICES][LONG_MAX_PALABRA]);

//guarda los valores de las aristas del grafo en "matrizAdyacente"
void LeerAristas(FILE * archivoGrafo, int ** matrizAdyacente, char vertices[][LONG_MAX_PALABRA]);

//lee y guarda toda la informacion necesaria a partir de los argumentos pasados al main y de los archivos
int LecturaDeDatos(int argc, char const* argv[], char const* nombreArchivoSalida, char vertices[][LONG_MAX_PALABRA], int*** matrizAdyacente);

#endif