/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 15:19:27 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 11:04:05 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*julia(void *paramss)
{
	t_fract		s;
	t_params	*p;

	p = (t_params *)paramss;
	s.y0 = -1;
	while (s.y0++ < 125)
	{
		s.x0 = -1;
		while (s.x0++ < 700)
		{
			s.z_r0 = s.x0 / p->zoom - p->cnx / p->zoom - p->fx;
			s.z_i0 = s.y0 / p->zoom - p->cny / p->zoom - p->fy;
			s.i0 = 0;
			while (s.z_r0 * s.z_r0 + s.z_i0 * s.z_i0 < 4 && s.i0 < p->it)
			{
				s.tmp0 = s.z_r0;
				s.z_r0 = s.z_r0 * s.z_r0 - s.z_i0 * s.z_i0 + p->c_r;
				s.z_i0 = 2 * s.z_i0 * s.tmp0 + p->c_i;
				s.i0++;
			}
			if (s.i0 != p->it)
				p->data[s.y0 * 700 + s.x0] = p->color + s.i0 * 1248518;
		}
	}
	pthread_exit(0);
}

void	*julia_1(void *paramss)
{
	t_fract1	s;
	t_params	*p;

	p = (t_params *)paramss;
	s.y1 = 124;
	while (s.y1++ < 250)
	{
		s.x1 = -1;
		while (s.x1++ < 700)
		{
			s.z_r1 = s.x1 / p->zoom - p->cnx / p->zoom - p->fx;
			s.z_i1 = s.y1 / p->zoom - p->cny / p->zoom - p->fy;
			s.i1 = 0;
			while (s.z_r1 * s.z_r1 + s.z_i1 * s.z_i1 < 4 && s.i1 < p->it)
			{
				s.tmp1 = s.z_r1;
				s.z_r1 = s.z_r1 * s.z_r1 - s.z_i1 * s.z_i1 + p->c_r;
				s.z_i1 = 2 * s.z_i1 * s.tmp1 + p->c_i;
				s.i1++;
			}
			if (s.i1 != p->it)
				p->data[s.y1 * 700 + s.x1] = p->color + s.i1 * 1248518;
		}
	}
	pthread_exit(0);
}

void	*julia_2(void *paramss)
{
	t_fract2	s;
	t_params	*p;

	p = (t_params *)paramss;
	s.y2 = 249;
	while (s.y2++ < 375)
	{
		s.x2 = -1;
		while (s.x2++ < 700)
		{
			s.z_r2 = s.x2 / p->zoom - p->cnx / p->zoom - p->fx;
			s.z_i2 = s.y2 / p->zoom - p->cny / p->zoom - p->fy;
			s.i2 = 0;
			while (s.z_r2 * s.z_r2 + s.z_i2 * s.z_i2 < 4 && s.i2 < p->it)
			{
				s.tmp2 = s.z_r2;
				s.z_r2 = s.z_r2 * s.z_r2 - s.z_i2 * s.z_i2 + p->c_r;
				s.z_i2 = 2 * s.z_i2 * s.tmp2 + p->c_i;
				s.i2++;
			}
			if (s.i2 != p->it)
				p->data[s.y2 * 700 + s.x2] = p->color + s.i2 * 1248518;
		}
	}
	pthread_exit(0);
}

void	*julia_3(void *paramss)
{
	t_fract3	s;
	t_params	*p;

	p = (t_params *)paramss;
	s.y3 = 374;
	while (s.y3++ < 500)
	{
		s.x3 = -1;
		while (s.x3++ < 700)
		{
			s.z_r3 = s.x3 / p->zoom - p->cnx / p->zoom - p->fx;
			s.z_i3 = s.y3 / p->zoom - p->cny / p->zoom - p->fy;
			s.i3 = 0;
			while (s.z_r3 * s.z_r3 + s.z_i3 * s.z_i3 < 4 && s.i3 < p->it)
			{
				s.tmp3 = s.z_r3;
				s.z_r3 = s.z_r3 * s.z_r3 - s.z_i3 * s.z_i3 + p->c_r;
				s.z_i3 = 2 * s.z_i3 * s.tmp3 + p->c_i;
				s.i3++;
			}
			if (s.i3 != p->it)
				p->data[s.y3 * 700 + s.x3] = p->color + s.i3 * 1248518;
		}
	}
	pthread_exit(0);
}
