/*
 ============================================================================
 Name        : parcial2_labo_penayo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validations.h"
#include "Controller.h"
int main(void) {
	LinkedList *bookList = ll_newLinkedList();
	LinkedList *edList = ll_newLinkedList();
	int opt;
	do {
		printf("\n%50s", "Menu principal");
		printf(
				"\n1- Cargar libros desde archivo\n2- Ordenar listado\n3- Mostrar Listado\n4- Aplicar descuentos\n5- Salir");
		cleanBuffer();
		if (validInt("Opcion", "Error.Opcion invalida", &opt, 1, 5, 15)) {
			switch (opt) {
			case 1:
				controller_loadFromText(bookList, edList);
				break;
			case 2:
				if (!ll_isEmpty(bookList)) {
					if (controller_sortBooks(bookList)) {
						printf("\nSe realizó el ordenamiento correctamente");
					}
				} else {
					printf("\nNo hay nada cargado para ordenar.");
				}

				break;
			case 3:
				if (!ll_isEmpty(bookList)) {
					controller_ListBooks(bookList, edList);
				} else {
					printf("\nNo hay nada cargado para listar.");
				}
				break;
			case 4:
				if (!ll_isEmpty(bookList)) {
					if(controller_map(bookList, edList)){
						printf("\nSe aplicaron los descuentos correctamente");
					}
				} else {
					printf("\nNo hay nada cargado.");
				}
				break;
			}
		}
	} while (!(opt == 5));
	ll_deleteLinkedList(bookList);
	ll_deleteLinkedList(edList);
	return EXIT_SUCCESS;
}

