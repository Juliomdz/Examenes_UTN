/*
 * utn.h
 *
 *  Created on: 16 abr. 2021
 *      Author: julio
 */

#ifndef UTN_H_
#define UTN_H_

/**
* \brief Recibe un string, lo recorre verificando que no quede un '\n' antes de la penultima posición y la valida
* \param char* string: Puntero al espacio de memoria donde se copiará la cadena obtenida
* \param limite: Define el tamaño del string
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int myGets(char* string, int limite);
/**
 * \brief Transforma una cadena de caractéres a números si es posible
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número entero o -1 (ERROR) si no
*/
int utn_getInt(int *pResultado);
/**
 * \brief Transforma una cadena de caractéres a números decimales si es posible
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número decimal o -1 (ERROR) si no
*/
int getFloat(float *pResultado);
/**
 * \brief Verifica que la cadena recibida contenga solamente números positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esNumerica(char* cadena, int limite);
/**
 * \brief Verifica que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esDecimal(char* cadena, int limite);
/**
 * \brief Le pide al usuario un número entero entre un rango
 * \param int* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* mensaje: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int min: El rango mínimo para ingresar un número
 * \param int max: El rango máximo para ingresar un número
 * \param int reintentos: cantidad de veces que, en caso de error, se volverá a iterar
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getNumero(int* pNumero, const char* mensaje, const char* mensajeError, int min, int max,int reintentos);
/**
 * \brief Le pide al usuario un número racional
 * \param float* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* sError: Texto que nos indica que hubo un error
 * \param int reintentos: cantidad de veces que, en caso de error, se volverá a iterar
 * \return Retorna 0 (EXITO) si se obtiene un número racional o -1 (ERROR) si no
*/
int utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, float min, float max, int reintentos);
/**
 * \brief Suma dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la suma, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la suma o -1 (ERROR) si no
*/
int utn_sumar(float numeroA, float numeroB, float* pResultado);
/**
 * \brief Resta dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la resta, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
*/
int utn_restar(float numeroA, float numeroB, float* pResultado);
/**
 * \brief Divide dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la división, que va a llegar al main mediante un puntero
 * \param const char* pDivisionPorCero: Mensaje de error si el divisor es cero
 * \return Retorna 0 (EXITO) si se pudo completar la division o -1 (ERROR) si no o si el divisor es 0
*/
int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero);
/**
 * \brief Multiplica dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la multiplicación, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la multiplicación o -1 (ERROR) si no
*/
int utn_multiplicar(float dividendo, float divisor, float* pResultado);
/**
 * \brief Factoriza un número ingresado y lo devuelve mediante un puntero
 * \param float numero: Número a ser factoriado
 * \param float* pResultado: El resultado de la factorización, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la factorisación o -1 (ERROR) si no
*/
int utn_factorial(float numero, float* pResultado);
/**
 * \brief Le pide al usuario una cadena de caracteres, la valida y verifica que no quede un enter
 * \param char* pResultado: Puntero donde se almacena la cadena de caracteres
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int limite: El maximo de caracteres que se pueden ingresar
 * \param int reintentos: cantidad de veces que se puede reintentar en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getText(char* pResultado, char* pMensaje, char* mensajeError, int limite, int reintentos);

/**
 * \brief Le pide al usuario un caracter y lo valida
 * \param char* pResultado: Puntero donde se almacena el caracter
 * \param  char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* mensajeError: Texto que nos indica que hubo un error
 * \param int reintentos: cantidad de veces que se puede reintentar en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_GetChar(char* pResultado,char* pMensaje,char* mensajeError,int reintentos);
/**
 * \brief recibe un char y valida que sea un valor entre a y z
 * \param char* letra: Puntero donde se almacena el caracter
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int esLetra(char* letra);

/**
 * \brief Le pide al usuario que ingrese un texto y lo convierte en mayúsculas
 * \param char* pString: Puntero donde se almacenará el texto ingresado en mayúsculas
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el texto en mayúsculas o -1 (ERROR) si no
 */
