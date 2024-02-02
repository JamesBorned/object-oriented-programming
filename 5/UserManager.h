#pragma once

#include "IUserManager.h"
#include "IUserRepository.h"
#include <iostream>
#include <vector>



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
        if(!user.getLogin().empty()){
            outuserfile << user.getId() << " " << user.getName() << " " << user.getLogin() << " " << user.getPassword() << '\n';
            outuserfile.close();
        }
    }

    void signOut(User& user) override
    {

        currentUser = nullptr;
        std::cout << "User has been signed out" << std::endl; // Пользователь вышел из системы
        std::string line;
        std::vector<std::string> lines;
        while(getline(outuserfile, line)){
            lines.push_back(line);
        }
        if(outuserfile.is_open()){
            for(int i=0; i<lines.size()-2; i++){
                outuserfile << lines[i] << '\n';
            }
        }
        outuserfile.close();
    }

    bool isAuthorized() override
    {
        std::string line;
        std::vector<std::string> lines;
        while(getline(outuserfile, line)){
            lines.push_back(line);
        }
        if(outuserfile.is_open()){
            for(int i=0; i<lines.size()-2; i++){
                outuserfile << lines[i] << '\n';
            }
        }
        outuserfile.close();
        return currentUser != nullptr;
    }
};