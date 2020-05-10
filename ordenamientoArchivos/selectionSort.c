#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int * arreglo, int tam){
   int i, j, min, temp;
   for(i = 0; i < tam - 1; i++){
      min = i;
      for(j = i + 1; j < tam; j++){
         if(arreglo[j] < arreglo[min]){
            min = j;
         }
      }
      temp = arreglo[i];
      arreglo[i] = arreglo[min];
      arreglo[min] = temp;
   }
}

void imprimirArreglo(int * arreglo, int tam){
   int i;
   for(i = 0; i < tam; i++){
      printf("%d ", arreglo[i]);
   }
   printf("\n");
}

int main(){
   int i, num, tam = 100000;
   int arreglo[100000];
   double tiempo;
   clock_t t; 

/*Aqui estamos creando un conjunto de elementos aleatorios,
aplico este paso aqui, porque el codigo no lee el archivo .dat
con el conjunto de datos.
*/
   for(i = 0; i < tam; i++){
      num = rand() % 100; 
      arreglo[i] = num;
   }
   
   printf("Arreglo inicial:\n");
   imprimirArreglo(arreglo, tam); //Imprime el arreglo sin organizar
   
   time_t local; 
   time(&local);
   t = clock();

   FILE * f = fopen( "selectionData.txt", "a" );
   fprintf(f, "-> SELECTION SORT\n");
   fprintf(f, "Cantidad de elementos: %d\n", tam);
   fprintf(f, "Tiempo Local (Fecha y hora): %s\n", ctime(&local));

   selectionSort(arreglo, tam);
   printf("Arreglo final:\n");
   imprimirArreglo(arreglo, tam);

   t = clock() - t; 
   tiempo = ((double)t)/CLOCKS_PER_SEC;
   
   fprintf(f, "Tiempo de ejecucion: %f seg\n", tiempo); //Tiempo que tomo el programa en ejecutarse.
   fprintf(f, "\n");
   fclose(f); 
  
   return 0;
}

