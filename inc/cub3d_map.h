/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 20:19:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include "cub3d_data.h"

# define MAP_EXT	(char *)".cub"

// Map Functions
void	open_map(char *cw_map);

// Read Map Functions
void	read_map(int fd, t_map *map);
int		get_line(char **line, int fd);

// Read Map Utils Function
t_bool	while_isspace(char *str);
t_bool	while_isdigit(char *str);

#endif