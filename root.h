#ifndef ROOT_H
#define ROOT_H

#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>

class Root{
	public:
		Root(double (*f)(double,void *));
		~Root();
		
		double solve(double x);

	private:
		const gsl_root_fsolver_type * T;
		gsl_root_fsolver *s;
		gsl_function F;
};

#endif
