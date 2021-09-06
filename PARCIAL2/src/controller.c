/*
 * controller.c
 *
 *  Created on: 22 jun. 2021
 *      Author: julio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "collections/LinkedList.h"
#include "PosicionArancelaria.h"
#include "utn.h"



static int contador=0; // NO ES LOCAL DE LA FUNCION

void articulo_setearValorInicialDeId(int id)
{
  contador = id;
}

int articulo_generarId(void)
{
  contador++;
  return contador;
}

int controller_loadArtFromText(char* path, Dictionary* articulos)
{
    int retorno=-1;

    if(path == NULL || articulos == NULL)
    {
        retorno=-1;
        printf("\nError al cargar los datos del archivo del registro de Articulos.\n");
   /* }else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
        printf("\nYa cargo los datos del archivo anteriormente.\n"); */
    }else{
        articulo_parser(path,articulos,&contador);

        printf("\nDatos del archivo del registro de Articulos cargados correctamente.\n");
        retorno=0;

    }

    return retorno;
}
int controller_altaArticulo(Dictionary* articulos)
{
  int ret=-1;
  char codigoArticulo[LONG_STRING];
  char descripcion[LONG_STRING];
  char pais[SIZE_COUNTRY];
  float valorFob;
  float peso;
  float ancho;
  float altura;
  float profundidad;
  char posicionArancelaria[LONG_STRING];
  int idArticulo;
  Articulo* pA;

  if(articulos!=NULL)
    {
    printf("\nSe va a dar de alta un nuevo articulo.\n");
    if(utn_getStringWithNumbers("\nIngrese el CODIGO del articulo:","ERROR! Codigo invalido.",codigoArticulo,LONG_STRING,3)==0 &&
        dict_get(articulos, codigoArticulo)==NULL)
      {
    if(utn_getText(descripcion,"\nIngrese La descripción del producto:","ERROR! Descripcion invalida.",255,3)==0 &&
       utn_getNombre(pais,"\nIngrese el País de origen:","ERROR! País invalida.",SIZE_COUNTRY,3)==0 &&
      utn_getFloat(&valorFob, "\nIngrese el VALOR FOB del articulo:", "ERROR! Valor invalido.",0.1,9999999, 3)==0 &&
      utn_getFloat(&peso, "\nIngrese el PESO del articulo:", "ERROR! Valor invalido.",0.1,9999999, 3)==0 &&
      utn_getFloat(&ancho, "\nIngrese el ANCHO del articulo en centimetros:", "ERROR! Medida invalida.",0.1,235, 3)==0 &&
      utn_getFloat(&altura, "\nIngrese el ALTO del articulo en centimetros:", "ERROR! Medida invalida.",0.1,239, 3)==0 &&
      utn_getFloat(&profundidad, "\nIngrese el LARGO del articulo en centimetros:", "ERROR! Medida invalida.",0.1,1219, 3)==0 &&
      utn_getStringWithNumbers("\nIngrese la POSICION ARANCELARIA del articulo:","ERROR! Codigo invalido.",posicionArancelaria,LONG_STRING,3)==0)
       {//235 ancho alto 239 1219
        idArticulo=articulo_generarId();
        pA=articulo_newParam(codigoArticulo,descripcion,pais,valorFob,peso,ancho,altura,profundidad,posicionArancelaria,idArticulo);
        if(pA!=NULL)
        {
          dict_insert(articulos, codigoArticulo, pA);
          ret=1;
          printf("\nSe dio de alta correctamente el articulo.\n");
        }
        else
        {
          articulo_delete(pA);
          ret =0;
          printf("\n NO se dio de alta el articulo.\n");
        }
      }
      }
    else
    {
      printf("\n ERROR. Ya existe un articulo con ese codigo.\n");
    }
    }
  else
  {
    printf("\n ERROR en el acceso a la lista de articulos.\n");
  }
  return ret;
}

