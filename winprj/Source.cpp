//Edgar Camilo Olmos Madrid
//1631855
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "Header.h"

using namespace std;

void displayMain();

int main()
{
	char ans2;
	int size, key;
	

	vector<Contact> contact_vect;

	vector<Contact>::iterator it;

	Contact contact;
	cout << "How many contact do you like to add to the list? ";
	while (!(cin >> size))
	{
		cout << "'n Enter a valid contact number to add to the list: ";
		cin.clear();
		cin.ignore(10, '\n');
	}


	system("cls");
	int selection;
	char ans = 'y';
	do {
		displayMain();

		cin >> selection;
		system("cls");
		switch (selection)
		{
		case 1:
		{
			cout << "Type a list of contacts: \n" << endl;
			for (int i = 0; i < size; i++)
			{
				
				cout << "\n\tContact number: ";
				cin >> contact.contact_number;
				cout << "\n\tFirst Name: ";
				cin >> contact.first_name;
				cout << "\n\tFamily Name: ";
				cin >> contact.last_name;
				cout << "\n\tCompany Name: ";
				cin >> contact.company_name;
				cout << "\n\tContact Phone: ";
				cin >> contact.phone.international;
				cin >> contact.phone.country;
				cin >> contact.phone.regional;
				cin >> contact.phone.home;
				cout << "\nStreet Number: ";
				cin >> contact.address.street_number;
				cout << "\nStreet Name: ";
				cin >> contact.address.street_name;
				cout << "\nCity: ";
				cin >> contact.address.city;
				cout << "\nProvince: ";
				cin >> contact.address.province;
				cout << "\nPostal Code: ";
				cin >> contact.address.postal_code;
				cout << "\nCountry: ";
				cin >> contact.address.country;
				cout << "\n\tMeeting Date(day/month/year) : ";
				cin >> contact.date.day;
				cin >> contact.date.month;
				cin >> contact.date.year;
				cout << endl;
				contact_vect.push_back(contact);
			}
		}

		break;
		case 2:
		{
			do {
				cout << "Displaying Contact List: ";
				cout << "\n\nVector contains: \n" << endl;
				for_each(contact_vect.begin(), contact_vect.end(), Displayer());
				cout << "To Display them again? (Press Y) ->";
				cin >> ans;
			} while (ans == 'Y' || ans == 'y');
		}
		break;
		case 3:
		{
			cout << endl;
			cout << "Enter a Contact Number to delete it: ";
			while (!(cin >> key))
			{
				
				cout << "\n Please enter a valid contact number: ";
				cin.clear();
				cin.ignore(10, '\n');
			}
			it = find_if(contact_vect.begin(), contact_vect.end(), IsEqualNumber(key));
			if (it != contact_vect.end())
			{
				contact_vect.erase(it);
				cout << "\nContact deleted\n" << endl;

			}
			else
			{
				cout << "\nNOT FOUND";
			}
			for_each(contact_vect.begin(), contact_vect.end(), Displayer());

		} break;
		case 4:
		{ int selection2;
		char ans3 = 'y';
		do {
			cout << "\n\Search:\n";
			cout << "	\t1) Search by Contact number.\n";
			cout << "	\t2) Search by First name and last name.\n";
			cin >> selection2;
			system("cls");
			switch (selection2)
			{
			case 1:
			{ int search;
			do {
				cout << "\n";
				cout << "Enter the Contact Number: ";
				cin >> search;
				it = find_if(contact_vect.begin(), contact_vect.end(), IsEqualNumber(search));
				if (it != contact_vect.end())
				{
					cout << "Finded!\n";
					cout << "Contact Number: " << it->contact_number << "\n" <<
						"First Name: " << it->first_name << "\n" <<
						"Last Name: " << it->last_name << "\n" <<
						"Company Name: " << it->company_name << "\n" <<
						"Contact Phone Number: " << it->phone.international << "-" << it->phone.country << "-" << it->phone.regional << "-" << it->phone.home << "\n" <<
						"Contact Address: " << it->address.street_number << " " << it->address.street_name << " " << it->address.city << " " << it->address.province << " " << it->address.postal_code << " " << it->address.country << "\n" <<
						"Meeting Date: " << it->date.day << "-" << it->date.month << "-" << it->date.year << "\n" << endl;
				}
				else
				{
					cout << "\n Contact not Found";
				}
				cout << endl;
				cout << "To make another search press 'Y'";
				cin >> ans3;
			} while (ans3 == 'Y' || ans3 == 'y'); system("cls");
			}
			break;
			case 2:
			{int result;
			string key_name, key_last;
			do {
				cout << "Enter the contact name: ";
				cin >> key_name;
				cout << "Enter the contact last name: ";
				cin >> key_last;
				it = find_if(contact_vect.begin(), contact_vect.end(), IsEqualName(key_name, key_last));
				if (it != contact_vect.end())
				{
					cout << "Finded!";
					cout << "Contact Number: " << it->contact_number << "\n" <<
						"First Name: " << it->first_name << "\n" <<
						"Last Name: " << it->last_name << "\n" <<
						"Company Name: " << it->company_name << "\n" <<
						"Contact Phone Number: " << it->phone.international << "-" << it->phone.country << "-" << it->phone.regional << "-" << it->phone.home << "\n" <<
						"Contact Address: " << it->address.street_number << " " << it->address.street_name << " " << it->address.city << " " << it->address.province << " " << it->address.postal_code << " " << it->address.country << "\n" <<
						"Meeting Date: " << it->date.day << "-" << it->date.month << "-" << it->date.year << "\n" << endl;
				}
				else
				{
					cout << "\n Contact not Found";
				}
				cout << endl;
				cout << "Do you want to search by first name and last name again? (Press Y) ->";
				cin >> ans3;
			} while (ans3 == 'Y' || ans3 == 'y'); system("cls");

			}
			}
			cout << "Do you want to come back to the Search menu? (Press Y) ->";
			cin >> ans;
		} while (ans == 'Y' || ans == 'y');
		}
		break;
		case 5:
		{
			int selection2;
			char ans3 = 'y';
			do {
				cout << "Sort: \n";
				cout << "	\t1) Sort by contact number.\n";
				cout << "	\t2) Sort by company name.\n";
				cin >> selection2;
				system("cls");
				switch (selection2)
				{
				case 1:
				{ int search, result;
				do {
					sort(contact_vect.begin(), contact_vect.end(), NumberComparator());
					cout << "Displaying a Sorted Contact List by Number: ";
					for_each(contact_vect.begin(), contact_vect.end(), Displayer());
					cout << "Do you want to sort again? (Press Y) ->";
					cin >> ans3;
				} while (ans3 == 'Y' || ans3 == 'y'); system("cls");
				}
				break;
				case 2:
				{int result;
				string name, lastname;
				do {
					sort(contact_vect.begin(), contact_vect.end(), NameComparator());
					cout << "Displaying a Sorted Contact List by Name: ";
					for_each(contact_vect.begin(), contact_vect.end(), Displayer());
					cout << "Do you want to sort again? (Press Y) ->";
					cin >> ans3;
				} while (ans3 == 'Y' || ans3 == 'y'); system("cls");

				}
				}
				cout << "Do you want to come back to the sort menu? (Press Y) ->";
				cin >> ans;
			} while (ans == 'Y' || ans == 'y');
		}
		break;
		case 6:
		{return 0;
		}
		default:
			return 0;
		}
		cout << " \n";
		cout << " If you want to do another option from the application , press Y \n";
		cin >> ans;
	}
	while (ans == 'y' || ans == 'Y');
	system("cls");


	system("pause");
	return 0;
}

void displayMain()
{
	cout << "Press1  to Create and add a contacs.\n";
	cout << "Press 2 to Display the contacs list.\n";
	cout << "	(3) Delete a Contact from the list \n";
	cout << "	(4) Search for a contact by:\n";
	cout << "		\t|->Contact number.\n";
	cout << "		\t|->First name and last name.\n\n";
	cout << "	(5) Sort the contacts by:\n";
	cout << "		\t|->contact number.\n";
	cout << "		\t|->company name.\n\n";
	cout << "	(6) Exit the application.\n";
}
