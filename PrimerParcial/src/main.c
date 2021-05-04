/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : Julio Mendez
 Enunciado   :



 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio_ext.h>
#include "arr.h"
#include "utn.h"
#include "cliente.h"
#include "compra.h"
#include "informes.h"
#define SIZE_ARRAY_CLIENTES 100
#define SIZE_ARRAY_COMPRAS 200

int main(void) {
  Cliente arrayClientes[SIZE_ARRAY_CLIENTES];
      int idCliente=1;
      int auxiliarIdCliente;
  Compra arrayCompras[SIZE_ARRAY_COMPRAS];
      int auxiliarIndiceCompra;
      int idCompra=1;
      int auxiliarIndice=0;
      int menu=0;
      int subMenu=0;

      if(cli_init(arrayClientes,SIZE_ARRAY_CLIENTES))
        {
          printf("Array de Clientes inicializado correctamente.\n");
        }
      if(com_init(arrayCompras,SIZE_ARRAY_COMPRAS))
        {
          printf("Array de Compras inicializado correctamente.\n\n");
        }
      cli_altaForzada(arrayClientes,SIZE_ARRAY_CLIENTES,"Jorge","Campos","45329876542",0,&idCliente);
      cli_altaForzada(arrayClientes,SIZE_ARRAY_CLIENTES,"Franco","Armani","66326549875",1,&idCliente);
      cli_altaForzada(arrayClientes,SIZE_ARRAY_CLIENTES,"Amadeo","Carrizo","54786543217",2,&idCliente);
      cli_altaForzada(arrayClientes,SIZE_ARRAY_CLIENTES,"German","Lux","18253691471",3,&idCliente);
      cli_altaForzada(arrayClientes,SIZE_ARRAY_CLIENTES,"Beto","Bologna","95327983214",4,&idCliente);

      com_altaForzada(arrayCompras,0,SIZE_ARRAY_COMPRAS,34545, "blanco", "Uruguay 158",  545,1,2,&idCompra);
      com_altaForzada(arrayCompras,1,SIZE_ARRAY_COMPRAS,43545, "rojo", "Brasil 1236",  121,2,2,&idCompra);
      com_altaForzada(arrayCompras,2,SIZE_ARRAY_COMPRAS,9789, "negro", "Balcarce 534",  760,3,2,&idCompra);
      com_altaForzada(arrayCompras,3,SIZE_ARRAY_COMPRAS,12345, "azul", "Ayacucho 534",  600,4,1,&idCompra);
      com_altaForzada(arrayCompras,4,SIZE_ARRAY_COMPRAS,6456, "rojo", "Goenaga 654",  500,5,2,&idCompra);
      com_altaForzada(arrayCompras,5,SIZE_ARRAY_COMPRAS,43545, "amarillo", "Brasil 1236",  360,2,1,&idCompra);

      printf("*~SISTEMA DE ADMINISTRACION DE VENTA DE BARBIJOS~*\n");
      do
          {
           printf("\nIngrese el numero de la opcion deseada:\n");
              if(utn_getNumero(&menu,"1.Dar de ALTA un cliente nuevo."
                               "\n2.MODIFICAR datos de un cliente existente."
                               "\n3.Dar de BAJA un cliente."
                               "\n4.Realizar orden de COMPRA."
                               "\n5.PAGAR compra."
                               "\n6.CANCELAR compra."
                               "\n7.IMPRIMIR clientes."
                               "\n8.INFORMES."
                               "\n9.Salir.\n","\nERROR-Opcion ingresada invalida.\n",1,12,1))
                  switch(menu)
                  {
                  case 1:
                    if(cli_alta(arrayClientes,SIZE_ARRAY_CLIENTES, &idCliente))
                      {}
                      break;
                  case 2:
                    if(cli_modificacion(arrayClientes, SIZE_ARRAY_CLIENTES))
                      {}
                      break;
                  case 3:
                    printf("Se van a ELIMINAR los datos de un cliente existente.");
                    if(cli_getClienteYId(arrayClientes, SIZE_ARRAY_CLIENTES,&auxiliarIndice,&auxiliarIdCliente)==1)
                      {
                        com_imprimirCliente(arrayCompras,SIZE_ARRAY_CLIENTES,auxiliarIdCliente);
                        cli_baja(arrayClientes,SIZE_ARRAY_CLIENTES,auxiliarIndice);
                        com_bajaCliente(arrayCompras,SIZE_ARRAY_COMPRAS,auxiliarIdCliente);
                      }
                      break;
                  case 4:
                      if(com_alta(arrayCompras,SIZE_ARRAY_COMPRAS,&idCompra,arrayClientes, SIZE_ARRAY_CLIENTES))
                        {}
                      break;
                  case 5:
                    printf("Se van a PAGAR una compra pendiente de cobro.");
                      if(com_getIdClienteByCompra(arrayCompras,SIZE_ARRAY_COMPRAS,&auxiliarIdCliente,&auxiliarIndiceCompra)==1)
                        {
                          cli_buscarID(arrayClientes,SIZE_ARRAY_CLIENTES,auxiliarIdCliente,&auxiliarIndice);
                          cli_imprimir(&arrayClientes[auxiliarIndice]);
                          com_pagar(&arrayCompras[auxiliarIndiceCompra]);
                        }
                      break;
                  case 6:
                    printf("Se van a CANCELAR una compra pendiente de cobro.");
                      if(com_getIdClienteByCompra(arrayCompras,SIZE_ARRAY_COMPRAS,&auxiliarIdCliente,&auxiliarIndiceCompra)==1)
                        {
                          cli_buscarID(arrayClientes,SIZE_ARRAY_CLIENTES,auxiliarIdCliente,&auxiliarIndice);
                          cli_imprimir(&arrayClientes[auxiliarIndice]);
                          com_cancelar(&arrayCompras[auxiliarIndiceCompra]);
                        }
                      break;
                  case 7:
                      if(com_imprimirClientesConContrataciones(arrayClientes,SIZE_ARRAY_CLIENTES,arrayCompras,SIZE_ARRAY_COMPRAS))
                        {}
                      break;
                  case 8:
                    do
                        {
                         printf("\nIngrese el numero de la opcion deseada:\n");
                            if(utn_getNumero(&subMenu,"1.Informar COLOR de barbijo que mas se compro."
                                             "\n2.Informar cantidad de compras PENDIENTES."
                                             "\n3.Informar compra con PRECIO POR UNIDAD mas bajo."
                                             "\n4.Salir.\n","\nERROR-Opcion ingresada invalida.\n",1,12,1))
                              {
                                switch(subMenu)
                                {
                                case 1:
                                  inf_barbijoMasComprado(arrayCompras,SIZE_ARRAY_COMPRAS);
                                    break;
                                case 2:
                                  inf_contadorComprasPendientes(arrayCompras,SIZE_ARRAY_COMPRAS);
                                    break;
                                case 3:
                                  inf_menorPrecioUnitario(arrayCompras,SIZE_ARRAY_COMPRAS);
                                  break;
                                case 4:
                                  printf("\nRegresando al menu principal.\n");
                                  break;
                                 }
                              }
                        }while(subMenu != 4);
                      break;
                  case 9:
                       printf("¡Adios!");
                      break;
                }

          }while(menu != 9);

          return 0;

	return EXIT_SUCCESS;
}


