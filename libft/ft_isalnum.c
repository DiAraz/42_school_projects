/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:04:01 by daraz             #+#    #+#             */
/*   Updated: 2023/08/15 10:07:03 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_isalnum checks whether the value of c is alphanumeric.

	RETURN VALUE :
	One if c is alphanumeric, zero if not.
*/

int ft_isalnum(int c)
{
	if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z')
	|| ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}