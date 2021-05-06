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
#include "informes.h"

/**
 * \brief Encuentra el color de barbijo que se compró mas veces
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
 */
int
inf_barbijoMasComprado (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  char listaColores[limite][SIZE_COLOR];
  int i;
  int j;
  int k;
  int l;
  int m;
  int flagExisteColor;
  int indiceColorLibre = 0;
  int acumuladorColor[limite];
  char colorMasComprado[SIZE_COLOR];
  int cantidadColorMasComprado = 0;

  if (arrayCompras != NULL && limite > 0)
    {
      for (i = 0; i < limite; i++)
        {
          flagExisteColor = 0;
          if (arrayCompras[i].status != 0)
            {
              for (j = 0; j < limite; j++)
                {
                  acumuladorColor[i] = 0;
                  if (strncmp (arrayCompras[i].color, listaColores[j],
                               SIZE_COLOR) == 0)
                    {
                      flagExisteColor = 1;
                      break;
                    }
                }
              if (flagExisteColor == 0)
                {
                  strncpy (listaColores[indiceColorLibre],
                           arrayCompras[i].color, SIZE_COLOR);
                  indiceColorLibre++;
                }
            }
          else
            {
              continue;
            }

        }
      for (m = 0; m < limite; m++)
        {
          for (l = 0; l < limite; l++)
            {
              if (arrayCompras[l].status == 0)
                {
                  continue;
                }
              if (strncmp (arrayCompras[l].color, listaColores[m], SIZE_COLOR)
                  == 0)
                {
                  acumuladorColor[m] = acumuladorColor[m]
                      + (arrayCompras[l].cantidadBarbijos);
                }

            }
        }
      for (k = 0; k < limite; k++)
        {
          if (k == 0 || acumuladorColor[k] > cantidadColorMasComprado)
            {
              cantidadColorMasComprado = acumuladorColor[k];
              strncpy (colorMasComprado, listaColores[k], SIZE_COLOR);
            }
        }
      retorno = 0;
      printf ("El color de barbijo mas comprado es: %s con %d unidades.\n",
              colorMasComprado, cantidadColorMasComprado);
    }
  return retorno;
}
/**
 * \brief Recorre el array de compras y contabiliza la cantidad de compras prendientes
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
inf_contadorComprasPendientes (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  int contadorComprasPendientes = 0;
  int i;

  if (arrayCompras != NULL && limite > 0)
    {
      for (i = 0; i < limite; i++)
        {
          if (arrayCompras[i].status == 1)
            {
              contadorComprasPendientes++;
            }
        }
      printf ("La cantidad de compras pendientes es: %d \n",
              contadorComprasPendientes);
      retorno = 0;
    }
  return retorno;
}
/**
 * \brief Busca la compra con menor precio por unidad
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
inf_menorPrecioUnitario (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  int i;
  float auxiliaPrecioMasBajo;
  float auxiliarPrecioUnitario;
  int idPrecioMasBajo;
  float auxiliarCantidad;
  float auxiliarImporte;

  if (arrayCompras != NULL && limite > 0)
    {
      for (i = 0; i < limite; i++)
        {
          if (arrayCompras[i].status == 2)
            {
              auxiliarImporte = arrayCompras[i].importe;
              auxiliarCantidad = arrayCompras[i].cantidadBarbijos;
              auxiliarPrecioUnitario = auxiliarImporte / auxiliarCantidad;
              if (i == 0 || auxiliarPrecioUnitario < auxiliaPrecioMasBajo)
                {
                  idPrecioMasBajo = arrayCompras[i].idCompra;
                  auxiliaPrecioMasBajo = auxiliarPrecioUnitario;
                }
            }
        }
      retorno = 0;
      printf (
          "La compra con el precio mas bajo es la ID %d con un precio de  %.2f$ por barbijo \n",
          idPrecioMasBajo, auxiliaPrecioMasBajo);
    }
  return retorno;
}

/**
 * \brief Encuentra el cliente con mas compras completadas
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
 */

int
inf_clienteMasPagadas (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  int listaClientes[limite];
  int i;
  int acumuladorCliente[limite];
  int clienteMasCompro = 0;
  int cantidadMasCompro = 0;

  if (arrayCompras != NULL && limite > 0)
    {
      inf_noRepetidos (arrayCompras, limite, listaClientes, 2);
      inf_clienteMasStatus (arrayCompras, limite, listaClientes, 2,
                            acumuladorCliente);
      for (i = 0; i < limite; i++)
        {
          if (i == 0 || acumuladorCliente[i] > cantidadMasCompro)
            {
              cantidadMasCompro = acumuladorCliente[i];
              clienteMasCompro = listaClientes[i];
            }
        }
      retorno = 0;
      printf (
          "El cliente que mas compras completo es ID: %d con %d compras completadas.\n",
          clienteMasCompro, cantidadMasCompro);
    }
  return retorno;
}
/**
 * \brief Encuentra el cliente con mas compras pendientes
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
 */
