#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

template <class T>
class BisectionMethod
{
	T a, b;
	T (*func)(T);
	int maxIterations;
	T tolerance;

	T evaluate(T val);
public:
	BisectionMethod(T a, T b,T (*func)(T));
	~BisectionMethod();
	
	int getIterations();
	void setIterations(int iter);
	T evalA();
	T evalB();
	T getMid();
	T findRoot();
};

#include "BisectionMethod.tpp"

#endif
