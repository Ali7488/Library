#include <iostream>
#include <string>
#include "../Include/BookManager.h"
int main() {
    BookManager Books;
    
    Books.addBook(Book(1234,"pheonix","michael"));
    Books.addBook(Book(1234,"dddd", "ssss"));
    //Books.displaybyID(1234);
    Books.borrowBookbyID(1234);
    //Books.displaybyID(1234);

    Books.displayAll();
    return 0;
}
