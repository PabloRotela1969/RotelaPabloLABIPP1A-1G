#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"




void harcodearTipos(eTipo lista[])
{
    lista[0] = (eTipo) {1000, "Ave"};
    lista[1] = (eTipo) {1001, "Perro"};
    lista[2] = (eTipo) {1002, "Gato"};
    lista[3] = (eTipo) {1003, "Roedor"};
    lista[4] = (eTipo) {1004, "Pez"};

}

void mostrarTipos( eTipo tipos[], int tTip)
{
    printf(" id  tipos \n");
    for(int i=0;i<tTip;i++)
    {
        printf(" %5d  %20s \n",tipos[i].idTipo,tipos[i].descripcion);

    }

}



int seleccionarUnTipo( eTipo tipos[], int tTip)
{
    int opcion;
    int noEncontrado;
    int indice;
    do
    {
        noEncontrado = 1;
        printf("\n INGRESE EL TIPO POR SU CODIGO \n");
        printf(" id   tipo \n");
        for(int i=0;i<tTip;i++)
        {
            printf(" %5d  %20s \n",tipos[i].idTipo,tipos[i].descripcion);

        }

        opcion = inputInt("Ingrese el id del tipo : ");
        for(int i=0;i<tTip;i++)
        {

            if(tipos[i].idTipo == opcion)
            {
                indice = i;
                noEncontrado = 0;
                break;
            }


        }

    }while(noEncontrado);
     if(!noEncontrado)
    {
         printf("\n_________________________________________________________\n");
        printf(" %5d  %20s \n",tipos[indice].idTipo,tipos[indice].descripcion);
    }
    return opcion;
}
