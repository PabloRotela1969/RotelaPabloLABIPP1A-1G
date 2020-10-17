#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"





void harcodeoMascota(eMascota lista[])
{
  int  idMascotas[10] = {10,11,12,13,14,15,16,17,18,19};
   char  nombres[10][30] = {"Michi","Pipi","Ayudante de Santa","Firulais","Dobby","Boby","Pucky","Michifuz","Bolt","Dexter"};
  int  idTipos[10] = {1000,1001,1002,1003,1001,1003,1003,1004,1002,1003};
  int  idColors[10] = {5000,5001,5004,5001,5002,5002,5003,5001,5002,5004};
  int  edads[10] = {10,11,12,13,14,15,16,17,18,19};


  int  isEmptys[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i =  0; i < 10; i++)
    {
     lista[i]. idMascota =  idMascotas[i];
     strcpy(lista[i]. nombre, nombres[i]);
     lista[i]. idTipo =  idTipos[i];
     lista[i]. idColor =  idColors[i];
     lista[i]. edad =  edads[i];


     lista[i]. isEmpty =  isEmptys[i];
     }
}

void prepararVectorMascota(eMascota lista[],int cantidad)
{
    for(int i = 0; i<cantidad; i++)
    {
        lista[i].isEmpty = 1;
    }
}



int buscarLibreMascota(eMascota lista[],int cantidad)
{
    int respuesta = -1;
    if(lista != NULL && cantidad != 0)
    {
        for(int i = 0; i<cantidad; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                respuesta = i;
                break;
            }
        }
    }
    return respuesta;
}


void mostrarCamposParaMascota()
{
     printf("| %15s| %30s| %20s| %20s| %10s| \n"," IDMASCOTA"," NOMBRE","TIPO","COLOR"," EDAD");
}


void mostrarUnMascota(eMascota unMascota )
{
     printf("| %15s| %30s|  \n"," IDMASCOTA"," NOMBRE");
     printf("| %15d| %30s|  \n",unMascota. idMascota,unMascota. nombre);


}








int mostrarMascotas(eMascota lista[],int cantidad, eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores, char mensaje[30])
{
    int error = 1;
    int NoHayParaMostrar = 1;
    int cantidadElementosPorPagina = 40;
    char tipoEncontrado[20];
    char colorEncontrado[20];
    float resto;

    if(lista != NULL && cantidad != 0 && cantidadDeMascotaCargados(lista,cantidad) > 0)
    {
        system("cls");
        printf(" %s \n", mensaje);
       mostrarCamposParaMascota();
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
                  mostrarCamposParaMascota();
                }
                NoHayParaMostrar = 0;

              for(int j=0; j<cantidadTipos; j++)
              {
                  if(lista[i].idTipo == listaTipos[j].idTipo && listaTipos[j].isEmpty == 0)
                  {
                      strcpy(tipoEncontrado,listaTipos[j].descripcion);
                      break;
                  }
              }
              for(int k=0; k<cantidadColores; k++)
              {
                  if(lista[i].idColor == listaColores[k].idColor && listaColores[k].isEmpty == 0)
                  {
                      strcpy(colorEncontrado,listaColores[k].nombreColor);
                      break;
                  }
              }
              printf("| %15d| %30s| %20s| %20s| %10d| \n",lista[i].idMascota, lista[i].nombre,tipoEncontrado,colorEncontrado, lista[i].edad);


            }
        }
    }
    if(NoHayParaMostrar)
    {
        printf("\nNo hay elementos para mostrar\n");
    }

    return error;
}


int cantidadDeMascotaCargados(eMascota lista[],int cantidad)
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

int proximoIDMascota(eMascota lista[],int cantidad)
{
    int max = -1;
    if(lista != NULL && cantidad != 0 && cantidadDeMascotaCargados(lista,cantidad) > 0)
    {

        for(int i = 0; i<cantidad; i++)
        {
            if((lista[i].isEmpty == 0 && max < lista[i]. idMascota) )
            {
                max = lista[i]. idMascota;
            }
        }
        max ++;
    }
    return max ;
}


int buscarMascotaPorID(eMascota lista[],int cantidad, int id)
{
    int encontrado = -1;
    if(lista != NULL && cantidad != 0 && cantidadDeMascotaCargados(lista,cantidad) > 0)
    {
        for(int i = 0; i<cantidad; i++)
        {
            if((lista[i].isEmpty == 0 && lista[i]. idMascota == id) )
            {
                encontrado = i;

            }
        }
    }
    return encontrado ;
}


