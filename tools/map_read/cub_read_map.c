/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:45:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/07 19:22:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static int	get_line(char **line, int fd);
static void	get_map_line(t_map *map, char *line);

void	read_map(int fd, t_map *map)
{
	char	*line;

	while (get_line(&line, fd))
	{
		if (while_isspace(line))
			get_map_line(map, line);
		ft_delete(line);
	}
}

static void	get_map_line(t_map *map, char *line)
{
	if (!ft_strncmp(NORTH, line, ft_strlen(NORTH)))
		parse_texture_path(map, line, NORTH);
	else if (!ft_strncmp(SOUTH, line, ft_strlen(SOUTH)))
		parse_texture_path(map, line, SOUTH);
	else if (!ft_strncmp(WEST, line, ft_strlen(WEST)))
		parse_texture_path(map, line, WEST);
	else if (!ft_strncmp(EAST, line, ft_strlen(EAST)))
		parse_texture_path(map, line, EAST);
	else if (!ft_strncmp(SPRITE, line, ft_strlen(SPRITE)))
		parse_texture_path(map, line, SPRITE);
	else if (!ft_strncmp(FLOOR, line, ft_strlen(FLOOR)))
		parse_color(line, map, *FLOOR);
	else if (!ft_strncmp(CLNG, line, ft_strlen(CLNG)))
		parse_color(line, map, *CLNG);
	else
		printf("map parsing goes here -> %s", line);
}

static int	get_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return ((intptr_t)ft_delete(*line));
	return (TRUE);
}
