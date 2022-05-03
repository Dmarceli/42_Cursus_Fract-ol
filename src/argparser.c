#include "../incs/fractol.h"

double calculate_distributor(t_mlx *mlx)
{
	if (mlx->chosen_fract == 1)
		return(calculate_mandelbrot(&mlx->nbrs));
	else if (mlx->chosen_fract == 2)
		return(calculate_julia(&mlx->nbrs));
	else if (mlx->chosen_fract == 3)
		return(calculate_burningship(&mlx->nbrs));
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((*s11 || *s22) && n > 0)
	{
		if (*s11 != *s22)
		{
			return (*s11 - *s22);
		}
		n--;
		s11++;
		s22++;
	}
	return (0);
}

int error_messsage(void)
{
	write(1, "\033[1;31mError!\n[0m", 14);
	write(1, "Usage:\n", 8);
	write(1, "./Fract_ol <Chosen Fractal>\n", 29);
	write(1, "Available Fractals:\n", 21);
	write(1, "\t-Mandelbrot\n", 14);
	write(1, "\t-Julia\n", 9);
	write(1, "\t-Burning Ship\n", 16);
	exit(0);
	return(0);
}

int argparser(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 2)
		return (error_messsage());
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		{
			mlx->chosen_fract = 1;
			return (1);
		}
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		{
			mlx->chosen_fract = 2;
			return(1);
		}
	else if (ft_strncmp(argv[1], "Burning", 11) == 0 && argc == 3 && ft_strncmp(argv[2], "Ship", 4) == 0)
		{
			mlx->chosen_fract = 3;
			return (1);
		}
	else
		return (error_messsage());
}
