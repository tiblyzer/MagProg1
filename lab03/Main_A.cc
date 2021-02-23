#include <iostream>

#include "Shapes.hh"

void PrintArea(const Shape& S)
{
	//mivel virtual, ezert hiaba Shape a t�pus, amelyik sz�rmaztatott oszt�lyt kapja param�ter�l az elj�r�s,
	//annak a met�dusa fog lefutni.
	S.PrintType();
	std::cout << "area= " << S.calculateArea() << std::endl;
}

void callPrintData(const Shape& S)
{
	//mindig a Shape PrintData met�dusa fog lefutni, itt nincs fel�l�r�s
	S.PrintData();
}

int main()
{
	Rectangle R(2,3);
	Triangle T(1, 2);
	Square S(5);

	R.PrintData();
	R.PrintType();
	std::cout << std::endl;

	T.PrintData();
	T.PrintType();
	std::cout << std::endl;

	S.PrintData();
	S.PrintType();
	std::cout << std::endl;

	PrintArea(R);
	PrintArea(T);
	PrintArea(S);

	callPrintData(R);
	callPrintData(T);
	callPrintData(S);

	return 0;
}
