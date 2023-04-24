/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:32:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

// Error Messages
# define ERR_ARGS	(char *)"\aInvalid number of arguments!\n"
# define ERR_PRNT	(char *)"\aSomething went wrong while doing a print!\n"
# define ERR_MEM	(char *)"\aSomething went wrong while allocating memory!\n"
# define ERR_WIN	(char *)"\aSomething went wrong while opening a window!\n"

// Error Codes
# define SYS_ARGS	(int)1
# define SYS_PRNT	(int)2
# define SYS_MEM	(int)3
# define SYS_WIN	(int)4

int		print_error(char *str, int syserr);
void	terminate_error(char *str, int syserr);

#endif