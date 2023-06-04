/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:05 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/04 21:01:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static void	load_textures(t_map *map);
static void	load_colours(t_map *map);

void	get_map(int fd, size_t map_len)
{
	t_map	map;

	init_map(&map);
	map.length = map_len;
	read_map(fd, &map);
	load_textures(&map);
	if (!validate_textures(&map))
		terminate_error(ERR_TEX, SYS_TEX);
	load_colours(&map);
	if (!validate_colours(&map))
		terminate_error(ERR_CLR, SYS_CLR);
}

static void	load_textures(t_map *map)
{
	load_north_texture(map);
	load_south_texture(map);
	load_west_texture(map);
	load_east_texture(map);
	load_sprite_texture(map);
}

static void	load_colours(t_map *map)
{
	load_floor_colour(map);
	load_cealing_colour(map);
}

// void	parse_color(char *line, t_map *map, char letter)
// {

// }
