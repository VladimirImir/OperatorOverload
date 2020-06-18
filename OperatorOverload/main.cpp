#include <iostream>
using namespace std;

class Fraction
{
	int integer;	 // Целая часть
	int numerator;	 // Числитель
	int denominator; // Знаменатель
public:
	const int get_integer()const
	{
		return integer;
	}
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructor

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "Constructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		//cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		//cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}

	// Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->reduse().to_improrep();
		other.reduse().to_improrep();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->reduse().to_proper();
	}
	Fraction& operator/=(Fraction other)
	{
		this->reduse().to_improrep();
		other.reduse().to_improrep();
		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		return this->reduse().to_proper();
	}
	Fraction& operator+=(Fraction other)
	{
		this->reduse().to_improrep();
		other.reduse().to_improrep();
		this->numerator = this->numerator * other.denominator + this->denominator * other.numerator;
		this->denominator = this->denominator *= other.denominator;
		return this->reduse().to_proper();
	}
	Fraction& operator-=(Fraction other)
	{
		this->reduse().to_improrep();
		other.reduse().to_improrep();
		this->numerator = this->numerator * other.denominator - this->denominator * other.numerator;
		this->denominator = this->denominator *= other.denominator;
		return this->reduse().to_proper();
	}

	//	Metods

	void print()const
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
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improrep()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduse()
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
};

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
bool operator<(const Fraction& right, const Fraction& left)
{

	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) < left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? true : false;
}
bool operator>(const Fraction& right, const Fraction& left)
{

	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) > left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? true : false;
}
bool operator<=(const Fraction& right, const Fraction& left)
{

	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) <= left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? true : false;
}
bool operator>=(const Fraction& right, const Fraction& left)
{

	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) >= left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? true : false;
}
bool operator==(const Fraction& right, const Fraction& left)
{

	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) == left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? true : false;
}
bool operator!=(const Fraction& right, const Fraction& left)
{

	return right.get_integer() + double(right.get_numerator() / right.get_denominator()) != left.get_integer() + double(left.get_numerator() / left.get_denominator()) ? true : false;
}
void main()
{
	setlocale(LC_ALL, "");
	Fraction A(2, 3);
	Fraction B(5, 7);
	Fraction C = A * B;
	cout << "Умножение: "; C.print();
	cout << endl;
	cout << "Умножение с присваиванием: "; (A *= B).print();
	cout << endl;
	Fraction D(2, 3);
	Fraction E(5, 7);
	Fraction F = D / E;
	cout << "Деление: "; F.print();
	cout << endl;
	cout << "Деление с присваиванием: "; (D /= E).print();
	cout << endl;
	Fraction G(2, 3);
	Fraction H(5, 7);
	Fraction I = G - H;
	cout << "Вычитание: "; I.print();
	cout << endl;
	cout << "Вычитание с присваиванием: "; (G -= H).print();
	cout << endl;
	Fraction J(2, 3);
	Fraction K(5, 7);
	Fraction L = J + K;
	cout << "Прибавление: "; L.print();
	cout << endl;
	cout << "Прибавление с присваиванием: "; (J += K).print();
	cout << endl;
	cout << "|====================================================================|" << endl;
	cout << "\t\t\t Overload Comparison Operators" << endl;
	cout << endl;
	Fraction Aa(20, 2, 3), Bb(99, 4, 5);
	if (Aa < Bb)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}
	Fraction Cc(20, 2, 3), Dd(99, 4, 5);
	if (Cc > Dd)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}
	Fraction Ee(20, 2, 3), Ff(99, 4, 5);
	if (Ee <= Ff)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}
	Fraction Gg(20, 2, 3), Hh(99, 4, 5);
	if (Gg >= Hh)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}
	Fraction Ii(20, 2, 3), Jj(99, 4, 5);
	if (Ii == Jj)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}
	Fraction Kk(20, 2, 3), Ll(99, 4, 5);
	if (Kk != Ll)
	{
		cout << true << endl;
	}
	else
	{
		cout << false << endl;
	}

}