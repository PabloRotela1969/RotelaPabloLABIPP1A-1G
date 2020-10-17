
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"



char inputChar(char mensaje[])
{
    char respuesta;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    return respuesta;
}

char inputCharPosibles(char mensaje[], char posibles[])
{
    char respuesta;
    int mal = 1;
    do
    {

        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c", &respuesta);
        for(int i = 0; i<strlen(posibles); i++)
        {
            if(respuesta == posibles[i])
            {
                mal = 0;
                break;
            }
        }
        if(mal)
        {
            printf("\nPOR FAVOR, INGRESE UN VALOR PERMITIDO\n");
        }

    }
    while(mal);


    return respuesta;
}




void inputString(char mensaje[], char salida[], int tam)
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(salida,tam,stdin);
    salida[strlen(salida)-1]='\0';
    fflush(stdin);
}





int inputInt(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);

    return atoi(salida);

}



float inputFloat(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                case '.':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

    }while(mal);

    return atof(salida);

}


/** \brief ingresando un mensaje indicativo y dos numeros, desde y hasta, devuelve un numero entero comprendido en desde y hasta
 *
 * \param mensaje[] char mensaje de lo que se espera recibir
 * \param desde int tope m�nimo
 * \param hasta int tope m�ximo
 * \return int n�mero entero comprendido entre tope minimo y tope m�ximo
 *
 */
int inputIntDesdeHasta(char mensaje[], int desde,int hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    int retorno;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

        retorno = atoi(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %d y %d, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;

}



/** \brief ingresando un cartel indicativo, un numero desde y otro hasta, devuelve un decimal comprendido entre desde y hasta
 *
 * \param mensaje[] char cartel indicativo
 * \param desde int entero inferior
 * \param hasta int entero superior
 * \return float devuelve un decimal comprendido entre los enteros superior e inferior
 *
 */
float inputFloatDesdeHasta(char mensaje[],int desde,int hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    float retorno;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                case '.':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }
        retorno = atof(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %d y %d, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;
}



/** \brief ingresando mensaje indicativo, flotante desde y flotante hasta, devuelve un flotante comprendido entre ambos
 *
 * \param mensaje[] char mensaje de lo que se espera recibir
 * \param desde float tope inferior
 * \param hasta float tope superior
 * \return float decimal entre ambos topes
 *
 */
float inputFloatDesdefHastaf(char mensaje[],float desde,float hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    float retorno;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                case '.':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }
        retorno = atof(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %f y %f, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;
}


