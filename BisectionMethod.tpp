#include "utils.h"
#include <math.h>
#include <iostream>

template <class T>
BisectionMethod<T>::BisectionMethod(T a, T b, T (*func)(T)):
	a(a),
	b(b),
	func(func)
{
	maxIterations = 50;
	tolerance = .00000000000001;
}

template <class T>
int BisectionMethod<T>::getIterations() const { return maxIterations; }

template <class T>
void BisectionMethod<T>::setIterations(int iter) { maxIterations = iter; }

template <class T>
T BisectionMethod<T>::getTolerance() const { return tolerance; }

template <class T>
void BisectionMethod<T>::setTolerance(T tol) { tolerance = tol; }

template <class T>
T BisectionMethod<T>::evaluate(T val) const { return func(val); }

template <class T>
T BisectionMethod<T>::evalA() const { return evaluate(a); }

template <class T>
T BisectionMethod<T>::evalB() const { return evaluate(b); }

template <class T>
T BisectionMethod<T>::getMid() const { return (T)(a + b) / 2; }

template <class T>
T BisectionMethod<T>::findRoot()
{
	T c, fa, fb, fc;
    int n = 1;

	std::cout << "Bisection Method" << "\n";

	while(n <= maxIterations)
	{
	    fa = func(a);
		fb = func(b);

		c = getMid();
		fc = func(c);

		if((fc == 0) || (b-a)/2 < tolerance)
		{
			std::cout << "number of iterations " << n << "\n";
			return c;
		}

		n += 1;

		if(sgn<T>(fc) == sgn<T>(fa))
		{
			a = c;
		}
		else
		{
		    b = c;
		}
	}
	std::cout << "Max iterations exceeded. Try increasing max iterations with method setIterations" << "\n";
	return c;
}

template <class T>
BisectionMethod<T>::~BisectionMethod() { }