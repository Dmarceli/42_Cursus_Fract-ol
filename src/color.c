#include "../incs/fractol.h"
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>

#include <stdio.h>

int		ft_int_rgb(int r, int g, int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

int		ft_color(double t)
{
	int		r;
	int		g;
	int		b;


	r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8 * (1 - t) * t * t * t * 255);
	g = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (ft_int_rgb(r, g, b));

}

