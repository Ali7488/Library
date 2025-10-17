#include "../Include/BookManager.h"

BookManager::BookManager(){}

void BookManager::addBook(Book newBook){
    collection.emplace(newBook.getID(), newBook);
//add a way to confirm its added
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

