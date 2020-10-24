#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "Fecha.h"
#include "Funciones.h"
#include "Mascotas.h"
#include "Servicios.h"


typedef struct
{
    int idTrabajo;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;


#endif // TRABAJOS_H_INCLUDED



void mostrarTrabajos(eTrabajo trabajos[], int tTra, eMascota mascotas[], int tMas, eServicio servicios[], int tSer,eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie);
int altaTrabajos(eTrabajo trabajos[], int tTra, eMascota mascotas[], int tMas,eColor colores[], int tCol, eTipo tipos[], int tTip, eServicio servicios[], int tSer, int idNuevoTrabajo, eCliente clientes[], int tClie);
void harcodearTrabajos(eTrabajo lista[]);
void prepararArrayTrabajos(eTrabajo trabajos[], int tope);
void conUnaMascotaMostrarTrabajosQueSeLeHicieron(eTrabajo trabajos[], int tTra, eMascota mascotas[], int tMas,eColor colores[], int tCol, eTipo tipos[], int tTip, eServicio servicios[], int tSer,  eCliente clientes[], int tClie);


