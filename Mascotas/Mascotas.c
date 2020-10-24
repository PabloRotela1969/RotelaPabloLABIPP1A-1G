#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"



int buscarLibreMascota(eMascota mascotas[], int tMas)
{
    int encontrado = -1;
    for(int i=0; i<tMas; i++)
    {

        if(mascotas[i].isEmpty == 1)
        {
            encontrado = i;
            break;
        }
    }
    return encontrado;
}

int altaMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, int idNuevo, eCliente clientes[], int tClie)
{
    eMascota aux;
    int indiceLibre;
    int resultado = 0;
   if( (tMas >0) || (tCol >0) || (tTip > 0))
    {
        printf("ALTA DE MASCOTA \n");
        indiceLibre = buscarLibreMascota(mascotas,tMas);
        aux.idMascota = idNuevo;
        inputString("\ningrese el nombre de la mascota : ",aux.nombre,20);
        aux.idColor = seleccionarUnColor(colores,tCol);
        aux.idTipo = seleccionarUnTipo(tipos,tTip);
        aux.edad = inputIntDesdeHasta("\nIngrese la edad de la mascota : ",1,100);
        aux.idCliente = seleccionarUnCliente(clientes, tClie);
        aux.isEmpty = 0;
        if(inputInt("\nIngrese 1 si confirma, cualquier otra para cancelar : ") == 1)
        {
            mascotas[indiceLibre] = aux;
        }
        else
        {
            resultado = 2;
        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA MOSTRAR\n");
        resultado = 1;
    }
    return resultado;
}


int bajaMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie)
{

    int indice;
    int resultado = 0;
    int i;
   if( (tMas >0) || (tCol >0) || (tTip > 0))
    {
        printf("BAJA DE MASCOTA \n");
        indice = seleccionarUnaMascota(mascotas,tMas,colores,tCol,tipos,tTip,clientes, tClie);
        for( i=0; i<tMas; i++)
        {
            if(mascotas[i].idMascota == indice)
            {

                break;
            }
        }

        if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
        {
            mascotas[i].isEmpty = 1;
        }
        else
        {
            resultado = 2;
        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA MOSTRAR\n");
        resultado = 1;
    }
    return resultado;
}



int modificaMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie)
{
    eMascota aux;
    int indice;
    int camposAmodificar;
    int resultado = 0;
    int i;
   if( (tMas >0) || (tCol >0) || (tTip > 0))
    {
        printf("\n MODIFICA DE MASCOTA \n");
        indice = seleccionarUnaMascota(mascotas,tMas,colores,tCol,tipos,tTip, clientes, tClie);
        for( i=0; i<tMas; i++)
        {
            if(mascotas[i].idMascota == indice)
            {

                break;
            }
        }
        camposAmodificar = inputIntDesdeHasta("\nIngrese por numero \n 1 = nombre \n 2 = color \n 3 = tipo \n 4 = edad \n 5 = cliente \n: ",1,5);
        switch(camposAmodificar)
        {
        case 1:
           inputString("\ningrese el nombre nuevo : ", aux.nombre ,20);
            if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
            {
                strcpy(mascotas[i].nombre ,aux.nombre);
            }
            else
            {
                resultado = 2;
            }


            break;

        case 2:
            aux.idColor = seleccionarUnColor(colores,tCol);
           if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
            {
                mascotas[i].idColor = aux.idColor;
            }
            else
            {
                resultado = 2;
            }
            break;
        case 3:
            aux.idTipo = seleccionarUnTipo(tipos,tTip);
           if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
            {
                mascotas[i].idTipo = aux.idTipo;
            }
            else
            {
                resultado = 2;
            }
            break;
        case 4:
            aux.edad = inputIntDesdeHasta("\n Ingrese una edad : ",1,100);
           if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
            {
                mascotas[i].edad = aux.edad;
            }
            else
            {
                resultado = 2;
            }
            break;

     case 5:
            aux.idCliente = seleccionarUnCliente(clientes, tClie);
           if(inputInt("\n Ingrese 1 si confirma, cualquier otra para cancelar : ") == 1)
            {
                mascotas[i].idCliente = aux.idCliente;
            }
            else
            {
                resultado = 2;
            }
            break;

        }


    }
    else
    {
        printf("\nNO HAY DATOS PARA MOSTRAR\n");
        resultado = 1;
    }
return resultado;
}



