/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:44:22 by daraz             #+#    #+#             */
/*   Updated: 2023/12/12 09:42:09 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_collectibles(t_game *game)
{
    int x;
    int y;
    int collectables;

    x = 0;
    y = 0;
    collectables = 0;

    while (x < game->line)
    {
        while (y < game->col)
        {
            if (game->map[x][y] == 'C')
            {
                collectables++;
            }
            y++;
        }
        y = 0;
        x++;
    }
    return (collectables);
}