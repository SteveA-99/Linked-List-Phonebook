#include "AddressBook.h"
#include <string>

AddressBook::AddressBook()
{

	head = nullptr;
	pos = nullptr;
}

AddressBook::~AddressBook()
{
	pos = head;
	Contact* temp;
	if (head == nullptr)
	{
		return;
	}
	while (pos->tail != nullptr)
	{
		temp = pos;
		pos = pos->tail;
		delete temp;
	}
	delete pos;
	head = nullptr;
	pos = nullptr;
}

void AddressBook::addContact(std::string fname, std::string lname, unsigned long long int pNum, std::string ad)
{
	Contact* temp = new Contact;
	temp->next = nullptr;
	temp->first = fname;
	temp->last = lname;
	temp->phoneNumber = pNum;
	temp->address = ad;
	if (head != nullptr)
	{
		pos = head;

		while (pos->next != nullptr)
		{
			
			pos = pos->next;

		}
		pos->next = temp;
	}
	else
	{

		head = temp;
	}

}

void AddressBook::deleteContact(std::string n)
{
	Contact* temp = head;
	Contact* pos = head->next;

	while (pos != nullptr)
	{
		if (pos->first == n)
		{
			break;
		}
		else
		{
			temp = pos;
			pos = pos->next;
		}
	}
	if (pos == nullptr)
	{
		std::cout << "There is nobody with that name" << std::endl;
	}
	else
	{
		std::cout << "deleting " << pos->first << std::endl;
		temp->next = pos->next;
		delete pos;
	}
}



int AddressBook::findContact(std::string name)
{
	Contact* p = head;
	while (p != nullptr)
	{
		if (p->last == name)
		{
			std::cout << p->first << " " << p->phoneNumber << " " << p->address << std::endl;

		}

		p = p->next;
	}

	return 0;
}


void AddressBook::editContact(std::string fname)
{
	Contact* e = head;
	int choice;
	std::string n;

	while (e != nullptr)
	{

		if (e->first.compare(fname) == 0)
		{
			std::cout << "what do you want to change?" << std::endl;
			std::cout << "1. Last name" << std::endl;
			std::cout << "2. Phone number" << std::endl;
			std::cout << "3. Address" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 1:
				std::cout << "What is the last name?" << std::endl;
				std::cin >> n;
				e->last = n;
				break;
			case 2:
				std::cout << "What is the phone number?" << std::endl;
				std::cin >> choice;
				e->phoneNumber = choice;
				break;
			case 3:
				std::cout << "What is the address?" << std::endl;
				std::cin >> n;
				e->address = n;
				break;

			}
		}
		e = e->next;
	}
}

void AddressBook::getCurrent()
{
	Contact* contactPtr;
	contactPtr = head;
	while (contactPtr)
	{
		std::cout << contactPtr->first << " " << contactPtr->last << " " << contactPtr->phoneNumber << " " << contactPtr->address << std::endl;
		contactPtr = contactPtr->next;

	}
}



void Contact::contact()
{
	Contact* temp;
	temp->first;
	temp->last;
	temp->phoneNumber;
	temp->address;
}





