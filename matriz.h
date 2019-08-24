#ifndef MATRIZ
#define MATRIZ

//reserva la memoria para una matriz
int** InstanciarMatriz(int m, int n);

//imprime la matriz
void ImprimirMatriz(int** matriz, int m, int n);

//llena la matriz con "x"
void LlenarMatrizN(int** matriz, int m, int n, int x);

#endif