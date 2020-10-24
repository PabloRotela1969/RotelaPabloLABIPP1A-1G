#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED
#include "Funciones.h"


typedef struct
{
    int idColor;
    char nombreColor[20];

}eColor;

#endif // COLORES_H_INCLUDED


void harcodearColores(eColor lista[]);

void mostrarColores( eColor colores[], int tCol);
int seleccionarUnColor( eColor colores[], int tCol);

