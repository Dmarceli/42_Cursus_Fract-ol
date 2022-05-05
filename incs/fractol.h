/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:03:41 by dmarceli          #+#    #+#             */
/*   Updated: 2022/05/05 18:38:46 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_UP 		126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define MAIN_PAD_ESC	53
# define P				35
# define M				46
# define BACKSPACE		51
# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2

# define WIDTH 600
# define HEIGHT 600

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	void	*win;
}				t_data;

typedef struct s_nbrs
{
	t_complex		min;
	t_complex		max;
	t_complex		relation;
	t_complex		c;
	t_complex		k;
	double			x_gap;
	double			y_gap;
	int				maxiterations;
	int				rgb;
	float			zoom;
}			t_nbrs;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				chosen_fract;
	int				win_x;
	int				win_y;
	t_data			data;
	t_nbrs			nbrs;
}				t_mlx;

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int			main(int argc, char **argv);
void		init_mlx(t_mlx *mlx);
void		my_pixel_put(t_data *data, int x, int y, int color);
t_complex	init_complex(double re, double im);
void		init_fractol(t_nbrs *nbr);
double		calculate_mandelbrot(t_nbrs *nbr);
int			draw(t_mlx *mlx);
int			ft_color(double t, t_mlx *mlx);
int			ft_int_rgb(int r, int g, int b);
int			ft_events(int keycode, t_mlx *mlx);
int			ft_exit(t_mlx *mlx);
int			print_pixel(t_mlx *mlx);
void		init_loops(t_mlx *mlx);
void		move_fractal(int keycode, t_mlx *mlx);
double		calculate_julia(t_nbrs *nbr);
double		calculate_burningship(t_nbrs *nbr);
int			argparser(int argc, char **argv, t_mlx *mlx);
int			error_messsage(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		calculate_distributor(t_mlx *mlx);
int			handle_mouse_click(int button, int x, int y, t_mlx *mlx);
void		zoom_in(t_nbrs *nbr);

#endif