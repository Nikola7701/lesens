#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

struct Address
{
	string street;
	short house;
	short flat;
};

struct Phonebook
{
	string name;
	long number;
	Address address;
};
int main()
{
	setlocale(LC_ALL, "Rus");
	Phonebook ab1;
	cout << "¬ведите им€ абонента:";
	getline(cin,ab1.name); //через поле
	cout << "¬ведите номер: ";
	cin >> ab1.number; //через поле
	cout << "¬ведите улицу: ";
	cin.ignore();
	getline(cin, ab1.address.street);
	cout << "¬ведите номер дома: ";
	cin >> ab1.address.house;
	cout << "¬ведите номер квартиры: ";
	cin >> ab1.address.flat;
	cout << ab1.name;
	cout << " " << ab1.number;
	cout << " " << ab1.address.street;
	cout << " " << ab1.address.house;
	cout << " " << ab1.address.flat;
	return 0;
}
