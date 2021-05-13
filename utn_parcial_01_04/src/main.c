/*
 ============================================================================
 Name        : utn_parcial_01_04.c
 Author      : martin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reparacion.h"
#include "Electrodomestico.h"
#include "utn.h"

#define QTY_REP 5
#define QTY_ELE 5
#define QTY_MAR 4
#define QTY_SER 5


int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int idReparacion = 0;

	Electrodomestico arrayEle[QTY_ELE];
	Reparacion arrayRep[QTY_REP];
	Servicio arraySer[] = { { 20000, "Garantia", 250, 0 }, { 20001,"Mantenimiento", 500, 0 }, { 20002, "Repuestos", 400, 0 }, { 20003,
				"Refaccion", 600, 0 } };
	Marca arrayMar[] = { { 1000, "Whirlpool", 0 }, { 1001, "Sony", 0 }, { 1002,"Liliana", 0 }, { 1003, "Gafa", 0 }, { 1004, "Phillips", 0 } };


	if (rep_inicializar(arrayRep, QTY_REP) == 0)
	{
		printf("\nEl array de reparaciones se inicializo correctamente.");
	}
	else
	{
		printf("\nError al inicializar reparaciones.");
	}

	if (ele_inicializar(arrayEle, QTY_ELE) == 0)
	{
		printf("\nEl array de electrodomesticos se inicializo correctamente.\n");
	}
	else
	{
		printf("\nError al inicializar reparaciones.\n");
	}




	do
	{
		menuPrincipal();
		if(utn_getNumero(&opcion,"\nOpcion [1-9]\n","\nError",1,9,2)!=0)
			opcion = 9;
		else
		{
			switch(opcion)
			{
				case 1: // Alta electrodomestico
					ele_alta(arrayEle, QTY_ELE,arrayMar,QTY_MAR);
					break;
				case 2 : //Modificar electrodomestico
					if(ele_arrayVacio(arrayEle, QTY_ELE))
						printf("No se ha dado de alta un Electrodomestico");
					else
						ele_modificar(arrayEle, QTY_ELE, arrayMar, QTY_MAR);
					break;
				case 3: //Baja electrodomestico
					if(ele_arrayVacio(arrayEle, QTY_ELE))
						printf("No se ha dado de alta un electrodomestico");
					else
						ele_baja(arrayEle, QTY_ELE, arrayMar, QTY_MAR);
					break;
				case 4 : //Mostrar electrodomestico
					if(ele_arrayVacio(arrayEle, QTY_ELE))
						printf("No se ha dado de alta un electrodomestico");
					else
					{
						ele_ordenar(arrayEle, QTY_ELE);
					}
					ele_printArray(arrayEle, QTY_ELE, arrayMar,QTY_MAR);
					break;

				case 5 : //Listar marcas
					if(mar_arrayVacio(arrayMar, QTY_MAR))
						printf("No se ha dado de alta ninguna marca");
					else
						mar_printArray(arrayMar, QTY_MAR);
					break;
				case 6: //Lista  Servicios
					if(ser_arrayVacio(arraySer, QTY_SER))
						printf("No se ha dado de alta ningun servicio");
					else
						ser_arrayPrint(arraySer, QTY_SER);
					break;
				case 7 : //Alta reparacion
					rep_alta(arrayRep, QTY_REP, arraySer, QTY_SER, arrayEle, QTY_ELE, arrayMar, QTY_MAR, &idReparacion);
					break;
				case 8 : //Lista reparacion
					if(rep_arrayVacio(arrayRep, QTY_REP))
						printf("No se ha dado de alta ninguna reparacion");
					else
						rep_printArray(arrayRep, QTY_REP, arrayEle, QTY_ELE, arraySer, QTY_SER);
					break;

				case 9 : // Salir
					break;
					default:
						printf("\nOpcion no valida");
			}
		}

	}while(opcion!=9);


	return EXIT_SUCCESS;
}