int controller_editArticulo(Dictionary* articulos)
{
    char respuesta;
    int opcion;
     int retorno=-1;
    Articulo* pArticulo;
    char codigoArticulo[LONG_STRING];
    char descripcion[LONG_STRING];
    char pais[SIZE_COUNTRY];
    float valorFob;
    float peso;
    float ancho;
    float altura;
    float profundidad;
    char posicionArancelaria[LONG_STRING];
    char codigoArticuloNuevo[LONG_STRING];
    char descripcionNuevo[LONG_STRING];
    char paisNuevo[SIZE_COUNTRY];
    float valorFobNuevo;
    float pesoNuevo;
    float anchoNuevo;
    float alturaNuevo;
    float profundidadNuevo;
    char posicionArancelariaNuevo[LONG_STRING];

    if(articulos != NULL &&
        utn_getStringWithNumbers("Ingrese CODIGO del articulo a modificar:",
                                 "Valor incorrecto.\n",codigoArticulo,LONG_STRING,2)==0)
    {
            pArticulo =(Articulo*) dict_get(articulos,codigoArticulo);
            if(pArticulo!=NULL)
              {
                printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                       "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                       "PosicionArancelaria");
            articulo_print(pArticulo);
            if(utn_getContinue(&respuesta,"Desea modificar este articulo?(y/n)","Incorrecto.\n",2)== 0 && (respuesta == 'y' || respuesta=='Y'))
            {
                articulo_getCodigoArticulo(pArticulo,codigoArticulo);
                articulo_getDescripcion(pArticulo,descripcion);
                articulo_getPais(pArticulo,pais);
                articulo_getValorFob(pArticulo,&valorFob);
                articulo_getPeso(pArticulo,&peso);
                articulo_getAncho(pArticulo,&ancho);
                articulo_getAltura(pArticulo,&altura);
                articulo_getProfundidad(pArticulo,&profundidad);
                articulo_getPosicionArancelaria(pArticulo,posicionArancelaria);
                do
                {
                    if(utn_getNumero(&opcion,"\nElija el campo a modificar:\n1.Codigo del articulo.\n2.Descripcion del articulo."
                        "\n3.Pais de origen.\n4.Valor FOB.\n5.Peso.\n6.Ancho.\n7.Altura.\n8.Profundidad.\n9.Posicion Arancelaria."
                        "\n10.Salir.\nElija una opcion:","Opcion incorrecta.\n",1,10,3)==1)
                    {
                        switch(opcion)
                        {
                        case 1:
                            if(utn_getStringWithNumbers("\nIngrese el CODIGO del articulo:","ERROR! Codigo invalido.",codigoArticuloNuevo,LONG_STRING,3) == 0)
                            {
                                articulo_setCodigoArticulo(pArticulo,codigoArticuloNuevo);
                            }
                            break;
                        case 2:
                            if(utn_getText(descripcionNuevo,"\nIngrese La descripción del producto:","ERROR! Descripcion invalida.",255,3)==0)
                            {
                                articulo_setDescripcion(pArticulo,descripcionNuevo);
                            }
                            break;
                        case 3:
                            if(utn_getNombre(paisNuevo,"\nIngrese el País de origen:","ERROR! País invalida.",SIZE_COUNTRY,3)==0)
                            {
                                articulo_setPais(pArticulo,paisNuevo);
                            }
                            break;
                        case 4:
                          if(utn_getFloat(&valorFobNuevo, "\nIngrese el VALOR FOB del articulo:", "ERROR! Valor invalido.",0.1,9999999, 3)==0)
                            {
                              articulo_setValorFob(pArticulo, valorFobNuevo);
                            }
                          break;
                        case 5:
                          if(utn_getFloat(&pesoNuevo, "\nIngrese el PESO del articulo:", "ERROR! Valor invalido.",0.1,9999999, 3)==0)
                            {
                              articulo_setPeso(pArticulo, pesoNuevo);
                            }
                          break;
                        case 6:
                          if(utn_getFloat(&anchoNuevo, "\nIngrese el ANCHO del articulo en centimetros:", "ERROR! Medida invalida.",0.1,235, 3)==0)
                            {
                              articulo_setAncho(pArticulo, anchoNuevo);
                            }
                          break;
                        case 7:
                          if(utn_getFloat(&alturaNuevo, "\nIngrese el ALTO del articulo en centimetros:", "ERROR! Medida invalida.",0.1,239, 3)==0)
                            {
                              articulo_setAltura(pArticulo, alturaNuevo);
                            }
                          break;
                        case 8:
                          if(utn_getFloat(&profundidadNuevo, "\nIngrese el LARGO del articulo en centimetros:", "ERROR! Medida invalida.",0.1,1219, 3)==0)
                            {
                              articulo_setProfundidad(pArticulo, profundidadNuevo);
                            }
                          break;
                        case 9:
                          if(utn_getStringWithNumbers("\nIngrese la POSICION ARANCELARIA del articulo:","ERROR! Codigo invalido.",posicionArancelariaNuevo,LONG_STRING,3)==0)
                            {
                              articulo_setPosicionArancelaria(pArticulo, posicionArancelariaNuevo);
                            }
                          break;
                        }
                    }
                }
                while(opcion != 10);
                printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                       "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                       "PosicionArancelaria");
                articulo_print(pArticulo);
                if(utn_getContinue(&respuesta,"Confirma la modificacion?(y/n)","Respuesta incorrecta",2)== 0 && (respuesta == 'y' || respuesta== 'Y'))
                {

                    printf("\nArticulo modificado correctamente.\n");
                    if(codigoArticuloNuevo!=codigoArticulo)
                      {
                    dict_insert(articulos, codigoArticuloNuevo, pArticulo);
                    dict_remove(articulos,codigoArticulo);
                    }
                    retorno=0;
                }
                else
                {
                    articulo_setCodigoArticulo(pArticulo,codigoArticulo);
                    articulo_setDescripcion(pArticulo,descripcion);
                    articulo_setPais(pArticulo,pais);
                    articulo_setValorFob(pArticulo, valorFob);
                    articulo_setPeso(pArticulo, peso);
                    articulo_setAncho(pArticulo, ancho);
                    articulo_setAltura(pArticulo, altura);
                    articulo_setProfundidad(pArticulo, profundidad);
                    articulo_setPosicionArancelaria(pArticulo, posicionArancelaria);
                    printf("\nNo se hizo la modificacion del Articulo.\n");
                    retorno=1;
                }
            }else{
                retorno = 1;
                printf("\nNo se modifico el Articulo.\n");
            }
        }
        else
          {
            printf("\nNo existe Articulo con el codigo ingresada.\n");
          }

    }
    else
      {
        printf("\nERROR. No se puede hacer la operacion.\n");
      }
    return retorno;
}



