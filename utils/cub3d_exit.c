/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:41:27 by ogonzale          #+#    #+#             */
/*   Updated: 2023/05/21 10:58:23 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"

static void	free_map(t_map map);

void	exit_game(t_game *game)
{
	free_map(game->map);
}

static void	free_map(t_map map)
{
	int	i;

	i = -1;
	while (++i < map.height)
		free(map.grid[i]);
	free(map.grid);
}
