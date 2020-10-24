#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include "Funciones.h"
#include "Tipos.h"
#include "Colores.h"
#include "Clientes.h"
#include "MascotasColores.h"

typedef struct
{
    int idMascota;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
    int idCliente;
}eMascota;

#endif // MASCOTAS_H_INCLUDED


void harcodearMascotas(eMascota lista[]);
void mostarUnaMascota(eMascota una,eColor colores[], int tColor, eTipo tipos[],int tTipo, eCliente clientes[], int tClie);
void prepararArrayMascotas(eMascota mascotas[], int tope);
void mostrarMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie);
int seleccionarUnaMascota(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie);
int altaMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, int idNuevo, eCliente clientes[], int tClie);
int buscarLibreMascota(eMascota mascotas[], int tMas);
int bajaMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie);
int modificaMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie);


void mostrarLasMascotasDeColorSeleccionado(eMascota mascotas[], int tMas, eColor colores[], int tCol);
void mostrarLasMascotasDeTipoSeleccionado(eMascota mascotas[], int tMas, eTipo tipos[], int tTip);
void informarLasMascotasDeMenorEdad(eMascota mascotas[], int tMas);
void listarMascotasSeparadasPorTipo(eMascota mascotas[], int tMas, eTipo tipos[], int tTip);
void listarMascotasConUnColorYUnTipo(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip);
void mostrarEloLosColoresConMasCantidadDeMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol);

