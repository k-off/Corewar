/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arguments.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** @desc	copy clean arguments from tmp array into the result array
** @param	char		**res	- array of clean arguments
** @param	char		***tmp	- 3d array of splitted arguments
** @param	int			argc	- amount of received strings
** @param	int			line_nr	- number of current line in the read file
** @return	char		**res	- array of clean arguments
*/

static void	split_args(char **res, char ***tmp, int argc, int line_nr)
{
	int			i[3];

	i[0] = 0;
	i[2] = 0;
	while (tmp[i[0]] != NULL && i[0] < argc)
	{
		i[1] = 0;
		while (tmp[i[0]][i[1]] && i[2] <= MAX_ARGS)
		{
			if (ft_strlen(tmp[i[0]][i[1]]) > 0)
			{
				res[i[2]] = ft_strdup(tmp[i[0]][i[1]]);
				i[2]++;
			}
			i[1]++;
		}
		free_str_arr(NULL, &tmp[i[0]], 0);
		i[0]++;
	}
	if (i[2] > MAX_ARGS)
		exit(ft_printf("ERROR: excess arguments (>MAX_ARGS) at line %d\n",
				line_nr));
	res[i[2]] = 0;
}

/*
** @desc	get clean arguments from the received array of strings
** @param	int			argc	- amount of received strings
** @param	char		**argv	- array of strings, operation arguments
** @param	int			line_nr	- number of current line in the read file
** @return	char		**res	- array of clean arguments
*/

static char	**get_clean(int argc, char **argv, int line_nr)
{
	char		**res;
	char		***tmp;
	int			i;

	if (MAX_ARGS < 1)
		exit(ft_printf("ERROR: MAX_ARGS value is not valid\n"));
	res = (char**)ft_memalloc(sizeof(char*) * (MAX_ARGS + 1));
	tmp = (char***)ft_memalloc(sizeof(char**) * (argc + 1));
	i = 0;
	while (i < argc)
	{
		tmp[i] = ft_strsplit(argv[i], ',');
		i++;
	}
	split_args(res, tmp, argc, line_nr);
	free(tmp);
	return (res);
}

/*
** @desc	convert arguments from the received array of strings
** @param	t_operation *op		- pointer to current operation structure
** @param	char		**argv	- array of strings, operation arguments
** @param	int			argc	- amount of received strings
** @param	t_data *data		- pointer to data structure
** @return	int 				- zero
*/

int			get_arguments(t_operation *op, char **argv, int argc, t_data *data)
{
	char	**clean_args;
	int	i;
	int	args_qty;
	int	allowed_types;

	clean_args = get_clean(argc, argv, data->line_qty);
	i = 0;
	while (clean_args[i] != NULL)
		i++;
	args_qty = ARGS_QTY[op->instruction_id];
	if (i != args_qty)
		exit(ft_printf("ERROR: wrong argument qty(line %d)\n", data->line_qty));
	allowed_types = ARGS_TYPES[op->instruction_id];
	int x;
	if ((x = set_arguments(op, clean_args, allowed_types, args_qty)) < 0)
		exit(ft_printf("ERROR: an argument is not valid(line %d)\n",
			data->line_qty));
	op->octet *= OCTAL[op->instruction_id];
	free_str_arr(NULL, &clean_args, 0);
	return (0);
}
