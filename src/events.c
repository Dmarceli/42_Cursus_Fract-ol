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
	return (1);
}

void	move_fractal(int keycode, t_mlx *mlx)
{
	t_complex	r;
	r.re = mlx->nbrs.max.re - (mlx->nbrs.min.re);
	r.im = mlx->nbrs.max.im - (mlx->nbrs.min.im);
	if (keycode == KEY_DOWN)
	{
		printf("KEY_DOWN\n");
		mlx->nbrs.min.im -= r.im * 0.05;
		mlx->nbrs.max.im -= r.im * 0.05;
	}
	else if (keycode == KEY_UP)
	{
		printf("KEY_UP\n");
		mlx->nbrs.min.im += r.im * 0.05;
		mlx->nbrs.max.im += r.im * 0.05;
	}
	else if (keycode == KEY_RIGHT)
	{
		printf("KEY_RIGHT\n");
		mlx->nbrs.min.re += r.re * 0.05;
		mlx->nbrs.max.re += r.re * 0.05;
	}
	else if (keycode == KEY_LEFT)
	{
		printf("KEY_LEFT\n");
		mlx->nbrs.min.re -= r.re * 0.05;
		mlx->nbrs.max.re -= r.re * 0.05;
	}
	draw(mlx);
	print_pixel(mlx);
}
