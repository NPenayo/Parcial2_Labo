/*
 * Book.c
 *
 *  Created on: 27 Jun 2021
 *      Author: npenayo
 */
#include "Book.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
eBook* newBook(char *id, char *title, char *author, char *price, int editorial) {
	eBook *newBook = NULL;
	if (id != NULL && title != NULL && author != NULL && price != NULL
			&& editorial > -1) {
		newBook = (eBook*) malloc(sizeof(eBook));
		setBookId(newBook, atoi(id));
		setBookTitle(newBook, title);
		setBookAuthor(newBook, author);
		setBookPrice(newBook, atoi(price));
		setBookEditorial(newBook, editorial);
	}
	return newBook;
}
int setBookId(eBook *this, int id) {
	int resp = 0;
	if (this != NULL) {
		this->_id = id;
		resp = 1;
	}
	return resp;
}
int setBookTitle(eBook *this, char *title) {
	int resp = 0;
	if (this != NULL && title != NULL) {
		strncpy(this->_title, title, sizeof(this->_title));
		resp = 1;
	}
	return resp;
}
int setBookAuthor(eBook *this, char *author) {
	int resp = 0;
	if (this != NULL && author != NULL) {
		strncpy(this->_author, author, sizeof(this->_author));
		resp = 1;
	}
	return resp;
}
int setBookPrice(eBook *this, int price) {
	int resp = 0;
	if (this != NULL) {
		this->_price = price;
		resp = 1;
	}
	return resp;
}
int setBookEditorial(eBook *this, int id) {
	int resp = 0;
	if (this != NULL) {
		this->_idEditorial = id;
		resp = 1;
	}
	return resp;
}
int getBookId(eBook *this) {
	int resp = -1;
	if (this != NULL) {
		resp = this->_id;
	}
	return resp;
}
int getBookTitle(eBook *this, char *output) {
	int resp = 0;
	if (this != NULL) {
		strcpy(output, this->_title);
		resp = 1;
	}
	return resp;
}
int getBookAuthor(eBook *this, char *output) {
	int resp = 0;
	if (this != NULL) {
		strcpy(output, this->_author);
		resp = 1;
	}
	return resp;
}
int getBookPrice(eBook *this) {
	int resp = -1;
	if (this != NULL) {
		resp = this->_price;
	}
	return resp;
}
int getBookEditorial(eBook *this) {
	int resp = -1;
	if (this != NULL) {
		resp = this->_idEditorial;
	}
	return resp;
}
int compareAuthors(void *bookA, void *bookB) {
	int resp = 0;
	if (strcmp(((eBook*) bookA)->_author, ((eBook*) bookB)->_author) > 0) {
		resp = 1;
	}
	if (strcmp(((eBook*) bookA)->_author, ((eBook*) bookB)->_author) < 0) {
		resp = -1;
	}
	return resp;
}
void editorialDiscount(void *book) {
	if (book != NULL) {
		if (getBookEditorial((eBook*) book) == 1
				&& getBookPrice((eBook*) book) >= 300) {
			setBookPrice((eBook*) book,(getBookPrice((eBook*) book)-getBookPrice((eBook*) book) * .20));
		}
		if (getBookEditorial((eBook*) book) == 2
				&& getBookPrice((eBook*) book) <= 200) {
			setBookPrice((eBook*) book, (getBookPrice((eBook*) book)-getBookPrice((eBook*) book) * .10));
		}
	}
}
