/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:18 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:52:23 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	init_fractol(t_nbrs *fractol)
{
	fractol->maxiterations = 30;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->relation.re = (fractol->max.re - fractol->min.re) / (WIDTH - 1);
	fractol->relation.im = (fractol->max.im - fractol->min.im) / (HEIGHT - 1);
	fractol->x_gap = (fabs(fractol->max.re) + fabs(fractol->min.re)) / WIDTH;
	fractol->y_gap = (fabs(fractol->max.im) + fabs(fractol->min.im)) / HEIGHT;
	fractol->zoom = 1.0f;
	fractol->k.re = (-0.4);
	fractol->k.im = (0.6);
}

double	calculate_mandelbrot(t_nbrs *nbr)
{
	int			i;
	double		t;
	t_complex	z;

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
