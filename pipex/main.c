/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:21:03 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/27 03:35:34 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(char **argv, int *fd, char **envp)
{
	int		fd_file;
	int		i;

	if (ft_strcmp(argv[1], "here_doc"))
	{
		i = 3;
		here_doc_func(argv);
		fd_file = open("temporary/tmp", O_RDONLY);
	}
	else
	{
		i = 2;
		fd_file = open(argv[1], O_RDONLY);
		if (fd_file < 0)
			error_such_file(argv[1]);
	}
	dup2(fd_file, 0);
	close (fd[0]);
	dup2(fd[1], 1);
	close (fd[1]);
	while (argv[i + 2])
	{
		pipex(argv[i], envp);
		i++;
	}
}

void	parent_proc(char **argv, int *fd, char **envp)
{
	int	fd_outfile;

	if (ft_strcmp(argv[1], "here_doc"))
		fd_outfile = open(argv[char_count(argv) - 1],
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd_outfile = open(argv[char_count(argv) - 1],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile < 0)
		exit (1);
	dup2(fd_outfile, 1);
	close (fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	pipex(argv[char_count(argv) - 2], envp);
}

int	aprove_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (!envp[i])
	{
		write(2, "Error! Floder PATH don't found!\n", 32);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1 || argc < 5 || !aprove_path(envp))
	{
		write(2, "Usage:	./pipex file1 cmd1 cmd2 ... file2\n", 42);
		write(2, "or	./pipex here_doc LIMITER cmd cmd1 file\n", 43);
		exit(0);
	}
	if (!aprove_file(argv[1]))
		error_such_file(argv[1]);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (!pid)
		child_proc(argv, fd, envp);
	parent_proc(argv, fd, envp);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
