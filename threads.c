/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 05:20:35 by nhamid            #+#    #+#             */
/*   Updated: 2019/03/18 07:47:45 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_pthread_mandel(t_params *params)
{
	pthread_t		t_id[4];
	pthread_attr_t	attr;
	int				i;

	pthread_attr_init(&attr);
	pthread_create(&t_id[0], &attr, mandel, (void *)params);
	pthread_create(&t_id[1], &attr, mandel_1, (void *)params);
	pthread_create(&t_id[2], &attr, mandel_2, (void *)params);
	pthread_create(&t_id[3], &attr, mandel_3, (void *)params);
	i = -1;
	while (++i < 4)
		pthread_join(t_id[i], NULL);
}

void	ft_pthread_julia(t_params *params)
{
	pthread_t		t_id[4];
	pthread_attr_t	attr;
	int				i;

	pthread_attr_init(&attr);
	pthread_create(&t_id[0], &attr, julia, (void *)params);
	pthread_create(&t_id[1], &attr, julia_1, (void *)params);
	pthread_create(&t_id[2], &attr, julia_2, (void *)params);
	pthread_create(&t_id[3], &attr, julia_3, (void *)params);
	i = -1;
	while (++i < 4)
		pthread_join(t_id[i], NULL);
}

void	ft_pthread_ship(t_params *params)
{
	pthread_t		t_id[4];
	pthread_attr_t	attr;
	int				i;

	pthread_attr_init(&attr);
	pthread_create(&t_id[0], &attr, burning, (void *)params);
	pthread_create(&t_id[1], &attr, burning_1, (void *)params);
	pthread_create(&t_id[2], &attr, burning_2, (void *)params);
	pthread_create(&t_id[3], &attr, burning_3, (void *)params);
	i = -1;
	while (++i < 4)
		pthread_join(t_id[i], NULL);
}
