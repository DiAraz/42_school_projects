/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:43:57 by daraz             #+#    #+#             */
/*   Updated: 2023/12/10 18:14:10 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	start_map(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_box = 0;
	game->exit = 0;
	game->player = 0;
	game->line = 0;
	game->col = 0;
	game->end_game = 0;
	game->move = 1;
}

int main(int argc, char **argv)
{
    t_game game;
    int fd;
    int fd_x;
    int fd_y;
    int fd_map;

    fd_x = open(argv[1], O_RDONLY);
    fd_y = open(argv[1], O_RDONLY);
    fd_map = open(argv[1], O_RDONLY);
    check_args(&game, argc, argv);
    start_map(&game);
    game.score = count_collectibles(&game);
    game.line = get_line_size(&game, fd_y);
    game.col = get_col_size(&game, fd_x);
    fd = open(argv[1], O_RDONLY);
    if (game.col == -1)
		ft_exit("Error\n", &game);
    close(fd_x);
	close(fd_y);
	close(fd);
	close(fd_map);
    
}