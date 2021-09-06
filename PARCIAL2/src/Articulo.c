/*
 * Articulo.c
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Articulo.h"
#include "utn.h"
#include "collections/LinkedList.h"
#include "PosicionArancelaria.h"

static int articulo_validarPais(char* cadena, int limite);


Articulo* articulo_new(void)
{
	return (Articulo*) malloc(sizeof(Articulo));
}

Articulo* articulo_newParam(char* codigoArticulo,char* descripcion,char* pais,float valorFob,float peso,float ancho,float altura,float profundidad,char* posicionArancelaria,int idArticulo)
{
	Articulo* auxArticulo = articulo_new();
	if(auxArticulo != NULL)
	{
		if  (articulo_setCodigoArticulo(auxArticulo,codigoArticulo) != 0 ||
				articulo_setDescripcion(auxArticulo,descripcion) != 0 ||
				articulo_setPais(auxArticulo,pais) != 0 ||
				articulo_setValorFob(auxArticulo,valorFob) != 0 ||
				articulo_setPeso(auxArticulo,peso) != 0 ||
				articulo_setAncho(auxArticulo,ancho) != 0 ||
				articulo_setAltura(auxArticulo,altura) != 0 ||
				articulo_setProfundidad(auxArticulo,profundidad) != 0 ||
				articulo_setPosicionArancelaria(auxArticulo,posicionArancelaria) != 0 ||
				articulo_setIdArticulo(auxArticulo,idArticulo) != 0)
		{
			articulo_delete(auxArticulo);
			auxArticulo = NULL;
		}
	}
	return auxArticulo;
}

int articulo_delete(Articulo* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
//-------------------------------------CodigoArticulo--------------------------------
int articulo_setCodigoArticulo(Articulo* this, char* CodigoArticulo)
{
	int retorno = -1;
	if(this != NULL && CodigoArticulo != NULL && isValidCodigoArticulo(CodigoArticulo))
	{
		strcpy(this->codigoArticulo,CodigoArticulo);
		retorno = 0;
	}
	return retorno;
}

int articulo_getCodigoArticulo(Articulo* this,char* codigoArticulo)
{
	int retorno = -1;
	if(this != NULL)
	{
	    strcpy(codigoArticulo,this->codigoArticulo);
		retorno = 0;
	}
	return retorno;
}

int isValidCodigoArticulo(char* nombre)
{
  int retorno=0;
  if (articulo_isAlphanumeric(nombre)==1)
    {
      retorno=1;
    }
	return retorno;
}
//--------------------------------------Descripcion-------
int articulo_setDescripcion(Articulo* this, char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && isValidDescripcion(descripcion))
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;
}

int articulo_getDescripcion (Articulo* this,char*  auxdescripcion)
{
	int retorno = -1;

	if(this != NULL)
	{
	    strcpy(auxdescripcion,this->descripcion);
		retorno = 0;
	}
	return retorno;
}


int isValidDescripcion (char* descripcion )
{
  int retorno=-1;
  int auxLen=strlen(descripcion);
  if(utn_esTexto(descripcion) && auxLen <= LONG_STRING)
    {
      retorno=1;
    }
  else
    {
      retorno=0;
    }
	return retorno;
}
//-----------------------Pais-------------
int articulo_setPais(Articulo* this, char* pais)
{
	int retorno = -1;
	if(this != NULL && pais!= NULL && isValidPais (pais) )
	{
		strcpy(this->pais,pais);
		retorno = 0;
	}
	return retorno;
}

int articulo_getPais (Articulo* this,char* auxpais)
{
	int retorno = -1;
	if(this != NULL)
	{
	    strcpy(auxpais,this->pais);
		retorno = 0;
	}
	return retorno;
}
//
int isValidPais (char* pais)
{
  {
    int retorno=-1;
    if(pais != NULL && articulo_validarPais(pais,SIZE_COUNTRY)==1)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}
//--------------------PosicionArancelaria
int articulo_setPosicionArancelaria(Articulo* this, char* posicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && posicionArancelaria!= NULL && isValidPosicionArancel(posicionArancelaria))
	{
		strcpy(this->posicionArancelaria,posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}

int articulo_getPosicionArancelaria (Articulo* this,  char* auxposicionArancelaria)
{
	int retorno = -1;

	if(this != NULL)
	{
	    strcpy(auxposicionArancelaria,this->posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}


//------------------------ValorFob

int articulo_setValorFob(Articulo* this,float valorFob)
{
	int retorno = -1;
	if(this != NULL && valorFob>=0 && isValidValorFob(valorFob) )
	{
		this->valorFob=valorFob;
		retorno = 0;
	}
	return retorno;
}

int articulo_getValorFob(Articulo* this, float* auxValorFob)
{
	int retorno= -1;

	if(this != NULL)
	{
		*auxValorFob = this->valorFob;
		retorno = 0;
	}
	return retorno;
}

int isValidValorFob(float valorFob)
{
  {
    int retorno=-1;
    if(valorFob >= 0)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}
//------------------Peso--------------
int articulo_setPeso(Articulo* this,float peso)
{
	int retorno = -1;
	if(this != NULL && peso>=0 && isValidValorPeso(peso))
	{
		this->peso=peso;
		retorno = 0;
	}
	return retorno;
}

int articulo_getPeso(Articulo* this,float* auxPeso)
{
	int retorno = -1;

	if(this != NULL)
	{
		*auxPeso = this->peso;
		retorno = 0;
	}
	return retorno;
}

int isValidValorPeso(float peso)
{
  {
    int retorno=-1;
    if(peso >= 0)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}
//---------------------Ancho--------
int articulo_setAncho(Articulo* this,float ancho)
{
	int retorno = -1;
	if(this != NULL && ancho>=0 && isValidAncho(ancho))
	{
		this->ancho=ancho;
		retorno = 0;
	}
	return retorno;
}

int articulo_getAncho(Articulo* this, float* auxAncho)
{
	int retorno = -1;
	if(this != NULL)
	{
		*auxAncho = this->ancho;
		retorno = 0;
	}
	return retorno;
}

int isValidAncho(float ancho)
{
  {
    int retorno=-1;
    if(ancho >= 0 && ancho <=235)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}
//---------------------Altura--------
int articulo_setAltura(Articulo* this,float altura)
{
	int retorno = -1;
	if(this != NULL && altura>=0 && isValidValorAltura(altura) )
	{
		this->altura=altura;
		retorno = 0;
	}
	return retorno;
}

int articulo_getAltura(Articulo* this,float* auxAltura)
{
	int retorno = -1;

	if(this != NULL)
	{
		*auxAltura = this->altura;
		retorno = 0;
	}
	return retorno;
}

int isValidValorAltura(float altura)
{
  {
    int retorno=-1;
    if(altura >= 0 && altura <=239)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}

//---------------------Profundidad--------
int articulo_setProfundidad(Articulo* this,float profundidad)
{
	int retorno = -1;
	if(this != NULL && profundidad>=0 && isValidProfundidad(profundidad))
	{
		this->profundidad=profundidad;
		retorno = 0;
	}
	return retorno;
}

int articulo_getProfundidad(Articulo* this,float* auxProfundidad)
{
	int retorno = -1;

	if(this != NULL)
	{
		*auxProfundidad = this->profundidad;
		retorno = 0;
	}
	return retorno;
}

int isValidProfundidad(float profundidad)
{
  {
    int retorno=-1;
    if(profundidad >= 0 && profundidad <=1219)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}

//--------------------------ID---------------------

int articulo_setIdArticulo(Articulo* this, int idArticulo)
{
	int retorno = -1;
	if(this != NULL && isValidId(idArticulo) )
	{
		this->idArticulo = idArticulo;
		retorno = 0;
	}
	return retorno;
}

int articulo_getIdAriculo(Articulo* this, int* auxIdArticulo)
{
	int retorno = -1;

	if(this != NULL)
	{
		*auxIdArticulo=this->idArticulo;
		retorno = 0;
	}
	return retorno;
}

int isValidId(int idArticulo)
{
  {
    int retorno=-1;
    if(idArticulo > 0)
      {
        retorno = 1;
      }
    else
      {
        retorno =0;
      }
      return retorno;
  }
}
//--------------------------------ABMC----------------------------------------------------------------------

int articulo_parser(char nombreArchivo[],Dictionary* articulos,int* pIdMaxEncontrado)
{
	FILE* pFile;
	char auxCodigoArticulo[LONG_STRING];
	char auxDescripcion[LONG_STRING];
	char auxPais[SIZE_COUNTRY];
	char auxValorFob[LONG_STRING];
	char auxPeso[LONG_STRING];
	char auxAncho[LONG_STRING];
	char auxAltura[LONG_STRING];
	char auxProfundidad[LONG_STRING];
	char auxPosicionArancelaria[LONG_STRING];
	char auxIdArticulo[LONG_STRING];
	float valorFob;
	float peso;
	float ancho;
	float altura;
	float profundidad;
	int idArticulo;

	Articulo* pA;
	int indice=-1;
	int idMax;
	pFile = fopen(nombreArchivo,"r");
	if(pFile!=NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxCodigoArticulo,auxDescripcion,
			          auxPais,auxValorFob,auxPeso,auxAncho,auxAltura,auxProfundidad,auxPosicionArancelaria,auxIdArticulo)==10)
			{
	      /* if(utn_esDecimal(auxValorFob,99999)==1 &&	utn_esDecimal(auxPeso,99999)==1 && utn_esDecimal(auxAncho,235)==1 &&
              utn_esDecimal(auxAltura,239)==1 && utn_esDecimal(auxProfundidad,1219)==1 && utn_esNumerica(auxIdArticulo,999)==1) {*/
					valorFob=atof(auxValorFob);
					peso=atof(auxPeso);
					ancho=atof(auxAncho);
					altura=atof(auxAltura);
					profundidad=atof(auxProfundidad);
					idArticulo=atoi(auxIdArticulo);
					pA = articulo_newParam(auxCodigoArticulo,auxDescripcion,auxPais,valorFob,peso,ancho,altura,profundidad,auxPosicionArancelaria,idArticulo);
					if(pA!=NULL)
					{
						dict_insert(articulos,auxCodigoArticulo,pA);
						if(indice==0 || idArticulo>idMax)
						{
							idMax = idArticulo;
						}
						indice++;
				}
			//}
			}
			else
			{
	        printf("\nError en el parseo de datos de articulos.\n");
			}
		}
		while(feof(pFile)==0);
		fclose(pFile);
		*pIdMaxEncontrado = idMax; // lo escribo en la var externa
	}
	return indice; // devuelve cantidad leidos
}






