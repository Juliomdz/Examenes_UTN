/*
 * compra.c
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

/**
 * \brief Inicializa el array de Compras con el estatus 0 (vacio) y el importe en 0
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_init (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayCompras != NULL)
    {
      retorno = 1;
      for (i = 0; i < limite; i++)
        {
          arrayCompras[i].status = 0;
          arrayCompras[i].importe = 0;
        }
    }
  return retorno;
}
/**
 * \brief Da de alta un nuevo cliente con los datos que el usuario ingresara en el id que se recibe del main
 * \param Compra* arrayCompra: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras
 * \param int Id: el ID que se asignara a la nueva compra y se devolvera incrementado en 1
 * \param Cliente* arrayClientes: recibe el array de clientes
 * \param int limiteCliente: recibe el limite maximo de cclientes posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_alta (Compra *arrayCompra, int limite, int *id, Cliente *arrayClientes,
          int limiteCliente)
{
  int retorno = -1;
  int indiceObtenido;
  int indiceCliente;
  Compra bufferCompra;

  if (com_buscarLugarLibre (arrayCompra, &indiceObtenido,
                            limite) && indiceObtenido <limite &&
                            limite > 0 && indiceObtenido >=0 && id != NULL)
    {

      printf ("Se va a dar de alta una nueva compra.");
      if (cli_getCliente (arrayClientes, limiteCliente, &indiceCliente) == 1
          && (utn_getNumero (&bufferCompra.cantidadBarbijos,
                             "\nIngrese la cantidad de BARBIJOS de la compra: ",
                             "\nCantidad ingresada invalida.", 1,
                             SIZE_MAX_BARBIJOS, 2)) == 1
          && !utn_getDireccion (
              bufferCompra.direccion,
              "\nIngrese el NOMBRE DE LA CALLE de su direccion(solo letras): ",
              "\nIngrese la ALTURA de la calle de su direccion(solo numeros).",
              "\n CALLE INVALIDA.", "\nALTURA INVALIDA.")
          && !utn_getText (bufferCompra.color, "\nIngrese el COLOR elegido: ",
                           "\nEso no es Color.\n", SIZE_COLOR, 2))
        {
          bufferCompra.idCliente = arrayClientes[indiceCliente].idCliente;
          bufferCompra.idCompra = *id;
          bufferCompra.status = 1;
          arrayCompra[indiceObtenido] = bufferCompra;
          retorno = 1;
          printf (
              "\nCompra creada satisfactoriamente. ID:%d STATUS:Pendiente de cobrar.\n",
              *id);
          (*id)++;
        }
      else
        {
          printf (
              "\nERROR EN LOS DATOS INGRESADOS. Volviendo al menu principal\n.");
        }

    }
  return retorno;
}
/**
 * \brief Da de baja todas las compras para un ID de cliente recibido
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \param int IdClienteRecibido: el ID de cliente del que se quieren eliminar las compras
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_bajaCliente (Compra *arrayCompras, int limite, int IdClienteRecibido)
{
  int retorno = -1;
  int i;
  for (i = 0; i < limite; i++)
    {
      if (arrayCompras[i].idCliente == IdClienteRecibido)
        {
          arrayCompras[i].status = 0;
          arrayCompras[i].importe = 0;
          retorno = 0;
        }
    }
  return retorno;
}
/**
 * \brief Pide importe y  confirmacion y cambia el status de la compra a 2(completada)
 *        y le da el importe ingresado
 * \param Compra* pCompra: recibe el puntero a la compra que se va a dar de baja
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_pagar (Compra *pCompra)
{
  int retorno = -1;
  float auxPrecio;
  char continuar;
  if (!utn_getFloat (&auxPrecio, "Ingrese el importe de la compra:",
                     "Ingreso invalido", 3))
    {
      utn_getContinue (
          &continuar,
          "\n¿Esta seguro que desea abonar y finalizar esta compra?",
          "\nERROR. respuesta invalida.", 2);
    }
  if (continuar == 'n' || continuar == 'N')
    {
      retorno = 0;
    }
  if (continuar == 'y' || continuar == 'Y')
    {
      pCompra->status = 2;
      pCompra->importe = auxPrecio;
      retorno = 1;
    }
  return retorno;
}

/**
 * \brief Pide confirmacion y cambia el status de la compra a 0(vacio)
 * \param Compra* pCompra: recibe el puntero a la compra que se va a dar de baja
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */

