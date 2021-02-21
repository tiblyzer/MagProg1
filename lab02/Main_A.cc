#include <iostream>

#include "Car_A.hh"

int main() {
	Audi A;
	Mercedes M;

	A.setLoero(250);
	M.setLoero(320);

	A.PrintAdvancedFeatures();
	M.PrintAdvancedFeatures();

	return 0;
}