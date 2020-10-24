#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colores.h"





void harcodearColores(eColor lista[])
{
    lista[0] = (eColor) {5000, "Negro"};
    lista[1] = (eColor) {5001, "Blanco"};
    lista[2] = (eColor) {5002, "Gris"};
    lista[3] = (eColor) {5003, "Rojo"};
    lista[4] = (eColor) {5004, "Azul"};

}


void mostrarColores( eColor colores[], int tCol)
{
    printf(" id  colores \n");
    for(int i=0;i<tCol;i++)
    {
        printf(" %5d  %20s \n",colores[i].idColor,colores[i].nombreColor);

    }

}



int seleccionarUnColor( eColor colores[], int tCol)
{
    int opcion;
    int noEncontrado;
    int indice;
    do
    {
        noEncontrado = 1;
        printf("\n INGRESE EL COLOR POR SU CODIGO \n");
        printf(" id   color \n");
        for(int i=0;i<tCol;i++)
        {
            printf(" %5d  %20s \n",colores[i].idColor,colores[i].nombreColor);

        }

        opcion = inputInt("Ingrese el id del color : ");
        for(int i=0;i<tCol;i++)
        {

            if(colores[i].idColor == opcion)
            {
                indice = i;
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
    if(!noEncontrado)
    {
         printf("\n_________________________________________________________\n");
        printf(" %5d  %20s \n",colores[indice].idColor,colores[indice].nombreColor);
    }

    return opcion;
}





