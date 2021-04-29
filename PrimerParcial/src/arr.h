/*
 * arr.h
 *
 *  Created on: 30 mar. 2021
 *      Author: julio
 */

#ifndef ARR_H_
#define ARR_H_



#endif /* ARR_H_ */

/**
* \brief Recibe un array de numeros, lo valida y busca el maximo
* \param int* array: Puntero al espacio de memoria desde donde se copiará la cadena
* \param limite: Define el tamaño del array
* \param int* resultado: Devuelve el maximo hallado al puntero resultado
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int arr_calcularMaximoInt(int* array,int limite, int* resultado);
/**
* \brief Recibe un array de numeros, lo valida y busca el minimo
* \param int* array: Puntero al espacio de memoria desde donde se copiará la cadena
* \param limite: Define el tamaño del array
* \param int* resultado: Devuelve el minimo hallado al puntero resultado
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int arr_calcularMinimoInt(int* array,int limite, int* resultado);
/**
* \brief Recibe un array de numeros, lo valida y busca el promedio
* \param int* array: Puntero al espacio de memoria desde donde se copiará la cadena
* \param limite: Define el tamaño del array
* \param int* resultado: Devuelve el promedio hallado al puntero resultado
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int arr_calcularPromedioInt(int* array,int limite, float* resultado);
/**
* \brief Recibe un array de numeros, lo valida y suma todos los valores
* \param int* array: Puntero al espacio de memoria desde donde se copiará la cadena
* \param limite: Define el tamaño del array
* \param int* resultado: Devuelve la suma total hallada al puntero resultado
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int arr_calcularSumaInt(int* array,int limite, float* resultado);
/**
* \brief Recibe un array de numeros, lo valida y ordena de forma creciente
* \param int* array: Puntero al espacio de memoria desde donde se copiará la cadena y regresará ordenada
* \param limite: Define el tamaño del array
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int arr_OrdenCrecienteInt (int* pArray, int limite);
/**
* \brief Recibe un array de numeros, lo valida y ordena de forma creciente
* \param int* array: Puntero al espacio de memoria desde donde se copiará la cadena y regresará ordenada
* \param limite: Define el tamaño del array
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int arr_OrdenDecrecienteInt (int* pArray, int limite);
