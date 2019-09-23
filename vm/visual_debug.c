/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_debug.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc	choose a carriage to display it's parameters
** @param	int carriage_id				- carriage id
** @param	int player_id				- player id
** @return	int res[4]					- (int[]){player_id, carriage_id, 0, 0}
*/

int				*find_appropriate_2(int *carriage_id, int *player_id)
{
	static int	*res;
	t_carriage	**tmp;
	int			i;
	int			found;

	if (!res)
		res = ft_memalloc(sizeof(int) * 4);
	tmp = get_current_frame(NULL, 2)->cursors;
	found = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i]->r1 == *player_id && (tmp[i]->id >= *carriage_id || !found))
		{
			res[0] = tmp[i]->id;
			res[1] = tmp[i]->r1;
			found++;
		}
		i++;
	}
	res[0] = (found) ? res[0] : tmp[0]->id;
	*carriage_id = res[0];
	*player_id = res[1];
	return (res);
}

int				*find_appropriate_1(int *carriage_id, int *player_id)
{
	static int	*res;
	t_carriage	**tmp;
	int			i;
	int			found;

	if (!res)
		res = ft_memalloc(sizeof(int) * 4);
	tmp = get_current_frame(NULL, 2)->cursors;
	found = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i]->r1 == *player_id && (tmp[i]->id <= *carriage_id || !found))
		{
			res[0] = tmp[i]->id;
			res[1] = tmp[i]->r1;
			found++;
		}
		i++;
	}
	res[0] = (found) ? res[0] : tmp[0]->id;
	*carriage_id = res[0];
	*player_id = res[1];
	return (res);
}

/*
** @desc	select carriage and player depending on keyboard input
** @param	int flag					- code of pressed key
** @return	int res[4]					- (int[]){player_id, carriage_id, 0, 0}
*/

int				*get_carriage_id(int flag)
{
	static int	current_carriage_id = 1;
	static int	current_player_id = -1;

	if (flag == 124)
		current_carriage_id++;
	if (flag == 123 && current_carriage_id > 1)
	{
		current_carriage_id--;
		return (find_appropriate_1(&current_carriage_id, &current_player_id));
	}
	if (flag == 126 && current_player_id < -1)
		current_player_id++;
	if (flag == 125 && current_player_id > -4)
		current_player_id--;
	return (find_appropriate_2(&current_carriage_id, &current_player_id));
}

/*
** @desc	draw information of carriage
** @param	t_win *win				- pointer to window struct
** @param	t_carriage *carriage	- pointer to carriage
** @param	int crg_nr				- number of the drawn carriage
** @return							- void
*/

void			draw_carriage_info(t_win *win, t_carriage *carriage, int arr_id)
{
	char		*s;
	char		*text;
	int			color;

	text = "Cursor";
	s = ft_lltoa_base(carriage->id, 10, 0);
	color = (get_carriage_id(0)[1] < 0 && get_carriage_id(0)[1] > -5) ?
		PLAYER_CLR[-carriage->r1] : PLAYER_CLR[0];
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 60, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1780, 60, color, s);
	free(s);
	text = "Position in array ";
	s = ft_lltoa_base(arr_id, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 80, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1780, 80, color, s);
	free(s);
	text = "Current opcode ";
	s = ft_lltoa_base(carriage->current_opcode, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 100, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1780, 100, color, s);
	free(s);
	draw_carriage_info2(win, carriage, color);
}

/*
** @desc	draw information of carriage
** @param	t_win *win				- pointer to window struct
** @return							- void
*/

void			draw_debug(t_win *win)
{
	long		cycle;
	char		*s;
	char		*text;
	int			cursor_amount;

	cursor_amount = draw_cursors(win, (int[]){0, 0}, (int[]){0, 0}, 0);
	cycle = get_current_frame(NULL, 2)->frame_nr;
	s = ft_lltoa_base(cycle, 10, 0);
	text = "Current cycle: \0";
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 0, 0xFFFFFF, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1756, 0, 0xFFFFFF, s);
	free(s);
	s = ft_lltoa_base(cursor_amount, 10, 0);
	text = "Total cursors: \0";
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 25, 0xFFFFFF, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1756, 25, 0xFFFFFF, s);
	free(s);
}
