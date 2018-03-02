#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <iostream>

template <class T>
void printVecLn(std::vector<T> vec)
{
	for (auto i = vec.begin(); i != vec.end(); ++i) std::cout << *i << ' ';
	std::cout << "\n";
}

template <class T>
void printVec(std::vector<T> vec)
{
	for (auto i = vec.begin(); i != vec.end(); ++i) std::cout << *i << ' ';
}

std::vector<int> convertVecToInt(std::vector<char> vec)
{
	std::vector<int> intVec;
	int temp;
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		temp = *i - '0';
		intVec.push_back(temp);
	}
	return intVec;
}

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
int sgn(T val)
{
	return (T(0) < val) - (val < T(0));
}

#endif