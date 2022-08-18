/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprove_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:44:30 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/26 23:55:30 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	aprove_file(char *filename)
{
	int	fd;

	if (ft_strcmp(filename, "here_doc"))
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		close (fd);
		return (1);
	}
	return (0);
}
