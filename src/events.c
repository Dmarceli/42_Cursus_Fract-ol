#include "../incs/fractol.h"
#include <stdlib.h>

int ft_events(int keycode, t_mlx *mlx)
{
	t_complex abs;

	abs.re = fabs(mlx->nbrs.max.re - mlx->nbrs.min.re);
	abs.im = fabs(mlx->nbrs.max.im - mlx->nbrs.min.im);
	if(MAIN_PAD_ESC == keycode)
	{
		(void)mlx;
		exit(0);
		return(0);
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_fractal(keycode, mlx);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == S_KEY)
		move_fractal(keycode, mlx);
	if (keycode == P)
	{
		printf("P\n");
		mlx->nbrs.min.re *= 0.96f;
		mlx->nbrs.min.im *=	0.96f;
		mlx->nbrs.max.re *= 0.96f;
		mlx->nbrs.max.im *= 0.96f;
		mlx->nbrs.relation.re *= 0.96f;
		mlx->nbrs.relation.im *= 0.96f;
		draw(mlx);
		print_pixel(mlx);
	}
	if (keycode == M)
	{
		printf("M\n");
		mlx->nbrs.maxiterations += 5;
		draw(mlx);
		print_pixel(mlx);
		printf("Max Iter:%d\n",mlx->nbrs.maxiterations);
	}
	if (keycode == BACKSPACE)
	{
		init_mandelbrot(&mlx->nbrs);
		draw(mlx);
		print_pixel(mlx);
	}
	return (1);
}

void	move_fractal(int keycode, t_mlx *mlx)
{
	t_complex	r;
	r.re = mlx->nbrs.max.re - (mlx->nbrs.min.re);
	r.im = mlx->nbrs.max.im - (mlx->nbrs.min.im);
	if (keycode == KEY_DOWN || keycode == S_KEY)
	{
		printf("KEY_DOWN\n");
		mlx->nbrs.min.im -= r.im * 0.05;
		mlx->nbrs.max.im -= r.im * 0.05;
	}
	else if (keycode == KEY_UP || keycode == W_KEY)
	{
		printf("KEY_UP\n");
		mlx->nbrs.min.im += r.im * 0.05;
		mlx->nbrs.max.im += r.im * 0.05;
	}
	else if (keycode == KEY_RIGHT || keycode == D_KEY)
	{
		printf("KEY_RIGHT\n");
		mlx->nbrs.min.re += r.re * 0.05;
		mlx->nbrs.max.re += r.re * 0.05;
	}
	else if (keycode == KEY_LEFT || keycode == A_KEY)
	{
		printf("KEY_LEFT\n");
		mlx->nbrs.min.re -= r.re * 0.05;
		mlx->nbrs.max.re -= r.re * 0.05;
	}
	draw(mlx);
	print_pixel(mlx);
}
