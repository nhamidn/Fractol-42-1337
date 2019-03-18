/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:49:03 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:26:20 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom_in(t_params *params)
{
	params->fx = (params->fx + ((params->mx - params->cnx) / params->zoom)
			- ((params->mx - params->cnx) / (params->zoom / 1.3)));
	params->fy = (params->fy + ((params->my - params->cny) / params->zoom)
			- ((params->my - params->cny) / (params->zoom / 1.3)));
}

void	zoom_out(t_params *params)
{
	params->fx = (params->fx + ((params->mx - params->cnx) / params->zoom)
			- ((params->mx - params->cnx) / (params->zoom * 1.3)));
	params->fy = (params->fy + ((params->my - params->cny) / params->zoom)
			- ((params->my - params->cny) / (params->zoom * 1.3)));
}

int		mouse_press(int mouse, int x, int y, t_params *params)
{
	if ((mouse == 4 || mouse == 5) && params->ft != 1)
	{
		params->mx = x;
		params->my = y;
		if (params->mx != 0 || params->my != 0)
		{
			if (mouse == 4)
			{
				params->it += 1;
				params->zoom *= 1.3;
				zoom_in(params);
			}
			else if (mouse == 5)
			{
				params->it -= 1;
				params->zoom /= 1.3;
				zoom_out(params);
			}
		}
		ft_destroy(params);
	}
	return (0);
}

int		mouse_move(int x, int y, t_params *params)
{
	if (params->ft == 1 && params->type == 1)
	{
		params->c_i = y / params->zoom - params->cny / params->zoom;
		params->c_r = x / params->zoom - params->cnx / params->zoom;
		ft_destroy(params);
	}
	return (0);
}

int		mouse_t(int mouse, int x, int y, t_params *params)
{
	if (mouse == 1 && params->type == 1 && params->ft == 1)
		params->ft = 0;
	else if ((mouse == 1 || mouse == 2) && params->ft == 0)
	{
		params->mx = x;
		params->my = y;
		if (params->mx != 0 || params->my != 0)
		{
			if (mouse == 1)
			{
				params->it += 1;
				params->zoom *= 1.3;
				zoom_in(params);
			}
			else if (mouse == 2)
			{
				params->it -= 1;
				params->zoom /= 1.3;
				zoom_out(params);
			}
		}
		ft_destroy(params);
	}
	return (0);
}
