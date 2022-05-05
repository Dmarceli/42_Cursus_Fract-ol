/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:15 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:19:59 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argparser(argc, argv, &mlx) == 1)
	{
		init_mlx(&mlx);
		init_fractol(&mlx.nbrs);
	}
	print_pixel(&mlx);
	mlx_loop(&mlx.mlx_ptr);
	return (0);
}
