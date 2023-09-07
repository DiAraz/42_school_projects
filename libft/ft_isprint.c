/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:13:39 by daraz             #+#    #+#             */
/*   Updated: 2023/09/07 19:59:28 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_isprint checks whether c is a printable character or not.

	RETURN VALUE :
	One if c is printable, zero if not.
*/

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
