/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:31:03 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/07 19:27:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

t_bool	check_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		return (TRUE);
	return (FALSE);
}

void	check_valid_number(int *nbr, char *line)
{
	size_t	len;
	char	*val;

	len = 0;
	while (ft_isdigit(line[len]))
		len++;
	*nbr = ft_atoi(line);
	val = ft_itoa(*nbr);
	if (!val)
		terminate_error(ERR_MEM, SYS_MEM);
	if (ft_strncmp(val, line, len))
	{
		ft_delete(val);
		terminate_error(ERR_BAD_CLR, SYS_BAD_CLR);
	}
	ft_delete(val);
	if (*nbr > 255 || *nbr < 0)
		terminate_error(ERR_BAD_CLR, SYS_BAD_CLR);
}
