/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:14:32 by daraz             #+#    #+#             */
/*   Updated: 2023/10/13 08:16:56 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <limits.h>

/* To read input from the stdin (terminal) and return line. */
int	ft_get_next_line(char **line)
{
	char	*buffer;
	int		num_read;
	int		i;
	char	c;

	i = 0;
	num_read = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	num_read = read(0, &c, 1);
	while (num_read && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		num_read = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (num_read);
}
