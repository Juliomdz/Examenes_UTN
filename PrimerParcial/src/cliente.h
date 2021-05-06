/*
 * cliente.h
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define SIZE_NOMBRE 512
#define SIZE_CUIT 12
#define SIZE_TIPO 32
typedef struct
{
    char nombre[SIZE_NOMBRE];
    char apellido[SIZE_NOMBRE];
    char cuit[SIZE_CUIT];
    int idCliente;
    int isEmpty;
}Cliente;

int cli_init(Cliente* array,int limite);
int cli_alta(Cliente* pPantalla,int limite, int* id);
int cli_baja(Cliente* arrayClientes,int limite, int indiceRecibido);
int cli_modificacion(Cliente* array,int limite);
int cli_getCliente(Cliente* arrayClientes,int limite,int* indiceObtenido);
int cli_getClienteYId(Cliente* arrayClientes,int limite,int* indiceObtenido, int*idBuscado);
int cli_imprimir(Cliente* pCliente);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarLugarLibre(Cliente* arrayPantalla,int* indiceLibre,int limite);
int cli_isEmptyIndice(Cliente* pPantalla);
int cli_buscarID(Cliente* arrayPantalla,int limite, int valorBuscado, int* indiceRespuesta);
int cli_altaForzada(Cliente* pPantalla,int limite,char* nombre,char* apellido,
                    char* cuit, int indice,int* id);

#endif /* CLIENTE_H_ */
