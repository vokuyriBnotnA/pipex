/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:22:50 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/26 23:54:21 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_func(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;
	char	*path_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_path, cmd);
		free(path_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

void	pipex(char *cmd1, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd1, ' ');
	path = path_func(cmds[0], envp);
	if (execve(path, cmds, envp) == -1)
		exit (1);
}

void	here_doc_func(char **argv)
{
	int		fd_file;
	char	*str;
	char	*limiter;

	fd_file = open("temporary/tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_file < 0)
		exit (1);
	limiter = ft_strjoin(argv[2], "\n");
	write (1, "pipe pipe heredoc> ", 19);
	str = get_next_line(0);
	while (str)
	{
		if (ft_strcmp(str, limiter))
		{
			free (str);
			break ;
		}
		write (fd_file, str, ft_strlen(str));
		free (str);
		write (1, "pipe pipe heredoc> ", 19);
		str = get_next_line(0);
	}
	close (fd_file);
}

void	error_such_file(char *filename)
{
	write (2, "pipex: no such file or directory :", 34);
	write (2, filename, ft_strlen(filename));
	write (2, "\n", 1);
	exit (1);
}
