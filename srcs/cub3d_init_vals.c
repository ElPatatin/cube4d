/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:16:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:33:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"

void	init_vals(t_mlx *vals, t_data *data)
{
	vals->ptr = mlx_init();
	if (!vals->ptr)
		terminate_error(ERR_WIN, SYS_WIN);
	vals->win = mlx_new_window(vals->ptr,
			WINWIDTH, WINHEIGHT, TITLE);
	data->img = mlx_new_image(vals->ptr, WINWIDTH, WINHEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	vals->data = data;
}
