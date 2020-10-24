#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "Funciones.h"

typedef struct
{
    int idCliente;
    char nombre[20];
    char sexo;
}eCliente;

#endif // CLIENTES_H_INCLUDED

void harcodearClientes(eCliente lista[]);

int seleccionarUnCliente( eCliente clientes[], int tClie);