void harcodearMascotas(eMascota lista[])
{
    lista[0] = (eMascota) {10, "Boby",1001,5001,3,0,10};
    lista[1] = (eMascota) {11, "Luly",1000,5003,5,0,10};
    lista[2] = (eMascota) {12, "Pipy",1003,5002,2,0,12};
    lista[3] = (eMascota) {13, "Rory",1004,5004,7,0,11};
    lista[4] = (eMascota) {14, "Pit",1000,5001,6,0,13};

}

void prepararArrayMascotas(eMascota mascotas[], int tope)
{
    for(int i=0;i<tope;i++)
    {
        mascotas[i].isEmpty = 1;
    }
}

void mostarUnaMascota(eMascota una,eColor colores[], int tColor, eTipo tipos[],int tTipo, eCliente clientes[], int tClie)
{

    if( (tColor >0) && (tTipo > 0))
    {
            printf(" %5d %20s ", una.idMascota,una.nombre);
            for(int i=0;i<tColor;i++)
            {
                if(una.isEmpty == 0 && una.idColor == colores[i].idColor)
                {
                    printf("%20s", colores[i].nombreColor);
                    break;
                }
            }
            for(int i=0;i<tTipo;i++)
            {
                if(una.isEmpty == 0 && una.idTipo == tipos[i].idTipo)
                {
                    printf("%20s", tipos[i].descripcion);
                    break;
                }
            }
            printf("%5d", una.edad);
            for(int i=0;i<tClie;i++)
            {
                if(una.isEmpty == 0 && una.idCliente == clientes[i].idCliente)
                {
                    printf("%20s %1c ", clientes[i].nombre, clientes[i].sexo);
                    break;
                }
            }



    }
    else
    {
        printf("\nNO HAY DATOS PARA MOSTRAR\n");
    }
}

void mostrarMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie)
{
   if( (tMas >0) || (tCol >0) || (tTip > 0))
    {
        printf(" %5s %20s %20s %20s  %5s %16s %5s \n", "id","nombre","color","tipo","edad" , "duenio" , "sexo");
        for(int i=0;i<tMas;i++)
        {
            if(mascotas[i].isEmpty == 0)
            {

                mostarUnaMascota(mascotas[i],colores,tCol,tipos,tTip, clientes, tClie);
                printf("\n");
            }
        }


    }
    else
    {
        printf("\nNO HAY DATOS PARA MOSTRAR\n");
    }
}





