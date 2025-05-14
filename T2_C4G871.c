#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void llenar_arr(int *arr, int n){
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100001; //Numero aleatorio entre 0 y 100000
    }
}

double bubble_sort(int *arr, int n){
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();
    
    //Reordenamiento con bubble sort
    for(int i=0; i<n-1; i++){
        //Se recorre el arreglo (cada vez un indice menos por estar en la posicion correcta)
        for(int j=0; j<n-i-1; j++){ 
            //Se acomoda el valor maximo en su posicion correcta
            if(arr[j] > arr[j+1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }

    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    //Imprir arreglo
    printf("\nEl arreglo 1 con bubble sort es: ");
    for(int i=0; i<n; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    
    return tiempo;
}

double selection_sort(int *arr, int n){
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();
    
    //Reordenamiento con selection sort
    for(int i=0; i<n-1; i++){
        int indice_minimo = i;

        //Encontrar el valor minimo
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[indice_minimo]){
                indice_minimo = j;
            }
        }

        //Se acomoda el valor minimo en la posicion correcta
        int aux = arr[i];
        arr[i] = arr[indice_minimo];
        arr[indice_minimo] = aux;
    }

    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    //Imprir arreglo
    printf("El arreglo 2 con selection sort es: ");
    for(int i=0; i<n; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
    
    return tiempo;
}

int main(){
    int tamano;
    double tiempo_bubble, tiempo_selection;
    printf("Digite el tamano para los arreglos: ");
    scanf("%i", &tamano);

    int *arr1 = (int *)malloc(tamano * sizeof(int));
    int *arr2 = (int *)malloc(tamano * sizeof(int));

    //Llenar de forma aleaoria
    srand(time(NULL));
    llenar_arr(arr1, tamano);
    llenar_arr(arr2, tamano);

    //Imprimir arreglos
    printf("El arreglo 1 sin ordenar es: ");
    for(int i=0; i<tamano; i++){
        printf("%i ", arr1[i]);
    }
    printf("\n");
    printf("El arreglo 2 sin ordenar es: ");
    for(int i=0; i<tamano; i++){
        printf("%i ", arr2[i]);
    }
    printf("\n");

    //Bubble sort
    tiempo_bubble = bubble_sort(arr1, tamano);

    //Selection sort
    tiempo_selection = selection_sort(arr2, tamano);

    printf("\nEl tiempo de ejecucion del buble sort es de: %f segundos\n", tiempo_bubble);
    printf("El tiempo de ejecucion del selection sort es de: %f segundos\n", tiempo_selection);

    //Liberar memoria
    free(arr1);
    free(arr2);
    
    return 0;
}