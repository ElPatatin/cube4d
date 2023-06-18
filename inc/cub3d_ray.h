/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:25:14 by ogonzale          #+#    #+#             */
/*   Updated: 2023/06/18 13:03:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAY_H
# define CUB3D_RAY_H

# include "cub3d_data.h"

// Ray calculations
void	calc_ray_pos_dir(t_game *game, int x);
void	calc_ray_delta_dist(t_game *game);
void	calc_ray_step_and_side_dist(t_game *game);

// DDA
void	perform_dda(t_game *game);

// Draw
void	draw_wall_and_background(t_game *game, int x);
int		**build_buffer(t_game *game);
void	draw_buffer(t_game *game);

#endif