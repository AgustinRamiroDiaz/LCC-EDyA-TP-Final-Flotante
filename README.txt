Para resolver el problema utilice el algoritmo Held-Karp con una implementaci�n recursiva. 
La implementaci�n m�s eficiente es la Bottom-Up ya que llena la matriz Held-Karp a medida que se recorre, pero opte por la forma recursiva para darle otro enfoque al problema.


La idea es calcular desde un v�rtice i, cuanto nos cuesta llegar hasta el primer v�rtice pasando por un conjunto de v�rtices s.

El algoritmo plantea la una funcion recursiva 
	g(i, s)   =   min   { Cik + g(k, s - {k}) }
		     k en S

Donde i es el v�rtice del cual partimos y s el conjunto de v�rtices que vamos a recorrer antes de llegar al primer v�rtice.
Cik representa el costo de ir desde el v�rtice i hacia el v�rtice k.






-Comando:
gcc TSP.c camino.c held_karp.c lectura.c matriz.c salida.c -o TSP-HeldKarp


-Bibliograf�a:

Held�Karp algorithm:
	https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm

Implementaci�n de Held-Karp en C con el metodo Bottom Up:
	https://www.quora.com/Are-there-any-good-examples-of-the-Held-Karp-algorithm-in-C++-Hard-to-find-example-code-to-solve-the-traveling-salesman-problem-Everyone-wants-to-just-talk-about-theory-and-not-show-how-to-actually-do-it-What-is-the-big-secret

What Is Dynamic Programming and How To Use It:
	https://www.youtube.com/watch?v=vYquumk4nWw 

Traveling Salesperson Problem - Dynamic Programming:
	https://www.youtube.com/watch?v=XaXsJJh-Q5Y

Dynamic Programming I: Fibonacci, Shortest Paths:
	https://www.youtube.com/watch?v=OQ5jsbhAv_M