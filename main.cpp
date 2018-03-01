#include "BisectionMethod.h"
#include <iostream>
#include <iomanip>   

using namespace std;

int main()
{
	BisectionMethod<double>* bisec = new BisectionMethod<double>(1, 10, [](double x) { return (x*x*x*x*x*x*x + x*x*x*x - 5) * 3 * x; });
	std::cout << std::setprecision(16) << "Root is " << bisec->findRoot() << "\n\n";
	system("pause");
	delete bisec;
	return 0;
}