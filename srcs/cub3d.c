/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:16:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (print_error(ERR_ARGS, SYS_ARGS));
	open_map(av[1], &map);
	graphics();
	return (EXIT_SUCCESS);
}

void	graphics(void)
{
	t_mlx	vals;
	t_data	data;

	init_vals(&vals, &data);
	new_window(&vals, &data);
	hooks(&vals);
	mlx_loop(vals.ptr);
}

void	hooks(t_mlx *vals)
{
	mlx_key_hook(vals->win, key_close_on_esc, vals);
	mlx_hook(vals->win, 2, 0, key_print_hook, vals);
	mlx_hook(vals->win, 17, 0, mouse_close_onclick, vals);
}
