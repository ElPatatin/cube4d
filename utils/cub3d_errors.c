/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:12:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"

int	print_error(char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "Error: %s", str) == ERRNUM)
		terminate_error(ERR_PRNT, SYS_PRNT);
	return (syserr);
}

void	terminate_error(char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "Error: %s", str) == ERRNUM)
		exit(ERRNUM);
	exit(syserr);
}
