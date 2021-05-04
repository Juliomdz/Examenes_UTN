/*
 * compra.h
 *
 *  Created on: 4 may. 2021
 *      Author: julio
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#define SIZE_COLOR 512
#define SIZE_DIRECCION_ENTREGA 64
#define SIZE_TIPO 32
#define SIZE_MAX_BARBIJOS 9999999
#include "cliente.h"
typedef struct
{
    float importe;
    char color[SIZE_COLOR];
    char direccion[SIZE_DIRECCION_ENTREGA];
    int cantidadBarbijos;
    int idCliente;
    int idCompra;
    int status; // 0 es vacio, 1 es pendiente de pago y 2 es abonada
}Compra;

int com_init(Compra* arrayCompras,int limite);
int com_alta(Compra* arrayCompra,int limite, int* id, Cliente* arrayClientes, int limiteCliente);
int com_bajaCliente(Compra* arrayCompras,int limite, int IdClienteRecibido);
int com_getIdClienteByCompra(Compra* arrayCompras,int limite, int*idClienteObtenido, int* indiceCompraObtenido);
int com_pagar(Compra* pCompra);
int com_cancelar(Compra* pCompra);
int com_buscarLugarLibre(Compra* arrayCompra,int* indiceLibre,int limite);
int com_buscarID(Compra* arrayCompras,int limite, int valorBuscado, int* indiceRespuesta);
int com_statusIndice(Compra* pCompra);
int com_imprimir(Compra* pCompra);
int com_imprimirCompras(Compra* arrayCompras,int limiteCompras, int IdClienteIngresado);
int com_imprimirClientesConContrataciones(Cliente* arrayClientes,int limiteClientes, Compra* arrayCompras,int limiteCompras);
int com_imprimirArray(Compra* arrayCompras,int limite);
int com_imprimirCliente(Compra* arrayCompras,int limite, int idAImprimir);
int com_altaForzada(Compra* arrayCompra,int indice,int limite,float importe, char* color,
                    char* direccion, int cantidadBarbijos, int idCliente, int status,int* id);
#endif /* COMPRA_H_ */
