/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:42:40 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 11:22:27 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_maps(t_game *game, int fd)
{
	int		i;
	int		y;
	char	*c;

	i = 0;
	y = game->line + 1;
	game->map = (char **)malloc(sizeof(char *) * y);
	if (!game->map)
		ft_exit("Error\n", game);
	while (i < y)
	{
		c = get_next_line(fd);
		game->map[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}
