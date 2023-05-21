/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 19:51:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static int	check_map_extension(char *cw_map);

void	open_map(char *cw_map)
{
	int	fd;

	if (check_map_extension(cw_map))
		terminate_error(ERR_EXT_MAP, SYS_EXT_MAP);
	fd = open(cw_map, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		terminate_error(ERR_OPEN_MAP, SYS_OPEN_MAP);
	do_parse_map(fd);
	if (close(fd))
		terminate_error(ERR_CLOSE_MAP, SYS_CLOSE_MAP);
}

static int	check_map_extension(char *cw_map)
{
	size_t	len;
	char	*str;

	len = ft_strlen(cw_map);
	str = ft_strrchr(cw_map, '/');
	if (!str)
		str = cw_map;
	if (len <= 4 || ft_strlen(&str[1]) <= 4)
		return (TRUE);
	if (ft_strncmp(MAP_EXT, &cw_map[len - 4], ft_strlen(MAP_EXT)))
		return (TRUE);
	return (FALSE);
}
