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




/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int cli_init(Cliente* arrayCliente,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayCliente != NULL)
    {
        retorno = 1;
        for(i=0;i<limite;i++)
        {
            strncpy(arrayCliente[i].nombre, "", sizeof(arrayCliente[i].nombre));
            strncpy(arrayCliente[i].apellido, "", sizeof(arrayCliente[i].apellido));
            strncpy(arrayCliente[i].cuit, "", sizeof(arrayCliente[i].cuit));
            arrayCliente[i].isEmpty=1;
        }
    }
    return retorno;
}

int cli_alta(Cliente* arrayCliente,int limite, int* id)
{
    int retorno = -1;
    int indiceObtenido;
    Cliente bufferCliente;
    if(cli_buscarLugarLibre(arrayCliente,&indiceObtenido,limite) && indiceObtenido <limite &&
        limite > 0 && indiceObtenido >=0 && id != NULL)
    {
            printf("Se va a dar de alta un nuevo cliente.");
            if(!utn_getNombre(bufferCliente.nombre,"\nIngrese el NOMBRE del nuevo cliente: ",
                              "\nEso no es un nombre.",SIZE_NOMBRE,2) &&
               !utn_getNombre(bufferCliente.apellido,"\nIngrese el APELLIDO del nuevo cliente: ",
                              "\nEso no es un apellido.",SIZE_NOMBRE,2)&&
               !utn_getCuit(bufferCliente.cuit,"\nIngrese el CUIT del nuevo cliente(sin guiones): ",
                            "\nEso no es CUIT.\n",SIZE_CUIT,2))
                        {
                            bufferCliente.idCliente = *id;
                            bufferCliente.isEmpty = 0;
                            arrayCliente[indiceObtenido] = bufferCliente;
                            retorno = 1;
                            printf("\nCliente dado de alta satisfactoriamente. ID:%d\n",*id);
                            (*id)++;

                        }
    }
    return retorno;
}

int cli_baja(Cliente* arrayClientes,int limite, int indiceRecibido)
{
    int retorno = -1;
    char continuar;
        if(utn_getContinue(&continuar, "\n¿Esta seguro que desea ELIMINAR a este cliente y todas sus compras?\n",
                               "\nOpcion de confirmacion ingresada invalida.\n", 5)==0 )
            {
            retorno = 0;
            arrayClientes[indiceRecibido].isEmpty = 1;
            printf("Se elimino correctamente el cliente ID:%d.\n",arrayClientes[indiceRecibido].idCliente);
            }
        else
          {
            printf("No se elimino ni modifico nada.\n");
          }
    return retorno;
}

int cli_modificacion(Cliente* arrayClientes,int limite)
{
    int retorno = -1;
    Cliente bufferCliente;
    int indiceObtenido=0;
    char continuar='n';
    int option;
    printf("Se van a modificar datos de un cliente existente.");
    if(cli_getCliente(arrayClientes,limite,&indiceObtenido)==1)
        {
          bufferCliente.idCliente =arrayClientes[indiceObtenido].idCliente;
          bufferCliente.isEmpty = 0;
          do
            {
              if(utn_getNumero(&option,"\n1.Ingrese la opcion acorde a lo que desea modificar:"
                                       "\n1.Modificar NOMBRE."
                                       "\n2.Modificar APELLIDO."
                                       "\n3.Modificar CUIT."
                                       "\n4.Salir.",
                                       "\nOpcion ingresada invalida.\n",1,4,1))
              switch(option)
              {
                case 1:
                  if(!utn_getNombre(bufferCliente.nombre,"\nIngrese el NOMBRE del nuevo cliente: ",
                                    "\nEso no es un nombre.",SIZE_NOMBRE,2))
                      {
                      printf("\nSe modificó satisfactoriamente el nombre.");
                      strncpy(arrayClientes[indiceObtenido].nombre,bufferCliente.nombre,SIZE_NOMBRE);
                      }
                    break;
                case 2:
                  if(!utn_getNombre(bufferCliente.apellido,"\nIngrese el APELLIDO del nuevo cliente: ",
                                    "\nEso no es un apellido.",SIZE_NOMBRE,2))
                    {
                      printf("\nSe modificó satisfactoriamente el Apellido.");
                      strncpy(arrayClientes[indiceObtenido].apellido,bufferCliente.apellido,SIZE_NOMBRE);
                    }
                    break;
                case 3:
                   if(!utn_getCuit(bufferCliente.cuit,"\nIngrese el CUIT del nuevo cliente(sin guiones): ",
                                   "\nEso no es CUIT.\n",SIZE_CUIT,2))
                     {
                       printf("\nSe modificó satisfactoriamente el CUIT.");
                       strncpy(arrayClientes[indiceObtenido].cuit,bufferCliente.cuit,SIZE_CUIT);
                     }
                    break;
                case 4:
                  continuar = 'N';
                    break;
              }
              utn_getContinue(&continuar,"\n¿Desea modificar otro valor del mismo cliente?",
                              "\nERROR. respuesta invalida.",2);
            }
          while(continuar=='y'|| continuar=='Y');
          retorno = 1;
        }

    return retorno;
}
int cli_getCliente(Cliente* arrayClientes,int limite,int* indiceObtenido)
{
  int retorno = -1;
  int bufferId=0;
  int bufferIndice;

  if(utn_getNumero(&bufferId,"\nIngrese el ID del cliente: ",
                           "\nEso no es un ID valido.",0,limite,2) &&
              cli_buscarID(arrayClientes,limite,bufferId,&bufferIndice) ==1)
            {
            if((cli_isEmptyIndice(&arrayClientes[bufferIndice]) == 0) &&
                bufferIndice <limite && limite > 0 && bufferIndice >=0)
               {
                *indiceObtenido = bufferIndice;
                retorno =1;
               }
            else
              {
                printf("\nERROR:Ese ID no existe.\n");
              }
            }
  return retorno;
}

