/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:13:12 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 12:20:27 by ogonzale         ###   ########.fr       */
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

// Game Loop
int		game_loop(t_game *game);

// Hooks Function
void	hooks(t_game *game);

// Init Functions
void	init_map(t_game *game, char map[MAPHEIGHT][MAPWIDTH]); //TODO: pass non-hardcoded map
void	init_player(t_game *game);

// Init Window
void	init_vals(t_mlx *vals, t_data *data);

// Util Function
void	new_window(t_mlx *vals, t_data *data);
void	ft_mlx_put_pixels(t_data *data, int x, int y, int color);
void	exit_game(t_game *game);

#endif