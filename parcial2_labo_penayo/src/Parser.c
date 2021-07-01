#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Book.h"
#include "Editorial.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo indicado por el usuario (modo texto).
 *
 * \param pFile char*
 * \param pBookList LinkedList*
 * \param edList LinkedList*
 * \return int
 *
 */
int parserBookFromText(FILE *pFile, LinkedList *pBookList, LinkedList *edList) {
	char buffer[5][128];
	int registers = 0;
	eBook *auxBook = NULL;
	Editorial *auxEd = NULL;
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0),
			*(buffer + 1), *(buffer + 2), *(buffer + 3), *(buffer + 4));
	while (!feof(pFile)) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0),
				*(buffer + 1), *(buffer + 2), *(buffer + 3), *(buffer + 4));
		auxEd = getEditorialByDescription(edList, *(buffer + 4));
		if (auxEd == NULL) {
			auxEd = newEditorial(*(buffer + 4));
			if (auxEd != NULL) {
				ll_add(edList, auxEd);
			} else {
				break;
			}
		}
		auxBook = newBook(*(buffer + 0), *(buffer + 1), *(buffer + 2),
				*(buffer + 3), getEditorialId(auxEd));
		ll_add(pBookList, auxBook);

		registers++;
	}
	return registers;
}
