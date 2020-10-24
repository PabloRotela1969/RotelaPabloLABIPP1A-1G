#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajos.h"




void harcodearTrabajos(eTrabajo lista[])
{
    lista[0] = (eTrabajo) {1000, 10,20000,{12,3,2020},0};
    lista[1] = (eTrabajo) {1001, 11,20001,{12,3,2020},0};
    lista[2] = (eTrabajo) {1002, 12,20001,{5,11,2019},0};
    lista[3] = (eTrabajo) {1003, 14,20002,{11,1,2018},0};

}





void mostrarTrabajos(eTrabajo trabajos[], int tTra, eMascota mascotas[], int tMas, eServicio servicios[], int tSer,eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie)
{
    if(tTra > 0 && tMas > 0 && tSer > 0 && tTip > 0 && tCol > 0 )
    {
        printf(" id                   nombre                  color                 tipo  edad            servicio     precio     fecha   cliente  sexo \n");
        for(int i = 0; i<tTra; i++)
        {
            if (trabajos[i].isEmpty == 0)
            {
                printf(" %2d ", trabajos[i].idTrabajo);

                for(int j = 0; j<tMas; j++)
                {
                    if(trabajos[i].idMascota == mascotas[j].idMascota)
                    {
                        //mostarUnaMascota(mascotas[j],colores,tCol,tipos,tTip);

                        printf(" %20s ", mascotas[j].nombre);
                        for(int k=0; k<tCol; k++)
                        {
                            if(mascotas[j].isEmpty == 0 && mascotas[j].idColor == colores[k].idColor)
                            {
                                printf(" %20s ", colores[k].nombreColor);
                                break;
                            }
                        }
                        for(int k=0; k<tTip; k++)
                        {
                            if(mascotas[j].isEmpty == 0 && mascotas[j].idTipo == tipos[k].idTipo)
                            {
                                printf(" %20s ", tipos[k].descripcion);
                                break;
                            }
                        }
                        printf(" %5d ", mascotas[j].edad);



                        break;
                    }
                }
                for(int j = 0; j<tSer; j++)
                {
                    if(trabajos[i].idServicio == servicios[j].idServicio)
                    {

                        printf(" %20s %4.3f ", servicios[i].descripcion, servicios[i].precio);

                    }

                }
                printf(" %02d/%02d/%4d ", trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
                for(int j = 0; j<tMas; j++)
                {
                    if(trabajos[i].idMascota == mascotas[j].idMascota)
                    {
                        for(int k=0; k<tClie; k++)
                        {
                            if(clientes[k].idCliente == mascotas[j].idCliente)
                            {
                                printf(" %20s %c \n", clientes[j].nombre, clientes[j].sexo);
                                break;
                            }


                        }



                    }

                }

            }

        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA MOSTRAR\n");
    }
}


int buscarLibreTrabajo(eTrabajo trabajos[], int tTra)
{
    int encontrado = -1;
    for(int i=0; i<tTra; i++)
    {

        if(trabajos[i].isEmpty == 1)
        {
            encontrado = i;
            break;
        }
    }
    return encontrado;
}


void prepararArrayTrabajos(eTrabajo trabajos[], int tope)
{
    for(int i=0;i<tope;i++)
    {
        trabajos[i].isEmpty = 1;
    }
}


int altaTrabajos(eTrabajo trabajos[], int tTra, eMascota mascotas[], int tMas,eColor colores[], int tCol, eTipo tipos[], int tTip, eServicio servicios[], int tSer, int idNuevoTrabajo, eCliente clientes[], int tClie)
{
    eTrabajo aux;
    int resultado = 0;
    if(tTra > 0 && tMas > 0 && tSer > 0 && tCol > 0 && tTip > 0 )
    {
        int indice = buscarLibreTrabajo(trabajos,tTra);
        aux.idTrabajo = idNuevoTrabajo;
        aux.idMascota = seleccionarUnaMascota(mascotas,tMas,colores,tCol,tipos,tTip,clientes, tClie );
        aux.idServicio = seleccionarServicios(servicios,tSer);
        aux.fecha.dia = inputIntDesdeHasta("Ingrese el dia :",1,31);
        aux.fecha.mes = inputIntDesdeHasta("Ingrese el mes :",1,12);
        aux.fecha.anio = inputIntDesdeHasta("Ingrese el anio :",1,2020);
        aux.isEmpty = 0;
        if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
        {
            trabajos[indice] = aux;
        }
        else
        {
            resultado = 2;
        }
    }
    return resultado;
}


void conUnaMascotaMostrarTrabajosQueSeLeHicieron(eTrabajo trabajos[], int tTra, eMascota mascotas[], int tMas,eColor colores[], int tCol, eTipo tipos[], int tTip, eServicio servicios[], int tSer,  eCliente clientes[], int tClie)
{
    int opcionMascota = seleccionarUnaMascota(mascotas,tMas,colores,tCol,tipos,tTip,clientes,tClie);
    printf(" id  servicios \n");
    for(int i=0; i<tTra; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            if(trabajos[i].idMascota == opcionMascota)
            {
                for(int j=0; j<tSer; j++)
                {
                    if(servicios[j].idServicio == trabajos[i].idServicio)
                    {
                        printf("  %20s %4.3f\n", servicios[j].descripcion,servicios[j].precio);
                    }
                }

            }
        }
    }
}












