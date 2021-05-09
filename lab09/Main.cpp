#include <iostream>
#include <algorithm>
#include "MyContainer.hh"
#include <vector>
#include <string>
#include <string_view>
#include <map>


struct myOperation {
	myOperation(int n = 0) : value(n) {}
	~myOperation() = default;

	int value;

	int operator() () const {
		return value * 2;
	}
};




struct Car {
	Car(int p = 0, std::string t = "0", bool a = "false") : power{ p }, type{ t }, adas{ a } {}
	~Car() = default;

	int power;
	std::string type;
	bool adas;

	friend std::ostream& operator  << (std::ostream& os, const Car& car) {
		os << car.power << " " << car.type << " " << car.adas << std::endl;
		return os;
	}
};

struct mySortCondition {
	bool operator() (const Car& a, const Car& b) {
		if (a.type == b.type) {
			return a.power > b.power;
		}

		else if (a.power == b.power){
			return a.type > b.type;
		}

		else {
			return a.power > b.power;
		}
		
	}
};


template<typename T>
void fillCars(MyContainer<T>& container)
{
	int index = 1;
	for (auto element = container.begin(); element != container.end();element++) {
		switch (index)
		{
		case 1: {
			*element = { 125, "Mercedes", true };
			break;
		}
		case 2: {
			*element = { 135, "Audi", true };
			break;
		}
		case 3: {
			*element = { 135, "Volkswagen", true };
			break;
		}
		case 4: {
			*element = { 325, "Toyota", true };
			break;
		}
		case 5: {
			*element = { 165, "Mazda", true };
			break;
		}
		case 6: {
			*element = { 156, "Mazda", true };
			break;
		}

		default:
			break;
		}
		
		++index;
		
	}
}

template<typename T>
void exampleWrapping(T variable)
{
	std::sort(variable.begin(), variable.end());

}


struct Example {
	int val;

	Example& operator = (const int n) {
		this->val = n;
		return *this;
	}
};

int main()
{
	MyContainer<int> C(6);
	MyContainer<int> D(6);

	int value = 52;

	//std::cout << C.end() - C.beg();


	for (MyContainer<int>::iteratorType element = C.begin(); element != C.end(); element++) {
		//auto n = C.end();
		*element = value;
		value -= 2;
	}

	for (MyContainer<int>::iteratorType element = C.begin(); element != C.end(); element++) {
		std::cout << *element << std::endl;
	}

	for (auto element : C)
		std::cout << element << std::endl;
	
	/*
	auto position = std::find(C.begin(), C.end(), 9);
	auto e = C.end();
	std::cout << *position << std::endl;
	std::sort(C.begin(), C.end());
	*/
	std::vector<int> v(9, 9);
	std::vector<int> v2(9);
	

	auto n = myFind(v.begin(), v.end(), 9);//std::find(C.begin(), C.end(), 9);
	auto n2 = myFind_if(v.begin(), v.end(), checkEven<int>());

	std::cout << "---\n";
	if (n2 != v.end()) std::cout << *n2 << std::endl;
	std::cout << "---\n";

	for (auto element : C)
		std::cout << element << std::endl;
	
	auto result = myAccumulate<int>(C.begin(), C.end());
	unsigned int count_result = myCount(v.begin(), v.end(),9);
	std::cout << result << " " << count_result <<  std::endl;

	//std::copy(C.begin(), C.end(),D.begin());

	//myCopy(C.begin(),C.end(),D.begin());
	//std::copy(C.begin(), C.end(), D);
	for (auto element : D)
		std::cout << element << std::endl;
	


	
	MyContainer<Car> cars(6);

	fillCars(cars);

	for (auto element : cars) {
		std::cout << element << std::endl;
	}
	
	//std::sort(cars.begin(), cars.end(), mySortCondition());

	std::sort(cars.begin(), cars.end(), [](const auto& lhs, const auto& rhs) {return lhs.type > rhs.type;});

	for (auto element : cars) {
		std::cout << element << std::endl;
	}
	
	std::map<std::string, int> m{ {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	std::map<int, std::string > m2{ {10, "CPU"}, {15, "GPU"}, {20, "RAM"}, };

	for (const auto& element : m) {
		std::cout << element.first << " " << element.second << std::endl;
	}
	
	auto element = m.begin();
	++element;

	m.erase(element);

	m["CPU"] = 25;  // update an existing value
	m["SSD"] = 30;  // insert a new value

	std::string newKey = "HDD";
	int newValue = 500;

	m[newKey] = newValue;

	for (const auto& element : m) {
		std::cout << element.first << " " << element.second << std::endl;
	}

	for (const auto& element : m) {
		m2[element.second] = element.first;
	}

	for (const auto& element : m2) {
		std::cout << element.first << " " << element.second << std::endl;
	}

	return 0;
}