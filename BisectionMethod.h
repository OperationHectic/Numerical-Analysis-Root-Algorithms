#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

template <class T>
class BisectionMethod
{
private:
	T a, b;
	T (*func)(T);
	int maxIterations;
	T tolerance;

	T evaluate(T val) const;
public:
	BisectionMethod(T a, T b, T (*func)(T));
	~BisectionMethod();
	
	int getIterations() const;
	void setIterations(int iter);
	
	T getTolerance() const;
	void setTolerance(T tol);
	
	T evalA() const;
	T evalB() const;
	T getMid() const;
	
	T findRoot();
};

#include "BisectionMethod.tpp"

#endif
