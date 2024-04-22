#include <iostream>
#include "vector.hpp"

int main()
{
	Vector<int> vec(5, 10);
	std::cout << vec;
	Vector<int> vec2 = vec;
	vec2.print();
	std::cout << std::endl;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	vec.print();
	std::cout << vec.Vcap() << std::endl;
	vec.shrink_to_fit();
	std::cout << vec.Vcap() << std::endl;
}
