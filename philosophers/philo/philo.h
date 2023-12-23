/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:16:42 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 10:33:02 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_rules;

typedef struct s_philosopher
{
	int						id;
	int						count_eat;
	int						left_fork;
	int						right_fork;
	long long int			last_meal;
	pthread_t				thread_id;
	struct t_rules			*rules;
}	t_philosopher;

typedef struct s_rules
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				death;
	int				must_eat;
	int				count_goal;
	int				eating_goal;
	long long int	first_time;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	writing;
	pthread_mutex_t	stop_check;
	t_philosopher	philosophers[200];
}	t_rules;



#endif