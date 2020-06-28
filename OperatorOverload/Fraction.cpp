#include"Fraction.h"

const int Fraction::get_integer()const
{
	return integer;
}
const int Fraction::get_numerator()const
{
	return numerator;
}
const int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//Constructor

Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	//cout << "DefConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	//cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	//cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	//cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	//cout << "CopyConstructor:" << this << endl;
}
Fraction::~Fraction()
{
	//cout << "Destructor:\t" << this << endl;
}

// Operators

Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(Fraction other)
{
	this->reduse().to_improrep();
	other.reduse().to_improrep();
	this->numerator *= other.numerator;
	this->denominator *= other.denominator;
	return this->reduse().to_proper();
}
Fraction& Fraction::operator/=(Fraction other)
{
	this->reduse().to_improrep();
	other.reduse().to_improrep();
	this->numerator *= other.denominator;
	this->denominator *= other.numerator;
	return this->reduse().to_proper();
}
Fraction& Fraction::operator+=(Fraction other)
{
	this->reduse().to_improrep();
	other.reduse().to_improrep();
	this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
	this->denominator = this->denominator *= other.denominator;
	return this->reduse().to_proper();
}
Fraction& Fraction::operator-=(Fraction other)
{
	this->reduse().to_improrep();
	other.reduse().to_improrep();
	this->numerator = this->numerator * other.denominator - this->denominator * other.numerator;
	this->denominator = this->denominator *= other.denominator;
	return this->reduse().to_proper();
}

//	Metods

void Fraction::print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer) cout << "+";
		cout << numerator << "/" << denominator;
	}
	else if (integer == 0)
		cout << 0;
	cout << endl;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improrep()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::reduse()
{
	// В дроби, в любом случае что то больше. Числитель может быть больше знаминателя или наоборот.
	int more; // большее значение
	int less; // меньшее значение
	int reminder = 0; // отстаток от деления
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		more = denominator;
		less = numerator;
	}
	do
	{
		reminder = more % less;
		more = less;
		less = reminder;
	} while (reminder);
	int GCD = more; // Найбольший Общий Делитель
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improrep();
	right.to_improrep();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).to_proper().reduse();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improrep();
	right.to_improrep();
	return Fraction(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator()).to_proper().reduse();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improrep();
	right.to_improrep();
	return Fraction(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator()).to_proper().reduse();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improrep();
	right.to_improrep();
	return Fraction(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator()).to_proper().reduse();
}