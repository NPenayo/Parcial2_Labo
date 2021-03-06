/*
 * Editorial.c
 *
 *  Created on: 27 Jun 2021
 *      Author: Nicolas Penayo
 */
#include "Editorial.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Editorial* newEditorial(char *description) {
	Editorial *newEditorial = (Editorial*) malloc(sizeof(Editorial));
	if (newEditorial != NULL) {
		setEditorialDescription(newEditorial, description);
		setEditorialId(newEditorial);
	}
	return newEditorial;
}
int getEditorialId(Editorial *this) {
	int id = -1;
	if (this != NULL) {
		id = this->_id;
	}
	return id;
}
int getEditorialDescription(Editorial *this, char *output) {
	int resp = 0;
	if (this != NULL) {
		strcpy(output, this->_description);
		resp = 1;
	}
	return resp;
}
int setEditorialId(Editorial *this) {
	int resp = 0;
	char description[128];
	if (this != NULL) {
		getEditorialDescription(this, description);
		if (!strcmp(description, "Planeta")) {
			this->_id = 1;
		}
		if (!strcmp(description, "SIGLO XXI EDITORES")) {
			this->_id = 2;
		}
		if (!strcmp(description, "Pearson")) {
			this->_id = 3;
		}
		if (!strcmp(description, "Minotauro")) {
			this->_id = 4;
		}
		if (!strcmp(description, "SALAMANDRA")) {
			this->_id = 5;
		}
		if (!strcmp(description, "PENGUIN BOOKS")) {
			this->_id = 6;
		}

		resp = 1;
	}
	return resp;

}
int setEditorialDescription(Editorial *this, char *description) {
	int resp = 0;
	if (this != NULL) {
		strcpy(this->_description, description);
		resp = 1;
	}
	return resp;
}
Editorial* getEditorialById(LinkedList *eList, int id) {

	Editorial *eFound = NULL;
	if (eList != NULL && id > -1) {
		for (int i = 0; i < ll_len(eList); i++) {
			if (getEditorialId(((Editorial*) ll_get(eList, i))) == id) {
				eFound = ll_get(eList, i);
				break;
			}
		}
	}
	return eFound;
}
Editorial* getEditorialByDescription(LinkedList *eList, char *desc) {

	Editorial *eFound = NULL;
	char description[128];
	if (eList != NULL && desc != NULL) {
		for (int i = 0; i <= ll_len(eList); i++) {
			eFound = ll_get(eList, i);
			if (eFound != NULL) {
				getEditorialDescription(eFound, description);
				if (strcmp(desc, description) == 0) {
					eFound = ll_get(eList, i);
					break;
				}
			}

		}
	}
	return eFound;
}
