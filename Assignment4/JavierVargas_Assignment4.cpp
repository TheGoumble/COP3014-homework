/*
Javier Vargas - 03/14/2024 - Assignment 4
*/

#include <iostream>
#include <fstream>
#include <sstream> // for parsing - https://www.youtube.com/watch?v=CAqX8YT4lHI
#include <iomanip> // for fixed and setprecision
using namespace std;

/**
 * @brief Class creates a student with there info and grades
 *
 *
 */
class COP3014
{
private:
	string fname; // First Name
	string lname; // Last Name
	string znum; // Z number
	// Grades for Assignments 1-4
	int a1;
	int a2;
	int a3;
	int a4;

	int midterm;
	int final_exam;
	double total_grade;
	string final_letter_grade;

public:

	// Constructor
	/**
	 * @brief Construct a new COP3014 object
	 *
	 *
	 */
	COP3014();

	// Paramenterized constructor
	/**
	 * @brief Construct a new COP3014 object
	 *
	 * @param fname First name
	 * @param lname Last Name
	 * @param znum Z-number
	 * @param a1 Assignments 1 grade
	 * @param a2 Assignments 2 grade
	 * @param a3 Assignments 3 grade
	 * @param a4 Assignments 4 grade
	 * @param midterm Midterm exam grade
	 * @param final_exam Final exam grade
	 */
	COP3014(string fname, string lname, string znum, int a1, int a2, int a3, int a4, int midterm, int final_exam);

	// Setter functions
	/**
	 * @brief Set the first name
	 *
	 * @param first_name First name
	 */
	void set_first_name(string first_name);

	/**
	 * @brief Set the last name
	 *
	 * @param last_name Last name
	 */
	void set_last_name(string last_name);

	/**
	 * @brief Set the z number
	 *
	 * @param set_z_number Z-number
	 */
	void set_z_number(string z_number);

	/**
	 * @brief Set the assignment grades
	 *
	 * @param assignment1 Assignments 1 grades
	 * @param assignment2 Assignments 2 grades
	 * @param assignment3 Assignments 3 grades
	 * @param assignment4 Assignments 4 grades
	 */
	void set_assignment_grades(int assignment1, int assignment2, int assignment3, int assignment4);

	/**
	 * @brief Set the midterm grade
	 *
	 * @param midterm_grade Midterm exam grade
	 */
	void set_midterm_grade(int midterm_grade);

	/**
	 * @brief Set the final exam grade
	 *
	 * @param final_exam_grade Final exam grade
	 */
	void set_final_exam_grade(int final_exam_grade);

	/**
	 * @brief Set the total grade
	 *
	 * @param grade Total grade
	 */
	void set_total_grade(double grade);

	// Getter functions
	 /**
	 * @brief Get the first name
	 *
	 * @return string First name
	 */
	string get_first_name() const;

	/**
	 * @brief Get the last name
	 *
	 * @return string Last name
	 */
	string get_last_name() const;

	/**
	 * @brief Get the Z-number
	 *
	 * @return string Z-number
	 */
	string get_z_number() const;

	/**
	 * @brief Get the assignment 1 grade
	 *
	 * @return int Assignment 1 grade
	 */
	int get_assignment1_grade() const;

	/**
	 * @brief Get the assignment 2 grade
	 *
	 * @return int Assignment 2 grade
	 */
	int get_assignment2_grade() const;

	/**
	 * @brief Get the assignment 3 grade
	 *
	 * @return int Assignment 3 grade
	 */
	int get_assignment3_grade() const;

	/**
	 * @brief Get the assignment 4 grade
	 *
	 * @return int Assignment 4 grade
	 */
	int get_assignment4_grade() const;

	/**
	 * @brief Get the midterm grade
	 *
	 * @return int Midterm exam grade
	 */
	int get_midterm_grade() const;

	/**
	 * @brief Get the final exam grade
	 *
	 * @return int Final exam grade
	 */
	int get_final_exam_grade() const;

	/**
	 * @brief Get the total grade
	 *
	 * @return double Total grade
	 */
	double get_total_grade() const;

	/**
	 * @brief Get the final letter grade
	 *
	 * @return string Final letter grade
	 */
	string get_final_letter_grade() const;

	// Function for string defensive coding

	/**
	 * @brief Defensive coding for string input
	 *
	 * @param prompt Prompt message
	 * @return string Valid string input
	 */
	string checker(string prompt);

	/**
	 * @brief Defensive coding for Z-number input
	 *
	 * @param prompt Prompt message
	 * @return string Valid Z-number
	 */
	string z_checker(string prompt);

	/**
	 * @brief Defensive coding for grade input
	 *
	 * @param prompt Prompt message
	 * @return int Valid grade
	 */
	int grade_checker(string prompt);

