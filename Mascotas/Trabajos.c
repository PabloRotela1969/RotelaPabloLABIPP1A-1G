
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajos.h"




void prepararVectorTrabajo(eTrabajo lista[],int cantidad)
{
    for(int i = 0; i<cantidad; i++)
    {
        lista[i].isEmpty = 1;
    }
}


