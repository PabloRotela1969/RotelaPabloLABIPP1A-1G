#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fechas.h"



void mostrarUnaFecha(eFecha fecha)
{
    printf("|%5d|%5d|%8d|\n", fecha.dia, fecha.mes, fecha.anio);
}

void mostrarEncabezadoFecha()
{
    printf("|%5s|%5s|%8s|\n", "DIA", "MES", "ANIO");
}
