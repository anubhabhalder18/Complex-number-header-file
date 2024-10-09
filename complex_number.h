// ComplexNumbers.h

#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // Getters and Setters
    double getReal() const { return real; }
    void setReal(double r) { real = r; }
    double getImag() const { return imag; }
    void setImag(double i) { imag = i; }

    // Operator Overloads
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex &other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    // Convert to Polar Form
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    double angle() const {
        return atan2(imag, real);
    }

    // Power
    Complex power(double exponent) const {
        double r = magnitude();
        double theta = angle();
        double newMagnitude = pow(r, exponent);
        double newAngle = theta * exponent;

        return Complex(newMagnitude * cos(newAngle), newMagnitude * sin(newAngle));
    }

    // Display
    void display() const {
        cout << "(" << real << ", " << imag << "i)" << endl;
    }
};

#endif // COMPLEXNUMBERS_H
