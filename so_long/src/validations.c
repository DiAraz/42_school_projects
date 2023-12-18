/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:55:13 by daraz             #+#    #+#             */
/*   Updated: 2023/12/18 10:34:52 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validation(t_game *game, int fd)
{
	ft_printf("Validations commence...\n");
	check_map(game);
	valid_map(game);
	valid_path(game, fd);
}
