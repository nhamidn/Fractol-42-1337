/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 01:08:49 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:29:01 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init(t_params *params)
{
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, 700, 500, params->str);
	params->img_ptr = mlx_new_image(params->mlx_ptr, 700, 500);
	params->data = (int *)mlx_get_data_addr(params->img_ptr, &params->bpp,
			&params->s_l, &params->endian);
}

void	init_params(t_params *params)
{
	params->mx = 0;
	params->my = 0;
	params->fx = 0;
	params->fy = 0;
	params->c_r = 0.4;
	params->c_i = 0.1;
	params->cnx = 700 / 2;
	params->cny = 500 / 2;
	params->it = 100;
	params->zoom = 125;
	params->color = 0x000000;
}

void	error_msg(void)
{
	ft_putstr("\033[0;31m");
	ft_putstr("#################################\n");
	ft_putstr("Usage : ./fract <fractal name>\n");
	ft_putstr("#################################\n");
	ft_putstr("\033[0;32m");
	ft_putstr("Fractals :			- Mandelbrot\n");
	ft_putstr("				- Julia\n");
	ft_putstr("				- Tricorn\n");
	ft_putstr("				- BurningShip\n");
	ft_putstr("\033[0m");
}

int		main(int argc, char **argv)
{
	t_params params;

	init_params(&params);
	params.ft = 0;
	if (argc == 2)
	{
		params.str = argv[1];
		checker(&params);
		mlx_hook(params.win_ptr, 5, 1, mouse_t, &params);
		mlx_hook(params.win_ptr, 4, 1, mouse_press, &params);
		mlx_hook(params.win_ptr, 6, 1, mouse_move, &params);
		mlx_hook(params.win_ptr, 2, 1, key_press, &params);
		mlx_put_image_to_window(params.mlx_ptr, params.win_ptr,
				params.img_ptr, 0, 0);
		mlx_loop(params.mlx_ptr);
	}
	else if (argc > 2)
	{
		ft_putstr("\033[0;31m");
		ft_putstr("Too much params ! Please enter just one\n");
		ft_putstr("\033[0m");
	}
	else
		error_msg();
	return (0);
}
