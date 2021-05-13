/*
 * utn.h
 *
 *  Created on: 10 may. 2021
 *      Author: marti
 */

#ifndef UTN_H_
#define UTN_H_


#define ARRAY_LEN_STRING 4096
#define ARRAY_LEN_INT 64
#define ARRAY_LEN_NOMBRE 30
#define ARRAY_LEN_APELLIDO 60
#define ARRAY_LEN_CHAR 2
#define ARRAY_LEN_DNI 11
#define ARRAY_LEN_CUIT 14
#define ARRAY_LEN_TEL 20


int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, int reintentos);
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getApellido(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCaracter(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCuit(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getTelefono(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCaracterSN(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);

#endif /* UTN_H_ */
