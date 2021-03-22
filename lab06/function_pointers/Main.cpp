#include <iostream>
#include <string>
#include <ctime>

class A {
	
public:
	A() = default;
	static void resetValue() { n = 0; }
	static int getValue() { return n; }
	static void increment() { n += 1; }
//private
	int a;
	static int n;
};

int A::n;

void demoInteger(int a) {
	std::cout << a << std::endl;
}

void demoFunction(){
	srand(time(0));
	std::cout <<  rand()%20 +5 << std::endl;
}

void demoPrint(){
	std::cout << "demoPrint() is called\n";
}

void demoExecuteFunctions(void (*function)()) {
	function();
}

int main() {
	/*int n = 5;
	int* a;
	a = &n;
	void (*f)(int);
	f = &demoInteger;
	f(5);
	
	//Print the address of functions;
	
	
	std::cout << demoFunction << " " << demoPrint << std::endl;

	demoExecuteFunctions(demoPrint);
	demoExecuteFunctions(demoFunction);

	*/
	
	
	A a1, a2;
	a1.resetValue();
	a1.increment();
	a1.increment();
	a1.increment();

	a2.resetValue();
	std::cout << a1.getValue() << std::endl;
	
	return 0;
}