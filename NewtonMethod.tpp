#include "MathFunctions.h"
#include <iostream>
#include <math.h>

template <class T>
NewtonMethod<T>::NewtonMethod(T x, T(*func)(T)):
	x(x),
	func(func)
{
	maxIterations = 30;
	tolerance = .00000000000001;
}

template <class T>
T NewtonMethod<T>::evaluate(T val) const { return func(val); }

template <class T>
int NewtonMethod<T>::getIterations() const { return maxIterations }

template <class T>
void NewtonMethod<T>::setIterations(int iter) { maxIterations = iter; }

template <class T>
T NewtonMethod<T>::getTolerance() const { return tolerance; }

template <class T>
void NewtonMethod<T>::setTolerance(T val) { tolerance = val; }

template <class T>
T NewtonMethod<T>::findRoot()
{
	int n = 1;
	T fx, dfx, newX;

	std::cout << "Newton Method" << "\n";

	while(n <= maxIterations)
	{
		fx = evaluate(x);
		dfx = derive(func, x);
		newX = x - (fx / dfx);
		if (abs(x - newX) < tolerance) 
		{ 
			std::cout << "number of iterations is " << n << "\n";
			return newX;
		}
		x = newX;
		n += 1;
	}
	return newX;
}

template <class T>
NewtonMethod<T>::~NewtonMethod() { }