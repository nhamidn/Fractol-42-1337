/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:07:42 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:30:03 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	menu(void)
{
	ft_putstr("\033[0;34m##################################\n");
	ft_putstr("#           \033[0mHow To Use\033[0;34m           #\n");
	ft_putstr("##################################\n");
	ft_putstr("# \033[01;33mzoom :   scroll Down or Up\033[0;34m     #\n");
	ft_putstr("# \033[01;33mChange iteration :   +  or -\033[0;34m   #\n");
	ft_putstr("# \033[01;33mMove :   use Arrows\033[0;34m            #\n");
	ft_putstr("# \033[01;33mClose :   use ESC\033[0;34m              #\n");
	ft_putstr("# \033[01;33mChange Fractal :  use 1 2 3 4\033[0;34m  #\n");
	ft_putstr("# \033[01;33mChange Color :  use C\033[0;34m          #\n");
	ft_putstr("##################################\n\033[0m");
}

int		checker2(t_params *params)
{
	if (ft_strcmp(params->str, "Mandelbrot") == 0)
	{
		ft_init(params);
		menu();
		params->var = 2;
		params->type = 0;
		ft_pthread_mandel(params);
	}
	else if (ft_strcmp(params->str, "Julia") == 0)
	{
		ft_init(params);
		menu();
		params->type = 1;
		params->ft = 1;
		ft_pthread_julia(params);
	}
	else
		return (0);
	return (1);
}

void	checker(t_params *params)
{
	if (checker2(params) == 0)
	{
		if (ft_strcmp(params->str, "Tricorn") == 0)
		{
			ft_init(params);
			menu();
			params->var = -2;
			params->type = 2;
			ft_pthread_mandel(params);
		}
		else if (ft_strcmp(params->str, "BurningShip") == 0)
		{
			ft_init(params);
			menu();
			params->var = 2;
			params->type = 3;
			ft_pthread_ship(params);
		}
		else
		{
			error_msg();
			exit(0);
		}
	}
}
