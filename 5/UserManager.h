#pragma once

#include "IUserManager.h"
#include "IUserRepository.h"
#include "iostream"

std::fstream file("sessions.txt");

class UserManager : public IUserManager
{
private:
    User* currentUser;
    IUserRepository* userRepository;
public:

    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr)
    {
    }

    void signIn(User& user) override
    {
        currentUser = &user;

        if (!file.is_open())
        {
            return;
        }

        int id = user.getId();
        file << id << '\n';

        file.close();
    }

    void signOut(User& user) override
    {

        currentUser = nullptr;
        std::cout << "User has been signed out" << std::endl; // Пользователь вышел из системы
        file.open("sessions.txt", std::ios::in | std::ios::out);
        file.close();
    }

    bool isAuthorized(User& user) override
    {
        return currentUser != nullptr;
        int id;
        if (file >> id && id==user.getId()) {
            return true;
        }
        else {
            return false;
        }
    }

};