int seleccionarUnaMascota(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip, eCliente clientes[], int tClie)
{
    int opcion;
    int noEncontrado;
    int indice;
    do
    {
        noEncontrado = 1;
        printf("\n INGRESE LA MASCOTA POR SU CODIGO \n");
        mostrarMascotas(mascotas,tMas,colores,tCol,tipos,tTip,clientes,tClie);
        opcion = inputInt("Ingrese el id de la mascota : ");
        for(int i=0; i<tMas; i++)
        {

            if(mascotas[i].idMascota == opcion)
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
        mostarUnaMascota(mascotas[indice],colores,tCol,tipos,tTip,clientes,tClie);

    }
    return opcion;
}

void mostrarLasMascotasDeColorSeleccionado(eMascota mascotas[], int tMas, eColor colores[], int tCol)
{
    int opcion = seleccionarUnColor(colores,tCol);
    int respuesta = 0;
    printf(" %20s %5s %20s \n","nombre","edad","color");
    for(int j=0; j<tCol; j++)
    {
        if(colores[j].idColor == opcion)
        {
            for(int i= 0; i<tMas; i++)
            {
                if(mascotas[i].idColor == opcion)
                {
                    printf(" %20s %5d %20s \n",mascotas[i].nombre, mascotas[i].edad, colores[j].nombreColor);
                    respuesta = 1;
                }
            }
            break;
        }


    }
    if(respuesta == 0)
    {
        printf("\nNO SE ENCONTRARON REGISTROS QUE CUMPLAN CON ESE CRITERIO\n");
    }
}

void mostrarLasMascotasDeTipoSeleccionado(eMascota mascotas[], int tMas, eTipo tipos[], int tTip)
{
    int opcion = seleccionarUnTipo(tipos,tTip);
    int respuesta = 0;
    printf(" %20s %5s %20s \n","nombre","edad","tipo");
    for(int j=0; j<tTip; j++)
    {
        if(tipos[j].idTipo == opcion)
        {
            for(int i= 0; i<tMas; i++)
            {
                if(mascotas[i].idTipo == opcion)
                {
                    printf(" %20s %5d %20s \n",mascotas[i].nombre, mascotas[i].edad, tipos[j].descripcion);
                    respuesta = 1;
                }
            }
            break;
        }
    }
    if(respuesta == 0)
    {
        printf("\nNO SE ENCONTRARON REGISTROS QUE CUMPLAN CON ESE CRITERIO\n");
    }
}


void informarLasMascotasDeMenorEdad(eMascota mascotas[], int tMas)
{
    int minEdad = 10000;
    printf(" %20s %5s  \n","nombre","edad");
    for(int i= 0; i<tMas; i++)
    {
        if(mascotas[i].isEmpty == 0 )
        {
            if( mascotas[i].edad < minEdad )
            {
                minEdad = mascotas[i].edad;
            }
        }
    }
    for(int i= 0; i<tMas; i++)
    {
        if((mascotas[i].isEmpty == 0 )&& (mascotas[i].edad == minEdad))
        {
           printf(" %20s %5d  \n",mascotas[i].nombre, mascotas[i].edad);

        }
    }



}



void listarMascotasSeparadasPorTipo(eMascota mascotas[], int tMas, eTipo tipos[], int tTip)
{
    printf(" %20s %5s  \n","nombre","tipos");
    for(int j= 0; j<tTip; j++)
    {
        for(int i= 0; i<tMas; i++)
        {
            if(mascotas[i].idTipo == tipos[j].idTipo )
            {
                printf(" %20s %5d %20s \n",mascotas[i].nombre, mascotas[i].edad, tipos[j].descripcion);
            }
        }
    }
}


void listarMascotasConUnColorYUnTipo(eMascota mascotas[], int tMas, eColor colores[], int tCol, eTipo tipos[], int tTip)
{
    int opcionColor;
    int opcionTipo;
    int cantidadMascotasCumplenCriterio = 0;
    opcionColor = seleccionarUnColor(colores,tCol);
    opcionTipo = seleccionarUnTipo(tipos,tTip);
    for(int i= 0; i<tMas; i++)
    {
        if(mascotas[i].isEmpty == 0)
        {


            for(int j= 0; j<tCol; j++)
            {
                if(mascotas[i].idColor == opcionColor )
                {
                    for(int k=0; k<tTip;k++)
                    {
                        if(mascotas[i].idTipo == opcionTipo )
                        {
                            cantidadMascotasCumplenCriterio++;
                            break;
                        }

                    }
                    break;

                }
            }
        }
    }
    printf("\n Hay %d mascotas que cumplen con el criterio \n ", cantidadMascotasCumplenCriterio);

}



void mostrarEloLosColoresConMasCantidadDeMascotas(eMascota mascotas[], int tMas, eColor colores[], int tCol)
{
    eMascotasColores listaAux[20];
    eMascotasColores aux;
    int cantidadMascotasConUnColor;
    int k = 0;
    for(int i = 0; i<tCol; i++)
    {
        cantidadMascotasConUnColor = 0;
        for(int j=0;j<tMas; j++)
        {
            if((colores[i].idColor == mascotas[j].idColor) && (mascotas[j].isEmpty == 0 ))
            {
                cantidadMascotasConUnColor++;
            }

        }
        listaAux[k].cantidadMascotas = cantidadMascotasConUnColor;
        strcpy(listaAux[k].nombreColor , colores[i].nombreColor);
        k++;

    }
    for(int i = 0; i<k - 1; i++)
    {
        for(int j = i+1; j<k; j++)
        {
            if(listaAux[i].cantidadMascotas < listaAux[j].cantidadMascotas)
            {
                aux = listaAux[i];
                listaAux[i] = listaAux[j];
                listaAux[j] = aux;
            }
        }
    }
    for(int i = 0; i<k ; i++)
    {
        printf(" Estas fueron las puntuaciones para el color %20s : %5d mascotas : \n", listaAux[i].nombreColor, listaAux[i].cantidadMascotas);
    }


}














