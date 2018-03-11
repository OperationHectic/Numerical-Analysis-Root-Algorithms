#include "NewtonMethod.h"
#include "BisectionMethod.h"
#include "SecantMethod.h"
#include <iostream>
#include <iomanip>   

using D_poly = double(*)(double);
using NM_D = NewtonMethod<double>;
using BM_D = BisectionMethod<double>;
using SM_D = SecantMethod<double>;

constexpr int PRECISION = 18;
const D_poly POLY = [](double x) { return (x*x*x*x*x*x*x + x*x*x*x - 5) * 3 * x; };
const D_poly POLY2 = [](double x) { return x*x - 612; };

int main()
{
	BM_D* bisec = new BM_D(1, 10, POLY);
	std::cout << std::setprecision(PRECISION) << "Root is " << bisec->findRoot() << "\n\n";
	
	NM_D* newton = new NM_D(1, POLY);
	std::cout << std::setprecision(PRECISION) << "Root is " << newton->findRoot() << "\n\n";

	SM_D* secant = new SM_D(1, 10, POLY2);
	std::cout << std::setprecision(PRECISION) << "Root is " << secant->findRoot() << "\n\n";
	
	delete bisec;
	delete newton;
	delete secant;

	system("pause");
	
	return EXIT_SUCCESS;
}