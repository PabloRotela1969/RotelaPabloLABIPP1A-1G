
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"




void harcodeoServicio(eServicio lista[])
{
  int  idServicios[3] = {20000,20001,20002};
   char  descripcions[3][25] = {"Corte","Desparacitado","Castrado"};
   float  precios[3] = {250.0,300.0,400.0};

  int  isEmptys[3] = {0,0,0};
    for(int i =  0; i < 3; i++)
    {
     lista[i]. idServicio =  idServicios[i];
     strcpy(lista[i]. descripcion, descripcions[i]);
     lista[i]. precio =  precios[i];

     lista[i]. isEmpty =  isEmptys[i];
     }
}

void prepararVectorServicio(eServicio lista[],int cantidad)
{
    for(int i = 0; i<cantidad; i++)
    {
        lista[i].isEmpty = 1;
    }
}



void mostrarCamposParaServicio()
{
     printf("| %15s| %30s| %15s| \n"," IDSERVICIO"," DESCRIPCION"," PRECIO");
}


void mostrarUnServicio(eServicio unServicio )
{
     printf("| %15d| %30s| %15.5f| \n",unServicio. idServicio,unServicio. descripcion,unServicio. precio);
}


int cantidadDeServicioCargados(eServicio lista[],int cantidad)
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







int mostrarServicios(eServicio lista[],int cantidad,char mensaje[])
{
    int error = 1;
    int NoHayParaMostrar = 1;
    int cantidadElementosPorPagina = 40;
    float resto;

    if(lista != NULL && cantidad != 0 && cantidadDeServicioCargados(lista,cantidad) > 0)
    {
        system("cls");
        printf(" %s \n", mensaje);
       mostrarCamposParaServicio();
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
                  mostrarCamposParaServicio();
                }
                NoHayParaMostrar = 0;
              mostrarUnServicio(lista[i]);
            }
        }
    }
    if(NoHayParaMostrar)
    {
        printf("\nNo hay elementos para mostrar\n");
    }

    return error;
}




