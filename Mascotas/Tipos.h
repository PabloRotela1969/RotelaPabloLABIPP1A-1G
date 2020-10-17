#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#include "Funciones.h"

typedef struct
{
int idTipo;
char descripcion[20];
int isEmpty;
}eTipo;

#endif // TIPOS_H_INCLUDED



/** \brief precarga de valores al array de estructuras
 *
 * \param lista[] eTipo array de estructuras
 * \return void
 *
 */
void harcodeoTipo(eTipo lista[]);


/** \brief establecer la propiedad isEmpty a 1 para que al operar con el array no se obtenga basura
 *
 * \param lista[] eTipo array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return void
 */
void prepararVectorTipo(eTipo lista[],int cantidad);

/** \brief en funcion a los campos de la estructura, muestra los mismos solamente
 *
 */
void mostrarCamposParaTipo();

/** \brief recibe una estructura y usando el metodo mostrarCampos, permite mostrar el contenido de cada propiedad de la estructura en forma tabular
 *
 * \param eTipo estructura cargada
 * \param void
 *
 */
void mostrarUnTipo(eTipo unTipo );

/** \brief recibiendo el array de estructuras , su cantidad máxima de elementos y un array de char con el mensaje a mostrar como titulo
 *  con el mostrarUnaestructura, muestra el contenido del mismo, pudiendo establecer una paginacion, el mensaje es acorde dónde se emplee esta función
 * \param lista[] eTipo array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \param char[]  mensaje , puede ser para mostrar estructuras simplemente o para exhibirlas para elegir el ID para borrar o modificarlas
 * \return int    0 = sin error, 1 = con errores
 */
int mostrarTipos(eTipo lista[],int cantidad,char mensaje[]);

/** \brief recibiendo el array de estructuras cuenta la cantidad de estructuras con isEmpty = 0 o sea, llenas
 *
 * \param lista[] eTipo array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    cantidad de estructuras llenas dentro del array
 */
int cantidadDeTipoCargados(eTipo lista[],int cantidad);


