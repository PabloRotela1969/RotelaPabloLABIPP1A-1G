#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colores.h"




void harcodeoColor(eColor lista[])
{
  int  idColors[5] = {5000,5001,5002,5003,5004};
   char  nombreColors[5][20] = {"Negro","Blanco","Gris","Rojo","Azul"};


  int  isEmptys[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i =  0; i < 5; i++)
    {
     lista[i]. idColor =  idColors[i];
     strcpy(lista[i]. nombreColor, nombreColors[i]);


     lista[i]. isEmpty =  isEmptys[i];
     }
}

void prepararVectorColor(eColor lista[],int cantidad)
{
    for(int i = 0; i<cantidad; i++)
    {
        lista[i].isEmpty = 1;
    }
}


void mostrarCamposParaColor()
{
     printf("| %15s| %30s| \n"," IDCOLOR"," NOMBRECOLOR");
}


void mostrarUnColor(eColor unColor )
{
     printf("| %15d| %30s| ",unColor. idColor,unColor. nombreColor);
}




int cantidadDeColorCargados(eColor lista[],int cantidad)
{
    int respuesta = 0;
    for(int i = 0; i<cantidad; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            respuesta++;
        }
    }
    return respuesta;
}





int mostrarColors(eColor lista[],int cantidad,char mensaje[])
{
    int error = 1;
    int NoHayParaMostrar = 1;
    int cantidadElementosPorPagina = 40;
    float resto;

    if(lista != NULL && cantidad != 0 && cantidadDeColorCargados(lista,cantidad) > 0)
    {
        system("cls");
        printf(" %s \n", mensaje);
       mostrarCamposParaColor();
        for(int i = 0; i<cantidad; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                error = 0;
                resto = i % cantidadElementosPorPagina;
                if( resto == 0 && i > 0)
                {
                    inputChar("Pulse enter para continuar :");
                    system("cls");
                  mostrarCamposParaColor();
                }
                NoHayParaMostrar = 0;
              mostrarUnColor(lista[i]);
              printf("\n");
            }
        }
    }
    if(NoHayParaMostrar)
    {
        printf("\nNo hay elementos para mostrar\n");
    }

    return error;
}







