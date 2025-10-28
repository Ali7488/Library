/********************************
 * Purpose: Manages a collection of book objects
 * variables: unordered_map<ID, Book> collection
 * methods: addBook, removeBook, findBook, borrowBookbyID,
 * returnBookbyID, displayAll, saveFile, LoadFile
********************************/
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include "../Include/Book.h"

using BookMap = std::unordered_map<int, Book>;
class BookManager{
    private:
    //hash map for storage of different book objects with the key being
    //a type int, and the value being type book.
    BookMap collection;
    public:
    BookManager();
    void addBook(Book newBook);
    void removeBook(Book removal);
    Book* findBook(int id);
    const Book* findBook(int id) const;
    void borrowBookbyID(int id);
    void returnBookbyID(int id);
    void displayAll()const ;
    void displaybyID(int id) const;

};

#endif
