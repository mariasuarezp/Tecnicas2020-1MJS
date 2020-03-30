#include <stdio.h>
#include <string.h>

typedef struct persona{
   char nombre[15];
   int fecha[3]; //Fecha de nacimiento(dia, mes, anio)
} persona;

enum meses{
   NOVIEMBRE = 11,
   DICIEMBRE = 12
};
 
void nuevaPersona(persona[][5], int[]); //Crea una persona
int menu(); //Imprime el menu para el usuario
void mostrarCalendario(persona[][5], int[]); //Imprime el calendario con todos los cumpleanios
void mostrarCumpleanios(persona[][5], int[]); //Imprime los cumpleanios de un mes seleccionado
void nombreCumpleanios(persona[][5], int[]); //Imprime el cumpleanios de una persona(nombre) seleccionada
