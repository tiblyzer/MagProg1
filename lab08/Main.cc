#include <iostream>
#include "MyUniquePtr.hh"

/*
debug memory management, and print memory leaks
*/

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#include <memory>
//
//#ifdef _DEBUG
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
//// allocations to be of _CLIENT_BLOCK type
//#else
//#define DBG_NEW new
//#endif


template<typename T>
T kivonas(T a, T b) {
	return a - b;
}

template<typename T,typename T1, typename T2, typename T3>

T demoTemplateFunction(T1 t1, T2 t2, T3 t3) {
	return t1 + t2 + t3;
}

template<typename T>
class C {
public:
	C() = default;
	~C() = default;

	T getValue() const { return value; }

	virtual T demoPureVirtual(T n) = 0;
private:
	T value;
};

template<typename T>
class D: public C<T> {
public:
	T demoPureVirtual(T n) {
		return n;
	}
};

int kivonas_int(int a, int b) {
	return a - b;
}

float kivonas_float(float a, float b)
{
	return a - b;
}

double kivonas_double(double a, double b)
{
	return a - b;
}

template<typename T>
T osszead(T a, T b) {
	return a + b;
}

template<typename T,typename T1,typename T2,typename T3>
T demoFunction(T1 t1, T2 t2, T3 t3)
{
	T n = sizeof(t1) + sizeof(t2) + sizeof(t3);
	return n;
}

class B {
	virtual void demoPureMethod2() = 0;
	virtual int demoPureMethod2(int n) = 0;
	virtual double demoPureMethod2(double n) = 0;
};


template<typename T>
struct A {
	A(T number = 0) : n(number) {}
	~A() = default;

	void setNValue(T newValue) { n = newValue; }
	T getNValue() const { return n; }

	void printData(T n) {
		std::cout << n << std::endl;
	}

	//virtual T demoPureMethod(T a, T b) = 0;

	T n;
};

template<typename T>
A<T> operator + (const A<T>& a, const A<T>& b) {
	return A<T>(a.n + b.n);
}

int main()
{
	MyUniquePtr<A<int>> n(new A<int>[100000000]);
	
	std::unique_ptr<int> n(new int[1000000]);

	//MyUniquePtr<int> n(new int[3]);
	//delete a;
	//_CrtDumpMemoryLeaks();

	A<int> a;

	D<int> d;
	d.demoPureVirtual(5);
	
	//int n = kivonas<int>(8, 5);
	float f = kivonas<float>(9.45, 0.25);
	bool b = kivonas<bool>(true, false);


	
	/*int n = osszead<int>(5, 6);
	float f = osszead<float>(5.23, 6.87);
	bool b = osszead<bool>(true, true);
	//A<int> a = osszead<A<int>>(A<int>(3), A<int>(5));

	A<int> a;
	*/
	return 0;
}