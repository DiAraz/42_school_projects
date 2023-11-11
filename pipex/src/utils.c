/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 07:33:28 by daraz             #+#    #+#             */
/*   Updated: 2023/11/11 15:52:05 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	error(void)
{
	perror("Error: ");
	return (1);
}

char	*find_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*slashed;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		slashed = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slashed, cmd);
		free(slashed);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **env)
{
	char	**cmd;
	int		i;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], env), cmd, env) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		i = -1;
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit (EXIT_FAILURE);
	}
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (i == 1)
		file = open(argv, O_RDONLY | O_CLOEXEC, 0777);
	if (file == -1)
	{
		perror("Error: ");
		return (-1);
	}
	return (file);
}
