#ifndef SECANTMETHOD_H
#define SECANTMETHOD_H

#include <iostream>
#include <math.h>

template <class T>
class SecantMethod
{
private:
	T a, b;
	T(*func)(T);
	int maxIterations;
	T tolerance;

	T evaluate(T val) const;
public:
	SecantMethod(T a, T b, T(*func)(T));
	~SecantMethod();

	int getIterations() const;
	void setIterations(int iter);

	T getTolerance() const;
	void setTolerance(T val);

	T findRoot();
};

#include "SecantMethod.tpp"

#endif

