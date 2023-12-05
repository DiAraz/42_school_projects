/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:28:23 by daraz             #+#    #+#             */
/*   Updated: 2023/12/05 10:16:28 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_digit:
    We check if the character is a digit.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
    We check if the character is + or -.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
    We compare two strings of digits to check if they are the same or not.
    Example: +42 == 42 but -42 != 42.
*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
