/*
 * cliente.c
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

/**
 * \brief Inicializa el array de Cliente con el isEmpty 1 (vacio)
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_init (Cliente *arrayClientes, int limite)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayClientes != NULL)
    {
      retorno = 1;
      for (i = 0; i < limite; i++)
        {
          strncpy (arrayClientes[i].nombre, "",
                   sizeof(arrayClientes[i].nombre));
          strncpy (arrayClientes[i].apellido, "",
                   sizeof(arrayClientes[i].apellido));
          strncpy (arrayClientes[i].cuit, "", sizeof(arrayClientes[i].cuit));
          arrayClientes[i].isEmpty = 1;
        }
    }
  return retorno;
}
/**
 * \brief Se da de alta un nuevo cliente con los datos que ingresa el usuario y el ID recibido del main
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \param int* id: recibe el id, se lo asigna al nuevo cliente y lo devuelve incrementado en 1
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_alta (Cliente *arrayClientes, int limite, int *id)
{
  int retorno = -1;
  int indiceObtenido;
  Cliente bufferCliente;
  if (limite > 0 && arrayClientes != NULL)
    {
      if (cli_buscarLugarLibre (arrayClientes, &indiceObtenido,
                                limite) && indiceObtenido <limite &&
                                limite > 0 && indiceObtenido >=0 && id != NULL)
        {
          printf ("Se va a dar de alta un nuevo cliente.");
          if (!utn_getNombre (bufferCliente.nombre,
                              "\nIngrese el NOMBRE del nuevo cliente: ",
                              "\nEso no es un nombre.", SIZE_NOMBRE, 2)
              && !utn_getNombre (bufferCliente.apellido,
                                 "\nIngrese el APELLIDO del nuevo cliente: ",
                                 "\nEso no es un apellido.", SIZE_NOMBRE, 2)
              && !utn_getCuit (
                  bufferCliente.cuit,
                  "\nIngrese el CUIT del nuevo cliente(sin guiones): ",
                  "\nEso no es CUIT.\n", SIZE_CUIT, 2))
            {
              bufferCliente.idCliente = *id;
              bufferCliente.isEmpty = 0;
              arrayClientes[indiceObtenido] = bufferCliente;
              retorno = 1;
              printf ("\nCliente dado de alta satisfactoriamente. ID:%d\n",
                      *id);
              (*id)++;

            }
        }
    }
  return retorno;
}
/**
 * \brief Pide confirmacion al usuario y da de baja al cliente en el indice recibido
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \param int indiceRecibido: recibe el indice,donde se encuentra el cliente a borrar
 * \return Retorna 1 (EXITO) si se pudo completar, 0 si no se modifico nada o -1 (ERROR) si no
 */
