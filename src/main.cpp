#include <iostream>
#include <string>
#include "../Include/BookManager.h"
int main() {
    BookManager Books;
    Book book1(1234,"12","12");
    Books.addBook(book1);
    Book* b = Books.findBook(book1.getID());
    if(b != nullptr)
        b->display();
    return 0;
}
