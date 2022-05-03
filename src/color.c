#include "../incs/fractol.h"


int		ft_int_rgb(int r, int g, int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

int		ft_color(double t, t_mlx *mlx)
{
	int		r;
	int		g;
	int		b;

	(void)mlx;

	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	// r = (int)(25 * (1 - t) * pow(t, 3) * 255);
	// g = (int)(2 * pow((1 - t), 2) * pow(t, 2) * 255);
	// b = (int)(18 * pow((1 - t), 3) * t * 255);
	return (ft_int_rgb(r, g, b));

}