int cli_getClienteYId(Cliente* arrayClientes,int limite,int* indiceObtenido, int*idBuscado)
{
  int retorno = -1;
  int bufferId=0;
  int bufferIndice;

  if(utn_getNumero(&bufferId,"\nIngrese el ID del cliente: ",
                           "\nEso no es un ID valido.",0,limite,2) &&
              cli_buscarID(arrayClientes,limite,bufferId,&bufferIndice) ==1)
            {
            if((cli_isEmptyIndice(&arrayClientes[bufferIndice]) == 0) &&
                bufferIndice <limite && limite > 0 && bufferIndice >=0)
               {
                *indiceObtenido = bufferIndice;
                retorno =1;
                *idBuscado=bufferId;
               }
            else
              {
                printf("\nERROR:Ese ID no existe.\n");
              }
            }
  return retorno;
}

int cli_imprimir(Cliente* pCliente)
{
  int retorno = -1;
  if(pCliente != NULL && !pCliente->isEmpty)
    {
  printf("[CLIENTE ID:%d] Nombre: %s %s. CUIT: %s \n",pCliente->idCliente, pCliente->nombre, pCliente->apellido,pCliente->cuit);
    retorno=1;
    }
  return retorno;
}

int cli_imprimirArray(Cliente* arrayClientes,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = 1;
        for(i=0;i<limite;i++)
        {
            cli_imprimir(&arrayClientes[i]);

        }
    }
    return retorno;
}

int cli_buscarLugarLibre(Cliente* arrayClientes,int* indiceLibre,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(cli_isEmptyIndice(&arrayClientes[i]))
            {
                retorno = 1;
                *indiceLibre = i;
                break;
            }
        }
        if(*indiceLibre != i)
          {
            retorno =-2;
          }
    }
    return retorno;
}

int cli_isEmptyIndice(Cliente* pCliente)
{
  int retorno = -1;

  if(pCliente != NULL)
  {
            if(pCliente->isEmpty ==1)
            {
                retorno=1;
            }
            if(pCliente->isEmpty ==0)
              {
                  retorno=0;
              }
    }
    return retorno;
}

int cli_buscarID(Cliente* arrayClientes,int limite, int valorBuscado, int* indiceRespuesta)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayClientes != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(arrayClientes[i].idCliente == valorBuscado)
              {
                *indiceRespuesta =i;
                retorno = 1;
                break;
              }
        }
        if (arrayClientes[i].idCliente != valorBuscado)
        {
            printf("\nERROR:Ese ID aun no ha sido asignado a nadie.\n");
            retorno = -2;
        }
    }
    return retorno;
}

int cli_altaForzada(Cliente* pCliente,int limite,char* nombre,char* apellido, char* cuit, int indice,int* id)
{
    int retorno = -1;

    if(cli_isEmptyIndice(&pCliente[indice])== 1&& limite > 0 && pCliente != NULL &&indice >= 0)
    {

            retorno = 0;
            strncpy(pCliente[indice].nombre,nombre,SIZE_NOMBRE);
            strncpy(pCliente[indice].apellido,apellido,SIZE_NOMBRE);
            strncpy(pCliente[indice].cuit,cuit,SIZE_TIPO);
            pCliente[indice].isEmpty = 0;
            pCliente[indice].idCliente = *id;
            (*id)++;
    }
    return retorno;
}

