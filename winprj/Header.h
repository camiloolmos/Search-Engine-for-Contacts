#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int key;
string key_name, key_last;

struct Phone_Number
{
	int international, country, regional, home;
};
struct Address_Info
{
	string street_number, street_name, city, province, postal_code, country;
};
struct Meeting_Date
{
	string month, day, year;
};
struct Contact
{
	int contact_number;
	string first_name, last_name, company_name;
	Phone_Number phone;
	Address_Info address;
	Meeting_Date date;

	Contact() {}
	Contact(int _contact_number, string _first_name, string _last_name, string _company_name, Phone_Number _phone, Address_Info _address, Meeting_Date _date)
	{
		contact_number = _contact_number;  first_name = _first_name;  last_name = _last_name;  company_name = _company_name; phone = _phone; address = _address; date = _date;
	}
};
struct Displayer
{
	void operator () (Contact element)
	{
		cout << "Contact Number: " << element.contact_number << "\n" <<
			"First Name: " << element.first_name << "\n" <<
			"Last Name: " << element.last_name << "\n" <<
			"Company Name: " << element.company_name << "\n" <<
			"Contact Phone Number: " << element.phone.international << "-" << element.phone.country << "-" << element.phone.regional << "-" << element.phone.home << "\n" <<
			"Contact Address: " << element.address.street_number << " " << element.address.street_name << " " << element.address.city << " " << element.address.province << " " << element.address.postal_code << " " << element.address.country << "\n" <<
			"Meeting Date: " << element.date.day << "-" << element.date.month << "-" << element.date.year << "\n" << endl;
	}
};
struct NumberComparator
{
	bool operator () (Contact & contact1, Contact & contact2)
	{
		return contact1.contact_number < contact2.contact_number;
	}
};
struct NameComparator
{
	bool operator () (Contact & contact1, Contact & contact2)
	{
		return contact1.first_name + " " + contact1.last_name < contact2.first_name + " " + contact2.last_name;
	}
};
struct IsEqualNumber
{
	IsEqualNumber() {}
	IsEqualNumber(int _key)
	{
		key = _key;
	}
	bool operator () (Contact & aContact)
	{
		return aContact.contact_number == key;
	}
};
struct IsEqualName
{
	IsEqualName() {}
	IsEqualName(string _key_name, string _key_last)
	{
		key_name = _key_name;
		key_last = _key_last;
	}
	bool operator () (Contact & aContact)
	{
		return aContact.first_name == key_name;
		return aContact.last_name == key_last;
	}
};