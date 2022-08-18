/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:03:17 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/25 18:46:12 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		aprove_file(char *filename);
int		ft_strlen(char *str);
int		ft_strlen_plus(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
int		char_count(char **str);
char	*ft_strnstr(char *haystack, char *needle, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *str, char c);
void	pipex(char *cmd1, char **envp);
char	*path_func(char *cmd, char **envp);
void	here_doc_func(char **argv);
void	error_such_file(char *filename);

#endif
