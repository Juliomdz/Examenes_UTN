/*
 * controller.h
 *
 *  Created on: 22 jun. 2021
 *      Author: julio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "collections/LinkedList.h"
#include "collections/Dictionary.h"
#include "Articulo.h"
#include "calculosTransporte.h"
#include "costosTransporte.h"

/** \brief Permite extraer los datos de un archivo de texto y guardarlos en memoria.
 * \param path char* Cadena de carateres que representa la ruta o nombre del archivo.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros donde se guardaran los datos.
 * \return int Retorna 0 si pudo hacer la carga en memoria; 1 si ya fueron cargados previamente; -1 si es nula.
 */
int controller_loadArtFromText(char* path, Dictionary* articulos);

int controller_altaArticulo(Dictionary* articulos);

int controller_editArticulo(Dictionary* articulos);

int controller_printArticulo(Dictionary* articulos);

int controller_removeArticulo(Dictionary* articulos);

int controller_saveArticuloAsText(char* path, Dictionary* articulos);
/////////////////////////////////POSICION ARANCELARIA///////////////////////////
int controller_loadPosArancelFromText(char* path, Dictionary* posArancel);

int controller_altaPosArancel(Dictionary* posArancel);

int controller_editPosArancel(Dictionary* posArancel);

int controller_removePosArancel(Dictionary* PosArancel);

int controller_printPosArancel(Dictionary* posArancel);

int controller_ListPosArancel(Dictionary* posArancel);

int controller_savePosArancelAsText(char* path, Dictionary* PosArancel);
///////////////////////////////////////////////////////////////////////////////
int controller_loadCostosFromText(char* path, CostosTransporte* costos);
///////////////////////////////////////////////////////////////////////////////
int controller_close(Dictionary* articulos, Dictionary* PosArancel);

//////////////////////////////////////////////////////////////////////////////

int controller_informesArticulos(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos);
int controller_ListArticulo(Dictionary* articulos);
int controller_printCostoMaritimo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos);
int controller_ListArticuloMaritimo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos);
int controller_printCostoAereo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos);
int controller_ListArticuloAereo(Dictionary* articulos, Dictionary* posArancel, CostosTransporte* costos);

int controller_saveCostosAsText(char* path, CostosTransporte* costos);

int controller_editCostos(char* path,CostosTransporte* pCostos);
#endif /* CONTROLLER_H_ */
