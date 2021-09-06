/*
 * costosTransporte.h
 *
 *  Created on: 22 jun. 2021
 *      Author: julio
 */

#ifndef COSTOSTRANSPORTE_H_
#define COSTOSTRANSPORTE_H_


typedef struct
{
  float valorContenedor;
  float metrosCubicosContenedor;
  float precioPorKilo;
  float constanteVolumetrica;
}CostosTransporte;

CostosTransporte* costos_new(void);

int costos_setValorContenedor(CostosTransporte* this,float valorContenedor);
int costos_getValorContenedor(CostosTransporte* this, float* valorContenedor);
int isValidContenedor(float valorContenedor);

int costos_setMetrosCubicosContenedor(CostosTransporte* this,float metrosCubicosContenedor);
int costos_getMetrosCubicosContenedor(CostosTransporte* this, float* metrosCubicosContenedor);
int isValidMetrosCubicos(float metrosCubicosContenedor);

int costos_setPrecioPorKilo(CostosTransporte* this,float precioPorKilo);
int costos_getPrecioPorKilo(CostosTransporte* this, float* precioPorKilo);
int isValidPrecioPorKilo(float precioPorKilo);

int costos_setConstanteVolumetrica(CostosTransporte* this,float constanteVolumetrica);
int costos_getConstanteVolumetrica(CostosTransporte* this, float* constanteVolumetrica);
int isValidConstanteVolumetrica(float constanteVolumetrica);

int costos_parser(char* nombreArchivo,CostosTransporte* pCostos);

#endif /* COSTOSTRANSPORTE_H_ */
