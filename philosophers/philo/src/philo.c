/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:16:39 by daraz             #+#    #+#             */
/*   Updated: 2024/01/03 16:13:28 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_philo(t_philosopher *p, t_rules *r)
{
	if (p->id % 2 == 1)
	{
		pthread_mutex_lock(&(r->fork[p->left_fork]));
		put_message(r, p->id, "has taken a fork");
		pthread_mutex_lock(&(r->fork[p->right_fork]));
		put_message(r, p->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(r->fork[p->right_fork]));
		put_message(r, p->id, "has taken a fork");
		pthread_mutex_lock(&(r->fork[p->left_fork]));
		put_message(r, p->id, "has taken a fork");
	}
	pthread_mutex_lock(&(r->meal_check));
	put_message(r, p->id, "is eating");
	pthread_mutex_lock(&(r->stop_check));
	(p->count_eat)++;
	p->last_meal = the_time();
	death_by_goal(r, p);
	pthread_mutex_unlock(&(r->stop_check));
	pthread_mutex_unlock(&(r->meal_check));
	ft_sleep(r->eat_time, r);
	pthread_mutex_unlock(&(r->fork[p->left_fork]));
	pthread_mutex_unlock(&(r->fork[p->right_fork]));
}

void	one_philo(t_philosopher *p, t_rules *r)
{
	put_message(r, p->id, "has taken a fork");
}

void	loop(t_philosopher *p, t_rules *r)
{
	int	stop;

	while (42)
	{
		eat_philo(p, r);
		pthread_mutex_lock(&(r->stop_check));
		stop = ft_stop_checker((r->death), (r->eating_goal));
		pthread_mutex_unlock(&(r->stop_check));
		if (stop)
			break ;
		put_message(r, p->id, "is sleeping");
		ft_sleep(r->sleep_time, r);
		put_message(r, p->id, "is thinking");
	}
}

/*
** In the function, we can only pass one parameter,
** so we add rules to each
** philosopher. In this function, we make sure they eat.
** They will repeat the process until they ensure
** they do not die or achieve the goal
** of eating. Once they achieve it,
** it doesn't matter if they sleep or think.
*/

void	*eating_loop(void *void_p)
{
	t_philosopher	*p;
	t_rules			*r;

	p = (t_philosopher *)void_p;
	r = (t_rules *)p->rules;
	if (r->n_philo == 1)
	{
		one_philo(&p[0], r);
		return (NULL);
	}
	if (p->id % 2)
		usleep(15000);
	loop(p, r);
	return (NULL);
}

/*
** We create a pointer to iterate through all the philosophers,
** creating a thread for each
** of them. It also saves the creation time of both
** the rules and each philosopher,
** generates a thread for each philosopher with the function;
** THREAD_FUNCTION(eating_process).
** Once everything is created, we let them eat
** while the program enters the checking phase.
*/

int	start_philo(t_rules *r)
{
	int				i;
	t_philosopher	*p;

	p = r->philosophers;
	r->first_time = the_time();
	i = -1;
	while (++i < r->n_philo)
	{
		if (pthread_create(&(p[i].thread_id), NULL, eating_loop, &(p[i])))
			return (1);
		pthread_mutex_lock(&(r->meal_check));
		p[i].last_meal = the_time();
		pthread_mutex_unlock(&(r->meal_check));
	}
	death_checker_loop(r, r->philosophers);
	exit_philo(r, p);
	return (0);
}
