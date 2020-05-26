#include "FuncionesCC.h"
#include <stdio.h>

int main(){
   setbuf(stdout, NULL);
   local **centroComercial = NULL; 
   int numPiso, numLocalxPiso, opcion, contador = 0, archivo; //El contador es la cantidad de locales ocupados
   HOME:
   printf("NUEVO CENTRO COMERCIAL\n");
   printf("*Cuantos pisos tiene el centro comercial?\n");
   scanf("%d", &numPiso);
   printf("*Cuantos locales por piso hay en el centro comercial?\n");
   scanf("%d", &numLocalxPiso);

   archivo = cargarDatos(centroComercial);
   if(archivo == 0){
      printf("Hubo un problema leyendo el archivo\n"); 
      goto HOME;   
   }
   else{
      centroComercial = reservarMemoriaCentroComercial(numPiso, numLocalxPiso);
      if(centroComercial != NULL){
         iniciarCentroComercial(centroComercial, numPiso, numLocalxPiso);
      }
      else{
         printf("Hubo un error asignando memoria\n");
      }
   }

   do{
      opcion = menu();
      switch(opcion){
         case 1:
            agregarLocal(centroComercial);
            contador++;
            break;
         case 2:
            desocuparLocal(centroComercial);
            contador--;
            break;
         case 3:
            buscarLocal(centroComercial, numPiso, numLocalxPiso);
            break;
         case 4:
            buscarLocalDisponible(centroComercial, numPiso, numLocalxPiso, contador);
            break;
         case 5:
            cambiarNombreLocal(centroComercial, numPiso, numLocalxPiso);
            break;
         case 6:
            buscarTema(centroComercial, numPiso, numLocalxPiso);
            break;
         case 7:
            break;
         default: printf("Escoge una opcion valida por favor\n");
      }
   }while(opcion != 7);
   guardarDatos(centroComercial);
   free(centroComercial);
   return 0;
}
