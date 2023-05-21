/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:31:35 by ogonzale          #+#    #+#             */
/*   Updated: 2023/05/21 12:30:25 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_player.h"

# define MOVE_SPEED	1.0

void	move_forward(t_game *game)
{
	if (game->map.grid[(int)(game->player.x + game->player.dir_x * MOVE_SPEED)][(int)game->player.y] == '0')
		game->player.x += game->player.dir_x * MOVE_SPEED;
	if (game->map.grid[(int)game->player.x][(int)(game->player.y + game->player.dir_y * MOVE_SPEED)] == '0')
		game->player.y += game->player.dir_y * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	if (game->map.grid[(int)(game->player.x - game->player.dir_x * MOVE_SPEED)][(int)game->player.y] == '0')
		game->player.x -= game->player.dir_x * MOVE_SPEED;
	if (game->map.grid[(int)game->player.x][(int)(game->player.y - game->player.dir_y * MOVE_SPEED)] == '0')
		game->player.y -= game->player.dir_y * MOVE_SPEED;
}

void	move_left(t_game *game)
{
	if (game->map.grid[(int)(game->player.x - game->player.dir_y * MOVE_SPEED)][(int)game->player.y] == '0')
		game->player.x -= game->player.dir_y * MOVE_SPEED;
	if (game->map.grid[(int)game->player.x][(int)(game->player.y + game->player.dir_x * MOVE_SPEED)] == '0')
		game->player.y += game->player.dir_x * MOVE_SPEED;
}

void	move_right(t_game *game)
{
	if (game->map.grid[(int)(game->player.x + game->player.dir_y * MOVE_SPEED)][(int)game->player.y] == '0')
		game->player.x += game->player.dir_y * MOVE_SPEED;
	if (game->map.grid[(int)game->player.x][(int)(game->player.y - game->player.dir_x * MOVE_SPEED)] == '0')
		game->player.y -= game->player.dir_x * MOVE_SPEED;
}