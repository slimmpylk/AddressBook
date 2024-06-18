// addressbook.cpp
#include "addressbook.h"
#include <fstream>
#include <iostream>

void AddressBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void AddressBook::displayContacts() const {
    for (const auto& contact : contacts) {
        contact.display();
        std::cout << "---------------------" << std::endl;
    }
}

void AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& contact : contacts) {
            outFile << contact.getName() << "\n" << contact.getPhoneNumber() << "\n" << contact.getEmail() << "\n";
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string name, phoneNumber, email;
        while (std::getline(inFile, name) && std::getline(inFile, phoneNumber) && std::getline(inFile, email)) {
            contacts.emplace_back(name, phoneNumber, email);
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}
