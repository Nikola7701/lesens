#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
template<typename T>
inline void Input(const std::string message, T &value)
{
	std::cout << message;
	std::cin >> value;
}

union MyUn
{
	short menu;
	short year;
}u;
void Menu(void)
{
	cout << "\n1 - годовщина свадьбы";
	cout << "\n2 - Âûñîêîñòíûé ëè ãîä";
	cout << "\n3 - Ëóííîå ÷èñëî òåêóùåãî ãîäà";
	cout << "\n4 - âûõîä";

 }

using years = long;
using one_year = short;

years DateDif(one_year year)
{
	time_t t;
	time(&t);
	return 1900 + localtime(&t)->tm_year - year;
}
void WeddingAnniversary(one_year year)
{

	enum Weddings
	{
		sitcevaya = 1, bumaznaya, kozh
	};
	years y = DateDif(year);
	switch (y)
	{
	case Weddings::sitcevaya:
		cout << endl << y << " - Ñèòöåâàÿ ñâàäüáà";
		break;
	default:
		cout << "Íåò òàêîé ñâàäüáû";
	}
}
bool IsLeapYear(one_year year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}

short MoonNum(one_year year)
{
	return year % 19 + 1;
}

int main()
{
	setlocale(LC_ALL, "");
	while (true)
	{
		system("cls");
		Menu();
		Input("Âûáåðåòå ïóíêò ìåíþ: ", u.menu);
		switch (u.menu)
		{
		case 1:
			Input("\nÂâåäèòå ãîä: ", u.year);
			WeddingAnniversary(u.year);
			break;
		case 2:
			Input("\nÂâåäèòå ãîä: ", u.year);
			if (IsLeapYear(u.year))
				cout << u.year << "Âèñîêîñíûé ãîä";
			else
				cout << u.year << "Íåâèñîêîñíûé ãîä";
			break;
		case 3:
			Input("\nÂâåäèòå ãîä: ", u.year);
			cout << "\nËóííîå ÷èñëî" << u.year << "ãîäà:" << MoonNum(u.year);
			break;
		case 4:
			return 0;
		default:
			cout << "\nÍåâåðíûé ïóíêò ìåíþ";
		}
		cout << endl;
		system("pause");
	}
	return 0;
}