int altaMascota(eMascota lista[],int cantidad, eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores)
{
    int error = 1;
    int indice;
    int legajo;
    eMascota nuevo;
    int opcion;
    if(lista != NULL && cantidad != 0)
    {

        indice = buscarLibreMascota(lista, cantidad);
        if(indice > -1)
        {
             system("cls");
            printf(" alta de Mascota\n");
            legajo = proximoIDMascota(lista, cantidad);

            nuevo.isEmpty = 0;
            nuevo. idMascota = legajo;
            inputString("Ingrese  nombre : ",nuevo. nombre, 30);
            mostrarTipos(listaTipos,cantidadTipos,"Lista de Tipos");
            nuevo. idTipo = inputIntDesdeHasta("Ingrese  idTipo : ",1000,1004);
            mostrarColors(listaColores, cantidadColores, "Lista de colores");
            nuevo. idColor = inputIntDesdeHasta("Ingrese  idColor : ", 5000, 5004);
            nuevo. edad = inputInt("Ingrese  edad : ");








            opcion = inputIntDesdeHasta("Confirma con 1 , cancela con 2 : ",1,2);
            error = 2;
            if(opcion == 1)
            {
                lista[indice] = nuevo;
                error = 0;
            }



        }
        else
        {
            printf("\nNO HAY MÁS ESPACIO DISPONIBLE\n");
        }
    }
    return error;
}



int bajaMascota(eMascota lista[],int cantidad, eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores)
{
    int error;
    int legajo;
    int indice;


    if(lista != NULL && cantidad != 0 && cantidadDeMascotaCargados(lista,cantidad) > 0)
    {
       system("cls");

        mostrarMascotas(lista, cantidad, listaTipos,cantidadTipos, listaColores, cantidadColores,"ELIMINAR Mascota");
        legajo = inputInt("Ingrese el ID desde el listado : ");
        indice = buscarMascotaPorID(lista, cantidad, legajo);

        if(indice > -1)
        {
       system("cls");

            mostrarUnMascota(lista[indice]);
            error = 2;
            if(inputIntDesdeHasta("Confirma con 1 , cancela con 2 : ",1,2) == 1)
            {
                lista[indice].isEmpty = 1;
                error = 0;
            }

        }
        else
        {
            printf("\nNO SE ENCONTRÓ EL ALUMNO INGRESADO\n");
            error = 1;
        }
    }
    else
    {
        printf("\n No hay elementos para mostrar \n");
        error = 1;
    }

    return error;
}


int modificaMascota(eMascota lista[],int cantidad,eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores)
{
    int error;
    int legajo;
    int indice;
    int auxInt;
    char auxString[30];


    int opcion;
    system("cls");
    if(lista != NULL && cantidad != 0 && cantidadDeMascotaCargados(lista,cantidad) > 0)
    {

        mostrarMascotas(lista, cantidad, listaTipos,cantidadTipos, listaColores, cantidadColores,"MODIFICAR Mascota");

        legajo = inputInt("Ingrese el legajo desde el listado : ");
        indice = buscarMascotaPorID(lista, cantidad, legajo);

        if(indice > -1)
        {
            system("cls");
            printf(" MODIFICAR Mascota \n");
            mostrarCamposParaMascota();
            mostrarUnMascota(lista[indice]);
            printf("Elija el campo por numero: \n");
            printf("1 =  nombre \n");
            printf("2 =  idTipo \n");
            printf("3 =  idColor \n");
            printf("4 =  edad \n");







            opcion = inputIntDesdeHasta("Elija opción del 1 al 3 : ",1,3);
            error = 2;
            switch(opcion)
            {
            case 1:
                inputString("Ingrese el nuevo  nombre : ",auxString,30);
                if(inputIntDesdeHasta("Confirma con 1 , cancela con 2 : ",1,2) == 1)
                {
                    strcpy(lista[indice]. nombre,auxString);
                    error = 0;
                }
                break;
            case 2:
                auxInt = inputInt("Ingrese el nuevo   idTipo : ");
                if(inputIntDesdeHasta("Confirma con 1 , cancela con 2 : ",1,2) == 1)
                {
                    lista[indice]. idTipo = auxInt;
                    error = 0;
                }
                break;
            case 3:
                auxInt = inputInt("Ingrese el nuevo   idColor : ");
                if(inputIntDesdeHasta("Confirma con 1 , cancela con 2 : ",1,2) == 1)
                {
                    lista[indice]. idColor = auxInt;
                    error = 0;
                }
                break;
            case 4:
                auxInt = inputInt("Ingrese el nuevo   edad : ");
                if(inputIntDesdeHasta("Confirma con 1 , cancela con 2 : ",1,2) == 1)
                {
                    lista[indice]. edad = auxInt;
                    error = 0;
                }
                break;



            }
        }
        else
        {
            printf("\nNO SE ENCONTRÓ EL REGISTRO INGRESADO\n");
            error = 1;
        }
    }
    else
    {
        printf("\n No hay elementos para mostrar \n");
        error = 1;
    }

    return error;
}
