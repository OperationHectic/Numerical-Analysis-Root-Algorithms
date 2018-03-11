template <class T>
SecantMethod<T>::SecantMethod(T a, T b, T(*func)(T)) :
	a(a),
	b(b),
	func(func)
{
	maxIterations = 30;
	tolerance = .00000000000001;
}

template <class T>
T SecantMethod<T>::evaluate(T val) const { return func(val); }

template <class T>
int SecantMethod<T>::getIterations() const { return maxIterations}

template <class T>
void SecantMethod<T>::setIterations(int iter) { maxIterations = iter; }

template <class T>
T SecantMethod<T>::getTolerance() const { return tolerance; }

template <class T>
void SecantMethod<T>::setTolerance(T val) { tolerance = val; }

template <class T>
T SecantMethod<T>::findRoot()
{
	int n = 1;
	T fa, fb, c;

	std::cout << "Secant Method" << "\n";

	while (n <= maxIterations)
	{
		fa = evaluate(a);
		fb = evaluate(b);

		c = b - fb * ((b - a) / (fb - fa));
		if (abs(b - c) < tolerance)
		{
			std::cout << "Number of iterations is " << n << "\n";
			return c;
		}
		a = b;
		b = c;
		n += 1;
	}
	return c;
}

template <class T>
SecantMethod<T>::~SecantMethod() { }