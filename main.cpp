// main.cpp
#include <iostream>
#include "addressbook.h"

void showMenu() {
    std::cout << "Address Book" << std::endl;
    std::cout << "1. Add Contact" << std::endl;
    std::cout << "2. Display Contacts" << std::endl;
    std::cout << "3. Save to File" << std::endl;
    std::cout << "4. Load from File" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    AddressBook addressBook;
    int choice;
    std::string filename = "contacts.txt";

    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the program." << std::endl;
            break;
        }

        std::string name, phoneNumber, email;
        switch (choice) {
            case 1:
                std::cin.ignore();
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                addressBook.addContact(Contact(name, phoneNumber, email));
                break;
            case 2:
                addressBook.displayContacts();
                break;
            case 3:
                addressBook.saveToFile(filename);
                break;
            case 4:
                addressBook.loadFromFile(filename);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
