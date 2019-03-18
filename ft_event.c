/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:12:43 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:26:14 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_destroy(t_params *params)
{
	mlx_destroy_image(params->mlx_ptr, params->img_ptr);
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	params->img_ptr = mlx_new_image(params->mlx_ptr, 700, 500);
	params->data = (int *)mlx_get_data_addr(params->img_ptr,
			&params->bpp, &params->s_l, &params->endian);
	if (params->type == 1)
		ft_pthread_julia(params);
	else if (params->type == 0)
		ft_pthread_mandel(params);
	else if (params->type == 2)
	{
		params->var = -2;
		ft_pthread_mandel(params);
	}
	else if (params->type == 3)
		ft_pthread_ship(params);
	mlx_put_image_to_window(params->mlx_ptr,
			params->win_ptr, params->img_ptr, 0, 0);
}

void	key_event(int keycode, t_params *params)
{
	if (keycode == 126)
		params->fy -= (4 / params->zoom);
	else if (keycode == 125)
		params->fy += (4 / params->zoom);
	else if (keycode == 124)
		params->fx += (4 / params->zoom);
	else if (keycode == 123)
		params->fx -= (4 / params->zoom);
	else if (keycode == 69)
		params->it += 2;
	else if (keycode == 78)
		if (params->it != 0)
			params->it -= 1;
	ft_destroy(params);
}

void	change_fract(int keycode, t_params *params)
{
	if (keycode == 83)
	{
		params->type = 0;
		params->var = 2;
		ft_destroy(params);
	}
	else if (keycode == 84)
	{
		params->type = 1;
		params->ft = 1;
		ft_destroy(params);
	}
	else if (keycode == 85)
	{
		params->type = 2;
		params->var = -2;
		ft_destroy(params);
	}
	else if (keycode == 86)
	{
		params->type = 3;
		ft_destroy(params);
	}
}

int		key_press(int keycode, t_params *params)
{
	if ((keycode == 126 || keycode == 125 || keycode == 123 ||
	keycode == 124 || keycode == 69 || keycode == 78) && params->ft != 1)
		key_event(keycode, params);
	else if (keycode == 8 && params->ft != 1)
	{
		params->color = rand() % (0xffffff - 150);
		ft_destroy(params);
	}
	else if (keycode == 83 || keycode == 84
			|| keycode == 85 || keycode == 86)
	{
		params->ft = 0;
		init_params(params);
		change_fract(keycode, params);
	}
	else if (keycode == 53)
	{
		mlx_destroy_image(params->mlx_ptr, params->img_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	return (0);
}
