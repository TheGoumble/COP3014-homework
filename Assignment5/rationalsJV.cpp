#include "rationalsJV.h"
#include <iostream>
#include <limits>

using namespace std;

namespace JV {
    Rational::Rational() : numerator(0), denominator(1) {}

    Rational::Rational(int wholeNum) : numerator(wholeNum), denominator(1) {}

    Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
     }

    istream& operator>>(istream& input, Rational& rational) {
        char slash;
        int num = 0, denom = 1;

        if (input >> num) {
            if (input.peek() == '/') {
                input >> slash;
                if (input >> denom) {
                    if (denom == 0) {
                        input.setstate(ios::failbit);
                    }
                    else {
                        rational = Rational(num, denom);
                    }
                }
                else {
                    input.setstate(ios::failbit);
                }
            }
            else {
                rational = Rational(num);
            }
        }
        else {
            input.setstate(ios::failbit);
        }

        return input;
    }

    ostream& operator <<(ostream& output, const Rational& rational) {
        if (rational.denominator == 1) {
            output << rational.numerator;
        }
        else {
            output << rational.numerator << "/" << rational.denominator;
        }
        return output;
    }

    bool Rational::operator ==(const Rational& other) const {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    bool Rational::operator <(const Rational& other) const {
        return (numerator * other.denominator < other.numerator * denominator);
    }

    bool Rational::operator <=(const Rational& other) const {
        return (numerator * other.denominator <= other.numerator * denominator);
    }

    bool Rational::operator >(const Rational& other) const {
        return (numerator * other.denominator > other.numerator * denominator);
    }

    bool Rational::operator >=(const Rational& other) const {
        return (numerator * other.denominator >= other.numerator * denominator);
    }

    bool Rational::operator !=(const Rational& other) const {
        return (numerator * other.denominator != other.numerator * denominator);
    }

    Rational Rational::operator +(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Rational Rational::operator -(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Rational Rational::operator *(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational Rational::operator /(const Rational& other) const {
        return Rational(numerator * other.denominator, other.numerator * denominator);
    }

    Rational Rational::operator -() const {
        return Rational(-numerator, denominator);
    }
}