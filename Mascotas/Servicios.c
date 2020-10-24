#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"




void mostrarServicios( eServicio servicios[], int tSer)
{
    printf(" id  servicios \n");
    for(int i=0;i<tSer;i++)
    {
        printf(" %5d  %20s %4.3f\n",servicios[i].idServicio, servicios[i].descripcion,servicios[i].precio);

    }

}


int seleccionarServicios(eServicio servicios[], int tSer)
{
    int opcion;
    int noEncontrado;
    do
    {
        noEncontrado = 1;
        printf("\n INGRESE EL SERVICIO POR SU CODIGO \n");
        mostrarServicios(servicios,tSer);

        opcion = inputInt("Ingrese el id del servicio : ");
        for(int i=0;i<tSer;i++)
        {

            if(servicios[i].idServicio == opcion)
            {
                noEncontrado = 0;
                break;
            }
        }
        if(noEncontrado)
        {
            printf("\nNO SE ENCUENTRA EL NUMERO INGRESADO, VUELVA A INTENTARLO\n");
        }
    }
    while(noEncontrado);
    return opcion;
}



void harcodearServicios(eServicio lista[])
{
    lista[0] = (eServicio) {20000, "Corte",250};
    lista[1] = (eServicio) {20001, "Desparasitado",300};
    lista[2] = (eServicio) {20002, "Castrado",400};
}

