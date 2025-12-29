/***********************************************************************************************************
 * This Class manages members, it ensures each member object is initialized with an ID and a role 
 * role is part of the role.h file where it is an enum class
 ***********************************************************************************************************/
#pragma once
#include "Role.h"
class Member
{
private:
    const int userID;
    Role userRole;
public:
    //Parameterized constructor
    Member(int id, Role newUserRole);


    //getter methods
    int getUserID() const;
    bool isAdmin() const;
    Role getRole() const;
};

