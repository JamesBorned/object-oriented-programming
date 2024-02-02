#pragma once
#include "User.h"
#include <fstream>

std::fstream userfile("users.txt");
std::fstream outuserfile("outusers.txt");

__interface IUserManager
{
public:
    void signIn(User& user);
    void signOut(User& user);
    bool isAuthorized(User& user);
};