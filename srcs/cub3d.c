/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:16:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/21 12:43:57 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"
#include "cub3d_ray.h"

static void	render_game(t_game *game);

char	simple_map[MAPHEIGHT][MAPWIDTH] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '0', 'E', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error(ERR_ARGS, SYS_ARGS));
	// open_map(av[1]);
	init_map(&game, simple_map);
	init_player(&game);
	graphics(&game);
	exit_game(&game);
	(void)av;
	return (EXIT_SUCCESS);
}

void	graphics(t_game *game)
{
	t_data	data;

	init_vals(&game->mlx, &data);
	new_window(&game->mlx, &data);
	hooks(game);
	game_loop(game);
	mlx_loop((&game->mlx)->ptr);
}

int	game_loop(t_game *game)
{
	game->mlx.data->img = mlx_new_image((&game->mlx)->ptr, WINWIDTH, WINHEIGHT);
	game->mlx.data->addr = mlx_get_data_addr(game->mlx.data->img, &game->mlx.data->bpp,
			&game->mlx.data->line_len, &game->mlx.data->endian); 
	render_game(game);
	mlx_put_image_to_window((&game->mlx)->ptr, (&game->mlx)->win, (&game->mlx)->data->img, 0, 0);
	mlx_destroy_image((&game->mlx)->ptr, (&game->mlx)->data->img);
	return (0);
}

static void	render_game(t_game *game)
{
	int		x;

	x = -1;
	while (++x < WINWIDTH)
	{
		calc_ray_pos_dir(game, x);
		calc_ray_delta_dist(game);
		calc_ray_step_and_side_dist(game);
		perform_dda(game, &game->mlx, x);
	}
}

void	hooks(t_game *game)
{
	mlx_loop_hook((&game->mlx)->ptr, game_loop, game);
	mlx_key_hook((&game->mlx)->win, handle_keys, game);
	mlx_hook((&game->mlx)->win, 2, 0, key_print_hook, &game->mlx);
	mlx_hook((&game->mlx)->win, 17, 0, mouse_close_onclick, &game->mlx);
}
