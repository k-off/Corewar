/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   provide_unique_id.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 19:27:06 by vmulder        #+#    #+#                */
/*   Updated: 2019/09/15 15:59:19 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Check if there are any duplicated within the n flag numbers.
** @param *tmp - a array with containing all -n flag numbers.
** @param size of the array.
** @return void.
*/

static void	non_auto_gen_id_duplicate_check(int *tmp, int arr_size)
{
	int i;
	int d;

	d = 0;
	i = 0;
	while (i < arr_size)
	{
		while (d < arr_size)
		{
			if (tmp[i] == tmp[d] && i != d)
				error_message(5);
			d++;
		}
		i++;
		d = 0;
	}
}

/*
** @desc Checks if we can assign this number to a player.
** @param *used - a array with containing all -n flag numbers.
** @param new_value - nbr we are trying to provide to the current player.
** @param size of the array.
** @return 1 or 0 - represents true or false.
*/

static int	check_value(int *used, int new_value, int tmp_arr_size)
{
	int i;

	i = 0;
	while (i < tmp_arr_size)
	{
		if (new_value == used[i])
			return (0);
		i++;
	}
	return (1);
}

/*
** @desc we going to give all the players there unique id.
** @param *arr - a array containing all the players.
** @param new_value - nbr we are trying to provide to the current player.
** @param tmp_arr_size of the array.
** @param warrior_count - nbr of warriors (players).
** @return void.
*/

static void	assign_unique_id(t_players *arr,
			int tmp_arr_size, int warrior_count, int *tmp)
{
	int i;
	int new_value;

	i = 0;
	new_value = 0;
	while (i < warrior_count)
	{
		if (arr[i].auto_gen_id == 1)
			new_value++;
		if (arr[i].auto_gen_id == 1 &&
			check_value(tmp, new_value, tmp_arr_size))
		{
			arr[i].id = new_value;
		}
		else if (arr[i].auto_gen_id == 1 &&
			!check_value(tmp, new_value, tmp_arr_size))
		{
			while (!check_value(tmp, new_value, tmp_arr_size))
				new_value++;
			arr[i].id = new_value;
		}
		i++;
	}
}

/*
** @desc create a int array with hold the non auto gen ids and check on dups.
** @param *arr - a array containing all the players.
** @param warrior_count - nbr of warriors (players).
** @return void.
*/

static void	check_and_create_unique_id_for_player(t_players *arr,
			int warrior_count)
{
	int i;
	int d;
	int tmp[8];

	d = 0;
	i = 0;
	while (i < warrior_count)
	{
		if (arr[i].auto_gen_id == 0)
		{
			tmp[d] = arr[i].id;
			d++;
		}
		i++;
	}
	non_auto_gen_id_duplicate_check(tmp, d);
	assign_unique_id(arr, d, warrior_count, tmp);
}

/*
** @desc check if there are any conflicting id's at all.
** @param *arr - a array containing all the players.
** @param warrior_count - nbr of warriors (players).
** @return void.
*/

void		check_and_prevent_duplicate_id(t_players *arr, int warrior_count)
{
	int i;
	int d;
	int stop;

	i = 0;
	d = 0;
	stop = 0;
	while (i < warrior_count)
	{
		while (d < warrior_count)
		{
			if (arr[i].id == arr[d].id && i != d)
			{
				check_and_create_unique_id_for_player(arr, warrior_count);
				stop = 1;
				break ;
			}
			d++;
		}
		if (stop)
			break ;
		d = 0;
		i++;
	}
}
