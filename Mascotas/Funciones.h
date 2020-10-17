#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando, luego que el usuario opera, se valida que sea un caracter
 *   de lo contrario vuelve a solicitar el ingreso
 * param char[] mensaje a mostrar para el usuario
 *
 * \return un solo caracter
 */
char inputChar(char mensaje[]);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando, luego que el usuario opera, se valida que sean números
 *   de lo contrario vuelve a solicitar el ingreso
 * param char[] mensaje a mostrar para el usuario
 *
 * \return un numero entero
 */
int inputInt(char mensaje[]);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando y una cadena de caracteres posibles, luego que el usuario opera, se valida que sean caracteres
 *   una vez que el usuario ingresó caracteres, verifica que estén en alguno de los ingresados como posibles, sino vuelva a pedir el ingreso
 * param char[] mensaje a mostrar para el usuario
 *
 * \return un carácter válido
 */
char inputCharPosibles(char mensaje[], char posibles[]);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando, un array de salida que es donde va a parar lo ingresado por el usuario
 *   y una cantidad de caracteres admisibles, devuelve lo que el usuario haya ingresado
 * param char[] mensaje a mostrar para el usuario
 * param char[] el array de salida, donde van a parar las pulsaciones del usuario
 * param int , la cantidad de caracteres máxima que soporta el array de salida
 * \return void
 */
void inputString(char mensaje[], char salida[], int tam);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando, una vez que el usuario ingresa, valida que sea un numero
 *   y que contenga el punto, de lo contrario pide un reingreso
 * param char[] mensaje a mostrar para el usuario
 * \return float , devuelve un numero decimal
 */
float inputFloat(char mensaje[]);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando y dos números que ofician de valor desde y hasta
 *  se valida que lo ingresado sea un entero y que además, esté comprendido en el rango de numeros ingresado
 * param char[] mensaje a mostrar para el usuario
 * param int valor DESDE
 * param int valor HASTA
 * \return int , un entero comprendido entre los valores DESDE y HASTA
 */
int inputIntDesdeHasta(char mensaje[], int desde,int hasta);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando y dos números que ofician de valor desde y hasta
 *  se valida que lo ingresado sea un DECIMAL  y que además, esté comprendido en el rango de numeros ingresado
 * param char[] mensaje a mostrar para el usuario
 * param int valor DESDE
 * param int valor HASTA
 * \return float , un DECIMAL comprendido entre los valores DESDE y HASTA
 */
float inputFloatDesdeHasta(char mensaje[],int desde,int hasta);

/** \brief funcion de librería, recibe un array de caracteres que es el cartel indicativo de lo que se está ingresando y dos números DECIMALES que ofician de valor desde y hasta
 *  se valida que lo ingresado sea un DECIMAL  y que además, esté comprendido en el rango de numeros ingresado
 * param char[] mensaje a mostrar para el usuario
 * param float valor DESDE
 * param float valor HASTA
 * \return float , un DECIMAL comprendido entre los valores DESDE y HASTA
 */
float inputFloatDesdefHastaf(char mensaje[],float desde,float hasta);

