#include <iostream>

void demoPointer(int* n)
{
	*n = 8;
}

int main()
{
	int n = 5;
	
	int* a = &n;
	int* b = a;

	std::cout << n << std::endl;
	std::cout << a << std::endl;
	std::cout << *a << std::endl;

	*a = 4;

	std::cout << *a << std::endl;
	
	demoPointer(&n);
	std::cout << n << std::endl;
	
	return 0;
}