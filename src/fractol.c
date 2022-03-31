/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:55:37 by dmarceli          #+#    #+#             */
/*   Updated: 2022/03/31 15:58:01 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	int A,B,i;
	float a,b,x,y,t,n=270;

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.x = 0;
	img.y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fractol!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (B = 0; B<=4*n; B++)
	{
		b = 2-(B/n);
		for (A=0; A<=4*n;A++)
		{
			a= -2+(A/n);
			x=0;
			y=0;
			for (i=1; i<=1000; i++)
			{
				t=x;
				x=(x*x)-(y*y)+a;
				y = (2*t*y)+b;
				if ((x*x)+(y*y)>4)
					break ;
			}
			if (i == 1001)
				my_mlx_pixel_put(&img, A, B, 0x21E3E9);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
