/*
Javier Vargas - 02/09/2024 - Assignment 2
*/

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip> //allows for the setprecision(n) functionality
#include <string>  // allows for to_string functionality

using namespace std;

//func for defensive code
int Pass(string prompt) { // parms are the var's prompt
	bool checker_on;

	int value;
	do {
		checker_on = 0; // set to continue repeating till true
		cout << prompt;
		cin >> value;

		if (!cin || cin.peek() != '\n') { // if cin accepts an input unaligned with data type
			cout << "A whole number value is needed\n";
			cin.clear(); // clear the cin error
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // using limits header allows for a better whipe
			checker_on = 1;
		}
		else if (value <= 0) {
			cout << "This number will not work\n";
			checker_on = 1;
		}
	} while (checker_on);  // will loop till correct datatype is given
	return value;
}

double PassD(string prompt) {
	bool checker_on;

	double value;
	do {
		checker_on = 0;
		cout << prompt;
		cin >> value;

		if (!cin) {
			cout << "A number value is needed\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checker_on = 1;
		}
		else if (value <= 0) {
			cout << "This number will not work\n";
			checker_on = 1;
		}
	} while (checker_on);
	return value;
}

int TermType() { // allows for option between years or months
	bool checker_on;
	char term;
	int term_num;

	do {
		checker_on = 0;
		cout << "Will your loan term be in Years(Y) or Months(M)?:\n";
		cin >> term;

		if (!cin || (term != 'M' && term != 'Y')) {
			cout << "Choices must be either Y or M\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checker_on = 1;
		}
		else if (term == 'Y') {
			term_num = Pass("Please input the amount of years on the loan term:\n") * 12; // use the pass function and * by 12 to produce the months
		}
		else {
			term_num = Pass("Please input the amount of months on the loan term:\n");
		}
	} while (checker_on);
	return term_num;
}

double MonthRate(int annual_rate) { // determines Monthy rate of interest
	double monthly_rate = pow(1 + (static_cast<double>(annual_rate) / 100), static_cast<double>(1) / 12) - 1;
	//double monthly_rate = 1+(static_cast<double>(annual_rate) / 100); //debug
	//cout << monthly_rate << endl; // debug
	//monthly_rate = pow(monthly_rate, static_cast<double>(1) / 12) - 1; //debug
	//cout << monthly_rate << endl; // debug
	return monthly_rate;
}

double MonthPay(double loan, int term, double monthly_rate) { // determines monthly fixed payment
	double M = pow(1 + monthly_rate, static_cast<double>(term));
	//cout << M << endl; // debug
	M = loan * ((monthly_rate * M) / (M - 1));
	//cout << setprecision(5) << M << endl; // debug
	return M;
}


// Un-used code but I keep it in to show thougth process of how to create table
// Still need split this into 3 different function 
//string AmortizTable(double M, double r, int n, double P) { //made final table a string holding all infromation 
//	string table;
//	double tot_pay = P;
//	double tot_int = 0.0;
//	double balance = P;
//	double principal;
//	double interest;
//	int year = 1;
//
//	table = "\t\tBeginning Balance\tInterest\tPrincipal\t\tEnding Balance\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//	for (int i = 1; i <= n; i++) {
//		interest = P * r;
//		principal = M - interest;
//		balance -= principal;
//		balance = abs(balance); // remove that -0 at the bottem of the balance
//		table += "\t" + to_string(i) + "\t\t" + formatCurr(P) + "\t\t" + formatCurr(interest) + "\t\t" + formatCurr(principal) + "\t\t" + formatCurr(balance) + "\n";
//
//		if ((i % 12) == 0) { // tracks every year reached 
//			table += "\t\t\t\t\t\tYear #" + to_string(year) + " End\n";
//			year += 1;
//		}
//		tot_int += interest; // adding to the total interest
//		P = balance;	// replacing the old balance with the updated
//	}
//	table += "\n\n\tPayment Every Month\t\t" + formatCurr(M) + "\n\n\tTotal Payments\t\t" + formatCurr(tot_pay + tot_int) + "\n\n\tTotal Interest\t\t" + formatCurr(tot_int) + "\n"; // displaying the summary
//	return table;
//}

double Table(double M, double r, int n, double P) {
	double balance = P;
	double principal;
	double interest;
	double tot_int = 0.0; 
	int year = 1; // begin at 1 years
	cout << "\t| Month | Beginning Balance | Interest | Principal | Ending Balance |\n";
	cout << "\t|--------------------------------------------------------------------|\n";

	for (int i = 1; i <= n; i++) {
		interest = P * r;
		principal = M - interest;
		balance -= principal;
		balance = abs(balance); // remove that -0 at the bottem of the balance

		cout << "\t|" << setw(6) << i << " | " << setw(19) << fixed << setprecision(2) << "$" << M << " | " << setw(8) << fixed << setprecision(2) << "$" << interest << " | " << setw(9) << fixed << setprecision(2) << "$" << principal << " | " << setw(16) << fixed << setprecision(2) << "$" << balance << "|\n";

		if ((i % 12) == 0) { // tracks every year reached 
			cout << "\t\t\t\t\t\tYear #" << year << " End\n";
			year += 1;
		}
		tot_int += interest; // adding to the total interest
		P = balance;	// replacing the old balance with the updated

	}
	return tot_int;
}

double Summary(double tot_interest, double P, double M) { // func to show the total payment, interest, and monthly payment
	cout << "\n\n\tPayment Every Month:\t\t$" << fixed << setprecision(2) << M << endl;
	cout << "\n\n\tTotal Payments:\t\t$" << fixed << setprecision(2) << (tot_interest + P) << endl; // add the total interest with the total loan
	cout << "\n\n\tTotal Interest:\t\t$" << fixed << setprecision(2) << tot_interest << endl;
	return 0;
}

int main()
{
	bool repeat;
	bool invalid;
	char answer;
	double P;
	double r;
	double M;
	double total_interest;
	int APR;
	int n;

	do { // allow to repeat till user stops
		repeat = 1;
			cout << "\t\t\tLoan Calculator \n";

		P = PassD("Please enter your loan amount XX.XX (dollars and cents):\n");
		cout << "Your loan amounts to: " << P << endl;

		APR = Pass("Please enter your Annual Percentage Rate(APR) XX(percentage)\n");
		cout << "Your APR is: " << APR << endl;

		n = TermType();
		cout << "Your loan term is " << n << " months long." << endl;

		r = MonthRate(APR);
		//cout << r // Debug

		M = MonthPay(P, n, r);
		//cout << M // Debug

		//cout << AmortizTable(M, r, n, P); //output table and summary amounts
		total_interest = Table(M, r, n, P); //creates the table while also setting the total interest to a var

		Summary(total_interest, P, M); 

		do { // Allows only Y or N as an option
			invalid = 0;

			cout << "\n\n\nWould you like to retart (Y/N)?\n";
			cin >> answer;
			if (!cin || (answer != 'Y' && answer != 'N')) {
				cout << "Choices must be either Y or N\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				invalid = 1;
			}
		} while (invalid);
		if (answer == 'N') { // closing the program
			cout << "Goodbye";
			repeat = 0;

		}

	} while (repeat);

	return 0;
}