#pragma once
class MyListElement
{
public:
	MyListElement(int n=0): value(n),next(nullptr), prev(nullptr) {}
	~MyListElement() = default;

	
private:
	int value;
	MyListElement* next;
	MyListElement* prev;
};

class MyList
{

};
