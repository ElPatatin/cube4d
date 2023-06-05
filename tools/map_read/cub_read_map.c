/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:45:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 16:35:39 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

void	read_map(int fd, t_map *map)
{
	char	*line;
	size_t	idx;

	map->map = (char **)ft_calloc(map->length + 1, sizeof(char *));
	if (!map->map)
		terminate_error(ERR_MEM, SYS_MEM);
	idx = 0;
	while (get_line(&line, fd))
	{
		map->map[idx] = ft_strdup(line);
		idx++;
		ft_delete(line);
	}
}

// static void	get_map_line(t_map *map, char *line, int fd)
// {
// 	if (!ft_strncmp(NORTH, line, ft_strlen(NORTH)))
// 		parse_texture_path(map, line, NORTH);
// 	else if (!ft_strncmp(SOUTH, line, ft_strlen(SOUTH)))
// 		parse_texture_path(map, line, SOUTH);
// 	else if (!ft_strncmp(WEST, line, ft_strlen(WEST)))
// 		parse_texture_path(map, line, WEST);
// 	else if (!ft_strncmp(EAST, line, ft_strlen(EAST)))
// 		parse_texture_path(map, line, EAST);
// 	else if (!ft_strncmp(SPRITE, line, ft_strlen(SPRITE)))
// 		parse_texture_path(map, line, SPRITE);
// 	else if (!ft_strncmp(FLOOR, line, ft_strlen(FLOOR)))
// 		parse_color(line, map, *FLOOR);
// 	else if (!ft_strncmp(CEALING, line, ft_strlen(CEALING)))
// 		parse_color(line, map, *CEALING);
// 	else
// 		parse_map(line, map, fd);
// }
