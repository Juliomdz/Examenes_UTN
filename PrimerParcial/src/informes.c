/*
 * informes.c
 *
 *  Created on: 4 may. 2021
 *      Author: julio
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "compra.h"
#include "utn.h"
#include "cliente.h"

/**
 * \brief Encuentra el color de barbijo que se compró mas veces
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
*/
int inf_barbijoMasComprado(Compra* arrayCompras,int limite)
{
  int retorno=-1;
  char listaColores[limite][SIZE_COLOR];
  int i;
  int j;
  int k;
  int flagExisteColor;
  int indiceColorLibre;
  int acumuladorColor[limite];
  char colorMasComprado[SIZE_COLOR];

  if(arrayCompras!=NULL && limite>0)
    {
      for(i=0;i<limite;i++)
        {
          flagExisteColor=0;
          if(arrayCompras[i].status!=0)
          {
              for(j=0;j<limite;j++)
                {
                  if(strncmp(arrayCompras[i].color,listaColores[j],SIZE_COLOR)==0)
                    {
                      flagExisteColor=1;
                      acumuladorColor[i] =acumuladorColor[i] + arrayCompras[i].cantidadBarbijos;
                      break;
                    }
                }
              if (flagExisteColor ==0)
                {
                  strncpy(listaColores[indiceColorLibre],arrayCompras[i].color,SIZE_COLOR);
                  acumuladorColor[i] =arrayCompras[i].cantidadBarbijos;
                  indiceColorLibre++;
                }
          }

        }
  for(k=0;k<limite;k++)
    {
      if(k==0 || acumuladorColor[k] > acumuladorColor[k-1])
        {
          strncpy(colorMasComprado,listaColores[k],SIZE_COLOR);
        }
    }
  retorno =0;
    printf("El color de barbijo mas comprado es: %s \n",colorMasComprado);
    }
  return retorno;
}
/**
 * \brief Recorre el array de compras y contabiliza la cantidad de compras prendientes
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
*/
int inf_contadorComprasPendientes(Compra* arrayCompras,int limite)
{
  int retorno=-1;
  int contadorComprasPendientes=0;
  int i;


  if(arrayCompras!=NULL && limite>0)
    {
      for(i=0;i<limite;i++)
        {
          if(arrayCompras[i].status==1)
            {
              contadorComprasPendientes++;
            }
        }
      printf("La cantidad de compras pendientes es: %d \n",contadorComprasPendientes);
      retorno =0;
    }
  return retorno;
}
/**
 * \brief Busca la compra con menor precio por unidad
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
*/
int inf_menorPrecioUnitario(Compra* arrayCompras,int limite)
{
  int retorno=-1;
  int i;
  float auxiliaPrecioMasBajo;
  float auxiliarPrecioUnitario;
  int idPrecioMasBajo;
  float auxiliarCantidad;
  float auxiliarImporte;

  if(arrayCompras!=NULL && limite>0)
    {
      for(i=0;i<limite;i++)
        {
          if(arrayCompras[i].status==2)
            {
              auxiliarImporte=arrayCompras[i].importe;
              auxiliarCantidad=arrayCompras[i].cantidadBarbijos;
              auxiliarPrecioUnitario=auxiliarImporte / auxiliarCantidad;
              if(i==0 || auxiliarPrecioUnitario<auxiliaPrecioMasBajo)
                {
                  idPrecioMasBajo = arrayCompras[i].idCompra;
                  auxiliaPrecioMasBajo = auxiliarPrecioUnitario;
            }
            }
        }
      retorno=0;
      printf("La compra con el precio mas bajo es la ID %d con un precio de  %.2f$ por barbijo \n",idPrecioMasBajo, auxiliaPrecioMasBajo);
    }
  return retorno;
}
