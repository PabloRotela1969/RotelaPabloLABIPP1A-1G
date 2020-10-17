#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"



void harcodeoTipo(eTipo lista[])
{
  int  idTipos[5] = {1000,1001,1002,1003,1004};
   char  descripcions[10][30] = {"Ave","Perro","Gato","Roedor","Pez"};


  int  isEmptys[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i =  0; i < 5; i++)
    {
     lista[i]. idTipo =  idTipos[i];
     strcpy(lista[i]. descripcion, descripcions[i]);
     lista[i]. isEmpty =  isEmptys[i];
     }
}


void prepararVectorTipo(eTipo lista[],int cantidad)
{
    for(int i = 0; i<cantidad; i++)
    {
        lista[i].isEmpty = 1;
    }
}


void mostrarCamposParaTipo()
{
     printf("| %15s| %30s| \n"," IDTIPO"," DESCRIPCION");
}


void mostrarUnTipo(eTipo unTipo )
{
     printf("| %15d| %30s| ",unTipo. idTipo,unTipo. descripcion);
}



int cantidadDeTipoCargados(eTipo lista[],int cantidad)
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






int mostrarTipos(eTipo lista[],int cantidad,char mensaje[])
{
    int error = 1;
    int NoHayParaMostrar = 1;
    int cantidadElementosPorPagina = 40;
    float resto;

    if(lista != NULL && cantidad != 0 && cantidadDeTipoCargados(lista,cantidad) > 0)
    {
        system("cls");
        printf(" %s \n", mensaje);
       mostrarCamposParaTipo();
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
                  mostrarCamposParaTipo();
                }
                NoHayParaMostrar = 0;
              mostrarUnTipo(lista[i]);
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

