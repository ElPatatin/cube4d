/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/07 18:57:11 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include "cub3d_data.h"

# define NORTH	(char *)"NO"
# define SOUTH	(char *)"SO"
# define WEST	(char *)"WE"
# define EAST	(char *)"E"
# define SPRITE	(char *)"S"

# define FLOOR	(char *)"F"
# define CLNG	(char *)"C"

# define WALL	(char)'1'
# define FREE	(char)'0'
# define P_NO	(char)'N'
# define P_SO	(char)'S'
# define P_WE	(char)'W'
# define P_EA	(char)'E'

# define VOID	(char)'v'

// Parser Functions
void	parse_map(int fd);
void	parse_color(char *line, t_map *map, char letter);
void	parse_texture_path(t_map *map, char *line, char *path);

// Parser Utils Functions
t_bool	check_valid_path(char *path);
void	check_valid_number(int *nbr, char *line);

#endif