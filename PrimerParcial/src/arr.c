/*
 * arr.c
 *
 *  Created on: 30 mar. 2021
 *      Author: julio
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "arr.h"


int arr_calcularMaximoInt(int* array, int limite, int* pResultado)
{
  int retorno = -1;
  int maximo;
  if(array != NULL && limite> 0 && pResultado !=NULL)
  {
    maximo = array[0];
    for(int i=1; i<limite;i++)
      {
        if(array[i]> maximo)
        {
          maximo = array[i];
        }
      }
    *pResultado=maximo;
    retorno =0;
  }
  return retorno;
}

int arr_calcularMinimoInt(int* array, int limite, int* pResultado)
{
  int retorno = -1;
  int minimo;
  if(array != NULL && limite> 0 && pResultado !=NULL)
  {
    minimo = array[0];
    for(int i=1; i<limite;i++)
      {
        if(array[i]< minimo)
        {
          minimo = array[i];
        }
      }
    *pResultado=minimo;
    retorno =0;
  }
  return retorno;
}


int arr_calcularPromedioInt(int* array, int limite, float* pResultado)
{
  int retorno = -1;
  int suma = 0;
  float promedio = 0;

  if(array != NULL && limite > 0 && pResultado != NULL)
  {
    for(int i = 0; i<limite; i++)
    {
      suma = suma + array[i];
    }
    promedio = (float) suma / limite;
    *pResultado = promedio;
    retorno = 0;
  }
  return retorno;
}


int arr_calcularSumaInt(int* array, int limite, float* pResultado)
{
  int retorno = -1;
  int suma = 0;

  if(array != NULL && limite > 0 && pResultado != NULL)
  {
    for(int i = 0; i<limite; i++)
    {
      suma = suma + array[i];
    }
    *pResultado = suma;
    retorno = 0;
  }
  return retorno;
}
int arr_OrdenDecrecienteInt (int* pArray, int limite)
{
  int retorno =-1;
  int aux;
  int flagSwap=0;
  int nuevoLimite;
  int i;

  if (pArray!= NULL && limite >=0)
    nuevoLimite=limite-1;
  do
    {
    flagSwap=0;
    for(i=0; i<nuevoLimite; i++)
    {
        if(pArray[i]<pArray[i+1])
          {
            flagSwap=1;
            aux=pArray[i];
            pArray[i]=pArray[i+1];
            pArray[i+1]=aux;
          }
    }
    nuevoLimite--;
    }
  while(flagSwap);
  retorno=0;

return retorno;
}
int arr_OrdenCrecienteInt (int* pArray, int limite)
{
  int retorno =-1;
  int aux;
  int flagSwap=0;
  int nuevoLimite;
  int i;

  if (pArray!= NULL && limite >=0)
    nuevoLimite=limite-1;
  do
    {
    flagSwap=0;
    for(i=0; i<nuevoLimite; i++)
    {
        if(pArray[i]>pArray[i+1])
          {
            flagSwap=1;
            aux=pArray[i];
            pArray[i]=pArray[i+1];
            pArray[i+1]=aux;
          }
    }
    nuevoLimite--;
    }
  while(flagSwap);
  retorno=0;

return retorno;
}
