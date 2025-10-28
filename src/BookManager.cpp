#include "../Include/BookManager.h"
#include "../Include/Book.h"
BookManager::BookManager(){}

void BookManager::addBook(Book newBook){
   auto insertAttempt = collection.emplace(newBook.getID(), newBook);
   if(!insertAttempt.second){
    std::cout << "A book with the ID " << newBook.getID() << " already exists!\n";
   }
   else {
    std::cout << "Book with ID " << newBook.getID() << " sucessfully added!\n";
   }
}

void BookManager::removeBook(Book removal){
    collection.erase(removal.getID());
    if(collection.find(removal.getID()) == collection.end())
        std::cout << "Book removed Successfully!\n";
}

Book* BookManager::findBook(int id){
   auto it = collection.find(id);
   if(it != collection.end()){
    return &(it->second);
   }
   else
    return nullptr;
}

const Book* BookManager::findBook(int id) const{
   auto it = collection.find(id);
   if(it != collection.end()){
    return &(it->second);
   }
   else
    return nullptr;
}

void BookManager::borrowBookbyID(int id){
    Book* book = findBook(id);
    if(book != nullptr){
        if(!book->getBorrowStatus()){
            book->borrowBook();
            std::cout << "Borrowed book with ID " << book->getID() << std::endl;
        }
        else 
        std::cout << "Book already borrowed!\n";
    }
    else
    std::cout << "Book not found\n";
}

void BookManager::returnBookbyID(int id){
    Book* book = findBook(id);
    if(book != nullptr){
        if(book->getBorrowStatus()){
            book->returnBook();
            std::cout << "Returned book with ID " << book->getID() << std::endl;
        }
        else 
        std::cout << "Book already not borrowed!\n";
    }
    else
    std::cout << "Book not found\n";
}


//Display all book object data
void BookManager::displaybyID(int id) const {
    const Book* bookptr = findBook(id);
    std::string borrowed;
    if(bookptr != nullptr){
    
    //Turn the bool into a printable string
    if(bookptr->getBorrowStatus())
        borrowed = "Borrowed";
    else
        borrowed = "Not Borrowed";
    
    std::cout << "BookID: " << id;
    std::cout << "\nTitle: " << bookptr->getTitle();
    std::cout << "\nAuthor: " << bookptr->getAuthor(); 
    std::cout << "\nBorrowed Status: " << borrowed;
    std::cout << std::endl <<std::endl;
    }
    else 
    std::cout << "Book not found\n";
}

void BookManager::displayAll() const{
    for(const auto& b: collection){
        displaybyID(b.first);
    }
}

