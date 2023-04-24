/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:02:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

int	key_close_on_esc(int keycode, t_mlx *vals)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vals->ptr, vals->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	key_print_hook(int keycode, t_mlx *vals)
{
	UNUSED(vals);
	if (keycode == ESC_KEY)
		return (1);
	printf("%d\n", keycode);
	return (0);
}
