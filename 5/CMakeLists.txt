cmake_minimum_required(VERSION 3.21)
project(5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(5
        FileUserRepository.h
        IRepository.h
        IUserManager.h
        IUserRepository.h
        LabOOP_5.cpp
        User.h
        UserManager.h)
