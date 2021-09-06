/*
 ============================================================================
 Name        : ParcialLaboProg2.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "collections/Dictionary.h"
#include "controller.h"
#include "costosTransporte.h"

int main(void) {
  Dictionary* articulos =dict_new(0);
  Dictionary* posicionArancel= dict_new(0);
  CostosTransporte* costos=costos_new();

  char archivoCostos[]={"costos.csv"};
  char archivoArticulos[]={"articulo.csv"};
  char archivoPosArancel[]={"posicion.csv"};
  int opcion;
  int flagStatusArchivos=0; //STATUS:0 no cargado; 1 cargado igual en memoria y archivo; 2 con modificaciones para guardar.

  printf("\n\tBienvenido al programa de administracion de nomina de empleados.\n");
  do{
      utn_getNumero(&opcion,"\n   MENU:\n"
                      "1. Cargar los datos de Articulos Y Posiciones Arancelarias desde el archivo de texto.\n"
                      "2. Alta de Articulo nuevo.\n"
                      "3. Modificar Articulo existente.\n"
                      "4. Baja de Articulo.\n"
                      "5. Menu de informes de Articulos.\n"
                      "6. Alta posicion Arancelaria nueva.\n"
                      "7. Modificar Posicion Arancelaria existente.\n"
                      "8. Baja Posicion Arancelaria.\n"
                      "9. Mostrar una Posicion Arancelaria.\n"
                      "10. Mostrar lista de Posiciones Arancelarias.\n"
                      "11. Modificar los valores de los costos de transporte.\n"
                      "12. Guardar datos de Articulos y Posiciones Arancelarias en Archivo de texto.\n"
                      "13. Salir.\n"
                      "\nElija una opcion:"
                      ,"Opcion invalida.\n",1,13,3);

                      switch(opcion){
                      case 1:
                          if(flagStatusArchivos==0 &&
                              (controller_loadArtFromText(archivoArticulos,articulos) == 0 &&
                              controller_loadPosArancelFromText(archivoPosArancel,posicionArancel)==0)&&
                              controller_loadCostosFromText(archivoCostos,costos)==0)
                            {
                              flagStatusArchivos=1;
                            }
                          break;
                      case 2:
                        if(flagStatusArchivos!=0 && controller_altaArticulo(articulos) == 1)
                            {
                            flagStatusArchivos=2;
                            }
                          break;
                      case 3:
                        if(flagStatusArchivos!=0 && controller_editArticulo(articulos) == 0)
                            {
                            flagStatusArchivos=2;
                            }
                          break;
                      case 4:
                        if(flagStatusArchivos!=0 && controller_removeArticulo(articulos) == 0)
                          {
                            flagStatusArchivos=2;
                          }
                          break;
                      case 5:
                        if(flagStatusArchivos!=0)
                          {
                          controller_informesArticulos(articulos,posicionArancel,costos);
                          }
                          break;
                      case 6:
                        if(flagStatusArchivos!=0 &&
                        controller_altaPosArancel(posicionArancel)==1){
                            flagStatusArchivos=2;
                        }
                          break;
                      case 7:
                        if(flagStatusArchivos!=0 &&
                          controller_editPosArancel(posicionArancel)==0){
                            flagStatusArchivos=2;
                        }
                          break;
                      case 8:
                        if(flagStatusArchivos!=0 &&
                            controller_removePosArancel(posicionArancel)==0){
                            flagStatusArchivos=2;
                        }
                          break;
                      case 9:
                        if(flagStatusArchivos!=0)
                          {
                            controller_printPosArancel(posicionArancel);
                          }
                          break;
                      case 10:
                        if(flagStatusArchivos!=0)
                          {
                            controller_ListPosArancel(posicionArancel);
                          }
                          break;
                      case 11:
                        controller_editCostos(archivoCostos,costos);
                          break;
                      case 12:
                        if(flagStatusArchivos ==2){
                            controller_saveArticuloAsText(archivoArticulos,articulos);
                            controller_savePosArancelAsText(archivoPosArancel,posicionArancel);
                            flagStatusArchivos=1;
                        }else{
                            printf("No hay cambios para guardar.\n");
                        }
                          break;
                      case 13:
                        controller_close(articulos,posicionArancel);
                          break;
                      }
  }while(opcion != 13);
  return 0;
}

