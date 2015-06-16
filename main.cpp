#include "root.h"
#include <cstdio>
#include <sstream>

short unsigned int debug;

double f(double x, void * /*params*/)
{
	return 6*cos(x) - exp(x);
}

int main(int argc, char* argv[])
{
	// Debug variable
	if (argc>=2) std::istringstream(argv[1]) >> debug;
	else debug = 0;

	Root root = Root(&f);

	printf("6*cos(x) - exp(x) = 0 for\nx = %.7f\n",root.solve(50));
	return 0;
}

