/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/06 18:04:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

// Error Messages
# define ERR_ARGS		(char *)"\aInvalid number of arguments!\n"
# define ERR_PRNT		(char *)"\aSomething went wrong while doing a print!\n"
# define ERR_MEM		(char *)"\aSomething went wrong while allocating memory!\
									\n"
# define ERR_WIN		(char *)"\aSomething went wrong while opening a window!\n"
# define ERR_OPEN_MAP	(char *)"\aMap could not be open!\n"
# define ERR_EXT_MAP	(char *)"\aMap extension is invalid!\n"

// Error Codes
# define SYS_ARGS		(int)1
# define SYS_PRNT		(int)2
# define SYS_MEM		(int)3
# define SYS_WIN		(int)4
# define SYS_OPEN_MAP	(int)5
# define SYS_EXT_MAP	(int)6

int		print_error(char *str, int syserr);
void	terminate_error(char *str, int syserr);

#endif