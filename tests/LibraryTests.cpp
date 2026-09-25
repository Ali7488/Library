#include "BookManager.h"

#include <cassert>

int main()
{
    BookManager manager;

    Book dune(1, "Dune", "Frank Herbert");
    Book hobbit(2, "The Hobbit", "J.R.R. Tolkien");

    assert(manager.addBook(dune));
    assert(manager.addBook(hobbit));
    assert(!manager.addBook(Book(1, "Duplicate", "Duplicate Author")));

    const Book *storedDune = manager.findBook(1);
    assert(storedDune != nullptr);
    assert(storedDune->getTitle() == "Dune");
    assert(!storedDune->getBorrowStatus());

    assert(manager.borrowBookbyID(1));
    assert(manager.findBook(1)->getBorrowStatus());

    assert(manager.returnBookbyID(1));
    assert(!manager.findBook(1)->getBorrowStatus());

    assert(!manager.removeBook(999));
    assert(manager.removeBook(2));
    assert(manager.findBook(2) == nullptr);

    return 0;
}
