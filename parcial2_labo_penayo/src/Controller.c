#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Validations.h"
#include "Arrays.h"
#include "Book.h"
#include "Editorial.h"
/**
 * \brief Guardar una LinkedList en un archivo de texto
 *
 * \param path Ruta del archivo a guardar | char*
 * \param toSaveList LinkedList con los elementos a guardar | LinkedList*
 * \param edList LinkedList de las editoriales a guardar | LinkedList*
 * \return resp [0] si hay un error en el nombre del archivo y [1] si se guardó exitosamente. | int
 */
int controller_saveAsText(char *path, LinkedList *toSaveList,
		LinkedList *edList) {
	{
		int resp = 0;
		FILE *file;
		file = fopen(path, "w");
		if (file != NULL && !ll_isEmpty(toSaveList)) {
			fprintf(file, "id,titulo,autor,precio,editorial\n");
			for (int i = 0; i < ll_len(toSaveList); i++) {
				eBook *tmp = ll_get(toSaveList, i);
				char author[128];
				char title[128];
				char editorial[128];
				getEditorialDescription(
						getEditorialById(edList, getBookEditorial(tmp)),
						editorial);
				getBookAuthor(tmp, author);
				getBookTitle(tmp, title);
				fprintf(file, "%d,%s,%s,%d,%s\n", getBookId(tmp), title, author,
						getBookPrice(tmp), editorial);
			}
			resp = 1;

		}
		fclose(file);
		return resp;
	}

}
/**
 * \brief Listar los elementos de tipo eBook que se encuentran en la LinkedList
 *
 * \param bookList Listado de Libros | LinkedList*
 * \param eList Listado de editoriales | LinkedList*
 * \return resp [0] si el listado está vacío y [1] si se pudo listar exitosamente. | int
 */
int controller_ListBooks(LinkedList *bookList, LinkedList *eList) {
	int resp = 0;
	char edDesciption[128];
	char tmpTitle[128];
	char tmpAuthor[128];
	eBook *tmp = NULL;
	if (!ll_isEmpty(bookList)) {
		printf("\n%50s", "Listado de Libros");
		printf("\n\n%5s %2c %30s %20c %10s %10c %11s %6c %14s", "ID", '|',
				"Titulo", '|', "Autor", '|', "Precio", '|', "Editorial");
		printf(
				"\n ------------------------------------------------------------------------------------------------------------------------------");
		for (int i = 0; i < ll_len(bookList); i++) {
			tmp = ll_get(bookList, i);
			if (tmp != NULL) {
				getEditorialDescription(
						getEditorialById(eList, getBookEditorial(tmp)),
						edDesciption);
				getBookTitle(tmp, tmpTitle);
				getBookAuthor(tmp, tmpAuthor);
				printf("\n%7d %-55s %-28s $%-15d %-16s", getBookId(tmp),
						tmpTitle, tmpAuthor, getBookPrice(tmp), edDesciption);
			}

		}
		printf("\n\nPresione una tecla para volver al menu...");
		__fpurge(stdin);
		getchar();
		resp = 1;
	}

	return resp;
}
/**
 * \brief Ordenar listado
 *
 * \param pBookList Listado de libros | LinkedList*
 * \return resp [0] si el puntero es NULL y [1] si se ordenó exitosamente | int
 */
int controller_sortBooks(LinkedList *pBookList) {
	int resp = 0;
	if (pBookList != NULL) {
		if (!ll_sort(pBookList, compareAuthors, 1)) {
			resp = 1;
		}
	}
	return resp;
}
/**
 * \brief Cargar datos de un archivo de texto e ingresarlo en una LinkedList de Libros
 *
 * \param pBookList Listado de libros | LinkedList *
 * \param edList Lstado de editoriales | LinkedList *
 * \return resp [0] si alguno de los punteros es NULL y [1] si se pudo leer el archivo exitosamente. | int
 */
int controller_loadFromText(LinkedList *pBookList, LinkedList *edList) {
	int resp = 0;
	char fileName[50];
	int count = 0;
	char confirm;
	FILE *file;
	initializeChar(fileName, 50);
	if (pBookList != NULL && edList != NULL) {
		do {
			clearConsole();
			printf("\nEscriba nombre de archivo(ej.Datos.csv):");
			cleanBuffer();
			fgets(fileName, strlen(fileName), stdin);
			char filePath[strlen(fileName) - 1];
			for (int i = 0; i < strlen(fileName); i++) {
				*(filePath + i) = *(fileName + i);
			}
			filePath[strcspn(filePath, "\n")] = 0;
			file = fopen(filePath, "r");
			if (file != NULL) {
				count = parserBookFromText(file, pBookList, edList);
				if (count) {
					printf("\nSe leyeron %d registros desde el archivo %s",
							count, fileName);
					resp = 1;
					break;
				}
				fclose(file);
			} else {
				printf("\nError!No se encuentra el archivo ingresado.");
				printf("\n¿Desea intentar nuevamente? (s/n): ");
				cleanBuffer();
				scanf("%c", &confirm);
			}
		} while (!(confirm == 'n'));

	}
	return resp;
}
/**
 * \brief Aplica una funcion a todos los elementos de la LinkedList y los guarda en un archivo "Mapeado.csv"
 *
 * \param pBookList Listado de libros | LinkedList*
 * \param edList Listado de editoriales | LinkedList *
 * \return resp [0] si alguno de los punteros es NULL y [1] si funciono ok. | int
 */
int controller_map(LinkedList *pBookList, LinkedList *edList) {
	int resp = 0;
	LinkedList *mapped = NULL;
	if (pBookList != NULL && edList != NULL) {
		mapped = ll_map(pBookList, editorialDiscount);
		if (mapped != NULL) {
			controller_saveAsText("Mapeado.csv", mapped, edList);
			ll_deleteLinkedList(mapped);
			resp =1;
		}
	}
	return resp;
}

