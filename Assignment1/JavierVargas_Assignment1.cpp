/*
Javier Vargas - 01/25/2024 - Assignment 1
*/

#include <iostream>
#include <cstdlib> 
#include <cmath>

using namespace std;



int end() 
	{
		cout << "Sorry this is NOT an option\n****CLOSING PROGRAM****\n";
		exit(1);
	}

double amount() {
	double money;
	cout << "\nPlease input your monitary amount ($xx.xx):\n$";
	cin >> money;
	if (money < 0)
		end();
	return money;
}

int convert(string sys) {
	double money_input;
	const double TWO_D = 2.0;
	const double ONE_D = 1.0;
	const int QUARTERS = 25;
	const int DIMES = 10;
	const int NICKELS = 5;
	const int PENNIES = 1;


	if (sys == "1" || sys == "USD" || sys == "USD(1)")
	{
		cout << "\nYou have selected the USD coin system";

		money_input = amount();

		cout << "\nQuarter: " << static_cast<int>(money_input * 100) / QUARTERS;
		cout << "\nDimes: " << (static_cast<int>(money_input * 100) % QUARTERS) / DIMES;
		cout << "\nNickels: " << ((static_cast<int>(money_input * 100) % QUARTERS) % DIMES) / NICKELS;
		cout << "\nPennies: " << (((static_cast<int>(money_input * 100) % QUARTERS) % DIMES) % NICKELS) / PENNIES;
	}
	else if (sys == "2" || sys == "CAD" || sys == "CAD(2)")
	{
		cout << "\nYou have selected the CAD coin system";
		money_input = amount();

		int dollars = static_cast<int>(money_input);
		int cents = static_cast<int>((money_input - dollars) * 100 + .5);
		cout << "\nToonies (Two Dollar Coins): " << dollars / static_cast<int>(TWO_D);
		cout << "\nLoonies (One Dollar Coins): " << dollars % static_cast<int>(TWO_D);
		cout << "\nQuarters: " << cents / QUARTERS;

		cout << "\nDimes: " << (cents % QUARTERS) / DIMES;
		cout << "\nNickels: " << ((cents % QUARTERS) % DIMES) / NICKELS;
		cout << "\nPennies: " << (((cents % QUARTERS) % DIMES) % NICKELS);
	
	}
	else
	{
		end();
	}


	return 0;
}

int main()
{
	string money_sys;

	cout << "Thank you for picking this coin dispenser machine!!!\n";
	cout << "Which monetary system are you converting to? USD(1) or CAD(2)\n";
	cin >> money_sys;

	convert(money_sys);

	return 0;
}
