/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:12 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:13:52 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

double calculate_julia(t_nbrs *nbr)
{
	int i;
	double t;
	t_complex z;
	z = init_complex(nbr->c.re, nbr->c.im);
	i = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
					&& i < nbr->maxiterations)
	{
		z = init_complex(
            pow(z.re, 2.0) - pow(z.im, 2.0) + nbr->k.re,
			2.0 * z.re * z.im + nbr->k.im);
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