int controller_removeArticulo(Dictionary* articulos)
{
    char codigoArticulo[LONG_STRING];
    Articulo* pArticulo;
    char respuesta;
    int retorno=-1;

    if(articulos != NULL &&
        utn_getStringWithNumbers("Ingrese CODIGO del articulo a eliminar:",
                                 "Valor incorrecto.\n",codigoArticulo,LONG_STRING,2)==0)
    {
            pArticulo =(Articulo*) dict_get(articulos,codigoArticulo);
            if(pArticulo!=NULL)
              {
                printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                       "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                       "PosicionArancelaria");
            articulo_print(pArticulo);

            if(utn_getContinue(&respuesta,"Desea eliminar este articulo?(y/n)","Incorrecto.\n",2)== 0 && (respuesta=='y' || respuesta == 'Y'))
            {
                articulo_delete(pArticulo);
                dict_remove(articulos,codigoArticulo);
                printf("\nArticulo eliminado correctamente.\n");
                retorno=0;
            }
            else
            {
                printf("\nNo se elimino el Articulo .\n");
                retorno = 1;
            }
        }
    }
    else
      {
        printf("ERROR. No se puede hacer la operacion.\n");
      }

    return retorno;
}

int controller_printArticulo(Dictionary* articulos)
{
  int retorno =-1;
  char codigoArticulo[LONG_STRING];
  Articulo* pArticulo;

  if(articulos != NULL &&
      utn_getStringWithNumbers("Ingrese CODIGO del articulo que desea visualizar:",
                               "Valor incorrecto.\n",codigoArticulo,LONG_STRING,2)==0)
  {
      pArticulo =(Articulo*) dict_get(articulos,codigoArticulo);
      if(pArticulo!=NULL)
        {
          printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                 "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                 "PosicionArancelaria");
          articulo_print(pArticulo);
          retorno =1;
        }
      else
        {
          printf("\nERROR. Ese codigo no existe en el registro.\n");
          retorno=0;
        }
  }
  return retorno;
}

