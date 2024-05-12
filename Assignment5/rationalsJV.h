#ifndef RATIONALS_JV_H
#define RATIONALS_JV_H

#include <iostream>

namespace JV {
	using namespace std;

	/**
	 * @brief A class to represent rational numbers.
	 */
	class Rational {
	private:
		int numerator;
		int denominator;

	public:
		// Constructors

		/**
		 * @brief Default constructor. Initializes the raional number to 0/1.
		 */
		Rational();

		/**
		 * @brief Constructor for creating a rational number from numerator and denominator.
		 * @param wholeNum The whole number to be converted to rational number.
		 */
		Rational(int wholeNum);

		/**
		 * @brief Constructor for creating a rational number from numerator and denominator.
		 * @param numer The numerator of the rational number.
		 * @param denom The denominator of the ratinal number.
		 */
		Rational(int numer, int denom);

		// Overload input and output operators

		/**
		 * @brief Overloaded input operator for reading a rational number from the input stream.
		 * @param input The input stream.
		 * @param rational The rational object to store the input.
		 * @return The input stream.
		 */
		friend istream& operator >>(istream& input, Rational& rational);

		/**
		 * @brief Overloaded output operator for printing a rational number to the output stream.
		 * @param output The output stream.
		 * @param rational The rational object to be printed.
		 * @return The output stream.
		 */
		friend ostream& operator <<(ostream& output, const Rational& rational);

		// Overload comparison operators

		 /**
		  * @brief Overloaded equality operator for comparing two rational numbers for equality.
		  * @param other The other rational number to compare with.
		  * @return True if the rational numbers are equal, false otherwise.
		  */
		bool operator ==(const Rational& other) const;

		/**
		 * @brief Overloaded less than operator for comparing two rational numbers.
		 * @param other The other rational number to compare with.
		 * @return True if the first rational number is less than the second, false otherwise.
		 */
		bool operator <(const Rational& other) const;

		/**
		 * @brief Overloaded less than operator for comparing two rational numbers.
		 * @param other The other rational number to compare with.
		 * @return True if the first rational number is less than or equal to the second, false otherwise.
		 */
		bool operator <=(const Rational& other) const;

		/**
		 * @brief Overloaded less than operator for comparing two rational numbers.
		 * @param other The other rational number to compare with.
		 * @return True if the first rational number is greater than to the second, false otherwise.
		 */
		bool operator >(const Rational& other) const;

		/**
		 * @brief Overloaded less than operator for comparing two rational numbers.
		 * @param other The other rational number to compare with.
		 * @return True if the first rational number is greater than or equal to the second, false otherwise.
		 */
		bool operator >=(const Rational& other) const;

		/**
		 * @brief Overloaded less than operator for comparing two rational numbers.
		 * @param other The other rational number to compare with.
		 * @return True if the first rational number not equal to the second, false otherwise.
		 */
		bool operator !=(const Rational& other) const;

		// Overloaded Mathematic operators

		/**
		 * @brief Overloaded division operator for dividing two rational numbers.
		 * @param other The other rational number to divide.
		 * @return The result of division as a new rational number.
		 */
		Rational operator +(const Rational& other) const;

		/**
		 * @brief Overloaded subtraction operator for subtracting two rational numbers.
		 * @param other The other rational number to subtract.
		 * @return The result of subtraction as a new rational number.
		 */
		Rational operator -(const Rational& other) const;

		/**
		 * @brief Overloaded multiplication operator for multiplying two rational numbers.
		 * @param other The other rational number to multiply.
		 * @return The result of multiplication as a new rational number.
		 */
		Rational operator *(const Rational& other) const;

		/**
		 * @brief Overloaded division operator for dividing two rational numbers.
		 * @param other The other rational number to divide.
		 * @return The result of division as a new rational number.
		 */
		Rational operator /(const Rational& other) const;

		/**
		 * @brief Overloaded unary negation operator for negating a rational number.
		 * @return The negated rational number.
		 */
		Rational operator -() const;
	};
}

#endif // RATIONALS_JV