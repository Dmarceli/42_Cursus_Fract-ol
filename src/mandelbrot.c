#include "../incs/fractol.h"

int draw(t_mlx *mlx)
{
	int	x;
	int	y;
	unsigned int color;

	x = -1;
	y = -1;
	while (++y < HEIGHT)
	{
		mlx->nbrs.c.im = mlx->nbrs.max.im - y * mlx->nbrs.relation.im;
		x = -1;
		while (++x < WIDTH)
		{
			mlx->nbrs.c.re = mlx->nbrs.min.re + x * mlx->nbrs.relation.re;
			color = ft_color(calculate_mandelbrot(&mlx->nbrs));
			my_pixel_put(&mlx->data, x, y, color);
		}
	}
	return (0);
}

void	init_mandelbrot(t_nbrs *fractol)
{
	fractol->maxiterations = 100;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->relation.re = (fractol->max.re - fractol->min.re) / (WIDTH - 1);
	fractol->relation.im = (fractol->max.im - fractol->min.im) / (HEIGHT - 1);
	printf("min.re == %f\n", fractol->min.re);
	printf("max.re == %f\n", fractol->max.re);
}


double calculate_mandelbrot(t_nbrs *nbr)
{
	int i;
	double t;
	t_complex z;
	z = init_complex(nbr->c.re, nbr->c.im);
	i = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
					&& i < nbr->maxiterations)
	{
		z = init_complex(
            pow(z.re, 2.0) - pow(z.im, 2.0) + nbr->c.re,
            2.0 * z.re * z.im + nbr->c.im);
			i++;
	}
	if (i >= nbr->maxiterations)
		return (0);
	else
	{
		t = (double)i / (double)nbr->maxiterations;
		return (t);
	}
	return (0);
}