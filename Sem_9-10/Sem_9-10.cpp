#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <locale>
#include <sstream>

#include <Windows.h> 

using namespace std;

int main()
{
	SetConsoleCP(CP_UTF8); // настраиваем консоль, чтобы она могла корректно
	SetConsoleOutputCP(CP_UTF8); // работать с выводом символов в кодировке UTF-8
	cout << "Welcome to the currency converter. Select the currency you want to convert" << endl;
	cout << "(1) RUB to EUR" << endl;
	cout << "(2) EUR to RUB" << endl;
	string answer;
	long double value1;
	string value_in;
	cin >> answer;
	if (answer == "1") {
		cout << "You have chosen to convert RUB to USD, enter the amount:" << endl;
		cin >> value_in;
		istringstream in(value_in);
		in.imbue(locale("ru_RU.utf8"));
		in >> get_money(value1,true);
		cout << "In Euro it will be ";
		value1 = value1 / 80;
		ostringstream sout;
		sout.imbue(locale("de_DE.UTF8"));
		sout << showbase << put_money(value1) << endl;
		cout << sout.str() << endl; // вывели в cout строку в UTF-8
	}
	else {
		cout << "You have chosen to convert USD to RUB, enter the amount:" << endl;
		cin >> value_in;
		istringstream in(value_in);
		in.imbue(locale("en_EN.utf8"));
		in >> get_money(value1, true);
		cout << "In Rub it will be ";
		value1 = value1 * 80;
		ostringstream sout;
		sout.imbue(locale("ru_RU.utf8"));
		sout << showbase << put_money(value1) << endl;
		cout << sout.str() << endl; // вывели в cout строку в UTF-8
	}
}