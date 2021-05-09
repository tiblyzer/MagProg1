#pragma once

template<typename T>
struct checkEven
{
	bool operator()(T value) {
		return value % 2;
	}
};


template<typename T>
class MyContainer
{
public:
	typedef		  T  dataType;
	typedef       T* arrayType;
	typedef       T* iteratorType;
	typedef const T* const_iteratorType;

	MyContainer(int N = 100) : size( N )
	{
		array = new dataType[N]();
	}

	~MyContainer() {
		if (array) delete[] array;
	}

	iteratorType begin() { 
		return array; 
	}
	//const_iteratorType beg() { return array; }
	iteratorType end() { return array + size; }

	MyContainer& operator ++() {
		++array;
		return *this;
	}

private:
	arrayType array;
	int size;
};

template<typename T2,typename T3>
void myCopy(T2 source_beg, T2 source_end, T3 target)
{
	/*auto target_element = target.begin();
	auto target_end = target.end();*/
	for (T2 element = source_beg; element != source_end; element++) {
		*target = *element;
		//target = element;
		
		target++;
		
	}
}

template<typename T2,typename T3>
T2 myFind(T2 source_beg, T2 source_end, T3 value)
{
	for (T2 element = source_beg; element != source_end; element++) {
		if (*element == value) {
			return element;
		}
	}

	return source_end;
}

template<typename T2, typename T3>
T2 myFind_if(T2 source_beg, T2 source_end, T3 operation)
{
	for (T2 element = source_beg; element != source_end; element++) {
		if (!operation(*element)) {
			return element;
		}
	}

	return source_end;
}

template<typename T,typename Iterator>
T myAccumulate(Iterator beg, Iterator end)
{
	T result = 0;

	for (Iterator element = beg; element != end; element++) {
		result += *element;
	}

	return result;
}

template<typename Iterator,typename T>
unsigned int myCount(Iterator beg, Iterator end, T value)
{
	unsigned int result = 0;

	for (Iterator element = beg; element != end; element++)
		if (*element == value) ++result;

	return result;
}