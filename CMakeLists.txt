cmake_minimum_required(VERSION 3.28)
project(harjoittelu)

set(CMAKE_CXX_STANDARD 26)

add_executable(harjoittelu main.cpp
        addressbook.cpp
        contact.cpp
        contact.h
        addressbook.h)
