#include "BookManager.h"

//Default Constructor
BookManager::BookManager() {}

// Function to add books into the collection where the ID is the key
void BookManager::addBook(Book newBook)
{
    // adds to collection then checks if book was added or not
    auto insertAttempt = collection.emplace(newBook.getID(), newBook);
    if (!insertAttempt.second)
    {
        std::cout << "A book with the ID " << newBook.getID() << " already exists!\n";
    }
    else
    {
        std::cout << "Book with ID " << newBook.getID() << " sucessfully added!\n";
    }
}

// Removes book then checks if book was removed successfully
void BookManager::removeBook(Book removal)
{
    collection.erase(removal.getID());
    if (collection.find(removal.getID()) == collection.end())
        std::cout << "Book removed Successfully!\n\n";
}

// searches for a book by its ID, if found it reterns a pointer to the book object, else returns empty pointer
Book *BookManager::findBook(int id)
{
    auto it = collection.find(id);
    if (it != collection.end())
    {
        return &(it->second);
    }
    else
        return nullptr;
}

// const version of findbook to use it in display (since display is const)
const Book *BookManager::findBook(int id) const
{
    auto it = collection.find(id);
    if (it != collection.end())
    {
        return &(it->second);
    }
    else
        return nullptr;
}

// uses the bookID to find the book and borrow
void BookManager::borrowBookbyID(int id)
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
    }
    else
        std::cout << "Book not found\n";
}

// same logic as borrowbook, but checks if book is borrowed then returns it
void BookManager::returnBookbyID(int id)
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
    }
    else
        std::cout << "Book not found\n";
}

// Display all book object data
void BookManager::displaybyID(int id) const
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