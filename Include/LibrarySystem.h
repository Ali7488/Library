/***********************************************************************
 * Coordinates the library's book collection and member records.
 * Handles CSV persistence plus the high-level operations currently
 * implemented by the LibrarySystem class.
 ************************************************************************/
#pragma once
#include <vector>
#include <unordered_map>

#include "BookManager.h"
#include "Member.h"

class LibrarySystem
{
private:
    // Map containing all members and their IDs
    std::unordered_map<int, Member> members;
    // Map that pairs userID with a vector of all books they borrowed
    std::unordered_map<int, int> bookBorrowedBy;
    // Book collection in library
    BookManager bookCollection;

public:
    LibrarySystem();

    bool loadFromCSV();
    bool saveToCSV();

    bool addMember(const Member &newMember);
    bool removeMember(const Member &toRemove);
    bool addBook(const Book &newBook);
    bool removeBook(const int id);
};
