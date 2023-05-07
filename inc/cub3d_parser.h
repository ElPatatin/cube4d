/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/06 20:38:40 by cpeset-c         ###   ########.fr       */
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

#endif