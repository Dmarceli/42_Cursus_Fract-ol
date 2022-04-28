#include "../incs/fractol.h"


int	main(int argc, char **argv)
{
	t_mlx	mlx;
	(void)argv;

	if (argc == 2)
	{
		init_mlx(&mlx);
		init_mandelbrot(&mlx.nbrs);
		draw(&mlx);
		print_pixel(&mlx);
		//mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.data.img, 0, 0);
	}
	//mlx_key_hook(&mlx.win_ptr, key_hook, &mlx);
	//mlx_hook(mlx.win_ptr, 2, 1L<<0, ft_exit, &mlx);
	mlx_loop(&mlx.mlx_ptr);	
	//mlx_loop_hook(mlx.mlx_ptr, (*print_pixel), &mlx);
	return (0);
}