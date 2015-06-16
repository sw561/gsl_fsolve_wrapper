#include "root.h"
#include "test.h"

short unsigned int debug=0;

double f(double x, void * params)
{
	double * p = (double*) params;
	return x*x - (*p);
}

bool test_square_root()
{
	Root root = Root(&f);

	for (int i=2; i<101; i+=1){
		double x = (double)i;
		if (debug) printf("Exact value = %.7f\n",sqrt(x));
		if (fabs(root.solve(x)-sqrt(x)) > 1e-6) return false;
	}

	return true;
}


int main()
{
	TestSuite s(__FILE__);

	s.test("Square roots",test_square_root);

	return 0;
}

