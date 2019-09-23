/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/05 09:56:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/09/15 16:58:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Check what kind of argument we got and extract.
** @param *argv - the argument we are going to check.
** @param *data - struct were we save some data provided by the arg.
** @return void.
*/

static void			handle_arg_after_flag(char *argv, t_cw *data)
{
	if (data->nflag)
	{
		if (arg_is_a_nbr(argv))
		{
			data->custom_id = ft_atoi(argv);
			data->nflagcount++;
			data->nflag = 0;
			data->double_n = 1;
		}
		else
			error_message(2);
	}
	else
	{
		if (arg_is_a_nbr(argv))
		{
			data->dumpcycle = ft_atoi(argv);
			data->dumpflag = 0;
		}
		else
			error_message(7);
	}
}

static void			extract_data_helper(char *argv, t_cw *data)
{
	if (!ft_strncmp(argv, "-v", 2))
	{
		if (get_visual(JUST_RETURN))
			error_message(10);
		get_visual(1);
	}
	else if (!ft_strncmp(argv, "-n", 2))
		data->nflag++;
	else if (!ft_strncmp(argv, "-L", 2))
	{
		if (data->lflag == 1)
			error_message(10);
		data->lflag = 1;
		save_l_flag(data);
	}
	else if (!ft_strncmp(argv, "-dump", 5))
	{
		if (data->save_d)
			error_message(10);
		data->dumpflag++;
		data->save_d++;
	}
	else
		error_message(3);
}

/*
** @desc Check what kind of argument we got and extract.
** @param *argv - the argument we are going to check.
** @param *data - struct were we save some data provided by the arg.
** @param *arr - arr of players were we are going to save there data.
** @return void.
*/

static void			extract_data_from_args(char *argv,
											t_cw *data, t_players *arr)
{
	if (ft_strequ(argv, "-n") && data->double_n)
		error_message(8);
	data->double_n = 0;
	if (data->warrior_count >= 4 && !ft_strequ(argv, "-dump")
		&& !ft_strequ(argv, "-v") && !ft_strequ(argv, "-L"))
	{
		if (data->dumpflag && !arg_is_a_nbr(argv))
			error_message(7);
	}
	if (data->dumpflag || data->nflag)
		handle_arg_after_flag(argv, data);
	else if (!ft_strncmp(&argv[ft_strlen(argv) - 4], ".cor", 4))
	{
		if (data->warrior_count == 4)
			error_message(9);
		extract_warrior_data(argv, &arr[data->warrior_count], data);
		data->warrior_count++;
	}
	else
		extract_data_helper(argv, data);
}

/*
** @desc The arguments we give the exe we are sending them 1 by 1.
** @param **argv - the arguments we are going to loop through.
** @param *data - struct were we save some data provided by the arg.
** @param *arr - arr of players were we are going to save there data.
** @return void.
*/

static void			loop_through_args(char **argv, t_cw *data, t_players *arr)
{
	int i;

	i = 1;
	ft_bzero(data, sizeof(data));
	while (argv[i])
	{
		extract_data_from_args(argv[i], data, arr);
		i++;
	}
	if (data->dumpcycle == 0 && data->save_d != 0)
		error_message(7);
	if (data->nflag || data->nflagcount > data->warrior_count)
		error_message(8);
	if (data->warrior_count > 4 || data->warrior_count < 1)
		error_message(11);
}

int					main(int argc, char **argv)
{
	t_cw		data;
	t_players	arr[4];
	t_players	**players;
	int			i;

	if (argc < 2 || argc > 17)
		exit(ft_printf("usage: ./vm [-n number_modifier1 ... playerN.cor\n"));
	i = 0;
	ft_bzero(arr, sizeof(arr));
	loop_through_args(argv, &data, arr);
	check_and_prevent_duplicate_id(arr, data.warrior_count);
	players = (t_players**)ft_memalloc(sizeof(t_players*) * 4);
	while (i < 4 && arr[i].id != 0)
	{
		players[i] = arr + i;
		i++;
	}
	battle(players, &data);
}
