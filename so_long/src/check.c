/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:54:51 by daraz             #+#    #+#             */
/*   Updated: 2023/12/10 16:10:12 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_args(t_game *game, int argc, char **argv)
{
    if (argc != 2)
        ft_exit("Error\nNumber of arguments must be 2\n", game);
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
    {
        ft_printf("Error\nMap file type must be \".ber\"\n");
        exit(0);
    }
}