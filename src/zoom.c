/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:14:17 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:50:52 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	zoom_in(t_nbrs *nbr)
{
	double	x_percent;
	double	y_percent;

	x_percent = nbr->x_gap * WIDTH * 0.1;
	y_percent = nbr->y_gap * HEIGHT * 0.1;
	nbr->min.re += x_percent;
	nbr->max.re -= x_percent;
	nbr->min.im -= y_percent;
	nbr->max.im += y_percent;
	if (nbr->min.re < 0 && nbr->max.re > 0)
		nbr->x_gap = (fabs(nbr->max.re) + fabs(nbr->min.re)) / (WIDTH);
	else
		nbr->x_gap = ((nbr->max.re - nbr->min.re) / (WIDTH));
	if (nbr->min.im > 0 && nbr->max.im < 0)
		nbr->y_gap = (fabs(nbr->max.im) + fabs(nbr->min.im)) / (HEIGHT);
	else
		nbr->y_gap = (nbr->min.im - nbr->max.im) / (HEIGHT);
}