int
com_cancelar (Compra *pCompra)
{
  int retorno = -1;
  char continuar;
  utn_getContinue (&continuar, "\n¿Esta seguro que desea CANCELAR esta compra?",
                   "\nERROR. respuesta invalida.", 2);
  if (continuar == 'n' || continuar == 'N')
    {
      retorno = 0;
    }
  if (continuar == 'y' || continuar == 'Y')
    {
      pCompra->status = 0;
      retorno = 1;
    }
  return retorno;
}
/**
 * \brief Se pide el ID de una compra y devuelve el ID del CLIENTE que la efectuo
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \param int* idClienteObtenido: el ID del cliente que realizo la compra ingresada
 * \param int* indiceCompraObtenido: devuelve El indice correspondiente a la ID ingresada
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_getIdClienteByCompra (Compra *arrayCompras, int limite,
                          int *idClienteObtenido, int *indiceCompraObtenido)
{
  int retorno = -1;
  int bufferId = 0;
  int bufferIndice;

  if (utn_getNumero (&bufferId, "\nIngrese el ID de la compra: ",
                     "\nEso no es un ID valido.", 0, limite, 2)
      && com_buscarID (arrayCompras, limite, bufferId, &bufferIndice) == 1)
    {
      if ((com_statusIndice (&arrayCompras[bufferIndice]) == 1)
          && bufferIndice < limite && limite > 0 && bufferIndice >= 0)
        {
          *idClienteObtenido = arrayCompras[bufferIndice].idCliente;
          retorno = 1;
          *indiceCompraObtenido = bufferIndice;
          printf ("\nEsa compra pertenece al cliente ID:%d.\n",
                  arrayCompras[bufferIndice].idCliente);
        }
      else
        {
          printf (
              "\nERROR:Ese ID no corresponde a una compra pendiente de pago.\n");
        }
    }
  return retorno;
}
/**
 * \brief Busca el indice de una compra por ID
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \param int valorBuscado: el ID del que se desea hallar el indice
 * \param int* indiceRespuesta: devuelve El indice correspondiente a la ID ingresada
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_buscarID (Compra *arrayCompras, int limite, int valorBuscado,
              int *indiceRespuesta)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayCompras != NULL)
    {
      retorno = 0;
      for (i = 0; i < limite; i++)
        {
          if (arrayCompras[i].idCompra == valorBuscado)
            {
              *indiceRespuesta = i;
              retorno = 1;
              break;
            }
        }
      if (arrayCompras[i].idCompra != valorBuscado)
        {
          printf ("\nERROR:Ese ID aun no ha sido asignado a nadie.\n");
          retorno = -2;
        }
    }
  return retorno;
}
/**
 * \brief Busca un lugar en el indice libre para el alta de compras
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int indiceLibre: el indice que se encontró libre y se va a devolver
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_buscarLugarLibre (Compra *arrayCompra, int *indiceLibre, int limite)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayCompra != NULL)
    {
      for (i = 0; i < limite; i++)
        {
          if (com_statusIndice (&arrayCompra[i]) == 0)
            {
              retorno = 1;
              *indiceLibre = i;
              break;
            }
        }
      if (*indiceLibre != i)
        {
          retorno = -2;
        }
    }
  return retorno;
}
/**
 * \brief regresa como retorno el status de compra. 0 vacio, 1 pendiente y 2 completado
 * \param Compra* arrayCompra: recibe el array de compra
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_statusIndice (Compra *pCompra)
{
  int retorno = -1;

  if (pCompra != NULL)
    {
      if (pCompra->status == 1)
        {
          retorno = 1;
        }
      if (pCompra->status == 0)
        {
          retorno = 0;
        }
      if (pCompra->status == 2)
        {
          retorno = 2;
        }
    }
  return retorno;
}
/**
 * \brief Imprime todas las compras de todos los clientes
 * \param Cliente* arrayCliente: recibe el array de clientes
 * \param int limiteClientes: recibe el limite maximo de clientes posible
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limiteCompras: recibe el limite maximo de compras posible
 * \param int IdClienteIngresado: el ID que se desea imprimir
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_imprimirClientesConContrataciones (Cliente *arrayClientes,
                                       int limiteClientes, Compra *arrayCompras,
                                       int limiteCompras)
{
  int retorno = -1;
  int i;
  int auxiliarIdCliente;

  if (limiteClientes > 0 && arrayClientes != NULL)
    {
      retorno = 1;
      for (i = 0; i < limiteClientes; i++)
        {
          if (arrayClientes[i].isEmpty == 0)
            {
              cli_imprimir (&arrayClientes[i]);
              auxiliarIdCliente = arrayClientes[i].idCliente;
              com_imprimirCompras (arrayCompras, limiteCompras,
                                   auxiliarIdCliente);
              printf ("\n");
            }
        }
    }
  return retorno;
}
/**
 * \brief Imprime todas las compras del ID ingresado
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \param int IdClienteIngresado: el ID que se desea imprimir
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_imprimirCompras (Compra *arrayCompras, int limiteCompras,
                     int IdClienteIngresado)
{
  int retorno = -1;
  int i;

  if (limiteCompras > 0 && arrayCompras != NULL)
    {
      retorno = 1;
      for (i = 0; i < limiteCompras; i++)
        {
          if (arrayCompras[i].idCliente == IdClienteIngresado
              && arrayCompras[i].status != 0)
            {
              com_imprimir (&arrayCompras[i]);
            }
        }
    }
  return retorno;
}
/**
 * \brief Imprime una sola compra
 * \param Compra* pCompra: recibe un puntero a una compra
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */

