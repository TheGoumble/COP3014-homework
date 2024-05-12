/*
Javier Vargas - 02/22/2024 - Assignment 3
*/

#include <iostream>
#include <cstdlib> //for rand() function
#include <ctime> //for setting rand() seed
#include <iomanip>
#include <fstream>
#include <sstream> // for parsing - https://www.youtube.com/watch?v=CAqX8YT4lHI
#include <vector> //for manipulation of arrays - https://www.youtube.com/watch?v=dQG41m6vf3A

using namespace std;

const int IMP_NUM = 10; // Define a constant for the number of students & quizzes 

// Prototypes

/**
* @brief Produce a random number of quizzes from 0 to 10.
* @return Random number of quizzes.
*/
int RandNumQuiz();

/**
* @brief Produce a random number of scores from 1 to 20.
* @return Random score.
*/
int RandScore();

/**
* @brief Calculate the average scores per student.
* @param quizScores Vector containing quiz scores.
* @return Average score.
*/
double CalAvg(const vector<int>& quizScores);

/**
* @brief Function for defensive coding, making sure the user inputs something valid.
* @param prompt Prompt message that aligns with what should be inputed.
* @param i Iteration taking place in the for-loop
* @return Valid user input.
*/
string Checker(string prompt, int i);

/**
* @brief Ask the user to input the names of the student.
* @param i Iteration taking place in the for-loop
* @return Formatted the fully formatted string to use in the txt file.
*/
string NameInput(int i);

/**
* @brief Create the file input with student names and scores needed to produce the file output.
* @param fileName Name of the file to generate.
*/
void GenInFile(string fileName);

/**
* @brief Process student data and calculate averages.
* @param inputFile Input file stream being used.
* @param outputFile Outpuit file stream being used.
*/
void ImproveData(ifstream& inputFile, ofstream& outputFile);

int main()
{
	srand(time(0));

	GenInFile("student_data.txt");

	ifstream inputFile("student_data.txt");
	ofstream outputFile("student_avg_data.txt");

	// Error handling
	if (!inputFile.is_open() || !outputFile.is_open()) {
		cout << "Error opening files." << endl;
		// return 1 as indication of error
		return 1;
	}

	//populates the read data into the studentData vector
	ImproveData(inputFile, outputFile);

	inputFile.close();
	outputFile.close();

	return 0;
}

int RandNumQuiz() {
	return rand() % 11;
}

int RandScore() {
	return rand() % 20 + 1;
}

double CalAvg(const vector<int>& quizScores) {
	if (quizScores.empty()) {
		return  0.0;
	}

	double total = 0.0;

	// range based for loop iterate through vector - https://www.youtube.com/watch?v=8qrZYjL2jBg
	for (int score : quizScores) {
		total += score;
	}

	// divides the total by the max amout of quizes given 10
	return total / IMP_NUM;
}

string Checker(string prompt, int i) {
	string input;
	do {
		cout << prompt << i + 1 << ": ";
		getline(cin, input);

		// Checks for empty or blank spaces if true prompted with why it did not pass - https://stackoverflow.com/questions/6444842/efficient-way-to-check-if-stdstring-has-only-
		if (input.empty() || input.find_first_not_of(" \t\n") == string::npos) {
			cout << "Invalid input. Please enter a name do not leave blank.\n";
		}
		// Checks for the use of space at any point
		else if(input.find(' ') != string::npos){
			cout << "Invalid input. Please do not leave a blank space in the name\n";
		}

		// Repeat if conditions are not met
	} while (input.empty() || input.find_first_not_of(" \t\n") == string::npos || input.find(' ') != string::npos);

	return input;
}

string NameInput(int i) {
	string firstName, lastName, formatted;

	firstName = Checker("Enter first name for student ", i);
	lastName = Checker("Enter last naem for studnet ", i);

	formatted = lastName + ", " + firstName + " ";
	return formatted;
}

void GenInFile(string fileName) {
	ofstream inputFile(fileName);

	// Error handling
	if (!inputFile.is_open()) {
		cout << "Error opening files." << endl;
		// fails to prove file so exits
		exit(1);
	}

	for (int i = 0; i < IMP_NUM; ++i) {
		string student;

		//Bug test for math
		//inputFile << "Student" << i + 1 << ", " << "FistName" << i + 1 << " ";

		student = NameInput(i);
		inputFile << student;

		int quizes = RandNumQuiz();
		for (int j = 0; j < quizes; ++j) {
			inputFile << RandScore() << " ";
		}
		inputFile << endl;
	}

	inputFile.close();
}

void ImproveData(ifstream& inputFile, ofstream& outputFile) {
	string line;
	while (getline(inputFile, line)) {
		stringstream stream(line);
		string lastName, firstName;

		// Pull out the last name, first name, and quiz scores
		stream >> lastName >> firstName;

		vector<int> quizScores;
		int score;
		while (stream >> score) {
			quizScores.push_back(score);
		}

		// Compute scores to find average
		double average = CalAvg(quizScores);

		// write into the output file
		outputFile << line << ": " << fixed << setprecision(1) << average << endl;
	}
}