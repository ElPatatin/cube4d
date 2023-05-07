/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:55:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/07 17:03:24 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

t_bool	while_isspace(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (!ft_isspace(str[idx]))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	while_isdigit(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (!ft_isdigit(str[idx]))
			return (TRUE);
	}
	return (FALSE);
}
