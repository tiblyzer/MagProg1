#pragma once

#include <iostream>
#include <utility>

template<typename T>
class MyUniquePtr
{
public:
	explicit MyUniquePtr(T* element): dynamic_element(element) {
		std::cout << sizeof(T) << std::endl;
	}
	~MyUniquePtr() {
		this->release();
	}

	MyUniquePtr& operator = (const MyUniquePtr& n) {
		this->dynamic_element = n.dynamic_element;
		return *this;
	}

	void printData(T n);
	void release() {
		if (dynamic_element)
			delete[] dynamic_element;
	}
private:
	T* dynamic_element;
};

