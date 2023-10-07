/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:19:55 by daraz             #+#    #+#             */
/*   Updated: 2023/10/07 14:19:58 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define READ_END	0
# define WRITE_END	1

int		error(void);
void	arg_error(int flag);
void	execute(char *argv, char **env);
int		open_file(char *argv, int i);

/* bonus */
int		ft_get_next_line(char **line);

#endif