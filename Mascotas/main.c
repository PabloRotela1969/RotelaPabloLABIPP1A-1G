#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"
#include "Tipos.h"
#include "Colores.h"
#include "Servicios.h"
#define topeMascota 20










int main()
{

    int tope = 10;
    int resultado;
    int opcion;

    eMascota listaDeMascotas[20];
    eColor listaDeColores[5];
    eTipo listaTipos[5];
    eServicio listaServicios[3];

    prepararVectorMascota( listaDeMascotas, 20);
    harcodeoMascota(listaDeMascotas);

    prepararVectorColor(listaDeColores,5);
    harcodeoColor(listaDeColores);

    prepararVectorTipo(listaTipos, 5);
    harcodeoTipo(listaTipos);

    prepararVectorServicio(listaServicios,3);
    harcodeoServicio(listaServicios);



    do
    {
        resultado = 0;
        printf("MENU PRINCIPAL \n");
        printf("\n 1 _ Alta de mascota \n 2 _ Modificar Mascota \n 3 _ Baja Mascota \n 4 _ Mostrar Mascotas \n 5 _ Listar tipos \n 6 _ Listar colores \n 7 _ Listar Servicios \n 8 _ Alta Trabajo \n 9 _ Listar Trabajos \n %d _ sale \n", tope);
        opcion = inputIntDesdeHasta(" OPCION : ",1,tope);
        switch(opcion)
        {
        case 1:
            resultado = altaMascota(listaDeMascotas, topeMascota,listaTipos,5,listaDeColores,5);
            break;
        case 2:
            resultado = modificaMascota(listaDeMascotas, topeMascota,listaTipos,5,listaDeColores,5);
            break;

            break;
        case 3:
            resultado = bajaMascota(listaDeMascotas, topeMascota,listaTipos,5,listaDeColores,5);
            break;
        case 4:
            mostrarMascotas(listaDeMascotas, topeMascota, listaTipos,5,listaDeColores,5, " MOSTRAR Mascota");
            break;
        case 5:
            mostrarTipos(listaTipos,5, "Mostrar Tipos");
            break;
        case 6:
            mostrarColors(listaDeColores,5 , "Mostrar Colores");
            break;
        case 7:
            mostrarServicios(listaServicios,3, "Mostrar Servicios");
            break;
        case 8:

            break;
        case 9:

            break;


        }


        switch(resultado)
        {
        case 0:
            printf("\n operacion exitosa \n");
            break;
        case 1:
            printf("\n hubo un error durante la operacion \n");
            break;
        case 2:
            printf("\n operacion cancelada por el usuario \n");
            break;
        }
    }
    while( opcion != tope );





    return 0;
}






























