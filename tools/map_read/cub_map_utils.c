/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:55:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 18:14:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

t_bool	while_isspace(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (!ft_isspace(str[idx]))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	while_isdigit(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (!ft_isdigit(str[idx]))
			return (TRUE);
	}
	return (FALSE);
}

void	get_map_length(int fd, int *map_len)
{
	char	*line;

	*map_len = 0;
	while ((get_line(&line, fd)))
	{
		(*map_len)++;
		ft_delete(line);
	}
	ft_delete(line);
}

int	get_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return ((intptr_t)ft_delete(*line));
	return (TRUE);
}
