/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:47:36 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:40:56 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct		s_fract
{
	int				x0;
	int				y0;
	int				z0;
	long double		i0;
	long double		c_r0;
	long double		c_i0;
	long double		z_i0;
	long double		z_r0;
	long double		tmp0;
}					t_fract;

typedef struct		s_fract1
{
	int				x1;
	int				y1;
	int				z1;
	long double		i1;
	long double		c_r1;
	long double		c_i1;
	long double		z_i1;
	long double		z_r1;
	long double		tmp1;
}					t_fract1;

typedef struct		s_fract2
{
	int				x2;
	int				y2;
	int				z2;
	long double		i2;
	long double		c_r2;
	long double		c_i2;
	long double		z_i2;
	long double		z_r2;
	long double		tmp2;
}					t_fract2;

typedef struct		s_fract3
{
	int				x3;
	int				y3;
	int				z3;
	long double		i3;
	long double		c_r3;
	long double		c_i3;
	long double		z_i3;
	long double		z_r3;
	long double		tmp3;
}					t_fract3;

typedef struct		s_params
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	it;
	long double		i;
	long double		c_r;
	long double		c_i;
	long double		fx;
	long double		fy;
	long double		z_i;
	long double		z_r;
	long double		tmp;
	double			zoom;
	char			*str;
	int				*data;
	int				var;
	int				color;
	int				ft;
	int				type;
	int				cnx;
	int				cny;
	int				mx;
	int				my;
	int				bpp;
	int				s_l;
	int				endian;
}					t_params;

void				ft_pthread_mandel(t_params *params);
void				ft_pthread_julia(t_params *params);
void				ft_pthread_ship(t_params *params);
void				*mandel(void *paramss);
void				*mandel_1(void *paramss);
void				*mandel_2(void *paramss);
void				*mandel_3(void *paramss);
void				*burning(void *paramss);
void				*burning_1(void *paramss);
void				*burning_2(void *paramss);
void				*burning_3(void *paramss);
void				*julia(void *paramss);
void				*julia_1(void *paramss);
void				*julia_2(void *paramss);
void				*julia_3(void *paramss);
void				ft_destroy(t_params *params);
void				ft_init(t_params *params);
void				init_params(t_params *params);
void				error_msg(void);
void				menu(void);
void				key_event(int keycode, t_params *params);
void				zoom_in(t_params *params);
void				zoom_out(t_params *params);
void				checker(t_params *params);
int					checker2(t_params *params);
void				change_fract(int keycode, t_params *params);
int					mouse_t(int mouse, int x, int y, t_params *params);
int					mouse_move(int x, int y, t_params *params);
int					mouse_press(int mouse, int x, int y, t_params *params);
int					key_press(int keycode, t_params *params);

#endif
