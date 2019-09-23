/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_history.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc	set or get frame to display
** @param	t_hist	*frame		- pointer to displayed frame
** @param	int		flag		- 0: get frame, !0: set frame
** @return	t_hist	*frame		- frame to display
*/

t_hist	*get_current_frame(t_hist *frame, int flag)
{
	static t_hist	*current = 0;
	int				tmp;

	tmp = 0;
	if (flag == 0 && frame != NULL)
		current = frame;
	else if ((flag == 0 && current == NULL)
			|| (flag == 1 && current->next == NULL))
	{
		get_pause(48);
		manage_history(&tmp);
	}
	else if (flag == 1 && current && current->next)
		current = current->next;
	else if (flag == -1 && current && current->prev)
		current = current->prev;
	return (current);
}

/*
** @desc	delete frame and all it's contents
** @param	t_hist	**deleted	- pointer to deleted frame
** @return						- void
*/

void	delete_frame(t_hist **deleted)
{
	int			i;

	i = 0;
	while (deleted[0]->cursors[i])
		i++;
	while (i > 0)
	{
		i--;
		free(deleted[0]->cursors[i]);
	}
	free(deleted[0]->cursors);
	free(deleted[0]->mem);
	free(deleted[0]->color_map);
	deleted[0]->prev = 0;
	deleted[0]->next = 0;
	deleted[0]->frame_nr = 0;
	free(deleted[0]);
	deleted = 0;
}

/*
** @desc	check frames amount and delete excess if needed
** @param	t_hist	*hist		- pointer to history
** @return						- void
*/

void	check_frame_qty(t_hist *hist)
{
	int		i;
	t_hist	*tmp;

	i = 0;
	tmp = hist;
	while (tmp->prev)
	{
		i++;
		tmp = tmp->prev;
	}
	while (i >= HIST_DEPTH)
	{
		i--;
		tmp = tmp->next;
		delete_frame(&(tmp->prev));
		tmp->prev = 0;
	}
}

/*
** @desc	run next cycle of the game, save new frame and check frames amount
** @param	t_hist	*hist		- pointer to history
** @return	t_hist	*new		- new frame to display
*/

t_hist	*new_frame(void)
{
	t_hist		*new;
	int			i;
	t_carriage	**curs;

	new = (t_hist*)ft_memalloc(sizeof(t_hist));
	battle_execute(save_players(NULL));
	new->frame_nr = (int)get_current_cycle(0);
	new->mem = (unsigned char*)ft_memdup(save_arena(new->mem), MEM_SIZE);
	new->color_map = (int*)ft_memdup(get_colormap(), MEM_SIZE * 4);
	i = 0;
	curs = save_carriages(NULL);
	while (curs[i])
		i++;
	new->cursors = (t_carriage**)ft_memalloc(sizeof(t_carriage*) * (i + 1));
	while (i > 0)
	{
		i--;
		new->cursors[i] = (t_carriage*)ft_memdup(curs[i], sizeof(t_carriage));
	}
	return (new);
}

/*
** @desc	get a new frame, switch to previous or to the next one for visual.
** @param	int		flag		- 0: get new, 1: return next, -1: return prev.
** @return	t_hist	*curr		- frame to display
*/

int		manage_history(int *flag)
{
	static t_hist	*hist = 0;
	t_hist			*tmp1;
	t_hist			*tmp2;

	if (get_pause(0) == 1 && *flag == 0)
		return (0);
	if (!hist)
		hist = new_frame();
	if (*flag == 0)
	{
		tmp2 = hist;
		tmp1 = new_frame();
		tmp1->prev = tmp2;
		if (tmp2)
			tmp2->next = tmp1;
		hist = tmp1;
		check_frame_qty(hist);
		get_current_frame(hist, 0);
	}
	else
		get_current_frame(NULL, *flag);
	redraw_window(get_current_frame(NULL, 2));
	return (0);
}
