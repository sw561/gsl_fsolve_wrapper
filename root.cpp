#include "root.h"
#include <cstdio>
#include "debug.h"

// Documentation to be found at:
// http://www.gnu.org/software/gsl/manual/html_node/One-dimensional-Root_002dFinding.html#One-dimensional-Root_002dFinding

Root::Root(double (*f)(double,void *)) : T(gsl_root_fsolver_brent)
{
	s = gsl_root_fsolver_alloc (T);

	F.function = f;
}

Root::~Root()
{
	gsl_root_fsolver_free (s);
}

double Root::solve(double a)
{
	int status;
	double r;
	int iter = 0;
	int max_iter = 100;

	F.params = (void*) &a;

	gsl_root_fsolver_set (s, &F, 0., a);
	do
	{
		iter++;
		status = gsl_root_fsolver_iterate (s);
		r = gsl_root_fsolver_root (s);

		// Test for convergence
		status = gsl_root_test_residual (F.function(r,(void*) &a), 1e-6);
		
		if (debug>0){
			if (status == GSL_SUCCESS) printf ("Converged:\n");
			
			printf ("%5d %.7f\n", iter, r);
		}
	}
	while (status == GSL_CONTINUE && iter < max_iter);

	return r;
}
