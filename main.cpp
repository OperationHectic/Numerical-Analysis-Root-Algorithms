#include "NewtonMethod.h"
#include "BisectionMethod.h"
#include <iostream>
#include <iomanip>   

constexpr int PRECISION = 18;

int main()
{
	BisectionMethod<double>* bisec = new BisectionMethod<double>(1, 10, [](double x) { return (x*x*x*x*x*x*x + x*x*x*x - 5) * 3 * x; });
	std::cout << std::setprecision(PRECISION) << "Root is " << bisec->findRoot() << "\n\n";
	
	NewtonMethod<double>* newton = new NewtonMethod<double>(1, [](double x) { return (x*x*x*x*x*x*x + x*x*x*x - 5) * 3 * x; });
	std::cout << std::setprecision(PRECISION) << "Root is " << newton->findRoot() << "\n\n";

	system("pause");
	
	delete bisec;
	delete newton;
	
	return 0;
}