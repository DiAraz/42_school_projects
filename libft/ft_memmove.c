/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:15:29 by daraz             #+#    #+#             */
/*   Updated: 2023/08/16 10:19:54 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memmove copies n bytes from memory area src to memory
	area dst. The memory areas may overlap: if the dst pointer is found
	to be between the src pointer and the index n, copying will be done
	back to front to prevent data being modified before being copied.
	Otherwise it will be done front to back	to preserve data.

	RETURN VALUE :
	A pointer to dst.
*/

void    *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_p;
	unsigned char *src_p;

	dst_p = dst;
	src_p = (unsigned char*)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
		while (len--)
			dst_p[len] = src_p[len];
	return (dst);
}
