#pragma once

#include <iostream>


//shape õsosztály
class Shape {
public:
	Shape(unsigned int w = 0, unsigned int h = 0) : szelesseg(w), magassag(h) {}

	void PrintData() const { std::cout << "Shape PrintData called.\n"; } //nem virtualis, nem fog a származtatott osztályban felülíródni
	virtual void PrintType() const { std::cout << "Virtual PrintType called!\n"; } //virtuális metódus, felülírható a származtatott osztályban
	virtual unsigned int calculateArea() const = 0; //tisztan virtualis metodus, a szarmaztatott osztalyban muszaj felulirni
protected:
	unsigned int szelesseg;
	unsigned int magassag;
};

class Triangle : public Shape {
public:
	Triangle(unsigned int w = 0, unsigned int h = 0) : Shape(w, h) {}

	//felülírt PrintData metódus, nem a Shape-ben levõ fog lefutni!!!
	void PrintData() const { std::cout << "Triangle PrintData called.\n"; }
	void PrintType() const {
		std::cout << "Triangle ";
	}

	//felülírt calculateArea metódus, nem a Shape-ben levõ fog lefutni!!!
	unsigned int calculateArea() const {
		return szelesseg * magassag / 2;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(unsigned int w=0, unsigned int h=0): Shape(w,h) {}

	//felülírt PrintData metódus, nem a Shape-ben levõ fog lefutni!!!
	void PrintData() const { std::cout << "Rectangle PrintData called.\n"; }

	void PrintType() const {
		std::cout << "Rectangle ";
	}
	//felülírt calculateArea metódus, nem a Shape-ben levõ fog lefutni!!!
	unsigned int calculateArea() const {
		return szelesseg * magassag;
	}
};

class Square : public Shape {
public:
	Square(unsigned int n=0): Shape(n,n) {}

	//felülírt PrintData metódus, nem a Shape-ben levõ fog lefutni!!!
	void PrintData() const { std::cout << "Square PrintData called.\n"; }

	void PrintType() const {
		std::cout << "Square ";
	}

	//felülírt calculateArea metódus, nem a Shape-ben levõ fog lefutni!!!
	unsigned int calculateArea() const {
		return szelesseg * magassag;
	}
};


