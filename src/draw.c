/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:02 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:32:14 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	draw(t_mlx *mlx)
{
	int				x;
	int				y;
	unsigned int	color;

	x = -1;
	y = -1;
	while (++y < HEIGHT)
	{
		mlx->nbrs.c.im = mlx->nbrs.max.im - y * mlx->nbrs.relation.im;
		x = -1;
		while (++x < WIDTH)
		{
			mlx->nbrs.c.re = mlx->nbrs.min.re + x * mlx->nbrs.relation.re;
			color = ft_color(calculate_distributor(mlx), mlx);
			my_pixel_put(&mlx->data, x, y, color);
		}
	}
	return (0);
}
