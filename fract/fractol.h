/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:26:07 by aammisse          #+#    #+#             */
/*   Updated: 2025/01/20 22:51:51 by aammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define ITERATION 80
# define ESCAPEVALUE 4
# define SHIFT_VALUE 0.1
# define ZOOMVALUE 1
# define ERROR_MESSAGE "Please enter the correct inputs !\n--> mandelbrot\n"
# define ERROR_MESSAGE2 "--> julia <value1> <value2>\n--> tricorn\n"

# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESCAPE_KEY 65307
# define TAB_KEY 65289
# define NUMPAD_PLUS 65451
# define NUMPAD_MINUS 65453
# define PAGEUP_KEY 65365
# define PAGEDOWN_KEY 65366
# define MOUSE_UP 4
# define MOUSE_DOWN 5

# define COLOR1 CYAN
# define COLOR2 BLUE
# define INSIDECOLOR BLACK
# define BLACK   0x000000 // Black
# define WHITE   0xFFFFFF // White
# define RED     0xFF0000 // Red
# define GREEN   0x00FF00 // Green
# define BLUE    0x0000FF // Blue
# define YELLOW  0xFFFF00 // Yellow
# define CYAN    0x00FFFF // Cyan
# define MAGENTA 0xFF00FF // Magenta
# define GRAY    0x808080 // Gray
# define ORANGE  0xFFA500 // Orange

typedef struct s_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_info;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_value
{
	double	x;
	double	y;
}				t_value;

typedef struct s_julia
{
	double	x;
	double	y;
}				t_julia;

typedef struct s_data
{
	double mouse_re;
	double mouse_im;
	int		color;
	char	*name;
	void	*mlx;
	void	*win;
	int		iteration;
	double	escape_value;
	double	shiftx;
	double	shifty;
	double	zoom;
	t_info	image;
	t_julia	value;
	t_color	hue;
}				t_data;

void	data_init(t_data *data);
void	clear_data(t_data *data);
void	fractal_init(t_data *data);
int		closewin(t_data *data);
void	my_mlx_pixel_put(t_info *image, int x, int y, int color);
double	scale(double unscaled_num, double new_min, double new_max,
			double old_max);
t_value	sum_complex(t_value z1, t_value z2);
t_value	sqrt_complex(t_value z);
double	ft_atod(char *str);
int		fractal_render(t_data *data);
int		handlemouse(int x, int y, t_data *data);
int		handlekey(int keycode, t_data *data);
void	mandelbrot(int x, int y, t_data *data);
void	julia(int x, int y, t_data *data);
int		ft_strcmp(char *s1, char *s2);
void	tricorn(int x, int y, t_data *data);
int		ft_isspace(int c);
int		ft_isdigit(int c);
double	helpfunc(char *c, double fraction, int divisor, double result);
int		ft_isdp(char *s);

#endif