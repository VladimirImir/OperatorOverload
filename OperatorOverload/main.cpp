#include"Fraction.h"
void main()
{
	setlocale(LC_ALL, "");
	Fraction A(2, 3);
	Fraction B(5, 7);
	Fraction C = A * B;
	cout << "���������: "; C.print();
	cout << endl;
	cout << "��������� � �������������: "; (A *= B).print();
	cout << endl;
	Fraction D(2, 3);
	Fraction E(5, 7);
	Fraction F = D / E;
	cout << "�������: "; F.print();
	cout << endl;
	cout << "������� � �������������: "; (D /= E).print();
	cout << endl;
	Fraction G(2, 3);
	Fraction H(5, 7);
	Fraction I = G - H;
	cout << "���������: "; I.print();
	cout << endl;
	cout << "��������� � �������������: "; (G -= H).print();
	cout << endl;
	Fraction J(2, 3);
	Fraction K(5, 7);
	Fraction L = J + K;
	cout << "�����������: "; L.print();
	cout << endl;
	cout << "����������� � �������������: "; (J += K).print();
	cout << endl;
}