int utn_getCadenaMayusculas(char* pString, int limite, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un texto y lo convierte en minúsculas
 * \param char* pString: Puntero donde se almacenará el texto ingresado en minúsculas
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el texto en minúsculas o -1 (ERROR) si no
 */
int utn_getCadenaMinusculas(char* pString, int limite, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un nombre
 * \param char* pNombre: Puntero donde se almacenará el nombre ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param int limite: tamaño maximo de la cadena
 * \param int reintentos: cantidad de reintentos dispoinbles
 * \return Retorna 0 (EXITO) si se obtiene el nombre o -1 (ERROR) si no
 */
int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos);

/**
 * \brief Le pide al usuario que ingrese un DNI
 * \param char* pDni: Puntero donde se almacenará el DNI ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el DNI o -1 (ERROR) si no
 */
int utn_getDni(char* pDni, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un CUIT
 * \param char* pCuit: Puntero donde se almacenará el CUIT ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param int limite: tamaño maximo de la cadena
 * \param int reintentos: cantidad de reintentos dispoinbles
 * \return Retorna 0 (EXITO) si se obtiene el CUIT o -1 (ERROR) si no
 */
int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError, int limite, int reintentos);

/**
 * \brief Le pide al usuario una edad
 * \param int* pEdad: Puntero donde se almacenará la edad ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la edad o -1 (ERROR) si no
 */
int utn_getEdad(int* pEdad, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario un precio
 * \param float* pPrecio: Puntero donde se almacenará el precio ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el precio o -1 (ERROR) si no
 */
int utn_getPrecio(float* pPrecio, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un teléfono
 * \param char* pTelefono: Puntero donde se almacenará el telefono ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el teléfono o -1 (ERROR) si no
 */
int utn_getTelefono(char* pTelefono, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un celular
 * \param char* pCelular: Puntero donde se almacenará el celular ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el celular o -1 (ERROR) si no
 */
int utn_getCelular(char* pCelular, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un email
 * \param char* pEmail: Puntero donde se almacenará el email ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el email o -1 (ERROR) si no
 */
int utn_getEmail(char* pEmail, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese un sitio web
 * \param char* pSitioWeb: Puntero donde se almacenará el sitio web ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el sitio web o -1 (ERROR) si no
 */
int utn_getSitioWeb(char* pSitioWeb, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese una tarjeta de crédito
 * \param char* pTarjeta: Puntero donde se almacenará la tarjeta de crédito ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la tarjeta de crédito o -1 (ERROR) si no
  */
int utn_getTarjetaCredito(char* pTarjeta, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese una dirección
 * \param char* pDireccion: Puntero donde se almacenará la direccion ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeAltura: Texto que informa que se debe ingresar una altura
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param char* pMensajeErrorAltura: Texto que nos informa que faltó escribir la altura de la dirección
 * \return Retorna 0 (EXITO) si se obtiene la dirección o -1 (ERROR) si no
 */
int utn_getDireccion(char* pDireccion, char* pMensaje, char* pMensajeAltura, char* pMensajeError, char* pMensajeErrorAltura);

/**
 * \brief Pide un texto al usuario y lo convierte en mayúsculas
 * \param char* cadena: Puntero donde se almacenará el texto en mayúsculas
 * \param limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) si se convierte en mayúsculas o -1 (ERROR) si no
 */
int getMayusculas(char* cadena, int limite);

/**
 * \brief Pide un texto al usuario y lo convierte en minúsculas
 * \param char* cadena: Puntero donde se almacenará el texto en minúsculas
 * \param limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) si se convierte en minúsculas o -1 (ERROR) si no
 */
int getMinusculas(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDecimal(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un nombre o apellido válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un nombre o apellido, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarNombre(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un DNI válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un DNI, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDni(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un CUIT válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un CUIT, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarCuit(char* cadena, int limite);

/**
 * \brief Valida que el número ingresado sea una edad válida
 * \param int* pNumero: Puntero donde se almacenará la edad correcta
 * \return Retorna 1 (verdadero) si es una edad válida, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarEdad(int* pNumero);


/**
 * \brief Valida que el número ingresado sea un precio válido
 * \param float* pResultado: Puntero donde se almacenará el precio
 * \return Retorna 1 (verdadero) si es un precio válido, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarPrecio(float* pResultado);

/**
 * \brief Valida que la cadena recibida sea un teléfono válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un teléfono, 0 (falso) si no o -1 si hubo algún error con los argumentos
  */
int validarTelefono(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un celular válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un celular, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarCelular(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un email válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un email, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarEmail(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un sitio web válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un sitio web, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarSitioWeb(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea una tarjeta de crédito válida
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una tarjeta de crédito, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarTarjetaCredito(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga una dirección válida
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una dirección, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDireccion(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga una altura válida de una dirección
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una altura de dirección, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDireccionAltura(char* cadena, int limite);
/**
 * \brief Pregunta al usuario si desea continuar y valida que ingres Y/y o N/n
 * \param char* pResultado: Puntero donde se almacena el caracter
 * \param  char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* mensajeError: Texto que nos indica que hubo un error
 * \param int reintentos: cantidad de veces que se puede reintentar en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getContinue(char* pRespuesta,char* pMensaje,char* mensajeError,int reintentos);

/**
 * \brief Verifica que una cadena de caracteres sea un numero entero sin signo
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 1 (EXITO) si es un entero; 0(NO) si el string no es un numero; -1 (ERROR) si es nulo
*/
int utn_esUnsignedEnteroChar(char* string);

/**
 * @fn int utn_isAlphanumeric(char*)
 * @brief Funcion que chequea si una cadena es alfanumerica
 *
 * @param pCadena: El puntero a char que se recorre para corroborar si es alfabetico
 * @return (0) Error (1)  OK
 */
int utn_isAlphanumeric(char *pCadena);

/**
 * @fn int utn_isNumeric(char*)
 * @brief Funcion que chequea si una cadena es numerica
 *
 * @param pCadena: El puntero a char que se recorre para corroborar si es alfabetico
 * @return (0) Error (1) OK
 */
int utn_isNumeric(char *pCadena);

/**
 * @fn int utn_getString(char*, char*, char*, int, int)
 * @brief Funcion que solicita por stdin el ingreso de una cadena que permite letras y numeros
 *
 * @param msg: El puntero a char que solicita el ingreso de una cadena
 * @param msgError: El puntero a char que informa de un error
 * @param pCadena: El puntero a char donde se guardar la cadena
 * @param limite: El limite de la cadena
 * @param reintentos: La cantidad de veces que el usuario puede reintentar en caso de error
 * @return (-1) Error (0)  OK
 */
int utn_getStringWithNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos);

/**
 * @fn int utn_getStringWithOnlyNumbers(char*, char*, char*, int, int)
 * @brief Funcion que solicita por stdin el ingreso de una cadena que permite solo numeros
 *
 * @param msg: El puntero a char que solicita el ingreso de una cadena
 * @param msgError: El puntero a char que informa de un error
 * @param pCadena: El puntero a char donde se guardar la cadena
 * @param limite: El limite de la cadena
 * @param reintentos: La cantidad de veces que el usuario puede reintentar en caso de error
 * @return (-1) Error (0)  OK
 */
int utn_getStringWithOnlyNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos);

/**
 * \brief Chequea que la cadena recibida sea un texto sin comas
 * \param char*: Cadena a validar
 * @return (-1) Error (1)  OK  (0) Caracteres Invalidos
 */
int utn_esTexto(char* str);

#endif /* UTN_H_ */