int
com_imprimir (Compra *pCompra)
{
  int retorno = -1;
  if (pCompra != NULL && pCompra->status == 2)
    {
      printf (
          "[CLIENTE ID:%d](COMPRA ID:%d) Cantidad de barbijos: %d | Color de barbijos: %s | importe %.2f$ \n",
          pCompra->idCliente, pCompra->idCompra, pCompra->cantidadBarbijos,
          pCompra->color, pCompra->importe);
      retorno = 1;
    }
  else if (pCompra != NULL && pCompra->status == 1)
    {
      printf (
          "[CLIENTE ID:%d](COMPRA ID:%d) Cantidad de barbijos: %d | Color de barbijos: %s | PENDIENTE DE PAGO. \n",
          pCompra->idCliente, pCompra->idCompra, pCompra->cantidadBarbijos,
          pCompra->color);
      retorno = 2;
    }
  return retorno;
}
/**
 * \brief Imprime el array de compras completo
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_imprimirArray (Compra *arrayCompras, int limite)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayCompras != NULL)
    {
      retorno = 1;
      for (i = 0; i < limite; i++)
        {
          if (arrayCompras[i].status != 0)
            {
              com_imprimir (&arrayCompras[i]);
            }

        }
    }
  return retorno;
}
/**
 * \brief Imprime un cliente por la ID valida
 * \param Compra* arrayCompras: recibe el array de compras
 * \param int limite: recibe el limite maximo de compras posible
 * v\param int idAImprimir: recibe la ID de la compra a imprimir
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_imprimirCliente (Compra *arrayCompras, int limite, int idAImprimir)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayCompras != NULL)
    {
      retorno = 1;
      for (i = 0; i < limite; i++)
        {
          if (arrayCompras[i].idCliente == idAImprimir
              && arrayCompras[i].status != 0)
            {
              com_imprimir (&arrayCompras[i]);
            }

        }
    }
  return retorno;
}

/**
 * \brief Da de alta forzada a modelos de compra para testear el programa
 * \param recibe todos los datos necesarios para dar de alta una compra
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */

int
com_altaForzada (Compra *arrayCompra, int indice, int limite, float importe,
                 char *color, char *direccion, int cantidadBarbijos,
                 int idCliente, int status, int *id)
{
  int retorno = -1;

  if (com_statusIndice (&arrayCompra[indice]) == 0 && limite > 0
      && arrayCompra != NULL && indice >= 0)
    {

      retorno = 0;
      arrayCompra[indice].importe = importe;
      strncpy (arrayCompra[indice].color, color, SIZE_COLOR);
      strncpy (arrayCompra[indice].direccion, direccion,
               SIZE_DIRECCION_ENTREGA);
      arrayCompra[indice].cantidadBarbijos = cantidadBarbijos;
      arrayCompra[indice].idCliente = idCliente;
      arrayCompra[indice].status = status;
      arrayCompra[indice].idCompra = *id;
      (*id)++;
    }
  return retorno;
}

/**
 * \brief Imprime el cliente ingresado que coincida con el ID recibido
 * \param Cliente* arrayCliente: recibe el array de clientes
 * \param int limiteClientes: recibe el limite maximo de clientes posible
 * \param int IdClienteIngresado: el ID que se desea imprimir
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
com_imprimirClientesPorId (Cliente *arrayClientes, int limite,
                           int IdClienteIngresado)
{
  int retorno = -1;
  int i;

  if (limite > 0 && arrayClientes != NULL)
    {

      for (i = 0; i < limite; i++)
        {
          if (arrayClientes[i].idCliente == IdClienteIngresado
              && arrayClientes[i].isEmpty == 0)
            {
              cli_imprimir (&arrayClientes[i]);
              retorno = 1;
            }
        }
    }
  return retorno;
}
