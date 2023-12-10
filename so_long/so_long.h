/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:35:02 by daraz             #+#    #+#             */
/*   Updated: 2023/12/10 15:47:44 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*on_box;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_floodfill;
	char	temp;
	int		line;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		player_on_box;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;

#endif