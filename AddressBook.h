#pragma once

#include <iostream>


class Contact
{
public:
	std::string first;
	std::string last;
	unsigned long long int phoneNumber;
	std::string address;
	void contact();
	Contact* tail;
	Contact* next;
};

class AddressBook
{
private:
	int size;
	Contact* head;
	Contact* pos;

public:
	AddressBook();
	~AddressBook();
	void addContact(std::string, std::string, unsigned long long int, std::string);
	void deleteContact(std::string);
	int findContact(std::string );
	void editContact(std::string);
	void getCurrent();

};





