/*
 * Reparacion.c
 *
 *  Created on: 12 may. 2021
 *      Author: marti
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "Reparacion.h"
#include "Electrodomestico.h"
#include "utn.h"


/*
 * brief Inicializa todas las posiciones del array como vacias
 * param array Array que se desea inicializar
 * param len Tamano del array
 * return Retorna 0 si salio OK y -1 si no
 */
int rep_inicializar(Reparacion*pArray, int len)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			pArray[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}


/*--------------------------------------------------------------------------------*/

/** \brief Recibe un array de estructuras y busca la primera posicion libre
* \param pArray Array de estructuras Alumnos
* \param len Longitud array
* \param id int puntero
* \return Retorna de la posición del índice de alumnos o -1 No retorna nada.
*/
int rep_lugarVacio(Reparacion* pArray, int len, int* id)
{
    int retorno=-1;
    int i;
    if(pArray!= NULL && len>=0 && id!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(pArray[i].isEmpty==1)
            {
                retorno=0;
                *id=i;
                break;
            }
        }
    }
    return retorno;
}

/*--------------------------------------------------------------------------------*/

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de servicios
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos un servicio guardado
 */

int rep_arrayVacio(Reparacion *pRepa, int len)
{
	int retorno = 1;
	int i;

	if (pRepa != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pRepa[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*--------------------------------------------------------------------------------*/

/** \brief Encontrar un orquestas por Id en devuelve la posición del índice.
* \param pArray Orquestas
* \param len int
* \param posicion int valor buscado
* \param id int Puntero.
* \return Retorno de la posición del índice de alumnos or (-1) si[Longitud no válida o puntero NULL recibido o alumno no encontrado]
*
*/

int rep_encontrarPorId(Reparacion* pArray,int len, int posicion, int* id)
{
    int retorno = -1;
    int i;
    if(pArray != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
        	if(pArray[i].isEmpty==1)
        		continue;
        	else if(pArray[i].id == posicion)
            {
                retorno = 0;
                *id=i;
                break;
            }
        }
    }
    return retorno;
}

/*--------------------------------------------------------------------------------*/

/*
 * brief Recibe una estructura e imprime los datos guardados en sus campos
 * param pRepo Estructura que se desea imprimir
 * param pElectro Array de electrodomesticos
 * param lenEle Tamaño del array de electrodomesticos
 * param pServ Array de servicios
 * param lenSer Tamaño del array de servicios
 */

void rep_print(Reparacion pRepa, Electrodomestico *pElectro,int lenEle, Servicio *pServ, int lenSer)
{

	printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d/%d/%d", pRepa.id,pRepa.serie, pRepa.idServicio,
			pRepa.fecha.dia, pRepa.fecha.mes, pRepa.fecha.anio);
}




/*--------------------------------------------------------------------------------*/

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param pRepa Array que se desea imprimir
 * param pElectro Array de electrodomesticos
 * param lenEle Tamaño del array de electrodomesticos
 * param pServ Array de servicios
 * param lenSer Tamaño del array de servicios
 */

void rep_printArray(Reparacion *pRepa, int lenRep,Electrodomestico *pElectro, int lenEle, Servicio *pServ,int lenSer)
{
	int i;

	if (pRepa != NULL && lenRep > 0 && pElectro != NULL && lenEle > 0&& pServ != NULL && lenSer > 0)
	{
		printf("\nId\t\tSerie\t\tidServicio\t\tFecha");
		for (i = 0; i < lenRep; i++)
		{
			if (pRepa[i].isEmpty == 0)
			{
				rep_print(pRepa[i], pElectro, lenEle, pServ, lenSer);

			}
		}
		printf("\n");
	}
}

/*--------------------------------------------------------------------------------*/

int rep_alta(Reparacion *pRepa, int lenRep, Servicio *pServ,int lenSer, Electrodomestico *pElectro, int lenEle,
		Marca *pMarca, int lenMar, int *contadorId)
{
	int retorno = -1;
	int pos;

	if (pRepa != NULL && lenRep > 0 && contadorId != NULL)
	{
		//if (buscarLibre(arrayRepa, lenRepa, &posicion) == -1)
		if(rep_lugarVacio(pRepa, lenRep, &pos) == -1)
		{
			printf("\nNo hay lugares vacios.");
		}
		else
		{
			(*contadorId)++;
			pRepa[pos].id = *contadorId; //El id coincide con el indice y es autoincremental

			ele_printArray(pElectro, lenEle, pMarca, lenMar);

			utn_getNumero(&pRepa[pos].serie,"\nNumero de serie del electrodomestico: ","\nError",0,100000, 2);

			ser_arrayPrint(pServ, lenSer);

			utn_getNumero(&pRepa[pos].idServicio,"\nId del servicio: ", "\nError",20000, 20003,2);

			utn_getNumero(&pRepa[pos].fecha.dia, "\nDia: ", "\nError",1,31,2);

			utn_getNumero(&pRepa[pos].fecha.mes, "\nMes: ", "\nError",1,12,2);

			utn_getNumero(&pRepa[pos].fecha.anio, "\nAnio: ", "\nError",1900,2021,2);

			pRepa[pos].isEmpty = 0;

			printf("\nId reparacion\t\tSerie electro\t\tId servicio\t\tFecha");

			rep_print(pRepa[pos], pElectro, lenEle, pServ, lenSer);
			retorno = 0;
		}
	}

	return retorno;
}

int rep_harcodear(Reparacion *pRepo, int len, int cantidad)
{
	int contador = 0;
	int i;

	if (pRepo != NULL && len > 0 && cantidad > 0)
	{
		Reparacion arrayAuxiliar[] = { { 0, 0, 20000, { 10, 12, 2019 }, 0 }, {1, 1, 20001, { 11, 2, 2017 }, 0 }, { 2, 2, 20002,
				{ 1, 1, 2016 }, 0 }, { 3, 3, 20003, { 8, 7, 2020 }, 0 }, { 4, 4,20004, { 18, 2, 2018 }, 0 } };

		if (cantidad <= len && cantidad <= 5)
		{
			for (i = 0; i < len; i++) {
				pRepo[i] = arrayAuxiliar[i]; //Puede asignar asi porque ambas estructuras son identicas. Guardo toda la informacion que tengo en mi array auxiliar adentro de mi array verdadero que se pasa por parametro
				contador++;
			}
		}
	}
	return contador;
}


/*-------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/

/*
 * brief Recibe una estructura e imprime los datos de sus campos
 * param servicio Estructura a imprimir
 */
void ser_print(Servicio pServ)
{

	printf("\n%d\t\t%s\t\t%.2f", pServ.id, pServ.descripcion,pServ.precio);
}

/*-------------------------------------------------------------------------------------------*/

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param array Array de servicios a imprimir
 * param len Tamaño del array de servicios
 */
void ser_arrayPrint(Servicio *pServ, int len)
{
	int i;

	if (pServ != NULL && len > 0)
	{
		for (i = 0; i < len; i++) {
			ser_print(pServ[i]);
		}
		printf("\n");
	}
}

/*-------------------------------------------------------------------------------------------*/

/*
 * brief Recibe el numero de id del servicio y devuelve su descripcion
 * param idServicio Numero de id del servicio
 * param pServ Array de servicios
 * param len Tamaño del array de servicios
 * param descripcion Puntero al espacio de memoria donde se va a guardar la descripcion del servicio
 * return Retorna 0 si se cargo la descripcion y -1 si no
 */

int ser_descripcionPorId(int idServicio, Servicio *pServ, int len,char *descripcion)
{
	int retorno = -1;
	int i;

	if (pServ != NULL && len > 0 && descripcion != NULL) {
		for (i = 0; i < len; i++)
		{
			if (pServ[i].id == idServicio)
			{
				strncpy(descripcion, pServ[i].descripcion, LEN_SERVICIO);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*-------------------------------------------------------------------------------------------*/

/*
 * brief Recibe la descripcion de un servicio y devuelve su numero de id
 * param descripcion Descripcion del servicio
 * param pServ Array de servicios
 * param len Tamaño del array de servicios
 * param idServicio Puntero al espacio de memoria donde se guardara el id del servicio
 * return Retorna 0 si se cargo el id y -1 si no
 */

int ser_idPorDescripcion(char *descripcion, Servicio *pServ, int len,int *idServicio)
{
	int retorno = -1;
	int i;

	if (pServ != NULL && len > 0 && descripcion != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (strcmp(pServ[i].descripcion, descripcion) == 0)
			{
				*idServicio = pServ[i].id;
				retorno = 0;
				break; //Breakeo para que no siga corriendo el for porque ya encontre el id
			}
		}
	}

	return retorno;
}

/*-------------------------------------------------------------------------------------------*/

int ser_arrayVacio(Servicio *pServ, int len)
{
	int retorno = 1;
	int i;

	if (pServ != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pServ[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

