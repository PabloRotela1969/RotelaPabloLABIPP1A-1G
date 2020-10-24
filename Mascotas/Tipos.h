#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#include "Funciones.h"


typedef struct
{
    int idTipo;
    char descripcion[20];
}eTipo;


#endif // TIPOS_H_INCLUDED
void harcodearTipos(eTipo lista[]);

int seleccionarUnTipo( eTipo tipos[], int tTip);
void mostrarTipos( eTipo tipos[], int tTip);


