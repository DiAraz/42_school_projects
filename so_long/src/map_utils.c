/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:44:22 by daraz             #+#    #+#             */
/*   Updated: 2023/12/10 17:49:04 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_collectibles(t_game *game)
{
    int i;
    int j;
    int collectables;

    i = 0;
    j = 0;
    collectables = 0;

    while (i < game->line)
    {
        while (j < game->col)
        {
            if (game->map[i][j] == 'C')
            {
                collectables++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (collectables);
}