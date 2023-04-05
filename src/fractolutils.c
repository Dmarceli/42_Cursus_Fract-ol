/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractolutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:09 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/10 19:44:19 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"
#include <stdlib.h>

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->win_x = WIDTH;
	mlx->win_y = HEIGHT;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x,
			mlx->win_y, "Fractol");
	mlx->data.img = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel,
			&mlx->data.line_length, &mlx->data.endian);
	mlx_mouse_hook(mlx->win_ptr, handle_mouse_click, mlx);
	mlx_hook(mlx->win_ptr, ON_MOUSEDOWN, (1L << 2), handle_mouse_click, mlx);
	mlx_hook(mlx->win_ptr, ON_KEYDOWN, (1L << 0), ft_events, mlx);
	mlx_hook(mlx->win_ptr, 17, (1L << 17), ft_exit, mlx);
	
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	window_labels(t_mlx *mlx)
{
	int	color;

	color = 0xffffff;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, 40, color,
		"Arrow keys or WASD to move around");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, 60, color,
		"'1' '2' '3' to change the color range");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, 80, color,
		"Mouse wheel to zoom in and out");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, 100, color,
		"'backspace' to reset the view");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 18, 120, color,
		"'M' to increase iterations");
}

int	print_pixel(t_mlx *mlx)
{
	draw(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->data.img, 0, 0);
	window_labels(mlx);
	return (0);
}



