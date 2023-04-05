/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:14:17 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/10 20:06:54 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void zoom(t_mlx *mlx, int keycode, int x, int y)
{
	t_complex	mouse;
	double		zoom;
	
	mouse.re = (double)x / (WIDTH / (mlx->nbrs.max.re - mlx->nbrs.min.re)) + mlx->nbrs.min.re;
	mouse.im = (double)y / (HEIGHT / (mlx->nbrs.max.im - mlx->nbrs.min.im) * -1 + mlx->nbrs.max.im);
	if (keycode == 4)
	{
		zoom = 0.9f;
		mlx->nbrs.maxiterations++;
	}
	else
	{
		mlx->nbrs.maxiterations--;
		zoom = 1.1f;
	}
	mlx->nbrs.min.re = interpolate(mouse.re, mlx->nbrs.min.re, zoom);
	mlx->nbrs.min.im = interpolate(mouse.im, mlx->nbrs.min.im, zoom);
	mlx->nbrs.max.re = interpolate(mouse.re, mlx->nbrs.max.re, zoom);
	mlx->nbrs.max.im = interpolate(mouse.im, mlx->nbrs.max.im, zoom);
}

