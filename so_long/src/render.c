/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:22:11 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 11:22:37 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_img(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->line)
	{
		x = 0;
		while (x < game->col)
		{
			put_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}
