/*
 * Articulo.h
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#define LONG_STRING 255
#define SIZE_COUNTRY 128

typedef struct
{
	char codigoArticulo[LONG_STRING];
	char descripcion[LONG_STRING];
	char pais[SIZE_COUNTRY];
	float valorFob;
	float peso;
	float ancho;
	float altura;
	float profundidad;
	char posicionArancelaria[LONG_STRING];
	int idArticulo;
}Articulo;

#endif /* ARTICULO_H_ */

Articulo* articulo_new();
Articulo* articulo_newParam(char* codigoArticulo,char* descripcion,char* pais,float valorFob,float peso,float ancho,float altura,float profundidad,char* posicionArancelaria,int idAriculo);
//-------------------------GET & SET
void articulo_setearValorInicialDeId(int id);

int articulo_delete(Articulo* this);

int articulo_setCodigoArticulo(Articulo* this, char* CodigoArticulo);
int articulo_getCodigoArticulo(Articulo* this,char* codigoArticulo);
int isValidCodigoArticulo(char* nombre);

int articulo_setDescripcion(Articulo* this, char* descripcion);
int articulo_getDescripcion (Articulo* this,char*  auxdescripcion);
int isValidDescripcion (char* descripcion );

int articulo_setPais(Articulo* this, char* pais);
int articulo_getPais (Articulo* this,char* auxpais);
int isValidPais (char* pais);

int articulo_setPosicionArancelaria(Articulo* this, char* posicionArancelaria);
int articulo_getPosicionArancelaria (Articulo* this,  char* auxposicionArancelaria);
//isValidEnArchivo"PosicionArancelaria.h"

int articulo_setValorFob(Articulo* this,float valorFob);
int articulo_getValorFob(Articulo* this, float* auxValorFob);
int isValidValorFob(float valorFob);

int articulo_setPeso(Articulo* this,float peso);
int articulo_getPeso(Articulo* this,float* auxPeso);
int isValidValorPeso(float valorFob);

int articulo_setAncho(Articulo* this,float ancho);
int articulo_getAncho(Articulo* this, float* auxAncho);
int isValidAncho(float ancho);

int articulo_setAltura(Articulo* this,float altura);
int articulo_getAltura(Articulo* this,float* auxAltura);
int isValidValorAltura(float altura);

int articulo_setProfundidad(Articulo* this,float profundidad);
int articulo_getProfundidad(Articulo* this,float* auxProfundidad);
int isValidProfundidad(float profundidad);

int articulo_setIdArticulo(Articulo* this, int idArticulo);
int articulo_getIdAriculo(Articulo* this, int* auxIdArticulo);
int isValidId(int idArticulo);

int articulo_print(Articulo* pArticulo);
//------------------------------ABMC-------------------------------------

#include "collections/Dictionary.h"

int articulo_parser(char nombreArchivo[],Dictionary* articulos,int* pIdMaxEncontrado);

int articulo_isAlphanumeric(char *pCadena);
