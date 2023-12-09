/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:34:37 by daraz             #+#    #+#             */
/*   Updated: 2023/12/09 15:51:22 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(char *nbstr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_pad_width(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

int	ft_print_unint(char *nbstr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_u(nbstr, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_pad_width(flags.width, 0, 0);
	}
	else
		count += ft_pad_width(flags.width, ft_strlen(nbstr), flags.zero);
	if (flags.left == 0)
		count += ft_print_u(nbstr, flags);
	return (count);
}

int	ft_print_unsigned(unsigned n, t_flags flags)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	nbstr = ft_printf_utoa(n);
	if (!nbstr)
		return (0);
	count += ft_print_unint(nbstr, flags);
	free(nbstr);
	return (count);
}
