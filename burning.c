/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 07:27:36 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:24:36 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*burning(void *paramss)
{
	t_fract		s;
	t_params	*p;

	p = (t_params *)paramss;
	s.z0 = -1;
	while (++s.z0 != 87500)
	{
		s.x0 = s.z0 % 700;
		s.y0 = s.z0 / 700;
		s.c_i0 = (s.y0 - p->cny) / p->zoom - p->fy;
		s.c_r0 = (s.x0 - p->cnx) / p->zoom - p->fx;
		s.z_r0 = 0;
		s.z_i0 = 0;
		s.i0 = 0;
		while (s.z_r0 * s.z_r0 + s.z_i0 * s.z_i0 < 4 && s.i0 < p->it)
		{
			s.tmp0 = s.z_r0;
			s.z_r0 = fabsl(s.z_r0 * s.z_r0 - s.z_i0 * s.z_i0 + s.c_r0);
			s.z_i0 = fabsl(p->var * s.tmp0 * s.z_i0) + s.c_i0;
			s.i0++;
		}
		if (s.i0 != p->it)
			p->data[s.y0 * 700 + s.x0] = p->color + s.i0 * 1248518;
	}
	pthread_exit(0);
}

void	*burning_1(void *paramss)
{
	t_fract3	s;
	t_params	*p;

	p = (t_params *)paramss;
	s.z3 = 87499;
	while (++s.z3 != 175000)
	{
		s.x3 = s.z3 % 700;
		s.y3 = s.z3 / 700;
		s.c_i3 = (s.y3 - p->cny) / p->zoom - p->fy;
		s.c_r3 = (s.x3 - p->cnx) / p->zoom - p->fx;
		s.z_r3 = 0;
		s.z_i3 = 0;
		s.i3 = 0;
		while (s.z_r3 * s.z_r3 + s.z_i3 * s.z_i3 < 4 && s.i3 < p->it)
		{
			s.tmp3 = s.z_r3;
			s.z_r3 = fabsl(s.z_r3 * s.z_r3 - s.z_i3 * s.z_i3 + s.c_r3);
			s.z_i3 = fabsl(p->var * s.tmp3 * s.z_i3) + s.c_i3;
			s.i3++;
		}
		if (s.i3 != p->it)
			p->data[s.y3 * 700 + s.x3] = p->color + s.i3 * 1248518;
	}
	pthread_exit(0);
}

void	*burning_2(void *paramss)
{
	t_fract2	s;
	t_params	*p;

	p = (t_params *)paramss;
	s.z2 = 174999;
	while (++s.z2 != 350000)
	{
		s.x2 = s.z2 % 700;
		s.y2 = s.z2 / 700;
		s.c_i2 = (s.y2 - p->cny) / p->zoom - p->fy;
		s.c_r2 = (s.x2 - p->cnx) / p->zoom - p->fx;
		s.z_r2 = 0;
		s.z_i2 = 0;
		s.i2 = 0;
		while (s.z_r2 * s.z_r2 + s.z_i2 * s.z_i2 < 4 && s.i2 < p->it)
		{
			s.tmp2 = s.z_r2;
			s.z_r2 = fabsl(s.z_r2 * s.z_r2 - s.z_i2 * s.z_i2 + s.c_r2);
			s.z_i2 = fabsl(p->var * s.tmp2 * s.z_i2) + s.c_i2;
			s.i2++;
		}
		if (s.i2 != p->it)
			p->data[s.y2 * 700 + s.x2] = p->color + s.i2 * 1248518;
	}
	pthread_exit(0);
}

void	*burning_3(void *paramss)
{
	t_fract1	s;
	t_params	*p;

	p = (t_params *)paramss;
	s.z1 = 262499;
	while (++s.z1 != 350000)
	{
		s.x1 = s.z1 % 700;
		s.y1 = s.z1 / 700;
		s.c_i1 = (s.y1 - p->cny) / p->zoom - p->fy;
		s.c_r1 = (s.x1 - p->cnx) / p->zoom - p->fx;
		s.z_r1 = 0;
		s.z_i1 = 0;
		s.i1 = 0;
		while (s.i1 < p->it && s.z_r1 * s.z_r1 + s.z_i1 * s.z_i1 < 4)
		{
			s.tmp1 = s.z_r1;
			s.z_r1 = fabsl(s.z_r1 * s.z_r1 - s.z_i1 * s.z_i1 + s.c_r1);
			s.z_i1 = fabsl(p->var * s.tmp1 * s.z_i1) + s.c_i1;
			s.i1++;
		}
		if (s.i1 != p->it)
			p->data[s.y1 * 700 + s.x1] = p->color + s.i1 * 1248518;
	}
	pthread_exit(0);
}
