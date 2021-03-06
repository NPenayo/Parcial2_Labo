/*
 * Book.c
 *
 *  Created on: 27 Jun 2021
 *      Author: Nicolas Alejandro Penayo
 */
#include "Book.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief Crea un nuevo elemento de tipo eBook
 *
 * @param id ID a asignarle al libro char*
 * @param title Titulo del libro char*
 * @param author Autor del libro char*
 * @param price Precio unitario del libro int
 * @param editorial Id de la editorial int
 * @return eBook*
 */
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
/**
 * @brief Setter de ID libro
 *
 * @param this Direccion de memoria del elemento eBook | eBook*
 * @param id ID a asignar | int
 * @param this Direccion de memoria del elemento eBook | eBook*
 * \return resp[0] si el puntero es NULL y [1] si se asigno correctamente. | int
 */
int setBookId(eBook *this, int id) {
	int resp = 0;
	if (this != NULL) {
		this->_id = id;
		resp = 1;
	}
	return resp;
}
/**
 * \brief Setter de Titulo libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \param title Titulo a asignar | char*
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \return resp[0] si el puntero es NULL y [1] si se asigno correctamente. | int
 */
int setBookTitle(eBook *this, char *title) {
	int resp = 0;
	if (this != NULL && title != NULL) {
		strncpy(this->_title, title, sizeof(this->_title));
		resp = 1;
	}
	return resp;
}
/**
 * \brief Setter de Autor libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \param author Autor a asignar | char*
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \return resp[0] si el puntero es NULL y [1] si se asigno correctamente. | int
 */
int setBookAuthor(eBook *this, char *author) {
	int resp = 0;
	if (this != NULL && author != NULL) {
		strncpy(this->_author, author, sizeof(this->_author));
		resp = 1;
	}
	return resp;
}
/**
 * \brief Setter de Precio libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \param price Precio a asignar | int
 * \return resp[0] si el puntero es NULL y [1] si se asigno correctamente. | int
 */
int setBookPrice(eBook *this, int price) {
	int resp = 0;
	if (this != NULL) {
		this->_price = price;
		resp = 1;
	}
	return resp;
}
/**
 * \brief Setter de Editorial libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \param id IdEditorial a asignar | int
 * \return resp[0] si el puntero es NULL y [1] si se asigno correctamente. | int
 */
int setBookEditorial(eBook *this, int id) {
	int resp = 0;
	if (this != NULL) {
		this->_idEditorial = id;
		resp = 1;
	}
	return resp;
}
/**
 * \brief Getter de Id Libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \return resp [-1] si el puntero es NULL o retorna el id correspondiente | int
 */
int getBookId(eBook *this) {
	int resp = -1;
	if (this != NULL) {
		resp = this->_id;
	}
	return resp;
}
/**
 * \brief Getter de Titulo libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \param output Titulo del libro obtenido | char *
 * \return resp[0] si el puntero es NULL y [1] si sali?? ok | int
 */
int getBookTitle(eBook *this, char *output) {
	int resp = 0;
	if (this != NULL) {
		strcpy(output, this->_title);
		resp = 1;
	}
	return resp;
}
/**
 * \brief Getter de Autor libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \param output Autor del libro obtenido | char *
 * \return resp[0] si el puntero es NULL y [1] si sali?? ok | int
 */
int getBookAuthor(eBook *this, char *output) {
	int resp = 0;
	if (this != NULL) {
		strcpy(output, this->_author);
		resp = 1;
	}
	return resp;
}
/**
 * \brief Getter de Precio libro
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \return resp [-1] si el puntero es NULL o retorna el precio correspondiente | int
 */
int getBookPrice(eBook *this) {
	int resp = -1;
	if (this != NULL) {
		resp = this->_price;
	}
	return resp;
}
/**
 * \brief Getter de IdEditorial
 *
 * \param this Direccion de memoria del elemento eBook | eBook*
 * \return resp [-1] si el puntero es NULL o retorna el id editorial correspondiente | int
 */
int getBookEditorial(eBook *this) {
	int resp = -1;
	if (this != NULL) {
		resp = this->_idEditorial;
	}
	return resp;
}
/**
 * \brief Compara el autor de los elementos tipo eBook
 *
 * \param bookA Libro 1 | void*
 * \param bookB Libro 2 | void*
 * \return resp [0] si ambos son iguales, [1] si el primero es mayor al segundo y [-1] si el primero es menor al segundo
 */
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
/**
 * \brief Aplicar un descuento al precio de un elemento eBook
 *
 * \param book Libro al cual aplicarle el descuento | void*
 */
void editorialDiscount(void *book) {
	if (book != NULL) {
		if (getBookEditorial((eBook*) book) == 1
				&& getBookPrice((eBook*) book) >= 300) {
			setBookPrice((eBook*) book,
					(getBookPrice((eBook*) book)
							- getBookPrice((eBook*) book) * .20));
		}
		if (getBookEditorial((eBook*) book) == 2
				&& getBookPrice((eBook*) book) <= 200) {
			setBookPrice((eBook*) book,
					(getBookPrice((eBook*) book)
							- getBookPrice((eBook*) book) * .10));
		}
	}
}