	// Function to compute total grade
	/**
	 * @brief Computes total grade
	 *
	 */
	void compute_total_grade();

	// Function to compute final letter grade
	/**
	 * @brief Computes final letter grade
	 *
	 */
	void compute_final_letter_grade();

	// Output function to display student information
	/**
	 * @brief Outputs student information
	 *
	 * @param os Output stream
	 */
	void output(ostream& os) const;

	// Input function
	/**
	 * @brief Inputs student information
	 *
	 */
	void input();
};

/**
 * @brief Class representing a COP3014 student in Spring 2024 which includes labs
 *
 */
class Spring24 : public COP3014
{
private:
	int lab;

public:
	// Default constructor
	 /**
	 * @brief Construct a new Spring24 object
	 *
	 */
	Spring24();

	// Parameterized constructor
	/**
	 * @brief Construct a new Spring24 object
	 *
	 * @param fname First name
	 * @param lname Last name
	 * @param znum Z-number
	 * @param a1 Assignment 1 grade
	 * @param a2 Assignment 2 grade
	 * @param a3 Assignment 3 grade
	 * @param a4 Assignment 4 grade
	 * @param midterm Midterm exam grade
	 * @param final_exam Final exam grade
	 * @param lab Lab grade
	 */
	Spring24(string fname, string lname, string znum, int a1, int a2, int a3, int a4, int midterm, int final_exam, int lab);

	// Setter function for lab grade
	/**
	 * @brief Set the lab grade
	 *
	 * @param lab_grade Lab grade
	 */
	void set_lab_grade(int lab_grade);

	// Getter function for lab grade
	/**
	 * @brief Get the lab grade
	 *
	 * @return int Lab grade
	 */
	int get_lab_grade() const;

	// Function to compute total grade
	/**
	 * @brief Computes total grade
	 *
	 */
	void compute_total_grade();

	// Function to output student information
	/**
	 * @brief Outputs student information on to a txt file 
	 *
	 * @param os Output stream
	 */
	void output(ostream& os) const;

	// Function to input student information
	/**
	 * @brief Inputs student information
	 *
	 */
	void input();
};

/**
 * @brief Main function
 * 
 * @return int 0
 */
