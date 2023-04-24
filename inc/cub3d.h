/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:13:12 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 19:50:25 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "ft_printf_fd.h"

# ifdef __APPLE__
#  define OS			(char *)"Apple"
#  include "../library/mlx_Darwin/mlx.h"
# elif __linux__
#  define OS			(char *)"Linux"
#  include "../library/mlx_Linux/mlx.h"
# endif

# include <math.h>

# include "cub3d_data.h"

// Graphics Function
void	graphics(void);

// Hooks Functin
void	hooks(t_mlx *vals);

// Init Functions
//
// Init Window
void	init_vals(t_mlx *vals, t_data *data);

// Util Function
void	new_window(t_mlx *vals, t_data *data);
void	ft_mlx_put_pixels(t_data *data, int x, int y, int color);

#endif