/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:42:11 by ogonzale          #+#    #+#             */
/*   Updated: 2023/06/18 13:49:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_ray.h"
#include "cub3d_images.h"

static void	do_dda_step(t_game *game);
static void	calc_perp_wall_distance(t_game *game);
static void	calc_wall_draw_parameters(t_game *game);

void	perform_dda(t_game *game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
		do_dda_step(game);
	calc_perp_wall_distance(game);
	calc_wall_draw_parameters(game);
}

static void	do_dda_step(t_game *game)
{
	if (game->ray.side_dist_x < game->ray.side_dist_y)
	{
		game->ray.side_dist_x += game->ray.delta_dist_x;
		game->ray.map_x += game->ray.step_x;
		game->ray.side = 0;
	}
	else
	{
		game->ray.side_dist_y += game->ray.delta_dist_y;
		game->ray.map_y += game->ray.step_y;
		game->ray.side = 1;
	}
	if (game->map.grid[game->ray.map_x][game->ray.map_y] == '1')
		game->ray.hit = 1;
}

static void	calc_perp_wall_distance(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.distance = game->ray.side_dist_x - game->ray.delta_dist_x;
	else
		game->ray.distance = game->ray.side_dist_y - game->ray.delta_dist_y;
}

static void	calc_wall_draw_parameters(t_game *game)
{
	if (game->ray.side == 0)
		game->wall.wall_x = game->player.y + \
		game->ray.distance * game->ray.dir_y;
	else
		game->wall.wall_x = game->player.x + \
		game->ray.distance * game->ray.dir_x;
	game->wall.line_height = (int)(WINHEIGHT / game->ray.distance);
	game->wall.draw_start = -game->wall.line_height / 2 + WINHEIGHT / 2;
	if (game->wall.draw_start < 0)
		game->wall.draw_start = 0;
	game->wall.draw_end = game->wall.line_height / 2 + WINHEIGHT / 2;
	if (game->wall.draw_end >= WINHEIGHT)
		game->wall.draw_end = WINHEIGHT - 1;
	game->wall.tex_step = 1.0 * TEXHEIGHT / game->wall.line_height;
	game->wall.tex_pos = (game->wall.draw_start - WINHEIGHT / 2 + \
		game->wall.line_height / 2) * game->wall.tex_step;
}
