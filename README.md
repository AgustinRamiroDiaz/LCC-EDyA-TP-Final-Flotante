Para resolver el problema utilice el algoritmo Held-Karp con una implementación recursiva. 
La implementacion mas eficiente es la Bottom-Up ya que llena la matriz Held-Karp a medida que se recorre, 
pero opte por la forma recursiva para darle otro enfoque al problema.


La idea es calcular desde un vertice i, cuanto nos cuesta llegar hasta el primer vertice del grafo 
pasando por un conjunto de vertices s.

El algoritmo plantea la una funcion recursiva 
	g(i, s)   =   min   { Cik + g(k, s - {k}) }
                k en S

Donde i es el vertice del cual partimos y s el conjunto de vertices que vamos a recorrer antes de llegar al primer vertice.
Cik representa el costo de ir desde el vertice i hacia el vertice k.

Tomo como n la cantidad de ciudades del grafo.
Mi implementacion utiliza 2 matrizes importantes: 
	-matrizHeldKarp[2^(n - 1) - 1][n - 1]: Contiene los valores de los costos posibles.
										   Las filas representan el conjunto s de vertices por los cuales quiero pasar,
										   las columnas representan el vertice del cual parto.
										   De forma matematica, matrizHeldKarp[fila][columna] = g(columna, fila).
	-matrizVertices[2^(n - 1) - 1][n - 1]: Almacena los vertices por los cuales se obtiene el menor costo.
										   Las filas y las columnas representan lo mismo que en la matrizHeldKarp.
										   De forma matematica, matrizVertices[fila][columna] = columna(g(columna, fila)).
A medida que se consigue el 

En la implementacion omiti el primer nodo en varias ocasiones para aprovechar mejor la memoria y realizar menos cuentas, 
ya que solo nos interesa el costo de g(a, {b, c, d, ...})




* Comando de compilacion:
	* gcc main.c camino.c held_karp.c lectura.c matriz.c salida.c -o main
* Comando ejecucion Linux:
	* ./main archivoEntrada archivoSalida
* Comando ejecucion Windows:
	* main.exe archivoEntrada archivoSalida
* Comando Personal:
	* cls & gcc main.c camino.c held_karp.c lectura.c matriz.c salida.c -o main & main.exe entrada5.txt salida.txt


Notas:
* Las ciudades se codifican con un indice numerico desde 0 a n - 1 y se mapean con el array de los nombres de las ciudades
* Para la implementacion de conjuntos utilice numeros que en binario tal que cada bit representa una ciudad
* Cree la matrizHeldKarp y la matrizVertices de un tamaño mas chico para ser mas eficiente con el uso de memoria omitiendo la primer ciudad
* Utilice memoria estatica para los nombres de los vertices porque pienso que no amerita ir reagrandando la memoria para este caso particular donde sabemos el maximo de ciudades


Bibliografia:

* [Held-Karp algorithm](https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm)

* [Implementacion de Held-Karp en C con el metodo Bottom Up](https://www.quora.com/Are-there-any-good-examples-of-the-Held-Karp-algorithm-in-C++-Hard-to-find-example-code-to-solve-the-traveling-salesman-problem-Everyone-wants-to-just-talk-about-theory-and-not-show-how-to-actually-do-it-What-is-the-big-secret)

* [What Is Dynamic Programming and How To Use It](https://www.youtube.com/watch?v=vYquumk4nWw)

* [Traveling Salesperson Problem - Dynamic Programming](https://www.youtube.com/watch?v=XaXsJJh-Q5Y)

* [Dynamic Programming I: Fibonacci, Shortest Paths](https://www.youtube.com/watch?v=OQ5jsbhAv_M)
