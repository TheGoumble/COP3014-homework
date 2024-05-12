/*
Javier Vargas - 04/19/2024 - Assignment 6
*/

#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

class StringVar
{
public:
	StringVar(int size1);
	//Initializes the object so it can accept string values up to size
	//in length. Sets the value of the object equal to the empty string.

	StringVar();
	//Initializes the object so it can accept string values of length 100
	//or less. Sets the value of the object equal to the empty string.

	StringVar(const char a[]);
	//Precondition: The array a contains characters terminated with '\0'.
	//Initializes the object so its value is the string stored in a and
	//so that it can later be set to string values up to strlen(a) in length.

	StringVar(const StringVar& string_object);
	//Copy constructor.

	//~StringVar(); for some reason the code will not allow >> if this member exists
	//Returns all the dynamic memory used by the object to the freestore.

	int length() const;
	//Returns the length of the current string value.

	void input_line(istream& ins);
	//Precondition: If ins is a file input stream, then ins has been
	//connected to a file.
	//Action: The next text in the input stream ins, up to '\n', is copied
	//to the calling object. If there is not sufficient room, then
	//only as much as will fit is copied.

	friend ostream& operator <<(ostream& outs, const StringVar& the_string);
	//Overloads the << operator so it can be used to output values
	//of type StringVar
	//Precondition: If outs is a file output stream, then outs
	//has already been connected to a file.

	// Added code for Assignment 6
	/**
	* @brief Returns a specified substring of the StringVar object.
	*
	* @param location A pointer to the starting position of the substring.
	* @param num_chars The number of characters to include in the substring.
	* @return StringVar A new StringVar object containing the specified substring.
	*/
	StringVar copy_piece(const char* loctaion, int num_chars) const;

	/**
	* @brief Returns a specified single character from the StringVar object.
	*
	* @param location A pointer to the position of the character.
	* @return char The character at the specified location.
	*/
	char one_char(const char* location) const;

	/**
	* @brief Changes a specified character in the StringVar object.
	*
	* @param location A pointer to the position of the character to change.
	* @param new_char The new character to set at the specified location.
	*/
	void set_char(const char* location, char new_char);

	/**
	* @brief Overloaded equality operator to compare two StringVar objects.
	*
	* @param other The StringVar object to compare with.
	* @return true If the two StringVar objects are equal.
	* @return false Otherwise.
	*/
	bool operator ==(const StringVar& other) const;
	
	/**
	* @brief Overloaded concatenation operator to concatenate two StringVar objects.
	*
	* @param other The StringVar object to concatenate with.
	* @return StringVar A new StringVar object containing the concatenated strings.
	*/
	StringVar operator +(const StringVar& other) const;
	
	/**
	* @brief Overloaded extraction operator to read a StringVar object from an input stream.
	*
	* @param ins The input stream from which to read.
	* @param str The StringVar object to store the input.
	* @return istream& The input stream after extraction.
	*/
	friend istream& operator>>(istream& ins, StringVar& str);

	/**
	* @brief Accesses a character at the specified index in the StringVar object.
	*
	* @param index The index of the character to access.
	* @return const char& A reference to the character at the specified index.
	*/
	const char& operator[](size_t index) const;

private:
	char* value; //pointer to dynamic array that holds the string value.
	int max_length; //declared max length of any string value.
};
void conversation(int max_name_size);
//Carries on a conversation with the user.

int main()
{
	StringVar str1("Hello"), str2("World");

	cout << str1 << " " << str2 << endl;

	// Test copy_piece
	StringVar test1 = str1.copy_piece(&str1[3], 2);
	cout << "Substring \"Hel\" from Hello: " << test1 << endl;

	// Test one_char and set_char
	char test2 = str1.one_char(&str1[1]);
	cout << "Character at position 1 of \"Hello\": " << test2 << std::endl;
	str2.set_char(&str2[1], '0');
	cout << "Updated string \"World\": " << str2 << std::endl;

	// Test equality operator
	if (str1 == str2) {
		cout << "Strings are equal." << endl;
	}
	else {
		cout << "Strings are not equal." << endl;
	}

	// Test concatenation operator
	StringVar combined = str1 + str2;
	cout << "Concatenated string: " << combined << endl;

	// Test extraction operator
	StringVar input;
	cout << "Enter a word: ";
	cin >> input;
	cout << "You entered: " << input << endl;

	return 0;
}

