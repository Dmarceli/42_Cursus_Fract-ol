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

int	print_pixel(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	draw(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->data.img, 0, 0);
	return (0);
}

