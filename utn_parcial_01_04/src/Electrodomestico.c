/*
 * Electrodomestico.c
 *
 *  Created on: 12 may. 2021
 *      Author: marti
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
#include "Electrodomestico.h"

/*
 * brief Inicializa todas las posiciones del array como vacias
 * param array Array que se desea inicializar
 * param len Tamano del array
 * return Retorna 0 si salio OK y -1 si no
 */
int ele_inicializar(Electrodomestico*pArray, int len)
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


//-----------------------------------------------------------------------------------------

/** \brief Recibe un array de estructuras y busca la primera posicion libre
* \param pArray Array de estructuras Alumnos
* \param len Longitud array
* \param id int puntero
* \return Retorna de la posición del índice de alumnos o -1 No retorna nada.
*/
int ele_lugarVacio(Electrodomestico* pArray, int len, int* id)
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

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param list Array de electrodomesticos
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos un electrodomestico guardado
 */
int ele_arrayVacio(Electrodomestico *pArray, int len)
{
	int retorno = 1;
	int i;

	if (pArray != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



//-----------------------------------------------------------------------------------------

/** \brief Encontrar un orquestas por Id en devuelve la posición del índice.
* \param pArray Orquestas
* \param len int
* \param posicion int valor buscado
* \param id int Puntero.
* \return Retorno de la posición del índice de alumnos or (-1) si[Longitud no válida o puntero NULL recibido o alumno no encontrado]
*
*/

int ele_encontrarPorId(Electrodomestico* pArray,int len, int posicion, int* id)
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


//-----------------------------------------------------------------------------------------

/*
 * brief Recibe una estructura e imprime los datos guardados en sus campos
 * param pElectro Estructura que se desea imprimir
 * param pMarca Array de marcas
 * param len Tamaño del array de marcas
 */
void ele_print(Electrodomestico pElectro, Marca *pMarca, int len)
{
	char descripcionMarca[21];
	if (pMarca != NULL && len > 0 && (mar_cargarDescripcionPorId(pElectro.idMarca, pMarca, len, descripcionMarca)==0))

	{

		printf("\n%d\t\t%d\t\t%d\t\t%s\t\t%d", pElectro.id,pElectro.serie, pElectro.idMarca,descripcionMarca, pElectro.modelo);
	}
}
//---------------------------------------------------------------------------------------------

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param pElectro Array de electrodomesticos
 * param lenEle Tamaño del array de electrodomesticos
 * param pMarca Array de marcas
 * param lenMar Tamaño del array de marcas
 */
void ele_printArray(Electrodomestico *pElectro, int lenEle,Marca *pMarca, int lenMar)
{
	int i;

	if (pElectro != NULL && lenEle > 0)
	{
		printf("\nId\t\tSerie\t\tIdMarca\tMarca\t\tModelo");
		for (i = 0; i < lenEle; i++)
		{
			if (pElectro[i].isEmpty == 0)
			{
				ele_print(pElectro[i], pMarca, lenMar);
			}
		}
		printf("\n");
	}
}
//-----------------------------------------------------------------------------------------------/*
/*
* brief Recorre el array de electrodomesticos y devuelve el electrodomestico que su serie coincida con la serie pasado por parametro
* param pArray Array de electrodomesticos
* param len Tamaño del array de electrodomesticos
* param serieElectrodomestico Dato serie del electrodomestico buscado
* return Retorna la estructura con los datos del electrodomestico buscado
*/

Electrodomestico ele_buscarPorSerie(Electrodomestico *pArray,int len, int serieElectrodomestico)
{
	int i;
	Electrodomestico retorno;

	if (pArray != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].serie == serieElectrodomestico)
			{
				retorno = pArray[i];
			}
		}
	}

	return retorno;
}


//-----------------------------------------------------------------------------------------------

/*
 * brief En un array existente de electrodomesticos agrega los datos pasados por parametro en la primera posicion libre
 * param pElectro Array de electrodomesticos
 * param lenEle Tamaño del array de electrodomesticos
 * param pMarca Array de marcas
 * param lenMar Tamaño del array de marcas
 * return Retorna 0 si se pudo agregar el electrodomestico y -1 si no
 */
