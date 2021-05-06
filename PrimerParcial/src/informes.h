/*
 * informes.h
 *
 *  Created on: 4 may. 2021
 *      Author: julio
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int inf_barbijoMasComprado(Compra* arrayCompras,int limite);
int inf_contadorComprasPendientes(Compra* arrayCompras,int limite);
int inf_menorPrecioUnitario(Compra* arrayCompras,int limite);
int inf_clienteMasPagadas(Compra* arrayCompras, int limite);
int inf_clienteMasPendientes(Compra* arrayCompras, int limite);
int inf_imprimirListaPendientesDePago(Cliente* arrayClientes,int limiteClientes, Compra* arrayCompras,int limiteCompras);
int inf_noRepetidos(Compra* arrayCompras,int limite,int* listaClientes, int statusBuscado);
int inf_clienteMasStatus(Compra* arrayCompras,int limite,int* listaClientes, int statusBuscado, int* acumuladorCliente);

#endif /* INFORMES_H_ */
