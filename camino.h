#ifndef CAMINO
#define CAMINO

//calcula la matriz de todos los vertices que se recorren a partir del minimo camino utilizando Held-Karp
int LlenarMatrizVertices(int** matrizVertices, int** matrizAdyacente, int n);

//llena "caminoVertices" con los vertices a recorrer del minimo camino
void LlenarCaminoVertices(int* caminoVertices, int** matrizVertices, int n);

#endif 