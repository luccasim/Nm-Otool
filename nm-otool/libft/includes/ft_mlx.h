/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:12:31 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/14 17:20:18 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <mlx.h>
# include <inttypes.h>
# include <stdlib.h>

# define IS_ARROW(a) 123 || 124 || 125 || 126

typedef enum	e_mlx_color
{
	MLX_RED = 0x00FF0000,
	MLX_GREEN = 0x0000FF00,
	MLX_BLUE = 0x000000FF,
	MLX_WHITE = 0x00FFFFFF,
	MLX_BROWN = 0x00BD8D46,
	MLX_YELLOW = 0x00FFA500,
	MLX_ORANGE = 0x00FC7F3C,
	MLX_BLOND = 0x00E2BC74,
	MLX_CYAN = 0x0000FFFF,
	MLX_DARK = 0x00000000
}				t_mlx_color;

typedef enum	e_mlx_key
{
	MLX_KEY_A = 0,
	MLX_KEY_B = 11,
	MLX_KEY_C = 8,
	MLX_KEY_D = 2,
	MLX_KEY_E = 14,
	MLX_KEY_F = 3,
	MLX_KEY_G = 5,
	MLX_KEY_H = 4,
	MLX_KEY_I = 34,
	MLX_KEY_J = 38,
	MLX_KEY_K = 40,
	MLX_KEY_L = 37,
	MLX_KEY_M = 46,
	MLX_KEY_N = 45,
	MLX_KEY_O = 31,
	MLX_KEY_P = 35,
	MLX_KEY_Q = 12,
	MLX_KEY_R = 15,
	MLX_KEY_S = 1,
	MLX_KEY_T = 17,
	MLX_KEY_U = 32,
	MLX_KEY_V = 9,
	MLX_KEY_W = 13,
	MLX_KEY_X = 7,
	MLX_KEY_Y = 16,
	MLX_KEY_Z = 6,
	MLX_KEY_1 = 18,
	MLX_KEY_2 = 19,
	MLX_KEY_3 = 20,
	MLX_KEY_4 = 21,
	MLX_KEY_5 = 23,
	MLX_KEY_6 = 22,
	MLX_KEY_7 = 26,
	MLX_KEY_8 = 28,
	MLX_KEY_9 = 25,
	MLX_KEY_0 = 29,
	MLX_KEY_MOIN = 27,
	MLX_KEY_PLUS = 24,
	MLX_KEY_RET = 36,
	MLX_KEY_SPACE = 49,
	MLX_KEY_ESC = 53,
	MLX_KEY_LEFT = 123,
	MLX_KEY_RIGHT = 124,
	MLX_KEY_BOT = 125,
	MLX_KEY_TOP = 126,
	MLX_KEY_NONE
}				t_mlx_key;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	uint32_t	height;
	uint32_t	width;
	char		*name;
}				t_window;

typedef struct	s_image
{
	void		*mlx;
	void		*img;
	void		*addr;
	uint32_t	height;
	uint32_t	width;
	int			bpp;
	int			endian;
	int			size_line;
}				t_image;

void			*ft_mlx_init_sglt(void);
/*
** Window
*/
t_window		*ft_mlx_window_new(char *name, uint32_t height, uint32_t width);
void			ft_mlx_window_info(t_window *w);
void			ft_mlx_window_pixel_put(t_window *w, int x, int y, int c);
void			ft_mlx_window_del(t_window *win);
void			ft_mlx_window_clear(t_window *win);
/*
** Image
*/
t_image			*ft_mlx_image_new(uint32_t height, uint32_t width);
void			ft_mlx_image_pixel_put(t_image *i, int x, int y, int c);
uint32_t		ft_mlx_image_pixel_get(t_image *i, int x, int y);
void			ft_mlx_image_clear(t_image *i);
void			ft_mlx_image_info(t_image *i);
void			ft_mlx_image_fill(t_image *i, int color);
void			ft_mlx_image_del(t_image *img);

#endif
