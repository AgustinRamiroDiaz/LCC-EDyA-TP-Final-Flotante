#ifndef HELDKARP
#define HELDKARP

//la columna representa el vertice desde el cual quiero llegar
//la fila n representa el subconjunto del grafo a recorrer en binario
//el primer nodo (el cual se omite en la matriz) es al cual quiero llegar

//calcula el valor de la matrizHeldKarp en la fila y columna de manera recursiva
//almacenando el vertice por el cual se pasa en caminoVertices
int MatrizHeldKarpMN(int** matrizHeldKarp, int** matrizAdyacente, int** matrizVertices, int n, int fila, int columna);

#endif 