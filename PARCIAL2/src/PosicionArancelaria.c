/*
 * PosicionArancelaria.c
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "PosicionArancelaria.h"

PosicionArancelaria* posArancel_new(void)
{
	return (PosicionArancelaria*) malloc(sizeof(PosicionArancelaria));
}

PosicionArancelaria* posArancel_newParam(char* posicionArancelaria,float seguro,float importacion,float tasaEstadistica,int tipoDeLicencia)
{
	PosicionArancelaria* auxPoscAranc = posArancel_new();
	if(auxPoscAranc != NULL)
	{
		if  ( 	posArancel_setPosicionArancelaria(auxPoscAranc,posicionArancelaria) < 0 ||
				posArancel_setSeguro(auxPoscAranc,seguro) < 0 ||
				posArancel_setImportacion(auxPoscAranc,importacion) < 0 ||
				posArancel_setTasaEstadistica(auxPoscAranc,tasaEstadistica) < 0 ||
				posArancel_setTipoDeLicencia(auxPoscAranc,tipoDeLicencia) < 0 )
		{
			posArancel_delete(auxPoscAranc);
			auxPoscAranc = NULL;
		}
	}
	return auxPoscAranc;;
}

int posArancel_delete(PosicionArancelaria* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
//-------------------------------------CodigoArticulo--------------------------------
int posArancel_setPosicionArancelaria(PosicionArancelaria* this, char* posicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && posicionArancelaria != NULL && isValidPosicionArancel(posicionArancelaria))
	{
		strcpy(this->posicionArancelaria,posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}

int posArancel_getPosicionArancelaria(PosicionArancelaria* this,char* posArancel)
{
	int retorno = -1;
	if(this != NULL)
	{
		strcpy(posArancel,this->posicionArancelaria);
		retorno=0;
	}
	return retorno;
}

int isValidPosicionArancel(char* pCadena)
{
int output = 1;
    if(pCadena !=NULL){
        for(int x = 0; pCadena[x] !='\0'; x++){
            if(
                ((pCadena[x] < '0' || pCadena[x] > 'z')
             || (pCadena[x] > '9' && pCadena[x] < 'A')
             || (pCadena[x] > 'Z' && pCadena[x] < 'a'))
             && ((pCadena[x] != '.') || (pCadena[x] != '_'))){
                 output = -1;
                 break;
             }
        }
    }
    return output;
}

//------------------------Seguro

int posArancel_setSeguro(PosicionArancelaria* this,float seguro)
{
	int retorno = -1;
	if(this != NULL && seguro>=0 && isValidSeguro(seguro) )
	{
		this->seguro=seguro;
		retorno = 0;
	}
	return retorno;
}

int posArancel_getSeguro(PosicionArancelaria* this, float* auxseguro)
{
 int retorno=-1;
	if(this != NULL)
	{
		*auxseguro = this->seguro;
    retorno = 0;
  }
  return retorno;
}

int isValidSeguro(float auxseguro)
{
  {
    int retorno=-1;
    if(auxseguro >= 0 && auxseguro<99)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}

//------------------------importacion

int posArancel_setImportacion(PosicionArancelaria* this,float importacion)
{
	int retorno = -1;
	if(this != NULL && importacion>=0 && isValidImportacion(importacion) )
	{
		this->importacion=importacion;
		retorno = 0;
	}
	return retorno;
}

int posArancel_getImportacion(PosicionArancelaria* this,float* auxImportacion)
{
	int retorno = -1;
	if(this != NULL)
	{
		*auxImportacion = this->importacion;
    retorno = 0;
  }
  return retorno;
}

int isValidImportacion(float importacion)
{
  {
    int retorno=-1;
    if(importacion >= 0 && importacion<=35)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}
//------------------------tasaEstadistica

int posArancel_setTasaEstadistica(PosicionArancelaria* this,float tasaEstadistica)
{
	int retorno = -1;
	if(this != NULL && tasaEstadistica>=0 && isValidTasaEstadistica(tasaEstadistica) )
	{
		this->tasaEstadistica=tasaEstadistica;
		retorno = 0;
	}
	return retorno;
}

int posArancel_getTasaEstadistica(PosicionArancelaria* this,float* auxTasaEstadistica)
{
	int retorno = -1;

	if(this != NULL)
	{
		*auxTasaEstadistica = this->tasaEstadistica;
    retorno = 0;
  }
  return retorno;
}

int isValidTasaEstadistica(float tasaEstadistica)
{
  {
    int retorno=-1;
    if(tasaEstadistica >= 0 && tasaEstadistica<=99)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}

//--------------------------tipoDeLicencia---------------------

int posArancel_setTipoDeLicencia(PosicionArancelaria* this, int tipoDeLicencia)
{
	int retorno = -1;
	if(this != NULL && isValidTipoDeLicencia(tipoDeLicencia) )
	{
		this->tipoDeLicencia = tipoDeLicencia;
		retorno = 0;
	}
	return retorno;
}

int posArancel_getTipoDeLicencia(PosicionArancelaria* this,int* auxTipoDeLicencia)
{
	int retorno = -1;
	if(this != NULL)
	{
		*auxTipoDeLicencia=this->tipoDeLicencia;
    retorno = 0;
  }
  return retorno;
}

int isValidTipoDeLicencia(int tipoDeLicencia)
{
  {
    int retorno=-1;
    if(tipoDeLicencia == 0 || tipoDeLicencia==1)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}


int posArancel_parser(char* nombreArchivo,Dictionary* posicionesArancel)
{
	FILE* pFile;
	char posicionArancelaria[LONG_STRING];
	char seguro[LONG_STRING];//float
	char importacion[LONG_STRING];//float
	char tasaEstadistica[LONG_STRING];//float
	char tipoDeLicencia[LONG_STRING];
	float seguroAux;
	float importacionAux;
	float tasaEstadisticaAux;
	int tipoDeLicenciaAux;
	PosicionArancelaria* pPosA;
	int indice=-1;
	pFile = fopen(nombreArchivo,"r");
	if(pFile!=NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",posicionArancelaria,seguro,importacion,tasaEstadistica,tipoDeLicencia)==5)
			{
				if(utn_esDecimal(seguro,99)==1 && utn_esDecimal(importacion,35)==1 && utn_esDecimal(tasaEstadistica,99)==1 && utn_esNumerica(tipoDeLicencia,1)==1)
				{
					seguroAux=atof(seguro);
					importacionAux=atof(importacion);
					tasaEstadisticaAux=atof(tasaEstadistica);
					tipoDeLicenciaAux=atoi(tipoDeLicencia);
					pPosA = posArancel_newParam(posicionArancelaria,seguroAux,importacionAux,tasaEstadisticaAux,tipoDeLicenciaAux);
					if(pPosA!=NULL)
					{
						dict_insert(posicionesArancel,posicionArancelaria,pPosA);
					}
					indice++;
				}
			}
			else
			{
          printf("\nError en el parseo de datos de Posiciones.\n");
			}
		}
		while(feof(pFile)==0);
		fclose(pFile);
	}
	return indice;//cantidad de leidos
}
int posArancel_print(PosicionArancelaria* pPosA){
    int retorno=-1;
    char posicionArancelaria[LONG_STRING];
    float seguro;
    float importacion;
    float tasaEstadistica;
    int tipoDeLicencia;
    char tipoLicenciaText[20];

    if(pPosA != NULL  &&
        posArancel_getPosicionArancelaria(pPosA,posicionArancelaria)==0 &&
        posArancel_getSeguro(pPosA,&seguro)==0&& //8517.62.99.900R
        posArancel_getImportacion(pPosA,&importacion)==0&&
        posArancel_getTasaEstadistica(pPosA,&tasaEstadistica)==0&&
        posArancel_getTipoDeLicencia(pPosA,&tipoDeLicencia)==0){
        retorno=1;
        if(tipoDeLicencia==0)
        {
            strcpy(tipoLicenciaText,"AUTOMATICA");
        }
        else
          {
            strcpy(tipoLicenciaText,"NO AUTOMATICA");
          }
        printf("%12s    %7.4f    %7.4f    %7.4f    %15s\n",posicionArancelaria,seguro,importacion,tasaEstadistica,tipoLicenciaText);
    }
    return retorno;
}

