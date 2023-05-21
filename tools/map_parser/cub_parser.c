/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:05 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 21:30:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

void	do_parse_map(int fd)
{
	t_map	map;

	map.grid_full = FALSE;
	read_map(fd, &map);
	// Here do check of map if all set up correctly
	// Here do expansion of void for the bit map
	// Here check validation of map
}

void	parse_texture_path(t_map *map, char *line, char *cmp)
{
	char	*path;

	line += ft_strlen(cmp);
	while (*line && ft_isspace(*line))
		line++;
	path = ft_strtrim(line, "\n");
	if (!path)
		terminate_error(ERR_MEM, SYS_MEM);
	if (check_valid_path(path))
	{
		ft_delete(path);
		terminate_error(ERR_BAD_RES, SYS_BAD_RES);
	}
	if (!ft_strncmp(NORTH, cmp, ft_strlen(NORTH)))
		map->no_path = path;
	else if (!ft_strncmp(SOUTH, cmp, ft_strlen(SOUTH)))
		map->so_path = path;
	else if (!ft_strncmp(WEST, cmp, ft_strlen(WEST)))
		map->we_path = path;
	else if (!ft_strncmp(EAST, cmp, ft_strlen(EAST)))
		map->ea_path = path;
	else if (!ft_strncmp(SPRITE, cmp, ft_strlen(SPRITE)))
		map->s_path = path;
}

void	parse_color(char *line, t_map *map, char letter)
{
	int	r;
	int	g;
	int	b;

	line++;
	while (*line && ft_isspace(*line))
		line++;
	check_valid_number(&r, line);
	while (*line && ft_isdigit(*line))
		line++;
	line++;
	check_valid_number(&g, line);
	while (*line && ft_isdigit(*line))
		line++;
	line++;
	check_valid_number(&b, line);
	if (letter == *FLOOR)
		map->f_color = (r << 16) | (g << 8) | b;
	else if (letter == *CEALING)
		map->c_color = (r << 16) | (g << 8) | b;
}

void	parse_map(char *line, t_map *map, int fd)
{
	char	**aux;
	size_t	map_len;

	if (map->grid_full)
		terminate_error(ERR_MAP, SYS_MAP);
	aux = ft_calloc(2, sizeof(char *));
	map_len = 0;
	while (get_line(&aux[map_len], fd))
	{
		if (!ft_ismap(aux[map_len][0]))
			break ;
		aux = ft_grid_realloc(aux, (map_len + 2), sizeof(char *));
		map_len++;
	}
	map->grid = (char **)ft_calloc(ft_strcount(aux) + 2, sizeof(char *));
	if (!map->grid)
		terminate_error(ERR_MEM, SYS_MEM);
	ft_gridcpy(map->grid, aux, line);
	map->grid_full = TRUE;
}
