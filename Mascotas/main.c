#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"
#include "Trabajos.h"

#define CINCO 5
#define VEINTE 20
#define TRES 3
void menu(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip,eTrabajo trabajos[], int tTRa, eServicio servicios[], int tSer, eCliente clientes[], int tClie);


int main()
{
    eColor colores[CINCO];
    eTipo tipos[CINCO];
    eMascota mascotas[VEINTE];
    eTrabajo trabajos[VEINTE];
    eServicio servicios[TRES];
    eCliente clientes[CINCO];


    harcodearColores(colores);
    harcodearTipos(tipos);
    prepararArrayMascotas(mascotas,20);
    prepararArrayTrabajos(trabajos,20);
    harcodearMascotas(mascotas);
    harcodearTrabajos(trabajos);
    harcodearServicios(servicios);
    harcodearClientes(clientes);

    menu(mascotas,VEINTE,colores,CINCO,tipos,CINCO,trabajos,VEINTE,servicios,TRES, clientes,CINCO);

    return 0;
}







void menu(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip,eTrabajo trabajos[], int tTRa, eServicio servicios[], int tSer, eCliente clientes[], int tClie)
{
    int opcionSuperior;
    int opcionInterna;
    int topeSuperior = 4;
    int topeInferior = 5;
    int idMascota = 1000;
    int idNuevoTrabajo = 30000;

    do
    {
        printf("\nMENU PRINCIPAL \n");

        opcionSuperior = inputIntDesdeHasta(" 1 = ABM mascotas \n 2 = TRABAJO \n 3 = MOSTRAR \n 4 = salir \n su opcion :",1,4);
        switch(opcionSuperior)
        {
        case 1:
            do
            {
                printf("\nMENU MASCOTAS \n");

                opcionInterna = inputIntDesdeHasta(" 1 = Alta  \n 2 = Baja \n 3 = modifica \n 4 = mostrar \n 5 = salir \n su opcion : ",1,5);
                switch(opcionInterna)
                {
                case 1:
                    idMascota++;
                    altaMascotas(mascotas,tMas,colores,tCol,tipos,tTip, idMascota,clientes, tClie);
                    break;
                case 2:
                    bajaMascotas(mascotas,tMas,colores,tCol,tipos,tTip,clientes, tClie);
                    break;
                case 3:
                    modificaMascotas(mascotas,tMas,colores,tCol,tipos,tTip,clientes, tClie);
                    break;
                case 4:
                    mostrarMascotas(mascotas,tMas,colores,tCol,tipos,tTip,clientes, tClie);
                    break;

                }

            }
            while(opcionInterna != topeInferior);



            break;
        case 2:
            do
            {
                printf("\nMENU TRABAJOS \n");

                opcionInterna = inputIntDesdeHasta(" 1 = mostrar  \n 2 = alta \n 3 = salir \n su opcion : ",1,3);
                switch(opcionInterna)
                {
                case 1:
                    mostrarTrabajos(trabajos,tTRa,mascotas,tMas,servicios,tSer,colores,tCol,tipos,tTip,clientes, tClie);
                    break;
                case 2:
                    idNuevoTrabajo++;
                    altaTrabajos(trabajos,tTRa,mascotas,tMas,colores,tCol,tipos,tTip,servicios,tSer,idNuevoTrabajo,clientes, tClie);

                    break;

                }

            }
            while(opcionInterna != 3);



            break;
        case 3:
            do
            {
                printf("\nMENU MOSTRAR \n");

                printf(" 1 = mostrar colores  \n 2 = mostrar tipos \n 3 = mostrar servicios  \n 4 = mostrar las mascotas seleccionando un color \n");
                printf(" 5 = mostrar las mascotas seleccionando un tipo  \n 6 = informar las mascotas de menor edad \n 7 = listar mascotas separadas por tipo  \n");
                printf(" 8 = listar Mascotas seleccionando Color y Tipo \n 9 = mostrar el o los colores con mas cantidad de mascotas \n");
                opcionInterna = inputIntDesdeHasta(" 10 = conUnaMascotaMostrarTrabajosQueSeLeHicieron \n 11 = salir \n su opcion : ",1,11);
                switch(opcionInterna)
                {
                case 1:
                    mostrarColores(colores, tCol);

                    break;
                case 2:
                    mostrarTipos(tipos, tTip);
                    break;
                case 3:
                    mostrarServicios(servicios,tSer);
                    break;
                case 4:
                    mostrarLasMascotasDeColorSeleccionado(mascotas,tMas,colores,tCol);
                    break;

                 case 5:
                    mostrarLasMascotasDeTipoSeleccionado(mascotas,tMas,tipos,tTip);
                    break;
                 case 6:
                    informarLasMascotasDeMenorEdad(mascotas,tMas);
                    break;
                 case 7:
                    listarMascotasSeparadasPorTipo(mascotas,tMas,tipos,tTip);
                    break;
                 case 8:
                    listarMascotasConUnColorYUnTipo(mascotas,tMas,colores,tCol,tipos,tTip);
                    break;

                 case 9:
                    mostrarEloLosColoresConMasCantidadDeMascotas(mascotas,tMas,colores,tCol);
                    break;

                 case 10:
                    conUnaMascotaMostrarTrabajosQueSeLeHicieron(trabajos,tTRa,mascotas,tMas,colores,tCol,tipos,tTip,servicios,tSer,clientes,tClie);
                    break;

                    }

            }
            while(opcionInterna != 11);



            break;
        }

    }
    while(opcionSuperior != topeSuperior);
}

