#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "Fechas.h"


typedef struct
{
int idTrabajo;
int idMascota;
int idServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;


#endif // TRABAJOS_H_INCLUDED



/** \brief establecer la propiedad isEmpty a 1 para que al operar con el array no se obtenga basura
 *
 * \param lista[] eTrabajo array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return void
 */
void prepararVectorTrabajo(eTrabajo lista[],int cantidad);



