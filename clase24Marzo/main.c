#include <stdio.h>
#include <string.h>
#include "calendario.h"

//Grupo: Daniel Caicedo y Maria Jose Suarez
int main(){
   int opc;
   int cantPersona[12]; //Guarda el numero de personas por mes
   persona calendario[12][5]; //Guarda los meses en las filas y la capacidad de gente en las columnas
   
   do{
      opc = menu();
      switch(opc){
         case 1:
            nuevaPersona(calendario, cantPersona);
            break;
         case 2:
            mostrarCalendario(calendario, cantPersona);
            break;
         case 3:
            mostrarCumpleanios(calendario, cantPersona);
            break;
         case 4:
            nombreCumpleanios(calendario, cantPersona);
            break;
         case 0:
            break;
         default: printf("Escoge una opcion valida por favor\n\n");
      }
   }while(opc != 0);

   return 0; 
}