int
cli_baja (Cliente *arrayClientes, int limite, int indiceRecibido)
{
  int retorno = -1;
  char continuar;
  if (limite > 0 && arrayClientes != NULL)
    {
      utn_getContinue (
          &continuar,
          "\n¿Esta seguro que desea ELIMINAR a este cliente y todas sus compras?\n",
          "\nOpcion de confirmacion ingresada invalida.\n", 5);
      if (continuar == 'y' || continuar == 'Y')
        {
          retorno = 1;
          arrayClientes[indiceRecibido].isEmpty = 1;
          printf ("Se elimino correctamente el cliente ID:%d.\n",
                  arrayClientes[indiceRecibido].idCliente);
        }
      else if (continuar == 'n' || continuar == 'N')
        {
          printf ("No se elimino ni modifico nada.\n");
          retorno = 0;
        }
    }
  return retorno;
}
/**
 * \brief Pide al usuario un ID de cliente y le permite modificar los datos del mismo
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_modificacion (Cliente *arrayClientes, int limite)
{
  int retorno = -1;
  Cliente bufferCliente;
  int indiceObtenido = 0;
  char continuar = 'n';
  int option;
  if (limite > 0 && arrayClientes != NULL)
    {
      printf ("Se van a modificar datos de un cliente existente.");
      if (cli_getCliente (arrayClientes, limite, &indiceObtenido) == 1)
        {
          bufferCliente.idCliente = arrayClientes[indiceObtenido].idCliente;
          bufferCliente.isEmpty = 0;
          do
            {
              if (utn_getNumero (
                  &option,
                  "\n1.Ingrese la opcion acorde a lo que desea modificar:"
                  "\n1.Modificar NOMBRE."
                  "\n2.Modificar APELLIDO."
                  "\n3.Modificar CUIT."
                  "\n4.Salir.",
                  "\nOpcion ingresada invalida.\n", 1, 4, 1))
                switch (option)
                  {
                  case 1:
                    if (!utn_getNombre (
                        bufferCliente.nombre,
                        "\nIngrese el NOMBRE del nuevo cliente: ",
                        "\nEso no es un nombre.", SIZE_NOMBRE, 2))
                      {
                        printf ("\nSe modificó satisfactoriamente el nombre.");
                        strncpy (arrayClientes[indiceObtenido].nombre,
                                 bufferCliente.nombre, SIZE_NOMBRE);
                      }
                    break;
                  case 2:
                    if (!utn_getNombre (
                        bufferCliente.apellido,
                        "\nIngrese el APELLIDO del nuevo cliente: ",
                        "\nEso no es un apellido.", SIZE_NOMBRE, 2))
                      {
                        printf (
                            "\nSe modificó satisfactoriamente el Apellido.");
                        strncpy (arrayClientes[indiceObtenido].apellido,
                                 bufferCliente.apellido, SIZE_NOMBRE);
                      }
                    break;
                  case 3:
                    if (!utn_getCuit (
                        bufferCliente.cuit,
                        "\nIngrese el CUIT del nuevo cliente(sin guiones): ",
                        "\nEso no es CUIT.\n", SIZE_CUIT, 2))
                      {
                        printf ("\nSe modificó satisfactoriamente el CUIT.");
                        strncpy (arrayClientes[indiceObtenido].cuit,
                                 bufferCliente.cuit, SIZE_CUIT);
                      }
                    break;
                  case 4:
                    continuar = 'N';
                    break;
                  }
              utn_getContinue (
                  &continuar,
                  "\n¿Desea modificar otro valor del mismo cliente?",
                  "\nERROR. respuesta invalida.", 2);
            }
          while (continuar == 'y' || continuar == 'Y');
          retorno = 1;
        }
    }
  return retorno;
}
/**
 * \brief Pide al usuario un ID de cliente y busca y devuelve el indice para dicho ID
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \param int* indiceOtenido: puntero donde devuelve el indice perteneciente al ID buscado
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_getCliente (Cliente *arrayClientes, int limite, int *indiceObtenido)
{
  int retorno = -1;
  int bufferId = 0;
  int bufferIndice;
  if (limite > 0 && arrayClientes != NULL)
    {
      if (utn_getNumero (&bufferId, "\nIngrese el ID del cliente: ",
                         "\nEso no es un ID valido.", 0, limite, 2)
          && cli_buscarID (arrayClientes, limite, bufferId, &bufferIndice) == 1)
        {
          if ((cli_isEmptyIndice (&arrayClientes[bufferIndice]) == 0)
              && bufferIndice < limite && limite > 0 && bufferIndice >= 0)
            {
              *indiceObtenido = bufferIndice;
              retorno = 1;
            }
          else
            {
              printf ("\nERROR:Ese ID no existe.\n");
            }
        }
    }
  return retorno;
}
/**
 * \brief Pide al usuario un ID de cliente y busca y devuelve el indice y el ID
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \param int* indiceOtenido: puntero donde devuelve el indice perteneciente al ID buscado
 * \param int* IdBuscado: puntero donde devuelve el ID ingresado
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_getClienteYId (Cliente *arrayClientes, int limite, int *indiceObtenido,
                   int *idBuscado)
{
  int retorno = -1;
  int bufferId = 0;
  int bufferIndice;
  if (limite > 0 && arrayClientes != NULL)
    {
      if (utn_getNumero (&bufferId, "\nIngrese el ID del cliente: ",
                         "\nEso no es un ID valido.", 0, limite, 2)
          && cli_buscarID (arrayClientes, limite, bufferId, &bufferIndice) == 1)
        {
          if ((cli_isEmptyIndice (&arrayClientes[bufferIndice]) == 0)
              && bufferIndice < limite && limite > 0 && bufferIndice >= 0)
            {
              *indiceObtenido = bufferIndice;
              retorno = 1;
              *idBuscado = bufferId;
            }
          else
            {
              printf ("\nERROR:Ese ID no existe.\n");
            }
        }
    }
  return retorno;
}
/**
 * \brief Imprime todos los datos del cliente para el puntero recibido
 * \param Cliente* pCliente: Puntero indizado del cliente que se desea imprimir
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_imprimir (Cliente *pCliente)
{
  int retorno = -1;
  if (pCliente != NULL && !pCliente->isEmpty)
    {
      printf ("[CLIENTE ID:%d] Nombre: %s %s. CUIT: %s \n", pCliente->idCliente,
              pCliente->nombre, pCliente->apellido, pCliente->cuit);
      retorno = 1;
    }
  return retorno;
}
/**
 * \brief Imprime todos los datos de todos los clientes del array
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_imprimirArray (Cliente *arrayClientes, int limite)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayClientes != NULL)
    {
      retorno = 1;
      for (i = 0; i < limite; i++)
        {
          cli_imprimir (&arrayClientes[i]);

        }
    }
  return retorno;
}
/**
 * \brief Recorre el array de clientes buscando un indice libre y lo devuelve como parametro
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int* indiceLibre: puntero donde devuelve el indice libre hallado
 * \param int limite: recibe el limite maximo de Clientes
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_buscarLugarLibre (Cliente *arrayClientes, int *indiceLibre, int limite)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayClientes != NULL)
    {
      for (i = 0; i < limite; i++)
        {
          if (cli_isEmptyIndice (&arrayClientes[i]))
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
 * \brief recibe un puntero de cliente,verifica su estado y lo devuelve por return
 * \param Cliente pCliente: Puntero indizado del cliente que se desea verificar
 * \return Retorna 1 (EMPTY) si el indice está vacio o 0 (EN USO) si está ocupado
 */
