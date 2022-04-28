#include "../incs/fractol.h"
#include <stdlib.h>

int ft_events(int keycode, t_mlx *mlx)
{
	t_complex abs;

	abs.re = fabs(mlx->nbrs.max.re - mlx->nbrs.min.re);
	abs.im = fabs(mlx->nbrs.max.im - mlx->nbrs.min.im);
	//printf("key %d\t\n", keycode);
	if(MAIN_PAD_ESC == keycode)
		{
			(void)mlx;
			exit(0);
			return(0);
		}
	if (keycode == KEY_UP)
	{
		printf("up\n");
		mlx->nbrs.min.im += abs.im * 0.05;
		mlx->nbrs.max.im += abs.im * 0.05;
	}
	print_pixel(mlx);
	//draw(mlx);
	return (1);
}