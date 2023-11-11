/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 07:32:19 by daraz             #+#    #+#             */
/*   Updated: 2023/11/11 15:16:00 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open_file(argv[1], 2);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	dup2(infile, STDIN_FILENO);
	close(fd[READ_END]);
	close(infile);
	execute(argv[2], env);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open_file(argv[4], 1);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(outfile, STDOUT_FILENO);
	close(fd[WRITE_END]);
	close(outfile);
	execute(argv[3], env);
}

int	main(int argc, char *argv[], char *env[])
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, env, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, env, fd);
	}
	else
	{
		ft_putstr_fd("Error: invalid arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
