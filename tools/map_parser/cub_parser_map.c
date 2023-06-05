/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:28:27 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 16:04:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_data.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static size_t	get_max_length(t_map *map);
static void		allocate_grid(t_map *map, size_t width);
static void		replace_spaces_with_void(t_map *map);

void	load_map(t_map *map)
{
	size_t	width;

	width = get_max_length(map);
	allocate_grid(map, width);
	replace_spaces_with_void(map);
	map_expander_handler(map, width);
}

static size_t	get_max_length(t_map *map)
{
	size_t	max;
	size_t	idx;

	max = 0;
	idx = 0;
	while (idx < ft_strcount(map->map))
	{
		if (ft_strlen(map->map[idx]) > max)
			max = ft_strlen(map->map[idx]);
		idx++;
	}
	return (max);
}

static void	allocate_grid(t_map *map, size_t width)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	UNUSED(width);
	while (map->map[len])
		len++;
	map->grid = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!map->grid)
		terminate_error(ERR_MEM, SYS_MEM);
	while (map->map[idx])
	{
		map->grid[idx] = ft_strdup(map->map[idx]);
		if (!map->grid[idx])
			terminate_error(ERR_MEM, SYS_MEM);
		idx++;
	}
}

static void	replace_spaces_with_void(t_map *map)
{
	size_t	idx;
	size_t	len;
	size_t	count;

	idx = 0;
	while (map->grid[idx])
	{
		len = ft_strlen(map->grid[idx]);
		count = 0;
		while (count < len)
		{
			if (ft_strchr(SPACES, map->grid[idx][count]) != NULL)
				map->grid[idx][count] = VOID;
			count++;
		}
		idx++;
	}
}
