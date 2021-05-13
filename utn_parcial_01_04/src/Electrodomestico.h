/*
 * Electrodomestico.h
 *
 *  Created on: 12 may. 2021
 *      Author: marti
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#define LEN_DESCRIPCION 20

typedef struct
{
	int id;
	int isEmpty;
	int serie;
	int idMarca;// Validar
	int modelo; //año de fabricación

}Electrodomestico;

typedef struct
{
	int id; //comienza en 1000
		char descripcion[LEN_DESCRIPCION]; //máx 20 caracteres
		int isEmpty;
}Marca;



#endif /* ELECTRODOMESTICO_H_ */

//-------------------------------------------------------------------------------------------*/
int ele_inicializar(Electrodomestico*pArray, int len);

int ele_lugarVacio(Electrodomestico* pArray, int len, int* id);

int ele_arrayVacio(Electrodomestico *pArray, int len);

int ele_encontrarPorId(Electrodomestico* pArray,int len, int posicion, int* id);

void ele_print(Electrodomestico pElectro, Marca *pMarca, int len);

void ele_printArray(Electrodomestico *pElectro, int lenEle,Marca *pMarca, int lenMar);

Electrodomestico ele_buscarPorSerie(Electrodomestico *pArray,int len, int serieElectrodomestico);

int ele_alta(Electrodomestico *pElectro, int lenEle,Marca *pMarca, int lenMar);

int ele_modificar(Electrodomestico *pElectro, int lenEle, Marca *pMarca,int lenMar);

int ele_baja(Electrodomestico *pElectro, int lenEle, Marca *pMarca,int lenMar);

int ele_ordenar(Electrodomestico *pArray, int len);

int ele_hardcodear(Electrodomestico *pElectro, int len, int cantidad);


/*---------------------------------------------------------------------------------------------*/

int mar_arrayVacio(Marca *pArray, int len);

void mar_print(Marca pMarca);

void mar_printArray(Marca *pArray, int len);

int mar_cargarDescripcionPorId(int idMarca, Marca *pArray, int len,char *descripcion);

int mar_descripcionPorId(char *descripcion, Marca *pArray, int len,int *idMarca);

/*---------------------------------------------------------------------------------------------*/

void menuPrincipal();
