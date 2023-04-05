/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:06 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/10 20:10:22 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	handle_mouse_click(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 1 && mlx->chosen_fract == 2)
		julia_mouse(x,y,mlx);
	if (keycode	== 5 || keycode == 4)
		zoom(mlx, keycode, x ,y);
	print_pixel(mlx);
	return (0);
}


int	ft_exit(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

int	ft_events(int keycode, t_mlx *mlx)
{
	if (MAIN_PAD_ESC == keycode)
		ft_exit(mlx);
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_fractal(keycode, mlx);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == S_KEY)
		move_fractal(keycode, mlx);
	if (keycode == M)
		mlx->nbrs.maxiterations += 1;
	if (keycode == BACKSPACE)
		init_fractol(&mlx->nbrs);
	if (keycode >= 49 && keycode <= 51)
		change_color_pallete(mlx, keycode);
	print_pixel(mlx);
	return (1);
}

void	move_fractal(int keycode, t_mlx *mlx)
{
	t_complex	r;

	r.re = mlx->nbrs.max.re - (mlx->nbrs.min.re);
	r.im = mlx->nbrs.max.im - (mlx->nbrs.min.im);
	if (keycode == KEY_DOWN || keycode == S_KEY)
	{
		mlx->nbrs.min.im -= r.im * 0.05;
		mlx->nbrs.max.im -= r.im * 0.05;
	}
	else if (keycode == KEY_UP || keycode == W_KEY)
	{
		mlx->nbrs.min.im += r.im * 0.05;
		mlx->nbrs.max.im += r.im * 0.05;
	}
	else if (keycode == KEY_RIGHT || keycode == D_KEY)
	{
		mlx->nbrs.min.re += r.re * 0.05;
		mlx->nbrs.max.re += r.re * 0.05;
	}
	else if (keycode == KEY_LEFT || keycode == A_KEY)
	{
		mlx->nbrs.min.re -= r.re * 0.05;
		mlx->nbrs.max.re -= r.re * 0.05;
	}
}

int				julia_mouse(int x, int y, t_mlx *mlx)
{
	mlx->nbrs.k.re = 4 * ((double)x / WIDTH - 0.5);
	mlx->nbrs.k.im = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
	print_pixel(mlx);
	return (0);
}