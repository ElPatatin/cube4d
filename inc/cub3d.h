/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:13:12 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 18:59:50 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "ft_printf_fd.h"

# ifdef __APPLE__
#  define OS			(char *)"Apple"
#  include "mlx.h"
# elif __linux__
#  define OS			(char *)"Linux"
#  include "mlx.h"
# endif

# include <math.h>

# include "cub3d_data.h"

// Graphics Function
void	graphics(t_game *game);

// Hooks Function
void	hooks(t_game *game);

// Game Function
int		game_loop(t_game *game);

// Init Functions
//
// Init Window
void	init_vals(t_mlx *vals, t_data *data);
// Init Map
void	init_map(t_map *map, size_t map_len);
// Init Player
void	init_player(t_game *game);


// Util Function
void	new_window(t_mlx *vals, t_data *data);
void	ft_mlx_put_pixels(t_data *data, int x, int y, int color);
t_bool	ft_ismap(int c);

#endif