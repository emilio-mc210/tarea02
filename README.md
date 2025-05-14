# tarea02
Tarea 2 de plataformas abiertas.

Compilar con:

gcc -Wall archivo-fuente.c -o ejecutable

Funcionamiento:

El programa solicita al usuario un número entero positivo, que determina el tamaño de los arreglos. A partir de este valor, se generan dos arreglos del mismo tamaño con números aleatorios entre . Luego, el programa ordena ambos arreglos (utilizando distintos algoritmos de ordenamiento), imprime cada uno en orden ascendente y muestra el tiempo que tardó cada algoritmo en completarse.

Detalles:

    1. Para medir el tiempo de ejecución de cada algoritmo se utilizan dos variables de tipo clock_t junto con la función clock(). Se registra la hora justo antes y justo después de ejecutar el algoritmo. Luego, la duración se calcula como la diferencia entre ambos tiempos, convertida a segundos mediante un cast a double y dividiendo por la constante CLOCKS_PER_SEC.
    2. Se utiliza malloc() para generar los arreglos con memoria dinámica.

Resultados:

    1. Para tamaño 10: 
        Bubble sort: 0.000007 segundos
        Selection sort: 0.000006 segundos

    2. Para tamaño 100: 
        Bubble sort: 0.000106 segundos
        Selection sort: 0.000072 segundos

    3. Para tamaño 1000: 
        Bubble sort: 0.008009 segundos
        Selection sort: 0.004864 segundos

    4. Para tamaño 10000: 
        Bubble sort: 0.470334 segundos
        Selection sort: 0.107507 segundos