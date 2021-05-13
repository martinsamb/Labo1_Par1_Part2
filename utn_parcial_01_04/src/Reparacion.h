/*
 * Reparacion.h
 *
 *  Created on: 12 may. 2021
 *      Author: marti
 */

#include "Electrodomestico.h"

#ifndef REPARACION_H_
#define REPARACION_H_

#define LEN_SERVICIO 25

typedef struct
{
	int dia;
	int mes;
	int anio;

}Fecha;

typedef struct
{
	int id;//autoincremental
	int serie; //debe existir - Validar
	int idServicio;//debe existir - Validar
	Fecha fecha; //Validar día-mes-año
	int isEmpty;

}Reparacion;

typedef struct
{
	int id;//comienza en 20000
	char descripcion[LEN_SERVICIO]; //máximo 25 caracteres
	float precio;
	int isEmpty;

}Servicio;




#endif /* REPARACION_H_ */

//-------------------------------------------------------------------------------------------*/
int rep_inicializar(Reparacion*pArray, int len);

int rep_lugarVacio(Reparacion* pArray, int len, int* id);

int rep_arrayVacio(Reparacion *pRepa, int len);

int rep_encontrarPorId(Reparacion* pArray,int len, int posicion, int* id);

void rep_print(Reparacion pRepa, Electrodomestico *pElectro,int lenEle, Servicio *pServ, int lenSer);

void rep_printArray(Reparacion *pRepa, int lenRep,Electrodomestico *pElectro, int lenEle, Servicio *pServ,int lenSer);

int rep_alta(Reparacion *pRepa, int lenRep, Servicio *pServ,int lenSer, Electrodomestico *pElectro, int lenEle,
		Marca *pMarca, int lenMar, int *contadorId);

int rep_harcodear(Reparacion *pRepo, int len, int cantidad);

/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

void ser_print(Servicio pServ);

void ser_arrayPrint(Servicio *pServ, int len);

int ser_descripcionPorId(int idServicio, Servicio *pServ, int len,char *descripcion);

int ser_idPorDescripcion(char *descripcion, Servicio *pServ, int len,int *idServicio);

int ser_arrayVacio(Servicio *pServ, int len);
