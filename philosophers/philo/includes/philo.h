/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:16:42 by daraz             #+#    #+#             */
/*   Updated: 2023/12/28 12:00:17 by daraz            ###   ########.fr       */
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

/*		---	utils	---		*/
void		put_message(t_rules *r, int id, char *s);
int			ft_atoi(const char *str);
long long	the_time(void);
long long	time_diff(long long present, long long past);
void		ft_sleep(long long time_sleep, t_rules *r);

/*		---	program end	---		*/
int			ft_stop_checker(int death, int goal);
void		death_checker_loop(t_rules *r, t_philosopher *p);
void		death_by_goal(t_rules *r, t_philosopher *p);

/*		---	init rules, mutex and philosophers	---		*/
int			param_init(t_rules *rules, char **arguments);

/*		---	program start	---		*/
int			start_philo(t_rules *rules);

/*		---	error manager	---		*/
int			ft_error(char *str);
int			ft_init_error(int error);

#endif