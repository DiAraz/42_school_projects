/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:45:18 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 12:08:09 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mutex_init(t_rules *rules)
{
    int	i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->fork[i]), NULL))
			return (2);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (2);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (2);
	if (pthread_mutex_init(&(rules->stop_check), NULL))
		return (2);
	return (0);
}

int philo_init(t_rules *rules)
{
    int	i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].count_eat = 0;
		rules->philosophers[i].left_fork = i;
		rules->philosophers[i].right_fork = (i + 1) % rules->n_philo;
		rules->philosophers[i].last_meal = 0;
		rules->philosophers[i].rules = (struct t_rules *)rules;
	}
	return (0);
}

int param_init(t_rules *rules, char **argv)
{
    rules->n_philo = ft_atoi(argv[1]);
	rules->death_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleep_time = ft_atoi(argv[4]);
	rules->death = 0;
	rules->count_goal = 0;
	rules->eating_goal = 0;
	if (rules->n_philo < 1 || rules->death_time < 0 || rules->eat_time < 0
		|| rules->sleep_time < 0 || rules->n_philo > 200)
		return (1);
	if (argv[5])
	{
		rules->must_eat = ft_atoi(argv[5]);
		if (rules->must_eat <= 0)
			return (1);
	}
	else
		rules->must_eat = -1;
    if (mutex_init(rules))
        return (2);
    philo_init(rules);
    return (0);
}
