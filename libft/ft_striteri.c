/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:38:52 by daraz             #+#    #+#             */
/*   Updated: 2023/09/07 19:57:47 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_striteri applies the given function f to each
	character in the given string s.

	RETURN VALUE :
	None.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
