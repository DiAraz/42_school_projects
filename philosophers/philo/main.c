/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:12:33 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 12:17:31 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **argv)
{
	t_rules rules;
	int parameters;

	if (ac != 5 && ac != 6)
		return (ft_error("Invalid inputs"));
	parameters = param_init(&rules, argv);
	if (parameters)
		return (ft_init_error(parameters));
	if (start_philo(&rules))
		return (ft_error("Thread creating failure"));
	return (0);
}