int
cli_isEmptyIndice (Cliente *pCliente)
{
  int retorno = -1;

  if (pCliente != NULL)
    {
      if (pCliente->isEmpty == 1)
        {
          retorno = 1;
        }
      if (pCliente->isEmpty == 0)
        {
          retorno = 0;
        }
    }
  return retorno;
}
/**
 * \brief Busca el indice de el ID ingresado y lo devuelve como parametro
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \param int valorBuscado: el ID del que se debe hallar el indice
 * \param int* indiceRespuesta: indice hallado donde se encuentra el ID buscado
 * \return Retorna 1 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_buscarID (Cliente *arrayClientes, int limite, int valorBuscado,
              int *indiceRespuesta)
{
  int retorno = -1;
  int i;
  if (limite > 0 && arrayClientes != NULL)
    {
      retorno = 0;
      for (i = 0; i < limite; i++)
        {
          if (arrayClientes[i].idCliente == valorBuscado)
            {
              *indiceRespuesta = i;
              retorno = 1;
              break;
            }
        }
      if (arrayClientes[i].idCliente != valorBuscado)
        {
          printf ("\nERROR:Ese ID aun no ha sido asignado a nadie.\n");
          retorno = -2;
        }
    }
  return retorno;
}
/**
 * \brief Se fuerza el alta un nuevo cliente con los datos hardcodeados en el main
 * \param Cliente* arrayClientes: recibe el array de Clientes
 * \param int limite: recibe el limite maximo de Clientes
 * \param todos los parametros necesarios para llenar la estructura.
 * \return Retorna 0 (EXITO) si se pudo completar o -1 (ERROR) si no
 */
int
cli_altaForzada (Cliente *pCliente, int limite, char *nombre, char *apellido,
                 char *cuit, int indice, int *id)
{
  int retorno = -1;

  if (cli_isEmptyIndice (&pCliente[indice]) == 1 && limite > 0
      && pCliente != NULL && indice >= 0)
    {

      retorno = 0;
      strncpy (pCliente[indice].nombre, nombre, SIZE_NOMBRE);
      strncpy (pCliente[indice].apellido, apellido, SIZE_NOMBRE);
      strncpy (pCliente[indice].cuit, cuit, SIZE_TIPO);
      pCliente[indice].isEmpty = 0;
      pCliente[indice].idCliente = *id;
      (*id)++;
    }
  return retorno;
}

