#include "LibrarySystem.h"
#include <iostream>

int main()
{
    LibrarySystem library;

    std::cout << "Loading from CSV...\n";
    if (!library.loadFromCSV())
    {
        std::cout << "Starting with an empty library.\n";
    }

    Book dune(1, "Dune", "Frank Herbert");
    Book hobbit(2, "The Hobbit", "J.R.R. Tolkien");
    Book testBook(982, "Dune", "Frank Herbert");

        std::cout
        << "\nAdding books (with a duplicate to test rejection)...\n";
    library.addBook(testBook);
    library.addBook(dune); // duplicate ID should be rejected
    library.addBook(hobbit);

    std::cout << "\nRemoving a missing book (id=999) and an existing one (id=1)...\n";
    library.removeBook(999); // expect "not found"
    library.removeBook(dune.getID()); // expect success

    std::cout << "\nSaving to CSV...\n";
    library.saveToCSV();

    // Directly exercise borrow/return/display on a local manager
    std::cout << "\nBorrow/return cycle test...\n";
    BookManager manager;
    manager.addBook(hobbit);
    manager.borrowBookbyID(hobbit.getID());
    manager.borrowBookbyID(hobbit.getID()); // should report already borrowed
    manager.returnBookbyID(hobbit.getID());
    manager.displayAll();

    return 0;
}
