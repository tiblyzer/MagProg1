#include "Car_B.hh"

inline int increment(int n) {
	return n += 1;
}

inline int decrement(int n) {
	return n -= 1;
}

int main()
{
	
	Audi A;
	Mercedes M;

	A.setLoero(250);
	M.setLoero(300);

	A.PrintFeatures();
	M.PrintFeatures();

	std::cout << std::endl << A << std::endl;

	int a = 2;
	int b = 3;

	std::cout << increment(a);

	return 0;
}