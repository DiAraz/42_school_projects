/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:44:22 by daraz             #+#    #+#             */
/*   Updated: 2023/12/23 11:22:23 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images(t_game *game)
{
	int	len;

	len = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->img.player = mlx_xpm_file_to_image(game->mlx, HERO, &len, &len);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, TREASURE, &len, &len);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, KEY, &len, &len);
	game->img.on_box = mlx_xpm_file_to_image(game->mlx, ON_TRSR, &len, &len);
}

void	put_map(int x, int y, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * 64, y * 64);
	if (c == 'B')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.on_box, x * 64, y * 64);
}

int	count_collectibles(t_game *game)
{
	int	x;
	int	y;
	int	collectables;

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

void	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
			}
			y++;
		}
		y = 0;
		x++;
	}
}
