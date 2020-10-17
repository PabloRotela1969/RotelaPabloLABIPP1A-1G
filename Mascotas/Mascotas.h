#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
#include "Funciones.h"
#include "Tipos.h"
#include "Colores.h"

typedef struct
{
int idMascota;
char nombre[30];
int idTipo;
int idColor;
int edad;



int isEmpty;
}eMascota;

#endif // MASCOTAS_H_INCLUDED




/** \brief precarga de valores al array de estructuras
 *
 * \param lista[] eMascota array de estructuras
 * \return void
 *
 */
void harcodeoMascota(eMascota lista[]);

/** \brief establecer la propiedad isEmpty a 1 para que al operar con el array no se obtenga basura
 *
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return void
 */
void prepararVectorMascota(eMascota lista[],int cantidad);

/** \brief busca en el array, estructura por estructura, donde hay una con isEmpty = 1 y devuelve el indice del array del mismo
 *
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    indice entre 0 y el tope donde se ubica la estructura que se puede sobreescribir
 */
int buscarLibreMascota(eMascota lista[],int cantidad);

/** \brief en funcion a los campos de la estructura, muestra los mismos solamente
 *
 */
void mostrarCamposParaMascota();

/** \brief recibe una estructura y usando el metodo mostrarCampos, permite mostrar el contenido de cada propiedad de la estructura en forma tabular
 *
 * \param eMascota estructura cargada
 * \param void
 *
 */
void mostrarUnMascota(eMascota unMascota );

/** \brief recibiendo el array de estructuras , su cantidad máxima de elementos y un array de char con el mensaje a mostrar como titulo
 *  con el mostrarUnaestructura, muestra el contenido del mismo, pudiendo establecer una paginacion, el mensaje es acorde dónde se emplee esta función
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \param char[]  mensaje , puede ser para mostrar estructuras simplemente o para exhibirlas para elegir el ID para borrar o modificarlas
 * \return int    0 = sin error, 1 = con errores
 */
int mostrarMascotas(eMascota lista[],int cantidad, eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores, char mensaje[30]);

/** \brief recibiendo el array de estructuras cuenta la cantidad de estructuras con isEmpty = 0 o sea, llenas
 *
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    cantidad de estructuras llenas dentro del array
 */
int cantidadDeMascotaCargados(eMascota lista[],int cantidad);

/** \brief recibiendo el array de estructuras busca secuencialmente en cada estructura hasta encontrar una cuyo isEmpty = 1 o sea, este vacia
 *
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    0 = sin error, 1 = con errores , 2 = operación cancelada
 */
int proximoIDMascota(eMascota lista[],int cantidad);


/** \brief recibiendo el array de estructuras permite cargar cada propiedad de una estructura y la ubica en el primer lugar vacío una vez confirmado
 *
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    el indice del array donde se encontró la primer estructura vacía
 */
int altaMascota(eMascota lista[],int cantidad, eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores);

/** \brief recibiendo el array de estructuras muestra todo lo cargado permitiendo elegir por un id al usuario, cuando confirma, se cambia el isEmpty de 0 a 1
 *
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    0 = sin error, 1 = con errores , 2 = operación cancelada
 */
int bajaMascota(eMascota lista[],int cantidad, eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores);

/** \brief recibiendo el array de estructuras muestra todo lo cargado permitiendo elegir por un id al usuario, luego muestra un pequeño sub menú con los campos a modificar
 *  una vez que el usuario selecciona el campo, se le pide el nuevo valor para el mismo y luego de confirmar, se reemplaza dicho valor por el que ya tenía
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    0 = sin error, 1 = con errores , 2 = operación cancelada
 */
int modificaMascota(eMascota lista[],int cantidad,eTipo listaTipos[], int cantidadTipos, eColor listaColores[], int cantidadColores);

/** \brief recibiendo el array de estructuras y un ID de estructura, busca secuencialmente en cada estructura del array hasta encontrar el id que coincida con el ingresado
 *  devolviendo el indice del array si lo encuentra y -1 si no lo encontró, se emplea para validar la selección de los id en el borrado y modificado
 * \param lista[] eMascota array de estructuras
 * \param int    cantidad maxima de elementos que pueden cargar al array
 * \return int    -1 si no encuentra el ID sino devuelve cualquier numero superior o igual a 0
 */
int buscarMascotaPorID(eMascota lista[],int cantidad, int id);





