#include "MyUniquePtr.hh"

template<typename T>
void MyUniquePtr<T>::printData(T n)
{
	std::cout << "P";
}

extern MyUniquePtr<int>;