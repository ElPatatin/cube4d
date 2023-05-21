/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 21:18:26 by cpeset-c         ###   ########.fr       */
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
# define CEALING	(char *)"C"

# define WALL		(char)'1'
# define FREE		(char)'0'
# define PLAYER_NO	(char)'N'
# define PLAYER_SO	(char)'S'
# define PLAYER_WE	(char)'W'
# define PLAYER_EA	(char)'E'
# define CLOSE_DOOR	(char)'D'
# define OPEN_DOOR	(char)'C'

# define VOID	(char)'V'

// Parser Functions
void	do_parse_map(int fd);
void	parse_color(char *line, t_map *map, char letter);
void	parse_texture_path(t_map *map, char *line, char *path);
void	parse_map(char *line, t_map *map, int fd);

// Parser Utils Functions
t_bool	check_valid_path(char *path);
void	check_valid_number(int *nbr, char *line);
char	**ft_grid_realloc(char **grid, ssize_t count, ssize_t size);
void	ft_gridcpy(char **grid, char **cpygrid, char *first);
t_bool	ft_gridcheck(char *line);

#endif