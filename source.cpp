/*
CS281-Spring 2020
Phone Book
Steven Awakem
4/30/20
This is a linked list program that will add a contact you can type in the first name, last name, phone number, and address of the person.
the delete function does not delete the first contact for some reason
*/

#include <iostream>
#include "AddressBook.h"
#include <string>

using namespace std;

int menu();
void pauseScreen2();
void pauseScreen();
void clearScreen();


int main()
{
	int input = 0;
	AddressBook a;
	Contact c;
	
	do
	{
		input = menu();

		switch (input)
		{
		case 1:
			cout << "Type the first name:" << endl;

			cin >> c.first;
			cout << "Type the last name" << endl;
			cin >> c.last;
			cout << "Type their number" << endl;
			cin >> c.phoneNumber;		
			cout << "Type their address" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(256, '\n');
			getline(cin, c.address);
			a.addContact(c.first, c.last, c.phoneNumber, c.address);
			pauseScreen2();
			break;

		case 2:
			cout << "Please type the last name of the person your trying to find:" << endl;
			cin >> c.first;
			a.findContact(c.first);			
			pauseScreen();
			break;

		case 3:
			cout << "Type the first name of the contact you wish to edit:" << endl;
			a.getCurrent();
			cin >> c.first;
			a.editContact(c.first);
			pauseScreen();
			break;

		case 4:
			cout << "Type the first name of the contact you wish to delete:" << endl;
			a.getCurrent();
			cin >> c.first;
			a.deleteContact(c.first);
			pauseScreen();
			break;

		case 5:
			a.getCurrent();
			pauseScreen();
			break;
		}

		clearScreen();
	} while (input != 6);

	return 0;
}


int menu()
{
	int input;
	cout << "***Contacts***" << endl;
	cout << "1. Add Contact" << endl;
	cout << "2. Find Contact" << endl;
	cout << "3. Edit Contact" << endl;
	cout << "4. Delete Contact" << endl;
	cout << "5. Display Current Contact" << endl;
	cout << "6. Quit" << endl;
	cout << "Enter Choice: " << endl;
	cin >> input;
	while (input < 1 or input > 6)
	{
		cout << "Enter a valid menu item" << endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		cin >> input;
	}
	return input;
}


void pauseScreen()
{
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Enter to continue!" << endl;
	cin.get();
}

void clearScreen()
{

	system("CLS");
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
}
void pauseScreen2()
{
	cout << "Enter to continue!" << endl;
	cin.get();
}








