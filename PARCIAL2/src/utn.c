/*
 * utn.c
 *
 *  Created on: 16 mar. 2021
 *      Author: julio Méndez
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"



#define SIZE_DNI 9
#define SIZE_CUIT 12
#define SIZE_TELEFONO 10
#define SIZE_CELULAR 13
#define SIZE_EMAIL 64
#define SIZE_SITIO_WEB 100
#define SIZE_TARJETA_CREDITO 20
#define SIZE_DIRECCION 64
#define SIZE_DIRECCION_ALTURA 10


int myGets(char* string, int limite)
{
  int retorno = -1;
  char bufferString[4096];

  if(string != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
  {
    __fpurge(stdin);
    if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
    {
        bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
    }
    if(strnlen(bufferString,sizeof(bufferString)) <= limite)
        {
            strncpy(string,bufferString,limite);
            retorno=0;
        }
  }
  return retorno;
}

int utn_getInt(int* pResultado)
{
  int retorno = -1;
  char bufferString[64];

  if( pResultado != NULL &&
      myGets(bufferString, sizeof(bufferString)) == 0 &&
      utn_esNumerica(bufferString, sizeof(bufferString)))
    {
      *pResultado = atoi(bufferString);
      retorno = 0;
    }
  return retorno;
}

int getFloat(float* pResultado)
{
  int retorno = -1;
  char buffer[64];

  if(pResultado != NULL)
  {
    if(myGets(buffer, sizeof(buffer)) == 0 && utn_esDecimal(buffer,sizeof(buffer)))
    {
      *pResultado = atof(buffer);
      retorno = 0;
    }
  }

  return retorno;
}

int utn_esNumerica(char* cadena, int limite)
{
  int retorno = -1;
  int i = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 0;
    if(cadena[0] == '-' || cadena[0] == '+')
    {
        i=1;
    }
    for( ;i<limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] >= '0' && cadena[i] <= '9')
      {
        retorno = 1;
      }
      else if(cadena[i] < '0' || cadena[i] > '9')
        {
          retorno = 0;
          break;
        }
    }
  }

  return retorno;
}

int utn_esDecimal(char* cadena, int limite)
{
  int retorno = -1;
  int punto = 1;
  int signo = 1;
  int i = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 0;
    for( ;i<limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] >= '0' && cadena[i] <= '9')
      {
        if(i == 0 && cadena[i] == '-' && signo)
        {
          signo = 0;
        }
        if(cadena[i] == '.' && punto)
        {
          punto = 0;
        }
        retorno = 1;
      }
    }
  }

  return retorno;
}

int utn_getNumero(int* pNumero, const char* mensaje, const char* mensajeError, int min, int max,int reintentos)
{
  int retorno = -1;
  int bufferInt;

  if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && min <= max)
  {
    do
    {
      printf(mensaje);
      __fpurge(stdin);
      if(utn_getInt(&bufferInt) == 0 &&
         bufferInt >= min &&
         bufferInt <= max)
        {
          retorno = 1;
          *pNumero = bufferInt;
          break;
        }
        else
        {
            printf(mensajeError);
            reintentos--;
      }
    }while(reintentos);
    if(reintentos==0)
    {
    printf("¡No hay mas intentos, vaya a tomarle el pelo al codigo de su abuela!\n");
    retorno = -2;
    }
  }
  else
  {
    printf("hay parametros invalidos en la funcion");
  }
  return retorno;
}

int utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, float min, float max, int reintentos)
{
  int retorno = -1;
  float buffer;

  if(pNumero != NULL && pTexto != NULL && mensajeError != NULL && min <= max)
  {
    while(reintentos)
    {
      printf(pTexto);
      __fpurge(stdin);
      if(getFloat(&buffer) == 0&&
          buffer >= min &&
          buffer <= max)
      {
        retorno = 0;
        *pNumero = buffer;
        break;
      }
      else
      {
        printf(mensajeError);
        reintentos--;
      }
    }
    if(reintentos==0)
    {
    printf("¡vaya a tomarle el pelo al codigo de su abuela!");
    }
  }
  else
  {
    printf("hay parametros invalidos en la funcion");
  }

  return retorno;
}

int utn_sumar(float numeroA, float numeroB, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = numeroA + numeroB;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

int utn_restar(float numeroA, float numeroB, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = numeroA - numeroB;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    if(divisor != 0)
    {
      resultado = dividendo / divisor;
      retorno = 0;
    }
    else
    {
      printf(pDivisionPorCero);
    }
  }

  *pResultado = resultado;
  return retorno;
}

int utn_multiplicar(float dividendo, float divisor, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = dividendo * divisor;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

int utn_factorial(float numero, float* pResultado)
{
  int retorno = -1;
  int acumulador = 1;

  if(pResultado != NULL)
  {
    if(numero <0)
    {
        retorno= -2;
        *pResultado=0;
    }
    else
    {
      if(numero==0)
      {
          *pResultado=1;
          retorno =0;
      }
      else
      {
        for(int i = 1; i <= numero; i++)
        {
          acumulador *= i;
        }
      }
      *pResultado = acumulador;
      retorno = 0;
    }
  }

  return retorno;
}

int utn_getText(char* pResultado, char* pMensaje, char* mensajeError, int limite, int reintentos)
{
  int retorno = -1;
  char buffer[limite];

  if(pResultado != NULL && pMensaje != NULL && mensajeError != NULL && limite >= 0 && reintentos >=0)
  {
    do
    {
      printf(pMensaje);
      __fpurge(stdin);
        if(myGets(buffer,limite)==0 &&
            utn_esTexto(buffer)==1)
        {
          retorno = 0;
          strncpy(pResultado, buffer,limite);
          break;
        }
        else
          {
            printf(mensajeError);
            reintentos--;
          }
    }while(reintentos);
  }
  return retorno;
}
/////////////////////////////////////////////
///
int utn_GetChar(char* pResultado,char* pMensaje,char* mensajeError,int reintentos){
    int retorno=-1;
    char letra[2];

    do{
        printf("%s",pMensaje);
        if(!myGets(letra, 1) &&esLetra(letra)==0){
            *pResultado=*letra;
            retorno=0;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }while(reintentos >= 0);

    return retorno;
}

int esLetra(char* letra){
    int retorno=-1;
    if((*letra >= 'a' && *letra <= 'z') || (*letra >= 'A' && *letra <= 'Z')){
        retorno=0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////////

int utn_getCadenaMayusculas(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[2024];

  if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && getMayusculas(bufferString, sizeof(bufferString)) == 0)
    {
      strncpy(pString, bufferString, limite);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getCadenaMinusculas(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[2024];

  if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && getMinusculas(bufferString, sizeof(bufferString)) == 0)
    {
      strncpy(pString, bufferString, limite);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}
int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos)
{
  int retorno = -1;
  char buffer[limite];

  if(pNombre != NULL && pMensaje != NULL && pMensajeError != NULL && limite >= 0 && reintentos >=0)
  {
    do
    {
      printf(pMensaje);
      __fpurge(stdin);
      if(myGets(buffer, sizeof(buffer)) == 0 && validarNombre(buffer, sizeof(buffer)) == 1)
          {
            strncpy(pNombre, buffer, limite);
            retorno = 0;
            break;
          }
        else
          {
            printf(pMensajeError);
            reintentos--;
          }
    }while(reintentos);
  }
  return retorno;
}

int utn_getDni(char* pDni, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[SIZE_DNI];

  if(pDni != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarDni(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pDni, bufferString, SIZE_DNI);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError, int limite, int reintentos)
{
  int retorno = -1;
  char bufferString[limite];

  if(pCuit != NULL && pMensaje != NULL && pMensajeError != NULL)
      {
        do
          {
          printf("%s", pMensaje);
          __fpurge(stdin);
          if(myGets(bufferString, sizeof(bufferString)) == 0 && validarCuit(bufferString, sizeof(bufferString)) == 1)
          {
            strncpy(pCuit, bufferString, limite);
            retorno = 0;
            break;
          }
          else
          {
            printf("%s", pMensajeError);
          }
        }
        while(reintentos);
      }

  return retorno;
}

int utn_getEdad(int* pEdad, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  int bufferInt;

  if(pEdad != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(utn_getInt(&bufferInt) == 0 && validarEdad(&bufferInt))
    {
      *pEdad = bufferInt;
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getPrecio(float* pPrecio, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  float bufferLongInt;

  if(pPrecio != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(getFloat(&bufferLongInt) == 0 && validarPrecio(&bufferLongInt) == 1)
    {
      *pPrecio = bufferLongInt;
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getTelefono(char* pTelefono, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[SIZE_TELEFONO];

  if(pTelefono != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarTelefono(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pTelefono, bufferString, SIZE_TELEFONO);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getCelular(char* pCelular, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[SIZE_CELULAR];

  if(pCelular != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarCelular(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pCelular, bufferString, SIZE_CELULAR);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getEmail(char* pEmail, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[SIZE_EMAIL];

  if(pEmail != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarEmail(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pEmail, bufferString, SIZE_EMAIL);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getSitioWeb(char* pSitioWeb, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[SIZE_SITIO_WEB];

  if(pSitioWeb != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarSitioWeb(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pSitioWeb, bufferString, SIZE_SITIO_WEB);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getTarjetaCredito(char* pTarjeta, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[SIZE_TARJETA_CREDITO];

  if(pTarjeta != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarTarjetaCredito(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pTarjeta, bufferString, SIZE_TARJETA_CREDITO);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int utn_getDireccion(char* pDireccion, char* pMensaje, char* pMensajeAltura, char* pMensajeError, char* pMensajeErrorAltura)
{
  int retorno = -1;
  char bufferString[SIZE_DIRECCION];
  char bufferString2[SIZE_DIRECCION_ALTURA];

  if(pDireccion != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarDireccion(bufferString, sizeof(bufferString)) == 1)
    {
      printf("%s", pMensajeAltura);
      __fpurge(stdin);
      if(myGets(bufferString2, sizeof(bufferString2)) == 0 && validarDireccionAltura(bufferString2, sizeof(bufferString2)) == 1)
      {
        strcat(bufferString, " ");
        strcat(bufferString, bufferString2);
        strncpy(pDireccion, bufferString, SIZE_DIRECCION);
        retorno = 0;
      }
      else
      {
        printf("%s", pMensajeErrorAltura);
      }
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int getMayusculas(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL)
  {
    for(int i = 0; i < limite; i++)
    {
      cadena[i] = toupper(cadena[i]);
    }
    retorno = 0;
  }

  return retorno;
}

int getMinusculas(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL)
  {
    for(int i = 0; i < limite; i++)
    {
      cadena[i] = tolower(cadena[i]);
    }
    retorno = 0;
  }

  return retorno;
}

int validarDecimal(char* cadena, int limite)
{
  int retorno = -1;
  int punto = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
      {
        continue;
      }
      if(punto == 0 && cadena[i] == '.')
      {
        punto = 1;
        continue;
      }
      if(cadena[i] < '0' || cadena[i] > '9' ||
      (punto == 1 && cadena[i] == '.'))
      {
        retorno = 0;
        break;
      }
    }
  }

  return retorno;
}

int validarNombre(char* cadena, int limite)
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

int validarDni(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] < '0' || cadena[i] > '9')
      {
        retorno = 0;
        break;
      }
    }
    if(strlen(cadena) != 8)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarCuit(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] < '0' || cadena[i] > '9')
      {
        retorno = 0;
        break;
      }
    }
    if(strlen(cadena) != 11)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarEdad(int* pNumero)
{
  int retorno = -1;

  if(pNumero != NULL)
  {
    retorno = 1;
    if(*pNumero < 1 || *pNumero > 122)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarPrecio(float* pResultado)
{
  int retorno = -1;

  if(pResultado != NULL)
  {
    retorno = 1;
    if(*pResultado <= 0)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarTelefono(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(cadena[4] == '-')
      {
        continue;
      }
      if(cadena[i] < '0' || cadena[i] > '9')
      {
        retorno = 0;
        break;
      }
    }
    if(cadena[4] == '-' && strlen(cadena) == 9)
    {
      retorno = 1;
    }
    else if(strlen(cadena) != 8)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarCelular(char* cadena, int limite)
{
  int retorno = -1;
  int signo = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(cadena[2] == '-')
      {
        signo = 1;
        continue;
      }
      if(signo && cadena[7] == '-')
      {
        continue;
      }
      if(cadena[i] < '0' || cadena[i] > '9')
      {
        retorno = 0;
        break;
      }
    }
    if(cadena[2] == '-' && cadena[7] == '-' && strlen(cadena) == 12)
    {
      retorno = 1;
    }
    else if(strlen(cadena) != 10)
    {
      retorno = 0;
    }
  }

  return retorno;
}


int validarEmail(char* cadena, int limite)
{
  int retorno = -1;
  int i;
  int arroba = 0;
  int punto = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9'))
      {
        retorno = 1;
      }
      else if(i > 0 && arroba == 0 && cadena[i] == '@')
      {
        arroba = 1;
        punto = 0;
      }
      else if(i > 0 && i < strlen(cadena) - 1 && cadena[i] == '.' && cadena[i - 1] != '.' && cadena[i - 1] != '@' && cadena[i - 1] != '-' && cadena[i - 1] != '_')
      {
        punto = 1;
        retorno = 1;
      }
      else if((cadena[i] == '-' && cadena[i - 1] != '-' && cadena[i - 1] != '_' && cadena[i - 1] != '.') || (cadena[i] == '_' && cadena[i - 1] != '_' && cadena[i - 1] != '-' && cadena[i - 1] != '.'))
      {
        retorno = 1;
      }
      else
      {
        retorno = 0;
        break;
      }
    }
    if(arroba == 0 || punto == 0 || cadena[i - 1] == '.')
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarSitioWeb(char* cadena, int limite)
{
  int retorno = -1;
  int i;
  int punto = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == '-')
      {
        retorno = 1;
      }
      else if(i == 3 && punto == 0 && cadena[i] == '.')
      {
        punto = 1;
        retorno = 1;
      }
      else if(i == strlen(cadena) - 4 && punto == 1 && cadena[i] == '.')
      {
        punto = 2;
        retorno = 1;
      }
      else
      {
        retorno = 0;
        break;
      }
    }
    if(punto == 0 || cadena[0] != 'w' || cadena[1] != 'w' || cadena[2] != 'w')
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarTarjetaCredito(char* cadena, int limite)
{
  int retorno = -1;
  int signo = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(cadena[4] == '-')
      {
        signo = 1;
        continue;
      }
      if(signo && cadena[9] == '-')
      {
        signo = 2;
        continue;
      }
      if(signo == 2 && cadena[14] == '-')
      {
        signo = 3;
        continue;
      }
      if(cadena[i] < '0' || cadena[i] > '9')
      {
        retorno = 0;
        break;
      }
    }
    if(cadena[4] == '-' && cadena[9] == '-' && cadena[14] && strlen(cadena) == 19)
    {
      retorno = 1;
    }
    else if(strlen(cadena) != 16)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int validarDireccion(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if((i == 0 || cadena[i - 1] == ' ') && cadena[i] >= 'A' && cadena[i] <= 'Z')
      {
        continue;
      }
      else if((cadena[i] >= 'a' && cadena[i] <= 'z') || cadena[i] == ' ')
      {
        continue;
      }
      else
      {
        retorno = 0;
        break;
      }
    }
  }

  return retorno;
}

int validarDireccionAltura(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] < '0' || cadena[i] > '9')
      {
        retorno = 0;
        break;
      }
    }
    if(strlen(cadena) < 1 || strlen(cadena) > 4)
    {
      retorno = 0;
    }
  }

  return retorno;
}

int utn_getContinue(char* pRespuesta,char* pMensaje,char* mensajeError,int reintentos){
    int retorno=-1;
    char letra[2];

    do{
        printf("%s[Y/N]",pMensaje);
        if((!myGets(letra, 1) &&esLetra(letra)==0)&&
            (!strncmp(letra,"y",1) || !strncmp(letra,"Y",1) || !strncmp(letra,"n",1) || !strncmp(letra,"N",1))){
            *pRespuesta=*letra;
            retorno=0;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }while(reintentos >= 0);

    return retorno;
}

int utn_esUnsignedEnteroChar(char* string)
{
  int retorno=-1;
  int i;
  if(string != NULL)
    {
      for( i=0;i<sizeof(string) && string[i] != '\0'; i++)
          {
            if(string[i] >= '0' && string[i] <= '9')
            {
              retorno = 1;
            }
            else if(string[i] < '0' || string[i] > '9')
              {
                retorno = 0;
                break;
              }
          }
    }
return retorno;
}


int utn_isAlphanumeric(char *pCadena){
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


int utn_isNumeric(char *pCadena){
    int output = 1;
    if(pCadena !=NULL){
        for(int x = 0; pCadena[x] !='\0'; x++){
            if(pCadena[x] < '0' || pCadena[x] > '9')
            {
                output = 0;
                break;
            }
        }
    }
    return output;
}


int utn_getStringWithNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos) {
    int output = -1;
    if (msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0) {
        do {
            printf("%s", msg);
            if ((myGets(pCadena, limite)==0) && utn_isAlphanumeric(pCadena)==1) {
                for(int x = 0; x<limite; x++){
                    if(esLetra(pCadena)==0)
                    {
                    pCadena[x] = toupper(pCadena[x]);
                    }
                }
                output = 0;
                break;
            } else {
                reintentos--;
                if (reintentos > 0) {
                    printf("%s: %d\n", msgError, reintentos);
                }
            }
        } while (reintentos > 0);
    }
    return output;
}


int utn_getStringWithOnlyNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos) {
    int output = -1;
    if (msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0) {
        do {
            printf("%s", msg);
            if (!(myGets(pCadena, limite)) && utn_isNumeric(pCadena)) {
                for(int x = 0; x<limite; x++){
                    pCadena[x] = toupper(pCadena[x]);
                }
                output = 0;
            } else {
                reintentos--;
                if (reintentos > 0) {
                    printf("%s: %d\n", msgError, reintentos);
                }
            }
        } while (output != 0 && reintentos > 0);
    }
    return output;
}


int utn_esTexto(char* str)
{
  int retorno = -1;
  int i=0;
  if(str != NULL)
  {
    for(i=0; (str[i] != '\0'); i++)
    {
      if((str[i] == ',') ||((str[i] != ' ') && (str[i] < '!' || str[i] > '~')))
        {
          retorno = 0;
        }
      else
        {
          retorno=1;
        }
    }
  }
  return retorno;
}
