#include "../incs/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	(void)argv;

	if (argparser(argc, argv, &mlx) == 1)
	{
		init_mlx(&mlx);
		init_fractol(&mlx.nbrs);
		draw(&mlx);
	}
	print_pixel(&mlx);
	mlx_loop(&mlx.mlx_ptr);
	return (0);
}