/*
 * costosTransporte.c
 *
 *  Created on: 22 jun. 2021
 *      Author: julio
 */

#include "costosTransporte.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

CostosTransporte* costos_new(void)
{
  return (CostosTransporte*) malloc(sizeof(CostosTransporte));
}
int costos_setValorContenedor(CostosTransporte* this,float valorContenedor)
{
  int retorno = -1;
  if(this != NULL && valorContenedor>0 && isValidContenedor(valorContenedor) )
  {
    this->valorContenedor=valorContenedor;
    retorno = 0;
  }
  return retorno;
}

int costos_getValorContenedor(CostosTransporte* this, float* valorContenedor)
{
 int retorno=-1;
  if(this != NULL)
  {
    *valorContenedor = this->valorContenedor;
    retorno = 0;
  }
  return retorno;
}

int isValidContenedor(float valorContenedor)
{
  {
    int retorno=-1;
    if(valorContenedor > 0 && valorContenedor<9999999)
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
int costos_setMetrosCubicosContenedor(CostosTransporte* this,float metrosCubicosContenedor)
{
  int retorno = -1;
  if(this != NULL && metrosCubicosContenedor>0 && isValidMetrosCubicos(metrosCubicosContenedor) )
  {
    this->metrosCubicosContenedor=metrosCubicosContenedor;
    retorno = 0;
  }
  return retorno;
}

int costos_getMetrosCubicosContenedor(CostosTransporte* this, float* metrosCubicosContenedor)
{
 int retorno=-1;
  if(this != NULL)
  {
    *metrosCubicosContenedor = this->metrosCubicosContenedor;
    retorno = 0;
  }
  return retorno;
}

int isValidMetrosCubicos(float metrosCubicosContenedor)
{
  {
    int retorno=-1;
    if(metrosCubicosContenedor > 0 && metrosCubicosContenedor<9999999)
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

int costos_setPrecioPorKilo(CostosTransporte* this,float precioPorKilo)
{
  int retorno = -1;
  if(this != NULL && precioPorKilo>0 && isValidMetrosCubicos(precioPorKilo) )
  {
    this->precioPorKilo=precioPorKilo;
    retorno = 0;
  }
  return retorno;
}

int costos_getPrecioPorKilo(CostosTransporte* this, float* precioPorKilo)
{
 int retorno=-1;
  if(this != NULL)
  {
    *precioPorKilo = this->precioPorKilo;
    retorno = 0;
  }
  return retorno;
}

int isValidPrecioPorKilo(float precioPorKilo)
{
  {
    int retorno=-1;
    if(precioPorKilo > 0 && precioPorKilo<9999999)
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

int costos_setConstanteVolumetrica(CostosTransporte* this,float constanteVolumetrica)
{
  int retorno = -1;
  if(this != NULL && constanteVolumetrica>0 && isValidMetrosCubicos(constanteVolumetrica) )
  {
    this->constanteVolumetrica=constanteVolumetrica;
    retorno = 0;
  }
  return retorno;
}

int costos_getConstanteVolumetrica(CostosTransporte* this, float* constanteVolumetrica)
{
 int retorno=-1;
  if(this != NULL)
  {
    *constanteVolumetrica = this->constanteVolumetrica;
    retorno = 0;
  }
  return retorno;
}

int isValidConstanteVolumetrica(float constanteVolumetrica)
{
  {
    int retorno=-1;
    if(constanteVolumetrica > 0 && constanteVolumetrica<9999999)
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

int costos_parser(char* nombreArchivo,CostosTransporte* pCostos)
{
  FILE* pFile;
  float valorContenedor;
  float metrosCubicosContenedor;
  float precioPorKilo;
  float constanteVolumetrica;
  char valorContenedorAux[16];
  char MetrosCubicosContenedorAux[16];
  char precioPorKiloAux[16];
  char ConstanteVolumetricaAux[16];
  int retorno=-1;
  pFile = fopen(nombreArchivo,"r");
  if(pFile!=NULL)
  {
    do
    {
      if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",valorContenedorAux,MetrosCubicosContenedorAux,precioPorKiloAux,ConstanteVolumetricaAux)==4)
      {
          if(utn_esDecimal(valorContenedorAux,9999999)==1 && utn_esDecimal(MetrosCubicosContenedorAux,9999999)==1 && utn_esDecimal(precioPorKiloAux,9999999)==1 && utn_esDecimal(ConstanteVolumetricaAux,9999999)==1)
          {
            valorContenedor=atof(valorContenedorAux);
            metrosCubicosContenedor=atof(MetrosCubicosContenedorAux);
            precioPorKilo=atof(precioPorKiloAux);
            constanteVolumetrica=atof(ConstanteVolumetricaAux);
            costos_setValorContenedor(pCostos, valorContenedor);
            costos_setMetrosCubicosContenedor(pCostos, metrosCubicosContenedor);
            costos_setPrecioPorKilo(pCostos, precioPorKilo);
            costos_setConstanteVolumetrica(pCostos, constanteVolumetrica);
          if(pCostos!=NULL)
          {
            retorno=1;
          //  printf("\nCostos de transporte cargados satisfactoriamente.\n");
          }
          else
          {
              retorno=0;
              printf("\nError en el parseo de costos de transporte.\n");
          }
          }
      }
      else
      {
          retorno=0;
          printf("\nError en el parseo de costos de transporte.\n");
      }
    }
    while(feof(pFile)==0);
    fclose(pFile);
  }
  return retorno;//cantidad de leidos
}
