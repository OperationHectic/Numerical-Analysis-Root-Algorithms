#ifndef NEWTONMETHOD_H
#define NEWTONMETHOD_H

#include "MathFunctions.h"
#include <iostream>
#include <math.h>

template <class T>
class NewtonMethod
{
private:
	T x;
	T(*func)(T);
	int maxIterations;
	T tolerance;

	T evaluate(T val) const;
public:
	NewtonMethod(T x, T(*func)(T));
	~NewtonMethod();

	int getIterations() const;
	void setIterations(int iter);

	T getTolerance() const;
	void setTolerance(T val);

	T findRoot();
};

#include "NewtonMethod.tpp"

#endif