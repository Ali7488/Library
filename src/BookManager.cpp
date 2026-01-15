#include "BookManager.h"

// Default Constructor
BookManager::BookManager() {}

// Function to add books into the collection where the ID is the key
bool BookManager::addBook(const Book &newBook)
{
    auto [key, status] = collection.emplace(newBook.getID(), newBook);
    if (status)
    {
        std::cout << "Book with ID " << newBook.getID() << " sucessfully added!\n";
        return true;
    }

    std::cout << "A book with the ID " << newBook.getID() << " already exists!\n";
    return false;
}

// Removes book then checks if book was removed successfully
bool BookManager::removeBook(const int &id)
{
    if (collection.erase(id) == 1)
    {
        std::cout << "Book removed Successfully!\n\n";
        return true;
    }

    std::cout << "Book was not found!\n";
    return false;
}

// searches for a book by its ID, if found it returns a pointer to the book object, else returns empty pointer
Book *BookManager::findBook(const int &id)
{
    auto it = collection.find(id);
    if (it != collection.end())
    {
        return &(it->second);
    }
    return nullptr;
}

// const version of findbook to use it in display (since display is const)
const Book *BookManager::findBook(const int &id) const
{
    auto it = collection.find(id);
    if (it != collection.end())
    {
        return &(it->second);
    }
    return nullptr;
}

// uses the bookID to find the book and borrow
bool BookManager::borrowBookbyID(const int &id)
{
    Book *book = findBook(id);
    if (book != nullptr) // Checks book exists
    {
        if (!book->getBorrowStatus())
        { // if book is not borrowed, borrow it
            book->borrowBook();
            std::cout << "Borrowed book with ID " << book->getID() << std::endl;
        }
        else // if borrowed print statement
            std::cout << "Book already borrowed!\n";
        return true;
    }

    std::cout << "Book not found\n";
    return false;
}

// same logic as borrowbook, but checks if book is borrowed then returns it
bool BookManager::returnBookbyID(const int &id)
{
    Book *book = findBook(id);
    if (book != nullptr)
    {
        if (book->getBorrowStatus())
        {
            book->returnBook();
            std::cout << "Returned book with ID " << book->getID() << std::endl;
        }
        else
            std::cout << "Book already not borrowed!\n";
        return true;
    }

    std::cout << "Book not found\n";
    return false;
}

// Display all book object data
void BookManager::displaybyID(const int &id) const
{
    const Book *bookptr = findBook(id);
    std::string borrowed;
    if (bookptr != nullptr)
    {

        // Turn the bool into a printable string
        if (bookptr->getBorrowStatus())
            borrowed = "Borrowed";
        else
            borrowed = "Not Borrowed";

        std::cout << "BookID: " << id;
        std::cout << "\nTitle: " << bookptr->getTitle();
        std::cout << "\nAuthor: " << bookptr->getAuthor();
        std::cout << "\nBorrowed Status: " << borrowed;
        std::cout << std::endl
                  << std::endl;
    }
    else
        std::cout << "Book not found\n";
}

// iterates through all books in collection and displays it
void BookManager::displayAll() const
{
    for (const auto &key : collection) // for key in collection, use the key.first (ID) to display the book details
    {
        displaybyID(key.first);
    }
}
