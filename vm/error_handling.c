/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/05 14:43:27 by vmulder        #+#    #+#                */
/*   Updated: 2019/09/16 14:21:55 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_std_error(char *error)
{
	write(2, error, ft_strlen(error));
}

void	error_message(int errornr)
{
	if (errornr == 1)
		print_std_error("Error: Champion executable size too big\n");
	else if (errornr == 2)
		print_std_error("Error: Missing id number after calling -n flag.\n");
	else if (errornr == 3)
		print_std_error("Error: Argument is not recognized.\n");
	else if (errornr == 4)
		print_std_error("Error: Can't find warrior.\n");
	else if (errornr == 5)
		print_std_error("Error: Id number after -n flag needs to be unique.\n");
	else if (errornr == 6)
		print_std_error("Error: Warrior is too big, or there is no code\n");
	else if (errornr == 7)
		print_std_error("Error: The cycle to dump the memory is incorrect.\n");
	else if (errornr == 8)
		print_std_error("Error: Wrong usage of the -n flag.\n");
	else if (errornr == 9)
		print_std_error("Error: There is a maximum of 4 players.\n");
	else if (errornr == 10)
		print_std_error("Error: You are giving duplicate flags.\n");
	else if (errornr == 11)
		print_std_error("Error: There is a minimum of 1 player.\n");
	exit(1);
}
