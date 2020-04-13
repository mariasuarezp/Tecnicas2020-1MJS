#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Local 
typedef struct local{
   char nombre[35];
   int idLocal; 
   int pisoLocal;
   int numLocalxPiso; 
   int estado; //Disponibilidad del espacio del local: 1=ocupado y 0=disponible
   int tipo; //Tematica del local: ropa, joyeria, comidas, electronicos
} local;

//Prototipos

local **reservarMemoriaCentroComercial(int numPiso, int numLocalxPiso);
void iniciarCentroComercial(local ** centroComercial, int numPiso, int numLocalxPiso); 
int menu();
void agregarLocal(local ** centroComercial);
void desocuparLocal(local ** centroComercial);
void buscarLocal(local ** centroComercial, int numPiso, int numLocalxPiso);
void buscarLocalDisponible(local ** centroComercial, int numPiso, int numLocalxPiso, int contador);
void cambiarNombreLocal(local ** centroComercial, int numPiso, int numLocalxPiso);
void buscarTema(local ** centroComercial, int numPiso, int numLocalxPiso);

#endif /* FUNCIONESCC_H_ */