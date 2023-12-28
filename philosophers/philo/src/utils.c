/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:12:13 by daraz             #+#    #+#             */
/*   Updated: 2023/12/28 10:14:13 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_message(t_rules *r, int id, char *s)
{
	int	stop;

	pthread_mutex_lock(&(r->stop_check));
	stop = ft_stop_checker((r->death), (r->eating_goal));
	pthread_mutex_lock(&(r->writing));
	if (!stop)
	{
		printf("%lld ", (the_time() - r->first_time));
		printf("%d ", (id + 1));
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&(r->writing));
	pthread_mutex_unlock(&(r->stop_check));
}

int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') && sign == 1)
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

/*
** We obtain the time by multiplying seconds by 1000 (to keep 3 digits 
** for milliseconds). We divide microseconds by a thousand to keep 
** 3 digits (milliseconds) and add them.
*/

long long	the_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_diff(long long present, long long past)
{
	return (present - past);
}

void	ft_sleep(long long time_sleep, t_rules *r)
{
	long long	i;
	int			stop;

	i = the_time();
	pthread_mutex_lock(&(r->stop_check));
	stop = ft_stop_checker((r->death), (r->eating_goal));
	pthread_mutex_unlock(&(r->stop_check));
	while (!stop)
	{
		if (time_diff(the_time(), i) >= time_sleep)
			break ;
		pthread_mutex_lock(&(r->stop_check));
		stop = ft_stop_checker((r->death), (r->eating_goal));
		pthread_mutex_unlock(&(r->stop_check));
		usleep(100);
	}
}
