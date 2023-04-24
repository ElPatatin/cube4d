/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:57:18 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:33:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HOOKS_H
# define CUB3D_HOOKS_H

# ifdef __APPLE__

#  define ESC_KEY		(int)53

#  define W_KEY			(int)13
#  define A_KEY			(int)0
#  define S_KEY			(int)1
#  define D_KEY			(int)2

#  define UP_KEY		(int)126
#  define DWN_KEY		(int)125
#  define RGT_KEY		(int)124
#  define LFT_KEY		(int)123

#  define ZOOM_IN_KEY	(int)4
#  define ZOOM_OUT_KEY	(int)5

#  define SPC_KEY		(int)49
#  define ENT_KEY		(int)36
#  define QUE_KEY		(int)12

# elif __linux__

#  define OS 					(char *)"Linux"
#  define LETTER_KEY_LEFT		97
#  define LETTER_KEY_RIGHT		100
#  define LETTER_KEY_UP       	119
#  define LETTER_KEY_DOWN		115
#  define LETTER_KEY_ACTION		101
#  define ARROW_KEY_LEFT	 	65361
#  define ARROW_KEY_RIGHT		65363
#  define ARROW_KEY_UP			65362
#  define ARROW_KEY_DOWN		65364
#  define SPACE_BAR				32
#  define KEY_ESC				65307

# endif

// Key Hooks
int	key_close_on_esc(int keycode, t_mlx *vals);
int	key_print_hook(int keycode, t_mlx *vals);

// Mouse Hooks
int	mouse_close_onclick(t_mlx *vals);

#endif