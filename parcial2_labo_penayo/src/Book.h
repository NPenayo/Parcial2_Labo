/*
 * Book.h
 *
 *  Created on: 27 Jun 2021
 *      Author: Nicolas Penayo 1E
 */

#ifndef BOOK_H_
#define BOOK_H_
typedef struct {
	int _id;
	char _title[128];
	char _author[50];
	int _price;
	int _idEditorial;
} eBook;

eBook* newBook(char *id, char *title, char *author, char *price, int editorial);
int setBookId(eBook *this, int id);
int setBookTitle(eBook *this, char *title);
int setBookAuthor(eBook *this, char *author);
int setBookPrice(eBook *this, int price);
int setBookEditorial(eBook *this, int id);
int getBookId(eBook *this);
int getBookTitle(eBook *this, char* output);
int getBookAuthor(eBook *this, char* output);
int getBookPrice(eBook *this);
int getBookEditorial(eBook *this);
int compareAuthors(void *bookA, void *bookB);
void editorialDiscount(void*book);
#endif /* BOOK_H_ */
