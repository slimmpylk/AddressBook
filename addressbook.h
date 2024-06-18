// addressbook.h
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "contact.h"
#include <vector>

class AddressBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact);
    void displayContacts() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
