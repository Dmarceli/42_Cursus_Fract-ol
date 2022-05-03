
#include "../incs/fractol.h"


double calculate_burningship(t_nbrs *nbr)
{

	int i;
	double t;
	t_complex z;
	i = 0;
	z = init_complex(nbr->c.re, nbr->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
					&& i < nbr->maxiterations)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + nbr->c.re,
			-2.0 * fabs(z.re * z.im) + nbr->c.im);
		i++;
	}
	if (i >= nbr->maxiterations)
		return (0);
	else
	{
		t = sqrt((double)i / (double)nbr->maxiterations);
		return (t);
	}
	return (0);
}