//This is only a demonstration function:
void conversation(int max_name_size)
{
	StringVar your_name(max_name_size), our_name("Anita");
	cout << "What is your name?\n";
	your_name.input_line(cin);
	cout << "We are " << our_name << endl;
	cout << "We will meet again " << your_name << endl;
}

//Uses cstddef and cstdlib:
StringVar::StringVar(int size1)
{
	max_length = size1;
	value = new char[max_length + 1];//+1 is for '\0'.
	value[0] = '\0';
}

//Uses cstddef and cstdlib:
StringVar::StringVar()
{
	max_length = 100;
	value = new char[max_length + 1];//+1 is for '\0'.
	value[0] = '\0';
}

//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const char a[])
{
	max_length = strlen(a) + 1;
	value = new char[max_length + 1];//+1 is for '\0'.
	strcpy_s(value, max_length + 1, a); // strcpy gave me an error
}
//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const StringVar& string_object)
{
	max_length = string_object.length();
	value = new char[max_length + 1];//+1 is for '\0'.
	strcpy_s(value, max_length + 1, string_object.value);
}

//StringVar::~StringVar()
//{
//	delete[] value;
//}
//Uses cstring:

int StringVar::length() const
{
	return strlen(value);
}

//Uses iostream:
void StringVar::input_line(istream& ins)
{
	ins.getline(value, max_length + 1);
}
//Uses iostream:
ostream& operator <<(ostream& outs, const StringVar& the_string)
{
	outs << the_string.value;
	return outs;
}

// Added code
StringVar StringVar::copy_piece(const char* location, int num_chars) const {
	// Calculate the length of the substring
	int length = strlen(location);

	// Check if the requested number of characters exceeds the len of str
	if (num_chars > length) {
		num_chars = length;
	}
	// Create a temporary array to store the substring
	char* temp = new char[num_chars + 1];
	// Copy the substring from the specified location
	strncpy_s(temp, num_chars + 1, location, num_chars);
	temp[num_chars] = '\0'; // Null-terminate the string
	// Create a new StringVar object with the substring
	StringVar result(temp);
	delete[] temp; // Free the temporary array
	return result;
}

char StringVar::one_char(const char* location) const {
	return *location;
}

void StringVar::set_char(const char* location, char new_char) {
	*const_cast<char*>(location) = new_char; // Set the character at the specified location to the new character
}

bool StringVar::operator ==(const StringVar& other) const {
	return strcmp(value, other.value) == 0; // Compare the string values
}

StringVar StringVar::operator +(const StringVar& other) const {
	// Calculate the length of the concatenated string
	int length = strlen(value) + strlen(other.value);
	// Create a temporary array to store the concatenated string
	char* temp = new char[length + 1];
	// Copy the first string
	strcpy_s(temp, length + 1, value);
	// Concatenate the second string
	strcat_s(temp, length + 1, other.value);
	// Create a new StringVar object with the concatenated string
	StringVar result(temp);
	delete[] temp; // Free the temporary array
	return result;
}

istream& operator >>(istream& ins, StringVar& str) {
	string temp; // Temporary string to hold the input word
	ins >> temp; // Read a word from the input stream
	str = temp.c_str(); // Assign the word to the StringVar object
	return ins;
}

const char& StringVar::operator[](size_t index) const {
	if (index < strlen(value)) {
		return value[index];
	}
	else {
		// Handle out-of-bounds access, for example return the last character
		return value[strlen(value) - 1];
	}
}