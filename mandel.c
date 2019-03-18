/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:14:02 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 22:57:23 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*mandel(void *paramss)
{
	t_fract		set;
	t_params	*p;

	p = (t_params *)paramss;
	set.z0 = -1;
	while (++set.z0 != 87500)
	{
		set.x0 = set.z0 % 700;
		set.y0 = set.z0 / 700;
		set.c_i0 = (set.y0 - p->cny) / p->zoom - p->fy;
		set.c_r0 = (set.x0 - p->cnx) / p->zoom - p->fx;
		set.z_r0 = 0;
		set.z_i0 = 0;
		set.i0 = 0;
		while (set.z_r0 * set.z_r0 + set.z_i0 * set.z_i0 < 4 && set.i0 < p->it)
		{
			set.tmp0 = set.z_r0;
			set.z_r0 = set.z_r0 * set.z_r0 - set.z_i0 * set.z_i0 + set.c_r0;
			set.z_i0 = p->var * set.tmp0 * set.z_i0 + set.c_i0;
			set.i0++;
		}
		if (set.i0 != p->it)
			p->data[set.y0 * 700 + set.x0] = p->color + set.i0 * 1248518;
	}
	pthread_exit(0);
}

void	*mandel_1(void *paramss)
{
	t_fract3	set;
	t_params	*p;

	p = (t_params *)paramss;
	set.z3 = 87499;
	while (++set.z3 != 175000)
	{
		set.x3 = set.z3 % 700;
		set.y3 = set.z3 / 700;
		set.c_i3 = (set.y3 - p->cny) / p->zoom - p->fy;
		set.c_r3 = (set.x3 - p->cnx) / p->zoom - p->fx;
		set.z_r3 = 0;
		set.z_i3 = 0;
		set.i3 = 0;
		while (set.z_r3 * set.z_r3 + set.z_i3 * set.z_i3 < 4 && set.i3 < p->it)
		{
			set.tmp3 = set.z_r3;
			set.z_r3 = set.z_r3 * set.z_r3 - set.z_i3 * set.z_i3 + set.c_r3;
			set.z_i3 = p->var * set.tmp3 * set.z_i3 + set.c_i3;
			set.i3++;
		}
		if (set.i3 != p->it)
			p->data[set.y3 * 700 + set.x3] = p->color + set.i3 * 1248518;
	}
	pthread_exit(0);
}

void	*mandel_2(void *paramss)
{
	t_fract2	set;
	t_params	*p;

	p = (t_params *)paramss;
	set.z2 = 174999;
	while (++set.z2 != 350000)
	{
		set.x2 = set.z2 % 700;
		set.y2 = set.z2 / 700;
		set.c_i2 = (set.y2 - p->cny) / p->zoom - p->fy;
		set.c_r2 = (set.x2 - p->cnx) / p->zoom - p->fx;
		set.z_r2 = 0;
		set.z_i2 = 0;
		set.i2 = 0;
		while (set.z_r2 * set.z_r2 + set.z_i2 * set.z_i2 < 4 && set.i2 < p->it)
		{
			set.tmp2 = set.z_r2;
			set.z_r2 = set.z_r2 * set.z_r2 - set.z_i2 * set.z_i2 + set.c_r2;
			set.z_i2 = p->var * set.tmp2 * set.z_i2 + set.c_i2;
			set.i2++;
		}
		if (set.i2 != p->it)
			p->data[set.y2 * 700 + set.x2] = p->color + set.i2 * 1248518;
	}
	pthread_exit(0);
}

void	*mandel_3(void *paramss)
{
	t_fract1	set;
	t_params	*p;

	p = (t_params *)paramss;
	set.z1 = 262499;
	while (++set.z1 != 350000)
	{
		set.x1 = set.z1 % 700;
		set.y1 = set.z1 / 700;
		set.c_i1 = (set.y1 - p->cny) / p->zoom - p->fy;
		set.c_r1 = (set.x1 - p->cnx) / p->zoom - p->fx;
		set.z_r1 = 0;
		set.z_i1 = 0;
		set.i1 = 0;
		while (set.i1 < p->it && set.z_r1 * set.z_r1 + set.z_i1 * set.z_i1 < 4)
		{
			set.tmp1 = set.z_r1;
			set.z_r1 = set.z_r1 * set.z_r1 - set.z_i1 * set.z_i1 + set.c_r1;
			set.z_i1 = p->var * set.tmp1 * set.z_i1 + set.c_i1;
			set.i1++;
		}
		if (set.i1 != p->it)
			p->data[set.y1 * 700 + set.x1] = p->color + set.i1 * 1248518;
	}
	pthread_exit(0);
}
