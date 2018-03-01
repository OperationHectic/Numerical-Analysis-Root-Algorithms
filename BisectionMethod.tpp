#include "MathFunctions.h"
#include <math.h>
#include <iostream>

template <class T>
BisectionMethod<T>::BisectionMethod(T a, T b, T (*func)(T)):
	a(a),
	b(b),
	func(func)
{
	maxIterations = 50;
	tolerance = .0001;
}

template <class T>
int BisectionMethod<T>::getIterations()
{
	return maxIterations;
}

template <class T>
void BisectionMethod<T>::setIterations(int iter)
{
	maxIterations = iter;
}

template <class T>
T BisectionMethod<T>::evaluate(T val)
{
	return func(val);
}

template <class T>
T BisectionMethod<T>::evalA()
{
	return evaluate(a);
}

template <class T>
T BisectionMethod<T>::evalB()
{
	return evaluate(b);
}

template <class T>
T BisectionMethod<T>::getMid()
{
	T mid = (a + b) / 2;
	return mid;
}

template <class T>
T BisectionMethod<T>::findRoot()
{
	T c, fa, fb, fc, tol;
    int n = 1;

	while(n <= maxIterations)
	{
	    fa = func(a);
		fb = func(b);

		c = getMid();
		fc = func(c);

		n += 1;

		if(fc < 0)
		{
			a = c;
		}
		else
		{
		    b = c;
		}
	}
	return c;
}

template <class T>
BisectionMethod<T>::~BisectionMethod()
{
}