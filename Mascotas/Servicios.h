#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
#include "Funciones.h"
typedef struct
{
int idServicio;
char descripcion[25];
float precio;

int isEmpty;
}eServicio;

#endif // SERVICIOS_H_INCLUDED





/** \brief precarga de valores al array de estructuras
 *
 * \param lista[] eServicio array de estructuras
 * \return void
 *
 */
void harcodeoServicio(eServicio lista[]);

/** \brief establecer la propiedad isEmpty a 1 para que al operar con el array no se obtenga basura
 *
 * \param lista[] eServicio array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return void
 */
void prepararVectorServicio(eServicio lista[],int cantidad);


/** \brief en funcion a los campos de la estructura, muestra los mismos solamente
 *
 */
void mostrarCamposParaServicio();

/** \brief recibe una estructura y usando el metodo mostrarCampos, permite mostrar el contenido de cada propiedad de la estructura en forma tabular
 *
 * \param eServicio estructura cargada
 * \param void
 *
 */
void mostrarUnServicio(eServicio unServicio );

/** \brief recibiendo el array de estructuras , su cantidad máxima de elementos y un array de char con el mensaje a mostrar como titulo
 *  con el mostrarUnaestructura, muestra el contenido del mismo, pudiendo establecer una paginacion, el mensaje es acorde dónde se emplee esta función
 * \param lista[] eServicio array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \param char[]  mensaje , puede ser para mostrar estructuras simplemente o para exhibirlas para elegir el ID para borrar o modificarlas
 * \return int    0 = sin error, 1 = con errores
 */
int mostrarServicios(eServicio lista[],int cantidad,char mensaje[]);

/** \brief recibiendo el array de estructuras cuenta la cantidad de estructuras con isEmpty = 0 o sea, llenas
 *
 * \param lista[] eServicio array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    cantidad de estructuras llenas dentro del array
 */
int cantidadDeServicioCargados(eServicio lista[],int cantidad);