static int articulo_validarPais(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
    if ((cadena[i] != ' ') && ((cadena[i] < 'A' || cadena[i] > 'z') || (cadena[i] < 'a' && cadena[i] > 'Z')) )
      {
    retorno = 0;
    break;
      }
    else{
        if((i == 0 || cadena[i - 1] == ' '))
        {
            if(cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                continue;
            }
            else if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
              cadena[i]=toupper(cadena[i]);
            }
        }
        else if((i != 0 || cadena[i - 1] != ' '))
        {
          if((cadena[i] >= 'a' && cadena[i] <= 'z') && cadena[i-1] != ' ')
          {
            continue;
          }
        else if(cadena[i] >= 'A' && cadena[i] <= 'Z')
          {
            cadena[i]=tolower(cadena[i]);
          }
        }
    }
    }
  }
  return retorno;
}

int articulo_print(Articulo* pArticulo)
{
    int retorno=-1;
    char codigoArticulo[LONG_STRING];
    char descripcion[LONG_STRING];
    char pais[SIZE_COUNTRY];
    float valorFob;
    float peso;
    float ancho;
    float altura;
    float profundidad;
    char posicionArancelaria[LONG_STRING];

    if(pArticulo != NULL  &&
        articulo_getCodigoArticulo(pArticulo,codigoArticulo)==0&&
        articulo_getDescripcion(pArticulo,descripcion)==0&&
        articulo_getPais(pArticulo,pais)==0&&
        articulo_getValorFob(pArticulo,&valorFob)==0&&
        articulo_getPeso(pArticulo,&peso)==0&&
        articulo_getAncho(pArticulo,&ancho)==0&&
        articulo_getAltura(pArticulo,&altura)==0&&
        articulo_getProfundidad(pArticulo,&profundidad)==0 &&
        articulo_getPosicionArancelaria (pArticulo,posicionArancelaria)==0)
    {
        retorno=1;
        printf("%8s    %24s    %12s   %8.2f    %8.2f    %6.2f    %6.2f    %7.2f    %12s\n",
               codigoArticulo,descripcion,pais,valorFob,peso,ancho,altura,profundidad,posicionArancelaria);
    }
    return retorno;
}