int main()
{
	COP3014 studentTest1("Frank", "Fabulous", "Z12345678", 90, 94, 0, 70, 100, 90);
	studentTest1.set_midterm_grade(0); // Change the midterm score
	studentTest1.compute_total_grade();
	studentTest1.compute_final_letter_grade();

	COP3014 studentTest2("Gina", "Genius", "Z98765432", 64, 54, 12, 34, 98, 95);
	studentTest2.set_assignment_grades(100, 100, 100, 95);
	studentTest2.compute_total_grade();
	studentTest2.compute_final_letter_grade();

	Spring24 studentTest3("Sammy", "Jackson", "Z00806783", 90, 94, 75, 100, 75, 76, 100);
	studentTest3.set_last_name("Surfer"); // Change the last name
	studentTest3.compute_total_grade();
	studentTest3.compute_final_letter_grade();

	Spring24 studentTest4("Markus", "Traveler", "50725032", 100, 100, 91, 50, 81, 80, 50);
	studentTest4.set_first_name("Tina"); // Change the first name
	studentTest4.compute_total_grade();
	studentTest4.compute_final_letter_grade();

	// set by user
	COP3014 studentTest5;
	studentTest5.input();
	studentTest5.compute_total_grade();
	studentTest5.compute_final_letter_grade();

	// set by user
	Spring24 studentTest6;
	studentTest6.input();
	studentTest6.compute_total_grade();
	studentTest6.compute_final_letter_grade();

	Spring24 studentTest7("Dora", "Trace", "z52725832", 96, 86, 91, 50, 81, 80, 45);
	studentTest7.set_lab_grade(80); // Change the lab grade to 80
	studentTest7.compute_total_grade();
	studentTest7.compute_final_letter_grade();

	ofstream outFile("student_grades.txt");
	if (outFile.is_open()) {
		studentTest1.output(outFile);
		studentTest2.output(outFile);
		studentTest3.output(outFile);
		studentTest4.output(outFile);
		studentTest5.output(outFile);
		studentTest6.output(outFile);
		studentTest7.output(outFile);

		outFile.close();
		cout << "Student information saved to student_grades.txt" << endl;
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
	return 0;
}

COP3014::COP3014() : fname("N/A"), lname("N/A"), znum("00000000"), a1(0), a2(0), a3(0), a4(0), midterm(0), final_exam(0)
{
	total_grade = 100.0;
	final_letter_grade = "N/A";
}

COP3014::COP3014(string fname, string lname, string znumber, int a1, int a2, int a3, int a4, int midterm, int final_exam)
	: fname(fname), lname(lname), a1(a1), a2(a2), a3(a3), a4(a4), midterm(midterm), final_exam(final_exam)
{
	// Strip leading 'Z' or 'z' characters
	while (!znumber.empty() && (znumber[0] == 'Z' || znumber[0] == 'z')) {
		znumber = znumber.substr(1);
	}

	// Check if the remaining string consists of exactly 8 digits
	bool valid = true;
	if (znumber.size() != 8) {
		valid = false;
	}
	else {
		for (char c : znumber) {
			if (!isdigit(c)) {
				valid = false;
				break;
			}
		}
	}

	// If valid, assign the z_number as is
	if (valid) {
		znum = "Z" + znumber;
	}
	else {
		// If it doesn't meet the requirements, display an error message or take appropriate action
		cout << "Invalid Z-number. Z-number must be 8 digits long." << endl;
		// You can also throw an exception or handle the error in any other way that suits your application
	}
	total_grade = 0.0;
	final_letter_grade = " ";
}

void COP3014::set_first_name(string first_name)
{
	fname = first_name;
}

void COP3014::set_last_name(string last_name)
{
	lname = last_name;
}

void COP3014::set_z_number(string z_number)
{
	znum = z_number;
}

void COP3014::set_assignment_grades(int assignment1, int assignment2, int assignment3, int assignment4)
{
	a1 = assignment1;
	a2 = assignment2;
	a3 = assignment3;
	a4 = assignment4;
}

void COP3014::set_midterm_grade(int midterm_grade) {
	midterm = midterm_grade;
}

void COP3014::set_final_exam_grade(int final_exam_grade)
{
	final_exam = final_exam_grade;
}

void COP3014::set_total_grade(double grade)
{
	total_grade = grade;
}

string COP3014::get_first_name() const
{
	return fname;
}

string COP3014::get_last_name() const
{
	return lname;
}

string COP3014::get_z_number() const
{
	return znum;
}

int COP3014::get_assignment1_grade() const
{
	return a1;
}

int COP3014::get_assignment2_grade() const
{
	return a2;
}

int COP3014::get_assignment3_grade() const
{
	return a3;
}

int COP3014::get_assignment4_grade() const
{
	return a4;
}

int COP3014::get_midterm_grade() const
{
	return midterm;
}

int COP3014::get_final_exam_grade() const
{
	return final_exam;
}

double COP3014::get_total_grade() const
{
	return total_grade;
}

string COP3014::get_final_letter_grade() const
{
	return final_letter_grade;
}

string COP3014::checker(string prompt)
{
	string input;
	do {
		cout << prompt;
		getline(cin, input);

		// Checks for empty or blank spaces if true prompted with why it did not pass - https://stackoverflow.com/questions/6444842/efficient-way-to-check-if-stdstring-has-only-
		if (input.empty() || input.find_first_not_of(" \t\n") == string::npos) {
			cout << "Invalid input. Please enter a name do not leave blank.\n";
		}
		// Checks for the use of space at any point
		else if (input.find(' ') != string::npos) {
			cout << "Invalid input. Please do not leave a blank space in the name\n";
		}

		// Repeat if conditions are not met
	} while (input.empty() || input.find_first_not_of(" \t\n") == string::npos || input.find(' ') != string::npos);

	return input;
}

string COP3014::z_checker(string prompt)
{
	string z_number;
	do {
		cout << prompt;
		getline(cin, z_number);

		// Strips leading 'Z' or 'z' chars
		while (!z_number.empty() && (z_number[0] == 'Z' || z_number[0] == 'z')) {
			z_number = z_number.substr(1);
		}

		// Check if the remaining string consists of exactly 8 digits
		bool valid = true;
		if (z_number.size() != 8) {
			valid = false;
		}
		else
		{
			// checks if string has only digits
			for (char c : z_number) {
				if (!isdigit(c)) {
					valid = false;
					break;
				}
			}
		}

		// If valid, assign the z_number;
		if (valid) {
			return "Z" + z_number;
		}
		else {
			cout << "Invalid Z-number. Z-number must be 8 digits long.\n";
		}
	} while (true);
}

int COP3014::grade_checker(string prompt)
{
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
		else if (value < 0 || value > 100) {
			cout << "This number will not work\n";
			checker_on = 1;
		}
	} while (checker_on);  // will loop till correct datatype is given
	return value;
}

void COP3014::compute_total_grade()
{
	if (midterm == 0 && final_exam == 0) {
		total_grade = 0;
		return; // If student missed both exams, total grade is 0
	}

	// Implamenting the equation given
	total_grade = ((a1 + a2 + a3 + a4) / 4.0) * 0.25 + midterm * 0.3 + final_exam * 0.45;
}

