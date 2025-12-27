#include "Member.h"

//initialize member object
Member::Member(int id, Role newUserRole) : userID(id), userRole(newUserRole) {}

//getter methods
int Member::getUserID() const{
    return userID;
}
bool Member::isAdmin() const{
    return userRole == Role::admin;
}

//Right now not needed, but this is for future proofing in case more roles are added
Role Member::getRole() const{
    return userRole;
}