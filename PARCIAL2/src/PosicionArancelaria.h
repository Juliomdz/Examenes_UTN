/*
 * PosicionArancelaria.h
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */

#ifndef POSICIONARANCELARIA_H_
#define POSICIONARANCELARIA_H_
#define LONG_STRING 255

typedef struct
{
	char posicionArancelaria[LONG_STRING];
	float seguro;
	float importacion;
	float tasaEstadistica;
	int tipoDeLicencia; //0 = automatica | 1 = no automatica
}PosicionArancelaria;


PosicionArancelaria* posArancel_new();
PosicionArancelaria* posArancel_newParam(char* posicionArancelaria,float seguro,float importacion,float tasaEstadistica,int tipoDeLicencia);
int posArancel_delete(PosicionArancelaria* this);
int posArancel_setPosicionArancelaria(PosicionArancelaria* this, char* posicionArancelaria);
int posArancel_getPosicionArancelaria(PosicionArancelaria* this,char* posArancel);
int isValidPosicionArancel(char* posicionArancelaria);
int posArancel_setSeguro(PosicionArancelaria* this,float seguro);
int posArancel_getSeguro(PosicionArancelaria* this, float* auxseguro);
int isValidSeguro(float auxseguro);
int posArancel_setImportacion(PosicionArancelaria* this,float importacion);
int posArancel_getImportacion(PosicionArancelaria* this,float* auxImportacion);
int isValidImportacion(float importacion);
int posArancel_setTasaEstadistica(PosicionArancelaria* this,float tasaEstadistica);
int posArancel_getTasaEstadistica(PosicionArancelaria* this,float* auxTasaEstadistica);
int isValidTasaEstadistica(float tasaEstadistica);
int posArancel_setTipoDeLicencia(PosicionArancelaria* this, int tipoDeLicencia);
int posArancel_getTipoDeLicencia(PosicionArancelaria* this,int* auxTipoDeLicencia);
int isValidTipoDeLicencia(int tipoDeLicencia);
//---------------------------------------------------------
#include "collections/Dictionary.h"

int posArancel_parser(char nombreArchivo[],Dictionary* posicionesArancel);
int posArancel_print(PosicionArancelaria* pPosA);

#endif /* POSICIONARANCELARIA_H_ */
