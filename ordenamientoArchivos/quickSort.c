#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int particion(int * arreglo, int left, int right){
   int i, j, pivote, temp;
   i = (left - 1); 
   pivote = arreglo[right];
   for(j = left; j <= right - 1; j++){
      if(arreglo[j] < pivote){
         i++;
         temp = arreglo[i];
         arreglo[i] = arreglo[j];
         arreglo[j] = temp; 
      }
   }
   temp = arreglo[i + 1];
   arreglo[i + 1] =arreglo[right];
   arreglo[right] = temp;

   return (i + 1);
}

void quickSort(int * arreglo, int left, int right){
   int i, indice, temp;

   if(left < right){
      indice = particion(arreglo, left, right);
      quickSort(arreglo, left, indice - 1);
      quickSort(arreglo, indice + 1, right);
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
   int i, n, num, tam = 100000; 
   int arreglo[100000];
   n = sizeof(arreglo)/sizeof(arreglo[0]);
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
   imprimirArreglo(arreglo, tam);

   time_t local; 
   time(&local);
   t = clock();

   quickSort(arreglo, 0, n - 1);
   printf("Arreglo final:\n");
   imprimirArreglo(arreglo, tam);

   FILE * f = fopen( "quickSortData.txt", "a" );
   fprintf(f, "-> QUICKSORT\n");
   fprintf(f, "Cantidad de elementos: %d\n", tam);
   fprintf(f, "Tiempo Local (Fecha y hora): %s\n", ctime(&local));

   t = clock() - t; 
   tiempo = ((double)t)/CLOCKS_PER_SEC;
   fprintf(f, "Tiempo de ejecucion: %f seg\n", tiempo); //Tiempo que tomo el programa en ejecutarse.
   fprintf(f, "\n");
   fclose(f); 
   
   return 0; 
}