#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#endif //input_H_INCLUDED

/** \brief Despliega un menu
 * \param void.
 * \return la opcion que el usuario ingresa por teclado. */
int menu (void);

/** \brief pide un numero al usuario, lo valida y devuelve.
 * \param mensaje: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param numero: es la variable donde almacenaremos el numero ingresado.
 * \param min: es el numero minimo que se puede ingresar.
 * \param max: es el numero maximo que se puede ingresar.
 * \return void */
void getInt(char* mensaje, char* error, int* numero, int min, int max);

/** \brief pide un numero decimal al usuario, lo valida y lo devuelve.
 * \param mensaje es el mensaje a mostrar.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param numeroFloat donde almacenaremos el numero ingresado.
 * \param min: es el numero minimo que se puede ingresar.
 * \param max: es el numero maximo que se puede ingresar.
 * \return void */

void getFloat(char* mensaje, char* error, float* numeroFloat, int min, int max);

/** \brief pide un caracter al usuario, lo valida y lo devuelve.
 * \param mensaje: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param caracter: es la variable donde almacenaremos el caracter ingresado.
 * \param min: es el caracter minimo que se puede ingresar.
 * \param max: es el caracter maximo que se puede ingresar.
 * \return void */
void getChar(char* mensaje, char* error, char* caracter, int min, int max);

/** \brief busca una respuesta del usuario pidiendole que indique un caracter u otro.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param inputChar: es la variable donde almacenaremos el caracter ingresado.
 * \param min: es el primer caracter valido que se puede ingresar.
 * \param max: es el segundo caracter valido que se puede ingresar.
 * \return void */
void obtenerCaracterEspecifico(char* mensaje, char* error, char* caracter, char car1, char car2);

/** \brief pide un texto al usuario, lo valida por rango y lo devuelve.
 * \param inputString: es la variable donde almacenaremos el texto ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es la cantidad de caracteres minima permitida.
 * \param max: es la cantidad de caracteres maxima permitida.
 * \return void */
void getString (char* mensaje, char error[], char* cadena, int min, int max);

