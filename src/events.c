/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:06 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 19:29:13 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	handle_mouse_click(int button, int x, int y, t_mlx *mlx)
{
	t_complex	new_center;
	double		height;
	double		width;

	new_center.im = y;
	new_center.re = x;
	printf("x = %f\n", new_center.re);
	printf("y = %f\n", new_center.im);
	if (button == 4 || button == 5 || button == 1)
	{
		height = fabs(mlx->nbrs.min.re - mlx->nbrs.max.re);
		width = fabs(mlx->nbrs.min.im - mlx->nbrs.max.im);
		mlx->nbrs.min.re = new_center.re - (width / 2);
		mlx->nbrs.max.re = new_center.re + (width / 2);
		mlx->nbrs.min.im = new_center.im + (height / 2);
		mlx->nbrs.max.re = new_center.im - (height / 2);
		if (button == 5)
		{
			zoom_in(&mlx->nbrs);
		}
	}
	return (1);
}

int	ft_exit(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

int	ft_events(int keycode, t_mlx *mlx)
{
	t_complex	abs;

	abs.re = fabs(mlx->nbrs.max.re - mlx->nbrs.min.re);
	abs.im = fabs(mlx->nbrs.max.im - mlx->nbrs.min.im);
	if (MAIN_PAD_ESC == keycode)
		ft_exit(mlx);
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_fractal(keycode, mlx);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == S_KEY)
		move_fractal(keycode, mlx);
	if (keycode == M)
	{
		printf("M\n");
		mlx->nbrs.maxiterations += 1;
		print_pixel(mlx);
	}
	if (keycode == BACKSPACE)
	{
		init_fractol(&mlx->nbrs);
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
	print_pixel(mlx);
}
