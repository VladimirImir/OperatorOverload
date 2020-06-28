#pragma once
#include <iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;	 // Целая часть
	int numerator;	 // Числитель
	int denominator; // Знаменатель
public:
	const int get_integer()const;
	const int get_numerator()const;
	const int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//Constructor

	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	// Operators

	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(Fraction other);
	Fraction& operator/=(Fraction other);
	Fraction& operator+=(Fraction other);
	Fraction& operator-=(Fraction other);

	//	Metods

	void print()const;
	Fraction& to_proper();
	Fraction& to_improrep();
	Fraction& reduse();
};