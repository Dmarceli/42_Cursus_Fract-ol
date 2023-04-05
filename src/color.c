/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:04:45 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/10 19:51:19 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	ft_int_rgb(int r, int g, int b)
{
	int	c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

int		ft_color(double t, t_mlx *mlx)
{
	t_colors c;
	if (mlx->nbrs.chosen_color == 1)
	{
		c.r = (int)(9 * (1 - t) * pow(t, 3) * 255);
		c.g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		c.b = (int)(8.5 * pow((1 - t), 3) * t * 255);	
	}
	else if (mlx->nbrs.chosen_color == 2)
	{
		c.r = (int)(7 * (1 - t) * pow(t, 3) * 255);
		c.g = (int)(9 * pow((1 - t), 2) * pow(t, 2) * 255);
		c.b = (int)(2000 * pow((1 - t), 3) * t * 255);	
	}
	else
	{
		c.r = (int)(25 * (1 - t) * pow(t, 3) * 255);
		c.g = (int)(2 * pow((1 - t), 2) * pow(t, 2) * 255);
		c.b = (int)(18 * pow((1 - t), 3) * t * 255);	
	}
	return (ft_int_rgb(c.r, c.g, c.b));
}

void change_color_pallete(t_mlx *mlx, int keycode)
{
	if (keycode == 49)
		mlx->nbrs.chosen_color = 1;
	if (keycode == 50)
		mlx->nbrs.chosen_color = 2;
	if (keycode == 51)
		mlx->nbrs.chosen_color = 3;
}