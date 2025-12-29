/********************************
 * Purpose: Manages a collection of book objects
 * variables: unordered_map<ID, Book> collection
 * methods: addBook, removeBook, findBook, borrowbookbyID,
 * returnBookbyID, displaybyID, displayAll 
********************************/
#pragma once
#include "Book.h"
#include <unordered_map>

class BookManager{
    private:
    using BookMap = std::unordered_map<int, Book>;
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
    void displayAll()const;
    void displaybyID(int id) const;

    //returns whole book collection
    const BookMap& getCollection() const{
        return collection;
    }

};


