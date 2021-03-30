#include <iostream>
#include <vector>


int main()
{
	std::vector<int> a6;
	std::vector<int> a7(5);
	std::vector<int> a8(5, 2);

	int n = 4;

	a6.push_back(5);
	a6.push_back(n);
	a6.push_back(n);
	a6.push_back(n);
	a6.push_back(7);

	std::cout << a6.back() << " ";
	a6.pop_back();

	std::cout <<  a6.back() << std::endl;

	for (int i = 0; i < a6.size(); ++i)
		std::cout << a6.at(i);

	typedef std::vector<int>::iterator vectorIterator;

	a8.clear();

	for (vectorIterator i = a8.begin(); i != a8.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	return 0;
}