void COP3014::compute_final_letter_grade()
{
	// Following the grade scale given to set what grade students have
	if (total_grade >= 90) {
		final_letter_grade = "A";
	}
	else if (total_grade >= 87) {
		final_letter_grade = "A-";
	}
	else if (total_grade >= 83) {
		final_letter_grade = "B+";
	}
	else if (total_grade >= 80) {
		final_letter_grade = "B";
	}
	else if (total_grade >= 77) {
		final_letter_grade = "B-";
	}
	else if (total_grade >= 73) {
		final_letter_grade = "C+";
	}
	else if (total_grade >= 70) {
		if (midterm == 0 || final_exam == 0) {
			final_letter_grade = 'F'; // If the student missed an exam, the grade should be "F"
		}
		else {
			final_letter_grade = 'C';
		}
	}
	else if (total_grade >= 67) {
		final_letter_grade = "C-";
	}
	else if (total_grade >= 63) {
		final_letter_grade = "D+";
	}
	else if (total_grade >= 60) {
		final_letter_grade = "D";
	}
	else if (total_grade >= 51) {
		final_letter_grade = "D-";
	}
	else {
		final_letter_grade = "F";
	}

	if (final_exam == -1) {
		final_letter_grade = "F";
	}
}

void COP3014::output(ostream& os) const
{
	os << fixed << setprecision(2); // set precision to two decimal
	os << fname << " " << lname << " - " << znum << endl;
	os << "\t\tAssign 1: " << a1 << endl;
	os << "\t\tAssign 2: " << a2 << endl;
	os << "\t\tAssign 3: " << a3 << endl;
	os << "\t\tAssign 4: " << a4 << endl;
	os << "\t\tMidterm: " << ((midterm == 0) ? 0 : midterm) << endl;
	os << "\t\tFinal: " << ((final_exam == -1) ? 0 : final_exam) << endl; // Output 0 if absent
	os << "\t\tTotal grade: " << total_grade << endl;
	os << "\t\tFinal grade: " << final_letter_grade << endl << endl;
}

void COP3014::input()
{

	cout << "New Students\n";

	// Defensive coding for names
	fname = checker("Enter student's first name: ");
	lname = checker("Enter student's last name: ");
	
	// Defensive coding for z number
	znum = z_checker("Enter student's Z-number: ");

	cout << "Enter grades for 4 assignments:\n";
	// Defensive coding for the grade ints
	a1 = grade_checker("Assignmnet 1: ");
	a2 = grade_checker("Assignment 2: ");
	a3 = grade_checker("Assignment 3: ");
	a4 = grade_checker("Assignment 4: ");

	midterm = grade_checker("Enter midterm grade (or 0 if absent): ");

	final_exam = grade_checker("Enter final exam grade (of 0 if absent): ");
	if (final_exam == 0)
		final_exam = -1; // Set to -1 to indicate absence
}

// Define all the Spring24 class functions

Spring24::Spring24() : COP3014(), lab(0) {}

Spring24::Spring24(string fname, string lname, string znum, int a1, int a2, int a3, int a4, int midterm, int final_exam, int lab)
	: COP3014(fname, lname, znum, a1, a2, a3, a4, midterm, final_exam), lab(lab) {}

void Spring24::set_lab_grade(int lab_grade)
{
	lab = lab_grade;
}

int Spring24::get_lab_grade() const
{
	return lab;
}

void Spring24::compute_total_grade()
{
	// Implamenting the equation given
	double total_grade = ((get_assignment1_grade() + get_assignment2_grade() + get_assignment3_grade() + get_assignment4_grade()) / 4.0) * 0.25 + get_midterm_grade() * 0.25 + get_final_exam_grade() * 0.4 + lab * 0.1;
	set_total_grade(total_grade);
}

void Spring24::output(ostream& os) const {
	os << fixed << setprecision(2); // set precision to two decimal
	os << get_first_name() << " " << get_last_name() << " - " << get_z_number() << endl;
	os << "\t\tAssign 1: " << get_assignment1_grade() << endl;
	os << "\t\tAssign 2: " << get_assignment2_grade() << endl;
	os << "\t\tAssign 3: " << get_assignment3_grade() << endl;
	os << "\t\tAssign 4: " << get_assignment4_grade() << endl;
	os << "\t\tMidterm: " << ((get_midterm_grade() == 0) ? 0 : get_midterm_grade()) << endl;
	os << "\t\tFinal: " << ((get_final_exam_grade() == -1) ? 0 : get_final_exam_grade()) << endl; // Output 0 if absent
	os << "\t\tLab: " << lab << endl;
	os << "\t\tTotal grade: " << get_total_grade() << endl;
	os << "\t\tFinal grade: " << get_final_letter_grade() << endl << endl;
}

void Spring24::input()
{
	// Adds to the function in the COP3014 class
	COP3014::input();
	lab = grade_checker("Enter grade for labs: ");
}