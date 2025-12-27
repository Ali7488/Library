#include "Book.h"

Book::Book(int ID, std::string title, std::string author): BookID(ID), BookTitle(title), Author(author), isBorrowed(false){std::cout << "Book Constructor called\n";}

//Getter Method Implementation
int Book::getID() const{
    return BookID;
}
std::string Book::getTitle() const{
    return BookTitle;
}

std::string Book::getAuthor() const{
    return Author;
}

bool Book::getBorrowStatus() const{
    return isBorrowed;
}

void Book::setTitle(std::string title){
    BookTitle = title;
}

void Book::setAuthor(std::string author){
    Author = author;
}

//Borrow Book Logic Implementation
void Book::borrowBook(){
    isBorrowed = true;
}

void Book::returnBook(){
    isBorrowed = false;
}


