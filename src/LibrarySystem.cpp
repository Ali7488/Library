#include "LibrarySystem.h"
#include <fstream>
#include <string>
#include <sstream>
bool LibrarySystem::loadFromCSV()
{
    std::ifstream inData("Books.csv");
    if (!inData.is_open())
    {
        std::cerr << "Failed to open file\n";
        return false;
    }

    std::string line;
    std::getline(inData, line);
    while (std::getline(inData, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::stringstream ss(line);
        std::string temp;

        std::getline(ss, temp, ',');
        int id = std::stoi(temp);

        std::getline(ss, temp, ',');
        std::string title = temp;

        std::getline(ss, temp, ',');
        std::string author = temp;

        bookCollection.addBook(Book(id, title, author));
    }
    return true;
}

bool LibrarySystem::saveToCSV()
{
    std::ofstream outData("Books.csv");
    if (!outData.is_open())
    {
        std::cerr << "Cannot open output file\n";
        return false;
    }
    outData << "id,title,author\n";

    const auto &collection = bookCollection.getCollection();
    for (const auto &[id, book] : collection)
    {
        outData << book.getID() << ","
                << book.getTitle() << ","
                << book.getAuthor()
                << "\n";
    }

    return true;
}

bool LibrarySystem::addMember(const Member& newMember)
{
    auto it = members.emplace(newMember.getUserID(), newMember);
    return it.second;
}

bool LibrarySystem::removeMember(const Member &toRemove)
{
    members.erase(toRemove.getUserID());
    return true;
}

bool LibrarySystem::addBook(const Book& newBook)
{
    bookCollection.addBook(newBook);
    return true;
}

bool LibrarySystem::removeBook(const Book &toRemove)
{
    bookCollection.removeBook(toRemove);
    return true;
}

