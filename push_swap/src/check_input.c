/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:46:06 by daraz             #+#    #+#             */
/*   Updated: 2023/12/05 10:16:24 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_number:
    We check if the argument is a number.
    Also we handle +1 1 and -1 as all of them are valid numbers.
*/
static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* duplicates:
    We check if the arguments have duplicate numbers.

*/
static int	duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* is_zero:
    We check the argument is a 0 to avoid 0 +0 -0 duplicates
	and 0 0000 +000 -00000000 too.
*/
static int	is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* correct_input:
    We check if the given arguments are all numbers, without duplicates.
*/
int	correct_input(char **av)
{
	int	i;
	int	zero;

	zero = 0;
	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		zero += is_zero(av[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (duplicates(av))
		return (0);
	return (1);
}
