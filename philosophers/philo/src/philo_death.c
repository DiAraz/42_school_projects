/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:25:20 by daraz             #+#    #+#             */
/*   Updated: 2023/12/28 12:19:35 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_stop_checker(int death, int goal)
{
	int	i;

	if (death || goal)
		i = 1;
	else
		i = 0;
	return (i);
}

/*
** Here we check for each philosopher
** the time difference between their last
** meal and how long they have been alive.
** If it is greater than their death time,
** 	(r->death = 1) becomes true
*/

void	death_by_hungry(t_rules *r, t_philosopher *p)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		pthread_mutex_lock(&(r->meal_check));
		if (time_diff(the_time(), p[i].last_meal) > r->death_time)
		{
			put_message(r, i, "died");
			pthread_mutex_lock(&(r->stop_check));
			r->death = 1;
			pthread_mutex_unlock(&(r->stop_check));
		}
		pthread_mutex_unlock(&(r->meal_check));
		usleep(50);
	}
}

/*
** Here we check for each philosopher 
** how many times they have eaten. In this function,
** we check that:
** 	p->count_eat == r->must_eat 
** (the philosopher eats the REQUIRED number of times)
** We do this for each philosopher in a loop, as it will count how many
** philosophers have done it. In the end,
** we check if all philosophers meet the goal.
*/

void	death_by_goal(t_rules *r, t_philosopher *p)
{
	if (p->count_eat == r->must_eat)
	{
		r->count_goal++;
	}
	if (r->count_goal == r->n_philo)
	{
		r->eating_goal = 1;
	}
}

/*
** This is the main loop to check if the launcher should be closed.
** STOP depends on whether someone dies or
** everyone meets the goal. Depending on two different cases, we separate into
** two different functions:
** - to check if they die of hunger: death_by_hungry()
** - to check if they finish by the goal: death_by_goal()
** If either of the two is satisfied, the program is closed.
*/

void	death_checker_loop(t_rules *r, t_philosopher *p)
{
	int	stop;

	while (1)
	{
		death_by_hungry(r, p);
		pthread_mutex_lock(&(r->stop_check));
		stop = ft_stop_checker((r->death), (r->eating_goal));
		pthread_mutex_unlock(&(r->stop_check));
		if (stop)
			break ;
	}
}
