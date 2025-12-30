/***********************************************************************
 * This is the heart of the project, here is where all the functions
 * to actually use the library manager occur, this is where user
 * Authentication, Book management, and user interface are actually ran
 *
 ************************************************************************/
#pragma once
#include <vector>

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
    bool removeBook(const Book &toRemove);
};
