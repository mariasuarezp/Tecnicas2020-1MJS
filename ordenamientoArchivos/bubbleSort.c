#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int * arreglo, int tam){
   int i, j, temp;
   for(i = 0; i < tam; i++){
      for(j = 0; j < (tam - i) - 1; j++){
         if(arreglo[j + 1] < arreglo[j]){
            temp = arreglo[j];
            arreglo[j] = arreglo[j + 1];
            arreglo[j + 1] = temp; 
         }
      }
   }
}

void imprimirArreglo(int * arreglo, int tam){
   int i;
   for(i = 0; i < tam; i++ ){
       printf("%d ", arreglo[i]);
   }
   printf("\n");
}

int main(){
   int i, num, tam = 100000;
   int arreglo[100000];
   double tiempo;
   clock_t t;

/*
Aqui estamos creando un conjunto de elementos aleatorios,
aplico este paso aqui, porque el codigo no lee el archivo .dat
con el conjunto de datos.
*/
   for(i = 0; i < tam; i++){
      num = rand() % 100; 
      arreglo[i] = num;
   }
   printf("Arreglo inicial:\n");
   imprimirArreglo(arreglo, tam);

   time_t local; 
   time(&local);
   t = clock();

   bubbleSort(arreglo, tam);
   printf("Arreglo final:\n");
   imprimirArreglo(arreglo, tam);

   FILE * f = fopen( "bubbleSortData.txt", "a" );
   fprintf(f, "-> BUBBLESORT\n");
   fprintf(f, "Cantidad de elementos: %d\n", tam);
   fprintf(f, "Tiempo Local (Fecha y hora): %s\n", ctime(&local));

   t = clock() - t; 
   tiempo = ((double)t)/CLOCKS_PER_SEC;
   fprintf(f, "Tiempo de ejecucion: %f seg\n", tiempo); //Tiempo que tomo el programa en ejecutarse.
   fprintf(f, "\n");
   fclose(f); 
   
   return 0; 
}
