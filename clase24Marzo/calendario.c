#include "calendario.h"

void nuevaPersona(persona calendario[12][5], int cantPersona[12]){
   int mes;
   persona alguien; 

   printf("Ingrese el nombre de la persona:\n");
   scanf("%s", alguien.nombre);
   printf("Ingrese la fecha de nacimiento:\n");
   fflush(stdin);
   printf("Dia:\n");
   scanf("%d", &alguien.fecha[0]);
   printf("Mes:\n");
   scanf("%d", &alguien.fecha[1]);
   printf("Anio:\n");
   scanf("%d", &alguien.fecha[2]);

//De parte de Daniel
   if(alguien.fecha[1] == NOVIEMBRE)
      printf("Sugoi?\n");
   if(alguien.fecha[1] == DICIEMBRE)
      printf("Merry Christmas\n");
   
   mes = alguien.fecha[1]-1;
   if(cantPersona[mes] >= 5){
      printf("Lo sentimos, ya tenemos muchos cumpleanios ese mes");
      return;
   }
   else{
      calendario[mes][cantPersona[mes]++] = alguien;
      printf("El cumpleanios de %s fue guardado en el calendario exitosamente\n", alguien.nombre);
      printf("Cumpleanios: [%d|%d|%d] \n", alguien.fecha[0], alguien.fecha[1], alguien.fecha[2]);
      printf("\n");
   }
   return;
}

int menu(){
   int opc;
   printf("1. Ingresar cumpleanios\n");
   printf("2. Mostrar calendario\n");
   printf("3. Busqueda cumpleanios por mes\n");
   printf("4. Busqueda cumpleanios por nombre\n");
   printf("0. Salir\n");
   printf(">Escoge un opcion, por favor:\n");
   scanf("%d", &opc);
   printf("\n");
   return opc; 
}

void mostrarCalendario(persona calendario[12][5], int cantPersona[12]){
   int i,j, dia, mes;

   printf("Ingrese el dia de hoy:\n");
   scanf("%d", &dia);
   printf("Ingrese el mes actual:\n");
   scanf("%d", &mes);

   printf("Calendario:\n");
   for(i = 0; i < 12; i++){
      for(j = 0; j < cantPersona[i]; j++){
         if(calendario[i][j].fecha[0] == dia && calendario[i][j].fecha[1] == mes){
            printf(">");
         }
         printf("[%s %d %d]\n", calendario[i][j].nombre, calendario[i][j].fecha[0], calendario[i][j].fecha[1]);
      }
   }
   return;
}

void mostrarCumpleanios(persona calendario[12][5], int cantPersona[12]){
   int i, mes;

   printf("Ingrese el mes del cumpleanios que busca:\n");
   scanf("%d", &mes);
   printf("Cumpleanios:\n");
   for(i = 0; i < cantPersona[--mes]; i++){
      printf("[%s %d %d]\n", calendario[mes][i].nombre, calendario[mes][i].fecha[0], calendario[mes][i].fecha[2]);
   }
   printf("\n");
   return; 
}

void nombreCumpleanios(persona calendario[12][5], int cantPersona[12]){
   int i, j;
   char nombres[15];

   printf("Ingrese el nombre de la persona cuyo cumpleanios esta buscando:\n");
   scanf("%s", nombres);
   printf("\n");
   for(i = 0; i < 12; i++){
      for(j = 0; j < cantPersona[i]; j++){
         if(calendario[i][j].nombre == nombres){
            printf("El cumpleanios de %s es [%d|%d]\n", nombres, calendario[i][j].fecha[0], calendario[i][j].fecha[1]);
            return;
         }
      }
   }
   printf("El nombre %s no existe en el calendario. Por favor intentelo nuevamente\n\n", nombres);
   nombreCumpleanios(calendario, cantPersona);  
   return;
}









