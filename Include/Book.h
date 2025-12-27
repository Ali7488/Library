/************************************************************************
 * Purpose: Book class definition, represents each individual Book object
 * in the library system later to be tored in the BookManager class
 * 
 * Variables: BookID, BookTitle, Author, isBorrowed
 * 
 * Methods: Constructor, Getter and Setter methods, borrowBook, 
 * returnBook, display
************************************************************************/
#pragma once
#include <string>
#include <cassert>
#include <iostream>

class Book {
private:
    const int BookID;
    std::string BookTitle, Author;
    bool isBorrowed;
public:
    //Constructor
    Book(int ID, std::string title, std::string author);

    //Getter Methods
    int getID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getBorrowStatus() const;

    //Setter Methods
    void setTitle(std::string title);
    void setAuthor(std::string author);
    
    //Borrowing Logic
    void borrowBook();
    void returnBook();
    
   
};

