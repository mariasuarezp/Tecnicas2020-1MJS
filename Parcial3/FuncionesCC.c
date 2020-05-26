#include "FuncionesCC.h"

/* Funcion que reserva la memoria de la matriz */
local ** reservarMemoriaCentroComercial(int numPiso, int numLocalxPiso){
   int i;
   local **centroComercial = malloc(numPiso * sizeof(local*));
   if(centroComercial != NULL){
      for(i = 0; i < numPiso; i++){
         centroComercial[i] = malloc(numLocalxPiso * sizeof(local));
         if(centroComercial[i] == NULL){
            printf("Hubo un error reservando memoria\n");
            break;
         }
      }
   }
   else{
      printf("Hubo un error reservando la memoria\n");
   }
   return centroComercial; 
}


/* Funcion que inicializa todos los locales como disponibles (Es decir en estado 0)*/
void iniciarCentroComercial(local **centroComercial, int numPiso, int numLocalxPiso){
   int i, j;
   for(i = 0; i < numPiso; i++){
      for(j = 0; j < numLocalxPiso; j++){
         centroComercial[i][j].idLocal = 0;
         centroComercial[i][j].estado = 0;
      }
   }
   return; 
}

/* Imprime el menu con todas las opciones y retorna la eleccion del usuario*/
int menu(){ 
   int opcion;

   printf("=======================================\n");
   printf("BIENVENIDO AL CENTRO COMERCIAL TPP\n");
   printf("=======================================\n");
   printf("1. Agregar Local\n");
   printf("2. Desocupar Local\n");
   printf("3. Buscar Local\n");
   printf("4. Buscar disponibilidad de locales\n");
   printf("5. Cambiar nombre de local\n");
   printf("6. buscarTema\n");
   printf("7. Salir\n");
   printf("======================================\n");
   printf("*Escoja una opcion, por favor:\n");
   scanf("%d", &opcion);
   printf("\n");

   return opcion; 
}

/* Funcion que agrega un nuevo local al centro comercial (ocupar un local) */
void agregarLocal(local ** centroComercial){
   local nuevo;
   int piso, numLocal, clase;

   printf("*Para ingresar un nuevo local, por favor brinde la siguiente informacion:\n");
   printf("->Ingrese el piso donde se va a ubicar el nuevo local:\n");
   scanf("%d", &piso);
   printf("->Ingrese la posicion del local en el piso:\n");
   scanf("%d", &numLocal);

   if(centroComercial[piso][numLocal].estado == 1){
      printf("La ubicacion del local que solicitaste ya esta ocupado.\n");
      printf("Por favor, vuelve a intentarlo\n");
      agregarLocal(centroComercial);
   }
   else{
      printf("Ingrese el nombre del local:\n");
      scanf("%s", nuevo.nombre);
      printf("Escoja la tematica del local:\n");
      printf("Ingrese el numero de su eleccion:[1.ropa, 2.joyeria, 3.comidas, 4.electronicos]\n");
      scanf("%d", &nuevo.tipo);
      nuevo.idLocal = rand();
      nuevo.pisoLocal = piso;
      nuevo.numLocalxPiso = numLocal;
      nuevo.estado = 1;   
      centroComercial[piso][numLocal] = nuevo;
      printf("El local %s ha sido ingresado exitosamente\n", centroComercial[piso][numLocal].nombre);
   }
   return;  
}

/* Funcion que desocupa un local, es decir que cambia el estado del local a disponible*/
void desocuparLocal(local ** centroComercial){
   int piso, numLocal;

   printf("->Ingrese el piso donde se va a ubicar el local que quiere desocupar:\n");
   scanf("%d", &piso);
   printf("->Ingrese la posicion del local que quiere desocupar:\n");
   scanf("%d", &numLocal);

   if(centroComercial[piso][numLocal].estado == 0){
      printf("La ubicacion del local que solicitaste ya esta desocupado");
      return;
   }
   else{
      centroComercial[piso][numLocal].estado = 0;
      printf("El local %s ha sido desalojado y ahora esta disponible\n", centroComercial[piso][numLocal].nombre );
   }
   return; 
}

