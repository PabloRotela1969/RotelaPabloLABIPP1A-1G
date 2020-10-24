#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "Funciones.h"

typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED


int seleccionarServicios(eServicio servicios[], int tSer);

void mostrarServicios( eServicio servicios[], int tSer);

void harcodearServicios(eServicio lista[]);