int controller_saveArticuloAsText(char* path, Dictionary* articulos)
{
    int longitud;
    int i;
    char codigoArticulo[LONG_STRING];
    char descripcion[LONG_STRING];
    char pais[SIZE_COUNTRY];
    float valorFob;
    float peso;
    float ancho;
    float altura;
    float profundidad;
    char posicionArancelaria[LONG_STRING];
    int idArticulo;
    int retorno=-1;
    FILE* pFile = NULL;
    Articulo* pArticulo;
    LinkedList* listaArticulos;

    pFile= fopen(path,"w");

    if(path != NULL && articulos != NULL && pFile != NULL)
    {
        fprintf(pFile,"codigoArticulo,descripcion,pais,valorFob,peso,ancho,altura,profundidad,posicionArancelaria,idArticulo\n");
        // Obtengo empleados del diccionario e imprimo sus datos
        listaArticulos=dict_getValues(articulos);
        longitud=ll_len(listaArticulos);
        //Escribo cada empleado en una linea del archivo
        for(i=0; i< longitud; i++)
        {
            pArticulo =(Articulo*) ll_get(listaArticulos,i);
            if(pArticulo!=NULL){
                articulo_getCodigoArticulo(pArticulo,codigoArticulo);
                articulo_getDescripcion(pArticulo,descripcion);
                articulo_getPais(pArticulo,pais);
                articulo_getValorFob(pArticulo,&valorFob);
                articulo_getPeso(pArticulo,&peso);
                articulo_getAncho(pArticulo,&ancho);
                articulo_getAltura(pArticulo,&altura);
                articulo_getProfundidad(pArticulo,&profundidad);
                articulo_getPosicionArancelaria(pArticulo,posicionArancelaria);
                articulo_getIdAriculo(pArticulo, &idArticulo);
            fprintf(pFile,"%s,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%s,%d\n",codigoArticulo,descripcion,pais,valorFob,peso,ancho,altura,profundidad,posicionArancelaria,idArticulo);
            }
        }
        printf("\nArticulos guardados en archivo de texto.\n");
        ll_clear(listaArticulos);
        ll_deleteLinkedList(listaArticulos);
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

//////////////////////////////////POSICIONES ARANCELARIAS//////////////////////
int controller_loadPosArancelFromText(char* path, Dictionary* posArancel)
{
    int retorno=-1;

    if(path == NULL || posArancel == NULL)
    {
        retorno=-1;
        printf("\nError al cargar los datos del archivo del registro de Posiciones.\n");
   /* }else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
        printf("\nYa cargo los datos del archivo anteriormente.\n");  */
    }else{
        posArancel_parser(path,posArancel);
        retorno=0;
        printf("\nDatos del archivo de registro de Posiciones cargados correctamente.\n");

    }

    return retorno;
}

int controller_altaPosArancel(Dictionary* posArancel)
{
  int ret=-1;
  char posicionArancelaria[LONG_STRING];
  float seguro;
  float importacion;
  float tasaEstadistica;
  int tipoDeLicencia;
  PosicionArancelaria* pPa;

  if(posArancel!=NULL)
    {
    printf("\nSe va a dar de alta una Posicion Arancelaria.\n");
    if(utn_getStringWithNumbers("\nIngrese el nomenclador de la POSICION ARANCELARIA:","ERROR! Codigo invalido.",posicionArancelaria,LONG_STRING,3)==0 &&
        dict_get(posArancel, posicionArancelaria)==NULL)
      {
    if(utn_getFloat(&seguro, "\nIngrese el porcentaje de SEGURO:", "ERROR! Valor invalido.",0.1,9999999, 3)==0 &&
      utn_getFloat(&importacion, "\nIngrese el porcentaje de importacion:", "ERROR! Medida invalida.",0.1,235, 3)==0 &&
      utn_getFloat(&tasaEstadistica, "\nIngrese el porcentaje de tasaEstadistica:", "ERROR! Medida invalida.",0.1,239, 3)==0 &&
      utn_getNumero(&tipoDeLicencia, "\nIngrese el tipo de licencia[0=Automatica | 1 = NO automatica]:", "ERROR! Medida invalida.",0,1, 3)==1)
       {//235 ancho alto 239 1219
        pPa=posArancel_newParam(posicionArancelaria,seguro,importacion,tasaEstadistica,tipoDeLicencia);
        if(pPa!=NULL)
        {
          dict_insert(posArancel, posicionArancelaria, pPa);
          ret=1;
          printf("\nSe dio de alta correctamente la posición arancelaria.\n");
        }
        else
        {
            posArancel_delete(pPa);
          ret =0;
          printf("\n NO se dio de alta la posición arancelaria.\n");
        }
      }
    else
      {
        printf("\n ERROR en la carga de datos. NO se dio de alta la posición arancelaria.\n");
      }
    }
    printf("\n ERROR. Ya existe una posicion arancelaria bajo ese nomenclador.\n");
    }
  else
    {
      printf("\n ERROR en el acceso a la lista de posiciones.\n");
    }
  return ret;
}

int controller_editPosArancel(Dictionary* posArancel)
{
    char respuesta;
    int opcion;
     int retorno=-1;
    PosicionArancelaria* pPa;
    char posicionArancelaria[LONG_STRING];
    float seguro;
    float importacion;
    float tasaEstadistica;
    int tipoDeLicencia;
    char posicionArancelariaNuevo[LONG_STRING];
    float seguroNuevo;
    float importacionNuevo;
    float tasaEstadisticaNuevo;
    int tipoDeLicenciaNuevo;


    if(posArancel != NULL &&
        utn_getStringWithNumbers("Ingrese NOMENCALDOR de la posicion a modificar:",
                                 "Valor incorrecto.\n",posicionArancelaria,2000,2)==0)
    {
        pPa =(PosicionArancelaria*) dict_get(posArancel,posicionArancelaria);
            if(pPa!=NULL)
              {
                printf("%12s    %7s    %7s    %7s    %15s\n","Posicion Arancelaria","Seguro","Importacion","Tasa Estadistica","Tipo De Licencia");
                posArancel_print(pPa);
            if(utn_getContinue(&respuesta,"Desea modificar esta posicion?(y/n)","Incorrecto.\n",2)== 0 && (respuesta == 'y' || respuesta=='Y'))
            {
                posArancel_getPosicionArancelaria(pPa,posicionArancelaria);
                posArancel_getSeguro(pPa,&seguro);
                posArancel_getImportacion(pPa,&importacion);
                posArancel_getTasaEstadistica(pPa,&tasaEstadistica);
                posArancel_getTipoDeLicencia(pPa,&tipoDeLicencia);
                do
                {
                    if(utn_getNumero(&opcion,"\nElija el campo a modificar:\n1.Nomenclador.\n2.Seguro."
                        "\n3.Importacion.\n4.Tasa Estadistica.\n5.Tipo De Licencia."
                        "\n16.Salir.\nElija una opcion:","Opcion incorrecta.\n",1,6,3)==1)
                    {
                        switch(opcion)
                        {
                        case 1:
                            if(utn_getStringWithNumbers("\nIngrese el NOMENCLADOR de la posicion:","ERROR! Codigo invalido.",posicionArancelariaNuevo,LONG_STRING,3) == 0)
                            {
                                posArancel_setPosicionArancelaria(pPa,posicionArancelariaNuevo);
                            }
                            break;
                        case 2:
                            if(utn_getFloat(&seguroNuevo,"\nIngrese el porcentaje de Seguro:","ERROR! Descripcion invalida.",0,99,3)==0)
                            {
                                posArancel_setSeguro(pPa, seguroNuevo);
                            }
                            break;
                        case 3:
                            if(utn_getFloat(&importacionNuevo,"\nIngrese el porcentaje de Importacion:","ERROR! Descripcion invalida.",0,35,3)==0)
                            {
                                posArancel_setImportacion(pPa,importacionNuevo);
                            }
                            break;
                        case 4:
                          if(utn_getFloat(&tasaEstadisticaNuevo,"\nIngrese el porcentaje de Tasa Estadistica:","ERROR! Descripcion invalida.",0,99,3)==0)
                            {
                              posArancel_setTasaEstadistica(pPa, tasaEstadisticaNuevo);
                            }
                          break;
                        case 5:
                          if(utn_getNumero(&tipoDeLicenciaNuevo, "\nIngrese el tipo de licencia[0=Automatica | 1 = NO automatica]:", "ERROR! Medida invalida.",0,1, 3)==1)
                            {
                              posArancel_setTipoDeLicencia(pPa, tipoDeLicenciaNuevo);
                            }
                          break;
                        }
                    }
                }
                while(opcion != 6);
                printf("%12s    %7s    %7s    %7s    %15s\n","Posicion Arancelaria","Seguro","Importacion","Tasa Estadistica","Tipo De Licencia");
                posArancel_print(pPa);
                if(utn_getContinue(&respuesta,"Confirma la modificacion?(y/n)","Respuesta incorrecta",2)== 0 && (respuesta == 'y' || respuesta== 'Y'))
                {
                    printf("\nPosicion modificada correctamente.\n");
                    if(posicionArancelariaNuevo!=posicionArancelaria)
                      {
                        dict_insert(posArancel, posicionArancelariaNuevo, pPa);
                        dict_remove(posArancel,posicionArancelaria);
                      }
                    retorno=0;
                }
                else
                {
                    posArancel_setPosicionArancelaria(pPa,posicionArancelaria);
                    posArancel_setSeguro(pPa,seguro);
                    posArancel_setImportacion(pPa,importacion);
                    posArancel_setTasaEstadistica(pPa,tasaEstadistica);
                    posArancel_setTipoDeLicencia(pPa,tipoDeLicencia);
                    printf("\nNo se hizo la modificacion de la Posicion.\n");
                    retorno=1;
                }
            }else{
                retorno = 1;
                printf("\nNo se modifico la Posicion.\n");
            }
        }
        else
          {
            printf("\nNo existe la Posicion con el nomenclador ingresado.\n");
          }

    }
    else
      {
        printf("\nERROR. No se puede hacer la operacion.\n");
      }
    return retorno;
}


int controller_removePosArancel(Dictionary* PosArancel)
{
    char nomenclador[LONG_STRING];
    PosicionArancelaria* pPosA;
    char respuesta;
    int retorno=-1;

    if(PosArancel != NULL &&
        utn_getStringWithNumbers("Ingrese NOMENCLADOR de la posicion a eliminar:",
                                 "Valor incorrecto.\n",nomenclador,2000,2)==0)
    {
            pPosA =(PosicionArancelaria*) dict_get(PosArancel,nomenclador);
            if(pPosA!=NULL)
              {
                printf("%12s    %7s    %7s    %7s    %15s\n","Posicion Arancelaria","Seguro","Importacion","Tasa Estadistica","Tipo De Licencia");
                posArancel_print(pPosA);

            if(utn_getContinue(&respuesta,"Desea eliminar esta Posicion?(y/n)","Incorrecto.\n",2)== 0 && (respuesta=='y' || respuesta == 'Y'))
            {
                posArancel_delete(pPosA);
                dict_remove(PosArancel,nomenclador);
                printf("\nPosicion eliminada correctamente.\n");
                retorno=0;
            }
            else
            {
                printf("\nNo se elimino la Posicion.\n");
                retorno = 1;
            }
        }
    }
    else
      {
        printf("ERROR. No se puede hacer la operacion.\n");
      }

    return retorno;
}

int controller_printPosArancel(Dictionary* posArancel)
{
  int retorno =-1;
  char nomenclador[LONG_STRING];
  PosicionArancelaria* pPa;

 if(posArancel != NULL &&
      utn_getStringWithNumbers("Ingrese NOMENCLADOR de la Posicion que desea visualizar:",
                               "Valor incorrecto.\n",nomenclador,LONG_STRING,2)==0)
  {
      pPa =(PosicionArancelaria*) dict_get(posArancel,nomenclador);
      if(pPa!=NULL)
        {
          printf("%12s    %7s    %7s    %7s    %15s\n","Posicion Arancelaria","Seguro","Importacion","Tasa Estadistica","Tipo De Licencia");
          posArancel_print(pPa);
          retorno =1;
        }
      else
        {
          printf("\nERROR. Ese nomenclador no existe en el registro.\n");
          retorno=0;
        }
  }
  return retorno;
}
int controller_ListPosArancel(Dictionary* posArancel)
{
  PosicionArancelaria* pPosA;
  int longitud;
  int i;
  int retorno=-1;
  LinkedList* listaPosA;

listaPosA=dict_getValues(posArancel);
    if(listaPosA != NULL && ll_isEmpty(listaPosA) == 0)
    {
        longitud = ll_len(listaPosA);
        printf("%12s    %7s    %7s    %7s    %15s\n","Posicion Arancelaria","Seguro",
               "Importacion","Tasa Estadistica","Tipo De Licencia");
        for(i=0; i < longitud; i++)
        {
            pPosA =(PosicionArancelaria*) ll_get(listaPosA,i);
            posArancel_print(pPosA);
        }
        printf("Cantidad de Posiciones Arancelarias registradas:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }
    ll_clear(listaPosA);
    ll_deleteLinkedList(listaPosA);
    return retorno;
}

int controller_savePosArancelAsText(char* path, Dictionary* PosArancel)
{
    int longitud;
    int i;

    char posicionArancelaria[LONG_STRING];
    float seguro;
    float importacion;
    float tasaEstadistica;
    int tipoDeLicencia;

    int retorno=-1;
    FILE* pFile = NULL;
    PosicionArancelaria * pPosA;
    LinkedList* listaPosiciones;

    pFile= fopen(path,"w");

    if(path != NULL && PosArancel != NULL && pFile != NULL)
    {
        fprintf(pFile,"posicionArancelaria,seguro,importacion,tasaEstadistica,tipoDeLicencia\n");
        // Obtengo empleados del diccionario e imprimo sus datos
        listaPosiciones=dict_getValues(PosArancel);
        longitud=ll_len(listaPosiciones);
        //Escribo cada empleado en una linea del archivo
        for(i=0; i< longitud; i++)
        {
            pPosA =(PosicionArancelaria*) ll_get(listaPosiciones,i);
            if(pPosA!=NULL){
                posArancel_getPosicionArancelaria(pPosA,posicionArancelaria);
                posArancel_getSeguro(pPosA,&seguro);
                posArancel_getImportacion(pPosA,&importacion);
                posArancel_getTasaEstadistica(pPosA,&tasaEstadistica);
                posArancel_getTipoDeLicencia(pPosA,&tipoDeLicencia);
            fprintf(pFile,"%s,%.4f,%.4f,%.4f,%d\n",posicionArancelaria,seguro,importacion,tasaEstadistica,tipoDeLicencia);
            }
        }
        printf("\nPosiciones Arancelarias guardadas en archivo de texto.\n");
        ll_clear(listaPosiciones);
        ll_deleteLinkedList(listaPosiciones);
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////

int controller_close(Dictionary* articulos, Dictionary* PosArancel)
{
    int retorno=-1;
    printf("Cerrando el programa...\n");
    if(articulos !=NULL && PosArancel!=NULL){
    dict_deleteDictionary(articulos);
    dict_deleteDictionary(PosArancel);
    retorno=0;
    }
    printf("\t ADIOS!.\n");
    return retorno;
}

//////////////////////////////////////////////COSTOS

int controller_loadCostosFromText(char* path, CostosTransporte* costos)
{
    int retorno=-1;

    if(path == NULL || costos == NULL)
    {
        retorno=-1;
        printf("\nError al cargar los datos del archivo del registro de costos.\n");
    }else{
        costos_parser(path,costos);
        printf("\nDatos del archivo de registro de costos cargados correctamente.\n");
        retorno=0;
    }

    return retorno;
}

/////////////////////////////////INFORMES//////////////////////////////////////

int controller_informesArticulos(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos)
{

int opcion;
do{
    utn_getNumero(&opcion,"\n   MENU DE INFORMES:\n"
                    "1. Mostrar un articulo.\n"
                    "2. Mostrar un articulo con costo maritimo.\n"
                    "3. Mostrar un articulo con costo aereo.\n"
                    "4. Listar todos los articulos.\n"
                    "5. Listar articulos con costo martitimo.\n"
                    "6. Listar articulos con costo aereo.\n"
                    "7. Volver al menu Principal.\n"
                    "\nElija una opcion:"
                    ,"Opcion invalida.\n",1,7,3);

                    switch(opcion){
                    case 1:
                      controller_printArticulo(articulos);
                        break;
                    case 2:
                      controller_printCostoMaritimo(articulos,posArancel,costos);
                        break;
                    case 3:
                      controller_printCostoAereo(articulos,posArancel,costos);
                      break;
                    case 4:
                      controller_ListArticulo(articulos);
                      break;
                    case 5:
                      controller_ListArticuloMaritimo(articulos,posArancel,costos);
                      break;
                    case 6:
                      controller_ListArticuloAereo(articulos,posArancel,costos);
                        break;
                    }
}while(opcion != 7);
return 0;
}

int controller_ListArticulo(Dictionary* articulos)
{
    Articulo* pArticulo;
    int longitud;
    int i;
    int retorno=-1;
    LinkedList* listaArticulos;

    listaArticulos=dict_getValues(articulos);
    if(listaArticulos != NULL && ll_isEmpty(listaArticulos) == 0)
    {
        longitud = ll_len(listaArticulos);
        printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
               "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
               "PosicionArancelaria");
        for(i=0; i < longitud; i++)
        {
            pArticulo =(Articulo*) ll_get(listaArticulos,i);
            articulo_print(pArticulo);
        }
        printf("Cantidad de articulos:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }
    ll_clear(listaArticulos);
    ll_deleteLinkedList(listaArticulos);
    return retorno;
}

int controller_printCostoMaritimo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos)
{
  int retorno=-1;
  double costoFinal;
  char codigoArticulo[LONG_STRING];
  char auxposicionArancelaria[18];
  Articulo* pArticulo;
  PosicionArancelaria* pPosArancel;

  if(articulos!=NULL && posArancel != NULL && costos != NULL)
  {
      utn_getStringWithNumbers("Ingrese CODIGO del articulo que desea visualizar:","Valor incorrecto.\n",codigoArticulo,LONG_STRING,2);
      pArticulo =(Articulo*) dict_get(articulos,codigoArticulo);
      if(pArticulo!=NULL)
        {
          articulo_getPosicionArancelaria(pArticulo, auxposicionArancelaria);
          pPosArancel =(PosicionArancelaria*) dict_get(posArancel,auxposicionArancelaria);
          if(pPosArancel!=NULL)
          {
              calc_CostoMaritimoConImpuestos(pArticulo,pPosArancel,costos,&costoFinal);
          printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                 "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                 "PosicionArancelaria");
          articulo_print(pArticulo);
          printf("\n\nEl costo final del producto en Argentina es de: %lf$  (Via Maritima)\n\n",costoFinal);
          retorno =1;
          }
        }
  }
  return retorno;
}

int controller_printCostoAereo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos)
{
  int retorno=-1;
  double costoFinal;
  char codigoArticulo[LONG_STRING];
  char auxposicionArancelaria[18];
  Articulo* pArticulo;
  PosicionArancelaria* pPosArancel;

  if(articulos!=NULL && posArancel != NULL && costos != NULL)
  {
      utn_getStringWithNumbers("Ingrese CODIGO del articulo que desea visualizar:","Valor incorrecto.\n",codigoArticulo,LONG_STRING,2);
      pArticulo =(Articulo*) dict_get(articulos,codigoArticulo);
      if(pArticulo!=NULL)
        {
          articulo_getPosicionArancelaria(pArticulo, auxposicionArancelaria);
          pPosArancel =(PosicionArancelaria*) dict_get(posArancel,auxposicionArancelaria);
          if(pPosArancel!=NULL)
          {
              calc_CostoAereoConImpuestos(pArticulo,pPosArancel,costos,&costoFinal);
          printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                 "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                 "PosicionArancelaria");
          articulo_print(pArticulo);
          printf("\n\nEl costo final del producto en Argentina es de: %lf$  (Via Aereo)\n\n",costoFinal);
          retorno =1;
          }
        }
  }
  return retorno;
}

int controller_ListArticuloMaritimo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos)
{
    Articulo* pArticulo;
    int longitud;
    int i;
    int retorno=-1;
    LinkedList* listaArticulos;
    PosicionArancelaria* pPosArancel;
    char auxposicionArancelaria[18];
    double costoFinal;

    listaArticulos=dict_getValues(articulos);
    if(listaArticulos != NULL && ll_isEmpty(listaArticulos) == 0)
    {
        longitud = ll_len(listaArticulos);
        for(i=0; i < longitud; i++)
        {
            pArticulo =(Articulo*) ll_get(listaArticulos,i);
            if(pArticulo!=NULL)
                    {
                      articulo_getPosicionArancelaria(pArticulo, auxposicionArancelaria);
                      pPosArancel =(PosicionArancelaria*) dict_get(posArancel,auxposicionArancelaria);
                      if(pPosArancel!=NULL)
                      {
                    calc_CostoMaritimoConImpuestos(pArticulo,pPosArancel,costos,&costoFinal);
                    printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                           "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                           "PosicionArancelaria");
                    articulo_print(pArticulo);
                    printf("\n\nEl costo final del producto en Argentina es de: %lf$  (Via Maritima)\n\n",costoFinal);
                      retorno =1;
                      }
                    }
        }
        printf("Cantidad de articulos:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }
    ll_clear(listaArticulos);
    ll_deleteLinkedList(listaArticulos);
    return retorno;
}

int controller_ListArticuloAereo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos)
{
    Articulo* pArticulo;
    int longitud;
    int i;
    int retorno=-1;
    LinkedList* listaArticulos;
    PosicionArancelaria* pPosArancel;
    char auxposicionArancelaria[18];
    double costoFinal;

    listaArticulos=dict_getValues(articulos);
    if(listaArticulos != NULL && ll_isEmpty(listaArticulos) == 0)
    {
        longitud = ll_len(listaArticulos);
        for(i=0; i < longitud; i++)
        {
            pArticulo =(Articulo*) ll_get(listaArticulos,i);
            if(pArticulo!=NULL)
                    {
                      articulo_getPosicionArancelaria(pArticulo, auxposicionArancelaria);
                      pPosArancel =(PosicionArancelaria*) dict_get(posArancel,auxposicionArancelaria);
                      if(pPosArancel!=NULL)
                      {
                          calc_CostoAereoConImpuestos(pArticulo,pPosArancel,costos,&costoFinal);
                      printf("%8s    %24s    %12s   %8s    %8s    %6s    %6s    %7s    %12s\n",
                             "CODIGO","Descripcion","Pais","FOB","Peso","Ancho","Altura","Profundidad",
                             "PosicionArancelaria");
                      articulo_print(pArticulo);
                      printf("\n\nEl costo final del producto en Argentina es de: %lf$  (Via Aereo)\n\n",costoFinal);
                      retorno =1;
                      }
                    }
        }
        printf("Cantidad de articulos:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }
    ll_clear(listaArticulos);
    ll_deleteLinkedList(listaArticulos);
    return retorno;
}

int controller_saveCostosAsText(char* path, CostosTransporte* costos)
{
    float valorContenedor;
    float metrosCubicosContenedor;
    float precioPorKilo;
    float constanteVolumetrica;

    int retorno=-1;
    FILE* pFile = NULL;

    pFile= fopen(path,"w");

    if(path != NULL && costos != NULL && pFile != NULL)
    {
        fprintf(pFile,"valorContenedor,metrosCubicosContenedor,precioPorKilo,constanteVolumetrica\n");
            if(costos!=NULL){
                costos_getValorContenedor(costos, &valorContenedor);
                costos_getMetrosCubicosContenedor(costos, &metrosCubicosContenedor);
                costos_getPrecioPorKilo(costos, &precioPorKilo);
                costos_getConstanteVolumetrica(costos, &constanteVolumetrica);
            fprintf(pFile,"%.4f,%.4f,%.4f,%.4f\n",valorContenedor,metrosCubicosContenedor,precioPorKilo,constanteVolumetrica);
            }
        printf("\nVariables de costos de transporte guardadas satisfactoriamente.\n");
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}



int controller_editCostos(char* path,CostosTransporte* pCostos)
{
    char respuesta;
    int opcion;
     int retorno=-1;
     float valorContenedor;
     float metrosCubicosContenedor;
     float precioPorKilo;
     float constanteVolumetrica;
     float valorContenedorNuevo;
     float metrosCubicosContenedorNuevo;
     float precioPorKiloNuevo;
     float constanteVolumetricaNuevo;

    if(pCostos != NULL)
    {
        costos_getValorContenedor(pCostos, &valorContenedor);
        costos_getMetrosCubicosContenedor(pCostos, &metrosCubicosContenedor);
        costos_getPrecioPorKilo(pCostos, &precioPorKilo);
        costos_getConstanteVolumetrica(pCostos, &constanteVolumetrica);
        printf("%21s    %21s    %21s    %21s    \n","Precio Contenedor","Metros Cubicos",
               "Precio por KG","Constante Volumetrica");
        printf("%21.2f    %21.2fs    %21.2f    %21.2f    \n",pCostos->valorContenedor,
               pCostos->metrosCubicosContenedor,pCostos->precioPorKilo,pCostos->constanteVolumetrica);
                do
                {
                    if(utn_getNumero(&opcion,"\nElija el campo a modificar:\n1.Costo de Contenedor.\n2.Metros Cubicos del Contenedor."
                        "\n3.Precio Por Kilo(aereo).\n4.Constante Volumetrica."
                        "\n5.Salir.\nElija una opcion:","Opcion incorrecta.\n",1,6,3)==1)
                    {

                        switch(opcion)
                        {
                        case 1:
                            if(utn_getFloat(&valorContenedorNuevo,"\nIngrese el Costo del contenedor:","ERROR! Descripcion invalida.",0,9999999,3)==0)
                            {
                                costos_setValorContenedor(pCostos,valorContenedorNuevo);
                            }
                            break;
                        case 2:
                            if(utn_getFloat(&metrosCubicosContenedorNuevo,"\nIngrese los metros cubicos del contenedor:","ERROR! Descripcion invalida.",0,9999,3)==0)
                            {
                                costos_setMetrosCubicosContenedor(pCostos, metrosCubicosContenedorNuevo);
                            }
                            break;
                        case 3:
                            if(utn_getFloat(&precioPorKiloNuevo,"\nIngrese el precio por kilo para el transporte aereo:","ERROR! Descripcion invalida.",0,9999999,3)==0)
                            {
                                costos_setPrecioPorKilo(pCostos,precioPorKiloNuevo);
                            }
                            break;
                        case 4:
                          if(utn_getFloat(&constanteVolumetricaNuevo,"\nIngrese el porcentaje de Constante Volumetrica:","ERROR! Descripcion invalida.",0,9999999,3)==0)
                            {
                              costos_setConstanteVolumetrica(pCostos, constanteVolumetricaNuevo);
                            }
                          break;
                        }
                    }
                }
                while(opcion != 5);
                printf("%21s    %21s    %21s    %21s    \n","Precio Contenedor","Metros Cubicos","Precio por KG","Constante Volumetrica");
                printf("%21.2f    %21.2fs    %21.2f    %21.2f    \n",pCostos->valorContenedor,pCostos->metrosCubicosContenedor,pCostos->precioPorKilo,pCostos->constanteVolumetrica);
                if(utn_getContinue(&respuesta,"Confirma la modificacion?(y/n)","Respuesta incorrecta",2)== 0 && (respuesta == 'y' || respuesta== 'Y'))
                {
                    printf("\nValores modificados correctamente.\n");
                    controller_saveCostosAsText(path,pCostos);
                    retorno=0;
                }
                else
                {
                    costos_setValorContenedor(pCostos, valorContenedor);
                    costos_setMetrosCubicosContenedor(pCostos, metrosCubicosContenedor);
                    costos_setPrecioPorKilo(pCostos, precioPorKilo);
                    costos_setConstanteVolumetrica(pCostos, constanteVolumetrica);
                    printf("\nNo se hizo la modificacion de las variables.\n");
                    retorno=1;
                }
    }
    else
      {
        printf("\nERROR. No se puede hacer la operacion.\n");
      }
    return retorno;
}