int ele_alta(Electrodomestico *pElectro, int lenEle,Marca *pMarca, int lenMar)
{
	int retorno = -1;
	int pos;

	if (pElectro != NULL && lenEle > 0 && pMarca != NULL && lenMar > 0)
	{
		//if (buscarLibreElectrodomestico(arrayElec, lenElec, &pos) == -1)
		if(ele_lugarVacio(pElectro, lenEle, &pos) == -1)
		{
			printf("\nNo hay lugares vacios.");
		}
		else
		{
			utn_getNumero(&pElectro[pos].id,"\nIngrese Id: \n","\nError",1,10000, 2);//id
			utn_getNumero(&pElectro[pos].serie,"\nIngrese numero de serie: \n","\nError",1,10000, 2);//serie
			mar_printArray(pMarca, lenMar);//muestro lista marcas
			utn_getNumero(&pElectro[pos].idMarca,"\nIngrese id de la marca: \n","\nError",1000,1004, 2);//idMarca
			utn_getNumero(&pElectro[pos].modelo,"\nIngrese modelo: \n","\nError",1,10000, 2);//modelo
			pElectro[pos].isEmpty = 0;//Cero es falso y cualquier valor diferente de cero es verdadero.
			printf("\nPosicion: %d\nId: %d\nSerie: %d\nId marca: %d\nModelo: %d",pos, pElectro[pos].id, pElectro[pos].serie,
					pElectro[pos].idMarca, pElectro[pos].modelo);
			retorno = 0;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------
int ele_modificar(Electrodomestico *pElectro, int lenEle, Marca *pMarca,int lenMar)
{
	int retorno = -1;
	int pos;
	int id;
	int opcion;

	if (pElectro != NULL && lenEle > 0)
	{
		ele_printArray(pElectro, lenEle, pMarca, lenMar);
		utn_getNumero(&id,"\nId a modificar: \n","\nError",1,10000,2);
		if(ele_encontrarPorId(pElectro, lenEle, id, &pos) == -1)
		{
			printf("\nEl id ingresado no existe.");
		}
		else
		{
			do
			{
				printf("\nPosicion: %d\nId: %d\nNumero de serie: %d\nId de la marca: %d\nModelo: %d\n",pos, pElectro[pos].id, pElectro[pos].serie,
						pElectro[pos].idMarca, pElectro[pos].modelo);
				utn_getNumero(&opcion,"\nModificar: \n\n1-Numero de serie \n2-Modelo \n3-Salir\n","\nError",1,3,2);
				switch (opcion)
				{
					case 1:
						utn_getNumero(&pElectro[pos].serie,"\nNumero de serie: ", "\nError",1,100000, 2);
						break;
					case 2:
						utn_getNumero(&pElectro[pos].modelo,"\nModelo: ", "\nError",1,10000, 2);
						break;
					case 3:
						break;
					default:
						printf("\nOpcion invalida");
				}
			} while (opcion != 3);
			retorno = 0;
		}
	}
	return retorno;
}
/*------------------------------------------------------------------------------------------------------------*/

/*
 * brief Elimina a un electrodomestico por su id (pone el campo isEmpty en 1)
 * param pElectro Array de electrodomesticos
 * param lenEle Tamaño del array de electrodomesticos
 * param pMarca Array de marcas
 * param lenMar Tamaño del array de marcas
 * reuturn Retorna 0 si se realizo OK la baja y -1 si no
 */

int ele_baja(Electrodomestico *pElectro, int lenEle, Marca *pMarca,int lenMar)
{
	int retorno = -1;
	int pos;
	int id;

	if (pElectro != NULL && lenEle > 0)
	{
		ele_printArray(pElectro, lenEle, pMarca, lenMar);

		utn_getNumero(&id,"\nId a eliminar: ","\nError",0, 10000,2);

		if(ele_encontrarPorId(pElectro, lenEle, id, &pos) == -1)
		{
			printf("\nEl id ingresado no existe.");
		}
		else
		{
			pElectro[pos].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------

/*
 * brief Ordena los electrodomesticos por modelo de manera ascendente y si es el mismo modelo los ordena por serie (tambien ascendente)
 * param pArray Array de electrodomesticos
 * param len Tamaño del array de electrodomesticos
 * return Retorna 0 si pudo ordenar OK y -1 si no
 */

int ele_ordenar(Electrodomestico *pArray, int len)
{
	int retorno = -1;
	int i, j;
	Electrodomestico buffer;

	if (pArray != NULL && len > 0)
	{
		for (i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if (pArray[i].modelo > pArray[j].modelo)
				{
					buffer = pArray[i];
					pArray[i] = pArray[j];
					pArray[j] = buffer;
				}
				else if (pArray[i].modelo < pArray[j].modelo)
				{
					buffer = pArray[i];
					pArray[i] = pArray[j];
					pArray[j] = buffer;
				}
				else if (pArray[i].modelo == pArray[j].modelo)
				{
					if (pArray[i].serie > pArray[j].serie)
					{
						buffer = pArray[i];
						pArray[i] = pArray[j];
						pArray[j] = buffer;
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int ele_hardcodear(Electrodomestico *pElectro, int len, int cantidad)
{
	int contador = 0;
	int i;

	if (pElectro != NULL && len > 0 && cantidad > 0)
	{
		Electrodomestico arrayAuxiliar[] = { { 0, 0, 1000, 0, 0 }, { 1, 1,
				1001, 1, 0 }, { 2, 2, 1002, 2, 0 }, { 3, 3, 1003, 3, 0 }, { 4,
				4, 1004, 4, 0 } };

		if (cantidad <= len && cantidad <= 5)
		{
			for (i = 0; i < len; i++)
			{
				pElectro[i] = arrayAuxiliar[i];
				contador++;
			}
		}
	}
	return contador;
}

/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

/*
 * brief Recibe un array de estructuras y la recorre para fijarse si tiene al menos un dato cargado
 * param pArray Array de marcas
 * param len Longitud del array
 * return Retorna 1 si esta completamente vacio y 0 si tiene al menos una marca guardada
 */

int mar_arrayVacio(Marca *pArray, int len)
{
	int retorno = 1;
	int i;

	if (pArray != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*---------------------------------------------------------------------*/

/*
 * brief Recibe una estructura e imprime los datos de sus campos
 * param marca Estructura a imprimir
 */

void mar_print(Marca pMarca)
{

	printf("\n%d\t\t%s", pMarca.id, pMarca.descripcion);
}

/*---------------------------------------------------------------------*/

/*
 * brief Recibe un array de estructuras e imprime los datos guardados en sus campos
 * param pArray Array de marcas a imprimir
 * param len Tamaño del array de marcas
 */

void mar_printArray(Marca *pArray, int len)
{
	int i;

	if (pArray != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{
				mar_print(pArray[i]);
			}
		}
		printf("\n");
	}
}

/*---------------------------------------------------------------------------------*/

/*
 * brief Recibe el numero de id del servicio y devuelve su descripcion
 * param idMarca Numero de id de la marca
 * param pArray Array de marcas
 * param len Tamaño del array de marcas
 * param descripcion Puntero al espacio de memoria donde se va a guardar la descripcion de la marca
 * return Retorna 0 si se cargo la descripcion y -1 si no
 */
int mar_cargarDescripcionPorId(int idMarca, Marca *pArray, int len,char *descripcion)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0 && descripcion != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (pArray[i].id == idMarca)
			{
				strncpy(descripcion, pArray[i].descripcion, LEN_DESCRIPCION);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/*---------------------------------------------------------------------------------*/
/*
 * brief Recibe la descripcion de una marca y devuelve su numero de id
 * param descripcion Descripcion de la marca
 * param pArray Array de marcas
 * param len Tamaño del array de marcas
 * param idMarca Puntero al espacio de memoria donde se guardara el id de la marca
 * return Retorna 0 si se cargo el id y -1 si no
 */
//cargarIdMarcaPorDescripcion

int mar_descripcionPorId(char *descripcion, Marca *pArray, int len,int *idMarca)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0 && descripcion != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (strcmp(pArray[i].descripcion, descripcion) == 0)
			{
				*idMarca = pArray[i].id;
				retorno = 0;
				break; //Breakeo para que no siga corriendo el for porque ya encontre el id
			}
		}
	}

	return retorno;
}


void menuPrincipal()
{
    printf("\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Alta electrodomestico\n");
    printf("2 - Modificar electrodomestico\n");
    printf("3 - Baja electrodomestico\n");
    printf("4 - Lista electrodomestico\n");
    printf("5 - Listar marcas \n");
    printf("6 - Lista  Servicios\n");
    printf("7 - Alta reparacion\n");
    printf("8 - Lista reparacion\n");
    printf("9 - Salir\n");
}



