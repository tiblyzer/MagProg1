#pragma once

#include <iostream>


//shape �soszt�ly
class Shape {
public:
	Shape(unsigned int w = 0, unsigned int h = 0) : szelesseg(w), magassag(h) {}

	void PrintData() const { std::cout << "Shape PrintData called.\n"; } //nem virtualis, nem fog a sz�rmaztatott oszt�lyban fel�l�r�dni
	virtual void PrintType() const { std::cout << "Virtual PrintType called!\n"; } //virtu�lis met�dus, fel�l�rhat� a sz�rmaztatott oszt�lyban
	virtual unsigned int calculateArea() const = 0; //tisztan virtualis metodus, a szarmaztatott osztalyban muszaj felulirni
protected:
	unsigned int szelesseg;
	unsigned int magassag;
};

class Triangle : public Shape {
public:
	Triangle(unsigned int w = 0, unsigned int h = 0) : Shape(w, h) {}

	//fel�l�rt PrintData met�dus, nem a Shape-ben lev� fog lefutni!!!
	void PrintData() const { std::cout << "Triangle PrintData called.\n"; }
	void PrintType() const {
		std::cout << "Triangle ";
	}

	//fel�l�rt calculateArea met�dus, nem a Shape-ben lev� fog lefutni!!!
	unsigned int calculateArea() const {
		return szelesseg * magassag / 2;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(unsigned int w=0, unsigned int h=0): Shape(w,h) {}

	//fel�l�rt PrintData met�dus, nem a Shape-ben lev� fog lefutni!!!
	void PrintData() const { std::cout << "Rectangle PrintData called.\n"; }

	void PrintType() const {
		std::cout << "Rectangle ";
	}
	//fel�l�rt calculateArea met�dus, nem a Shape-ben lev� fog lefutni!!!
	unsigned int calculateArea() const {
		return szelesseg * magassag;
	}
};

class Square : public Shape {
public:
	Square(unsigned int n=0): Shape(n,n) {}

	//fel�l�rt PrintData met�dus, nem a Shape-ben lev� fog lefutni!!!
	void PrintData() const { std::cout << "Square PrintData called.\n"; }

	void PrintType() const {
		std::cout << "Square ";
	}

	//fel�l�rt calculateArea met�dus, nem a Shape-ben lev� fog lefutni!!!
	unsigned int calculateArea() const {
		return szelesseg * magassag;
	}
};


