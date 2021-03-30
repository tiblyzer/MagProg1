#include <iostream>
#include <vector>


class A {
public:
	A() = default;
	~A() = default;
	A(const A& a) : n(a.n) {}
private:
	int n;
};

int main()
{
	/*
	Static, dynamic allocation, and management
	*/
	int d[100];

	int* b;
	
	b = new int[100];
	delete[] b;

	A a;
	A* a2 = new A();
	delete a2;

	A* a3;
	a3 = new A[100]();
	delete[] a3;

	A a4(a);
	a4 = a;

	
	//example of iterators, and pointer arithmetic operations
	int n[100];
	int* iterator = n;

	for (int i = 0; i < 100; ++i)
		n[i] = i;

	std::cout << *iterator << std::endl;
	
	iterator += 1;
	std::cout << *iterator << std::endl;

	iterator += 5;
	std::cout << *iterator << std::endl;
	
	iterator -= 6;
	std::cout << *iterator << std::endl;
	
	//difference of value and pointer incrementation
	std::cout << *(iterator++) << std::endl;
	std::cout << (*iterator)++ << std::endl;
	std::cout << "-----\n";


	//example of iterators.
	iterator -= 1;
	int* end = &n[99];

	for (int* i = iterator; i < end; ++i)
		std::cout << *i << std::endl;
	
	int c;
	c++;
	++c;
	
	return 0;
}