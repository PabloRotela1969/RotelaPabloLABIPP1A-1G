#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"

void harcodearClientes(eCliente lista[])
{
    lista[0] = (eCliente) {10, "Pablo", 'm'};
    lista[1] = (eCliente) {11, "Alejandra", 'f'};
    lista[2] = (eCliente) {12, "Claudia", 'f'};
    lista[3] = (eCliente) {13, "Jose", 'm'};
    lista[4] = (eCliente) {14, "Laura", 'f'};

}




int seleccionarUnCliente( eCliente clientes[], int tClie)
{
    int opcion;
    int noEncontrado;
    int indice;
    do
    {
        noEncontrado = 1;
        printf("\n INGRESE EL CLIENTE POR SU CODIGO \n");
        printf(" id   CLIENTE    SEXO \n");
        for(int i=0;i<tClie;i++)
        {
            printf(" %5d  %20s %1c \n",clientes[i].idCliente,clientes[i].nombre, clientes[i].sexo);

        }

        opcion = inputInt("Ingrese el id del tipo : ");
        for(int i=0;i<tClie;i++)
        {

            if(clientes[i].idCliente == opcion)
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
        printf(" %5d  %20s %c \n",clientes[indice].idCliente,clientes[indice].nombre,clientes[indice].sexo);
    }
    return opcion;
}
