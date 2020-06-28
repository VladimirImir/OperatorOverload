#include"Fraction.h"
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
}