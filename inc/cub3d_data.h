/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:54:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:30:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DATA_H
# define CUB3D_DATA_H

# include <stddef.h>

# define WINHEIGHT	(int)1080
# define WINWIDTH	(int)1920
# define TITLE		(char *)"cub3d gatito miau miau"

typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;

struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct s_mlx
{
	void	*ptr;
	void	*win;
	t_data	*data;
};

#endif