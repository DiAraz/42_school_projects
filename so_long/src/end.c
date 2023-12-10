/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:54:48 by daraz             #+#    #+#             */
/*   Updated: 2023/12/10 16:06:19 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_exit(char *str, t_game *game)
{
        ft_printf("%s", str);
        if (game->map[0])
            free_map(game);
        exit(0);
}

void free_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}