int
inf_clienteMasPendientes (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  int listaClientes[limite];
  int k;
  int acumuladorCliente[limite];
  int clienteMasPendiente = 0;
  int cantidadMasPendiente = 0;

  if (arrayCompras != NULL && limite > 0)
    {
      inf_noRepetidos (arrayCompras, limite, listaClientes, 1);
      inf_clienteMasStatus (arrayCompras, limite, listaClientes, 1,
                            acumuladorCliente);
      for (k = 0; k < limite; k++)
        {
          if (k == 0 || acumuladorCliente[k] > cantidadMasPendiente)
            {
              cantidadMasPendiente = acumuladorCliente[k];
              clienteMasPendiente = listaClientes[k];
            }
        }
      retorno = 0;
      printf (
          "El cliente con mas compras pendientes es ID: %d con %d compras pendientes.\n",
          clienteMasPendiente, cantidadMasPendiente);
    }
  return retorno;
}
/**
 * \brief Imprime la lista de compras pendientes de pago y el cliente al que pertenece cada una
 * \param Cliente* arrayCliente: recibe el array de clientes
 * \param int limiteClientes: recibe el limite maximo de clientes posible
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limiteCompras: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
inf_imprimirListaPendientesDePago (Cliente *arrayClientes, int limiteClientes,
                                   Compra *arrayCompras, int limiteCompras)
{
  int retorno = -1;
  int i;
  int auxiliarIdCliente;

  if (limiteClientes > 0 && arrayCompras != NULL)
    {
      printf ("Estas son las compras pendientes de pago:\n");
      retorno = 1;
      for (i = 0; i < limiteClientes; i++)
        {
          if (arrayCompras[i].status == 1)
            {
              com_imprimir (&arrayCompras[i]);
              auxiliarIdCliente = arrayCompras[i].idCliente;
              com_imprimirClientesPorId (arrayClientes, limiteClientes,
                                         auxiliarIdCliente);
              printf ("\n");
            }
        }
    }
  return retorno;
}
/**
 * \brief Arma una lista de clientes no repetidos segun el status de la compra
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \param int* listaClientes: Devuelve la lista de clientes sin repetir a ese espacio de memoria
 * \param int statusBuscado: recibe el tipo de status que se desea usar como criterio para armar la lista
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
 */

int
inf_noRepetidos (Compra *arrayCompras, int limite, int *listaClientes,
                 int statusBuscado)
{
  int retorno = -1;
  int flagExisteCliente;
  int indiceClienteLibre = 0;
  int i;
  int j;

  flagExisteCliente = 0;
  if (arrayCompras != NULL && limite > 0)
    {
      for (i = 0; i < limite; i++)
        {
          flagExisteCliente = 0;
          if (arrayCompras[i].status == statusBuscado)
            {
              for (j = 0; j < limite; j++)
                {
                  if (arrayCompras[i].idCliente == listaClientes[j])
                    {
                      flagExisteCliente = 1;
                      break;
                    }
                }
              if (flagExisteCliente == 0)
                {
                  listaClientes[indiceClienteLibre] = arrayCompras[i].idCliente;
                  indiceClienteLibre++;
                }
            }
        }
      retorno = 0;
    }

  return retorno;
}
/**
 * \brief Recibe una lista de clientes sin repetir y busca al de mas compras de un status dado
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \param int* listaClientes: RECIBE lista de clientes sin repetir
 * \param int statusBuscado: recibe el tipo de status que se desea usar como criterio
 *                           para buscar el cliente de mas compras de este tipo
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
 */
int
inf_clienteMasStatus (Compra *arrayCompras, int limite, int *listaClientes,
                      int statusBuscado, int *acumuladorCliente)
{
  int retorno = -1;
  int i;
  int j;

  if (arrayCompras != NULL && limite > 0)
    {
      for (i = 0; i < limite; i++)
        {
          acumuladorCliente[i] = 0;
          for (j = 0; j < limite; j++)
            {
              if (arrayCompras[j].status != statusBuscado)
                {
                  continue;
                }
              if (arrayCompras[j].idCliente == listaClientes[i])
                {
                  acumuladorCliente[i] = (acumuladorCliente[i] + 1);
                }

            }
        }
      retorno = 0;
    }
  return retorno;
}