/* Funcion que brinda la informacion de un local al ingresar su nombre*/
void buscarLocal(local ** centroComercial, int numPiso, int numLocalxPiso ){
   int i, j; 
   char nombreLocal[35];
   
   printf("->Ingrese el nombre del local que esta buscando:\n");
   scanf("%s", nombreLocal);
   for(i = 0; i < numPiso; i++){
      for(j = 0; j < numLocalxPiso; j++){
         if(!strcmp(centroComercial[i][j].nombre, nombreLocal) && centroComercial[i][j].estado == 1){
            printf("El local %s fue encontrado exitosamente\n", nombreLocal); //Borrar
            printf("======================================\n");
            printf("Local: %s\n", centroComercial[i][j].nombre);
            printf("ID: %d\n", centroComercial[i][j].idLocal);
            printf("Piso: %d\n", centroComercial[i][j].pisoLocal);
            printf("Numero del local: %d\n", centroComercial[i][j].numLocalxPiso);
            printf("Tematica: %d\n", centroComercial[i][j].tipo);
            printf("Estado: Ocupado\n");
            printf("=======================================\n");
            return;
         }
      }
   }
   printf("El nombre del local que solicitaste no existe\n");
   return; 
}

/* Esta funcion muestra la cantidad de locales disponibles y ocupados. 
Esta brinda la ubicacion de los locales ocupados*/
void buscarLocalDisponible(local ** centroComercial, int numPiso, int numLocalxPiso, int contador){
   int i, j, totalLocales, localesDisponibles;
   totalLocales = numPiso * numLocalxPiso; 
   localesDisponibles = totalLocales - contador;
   printf("========================================\n");
   printf("*Locales disponibles: %d\n", localesDisponibles);
   printf("*Locales Ocupados: %d\n", contador);
   printf("========================================\n");
   printf("Ubicacion de los locales ocupados:\n");
   for(i = 0; i < numPiso; i++){
      for(j = 0; j < numLocalxPiso; j++){
         if(centroComercial[i][j].estado == 1){
            printf("->%s esta ubicado en el piso %d local %d\n", centroComercial[i][j].nombre, centroComercial[i][j].pisoLocal, centroComercial[i][j].numLocalxPiso);
         }
      }
   }
   return;
}

/*Esta funcion modifica el nombre de un local que se encuentra ocupado */
void cambiarNombreLocal(local ** centroComercial, int numPiso, int numLocalxPiso){
   int i, j; 
   char nombreLocal[35];
   
   printf("->Ingrese el nombre del local que quiere cambiar:\n");
   scanf("%s", nombreLocal);
   for(i = 0; i < numPiso; i++){
      for(j = 0; j < numLocalxPiso; j++){
         if(!strcmp(centroComercial[i][j].nombre, nombreLocal) && centroComercial[i][j].estado == 1){
            printf("*El local %s ha sido encontrado exitosamente.\n", centroComercial[i][j].nombre);
            printf("->Ahora, ingrese el nuevo nombre del local:\n");
            scanf("%s", centroComercial[i][j].nombre); 
            printf("*El nuevo nombre del local es %s\n", centroComercial[i][j].nombre);
            return;
         }
      }
   }
   printf("El nombre del local que solicitaste no existe\n");
   return; 
}

/* Esta funcion informa la tematica del local que se ingrese*/ 
void buscarTema(local ** centroComercial, int numPiso, int numLocalxPiso){
   int i, j;
   enum tema clase; 
   printf("Tematicas: 1.ropa, 2.joyeria, 3.comidas, 4. electronicos\n");
   printf("Escoja la tematica que esta buscando:\n");
   scanf("%d", &clase);
   for(i = 0; i < numPiso; i++){
      for(j = 0; j < numLocalxPiso; j++){
         if(centroComercial[i][j].tipo == clase && centroComercial[i][j].estado == 1){
            if(clase == 1){
               printf("->El local %s tiene tematica de ropa\n", centroComercial[i][j].nombre);
               continue;
            }
            else if(clase == 2){
               printf("->El local %s tiene tematica de joyeria\n", centroComercial[i][j].nombre);
               continue;
            }
            else if(clase == 3){
               printf("->El local %s tiene tematica de comidas\n", centroComercial[i][j].nombre);
               continue;
            }
            else if(clase == 4){
               printf("->El local %s tiene tematica de electronicos\n", centroComercial[i][j].nombre);
               continue;
            }
         }
      }
   }
   return;
}

//Funciones de ordenamiento

void ordenarNombre(local **centroComercial, int numPiso, int numLocalxPiso){
}



//Funciones de archivos

int cargarDatos(local ** centroComercial){
   FILE * f = fopen("datosCC.dat", "rb");
   if(f == NULL){
      return 0; 
   }
   fread(centroComercial, sizeof(local), 1, f);
   fclose(f);
   return 1; 
}

void guardarDatos(local ** centroComercial){
   FILE *f = fopen("datosCC.dat", "wb");
   fwrite(centroComercial, sizeof(local), 1, f);
   fclose(f);
   return;
}




