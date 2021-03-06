/*
 * Editorial.h
 *
 *  Created on: 27 Jun 2021
 *      Author: npenayo
 */
#include "LinkedList.h"
#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct {
	int _id;
	char _description[128];
} Editorial;

Editorial* newEditorial(char *description);
int setEditorialId(Editorial *this);
int setEditorialDescription(Editorial *this, char*);
int getEditorialId(Editorial *this);
int getEditorialDescription(Editorial *this, char *output);
Editorial* getEditorialById(LinkedList *eList, int id);
Editorial* getEditorialByDescription(LinkedList *eList, char *desc);
#endif /* EDITORIAL_H_ */
