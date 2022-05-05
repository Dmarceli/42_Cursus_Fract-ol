/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:04:57 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:23:58 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

double calculate_burningship(t_nbrs *nbr)
{
	int			i;
	double		t;
	t_complex	z;

	i = 0;
	z = init_complex(nbr->c.re, nbr->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& i < nbr->maxiterations)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + nbr->c.re,
			-2.0 * fabs(z.re * z.im) + nbr->c.im);
		i++;
	}
	if (i >= nbr->maxiterations)
		return (0);
	else
	{
		t = ((double)i / (double)nbr->maxiterations);
		return (t);
	}
	return (0);
}