/*//REEMPLAZADA EN CONTROLLER
int articulos_alta(Dictionary* articulos)
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
	char auxId[10];
	Articulo* pA;

	if(articulos!=NULL)
	  {
	  printf("\nSe va a dar de alta un nuevo articulo.\n");
    if(utn_getStringWithNumbers("\nIngrese el CODIGO del articulo:","ERROR! Codigo invalido.",codigoArticulo,LONG_STRING,3)==0 &&
        utn_getText(descripcion,"\nIngrese La descripción del producto:","ERROR! Descripcion invalida.",255,3)==0 &&
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
        sprintf(auxId,"%d",idArticulo);
        if(pA!=NULL)
        {
          dict_insert(articulos, auxId, pA);
          ret=1;
          printf("\nSe dio de alta correctamente el articulo.\n");
        }
        else
        {
          articulo_delete(pA);
          ret =0;
        }
      }
	  }
	return ret;
}
*/
int articulo_isAlphanumeric(char *pCadena){
    int output = 1;
    if(pCadena !=NULL){
        for(int x = 0; pCadena[x] !='\0'; x++){
            if(
               ((pCadena[x] < '0' || pCadena[x] > 'z')
            || (pCadena[x] > '9' && pCadena[x] < 'A')
            || (pCadena[x] > 'Z' && pCadena[x] < 'a'))
            && (pCadena[x] != '_' && pCadena[x] != '.')){
                output = -1;
                break;
            }
        }
    }
    return output;
}


