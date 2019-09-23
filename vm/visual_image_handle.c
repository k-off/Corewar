/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_image_handle.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc	set or get current cycle
** @param	int flag					- !0 to set cycle, 0 to get cycle
** @return	int curretn_cycle			- current cycle
*/

long			get_current_cycle(int flag)
{
	static long		current_cycle = 0;
	static long		total_cycles_to_die = 0;

	if (flag != 0 && flag != 999)
		current_cycle++;
	else
	{
		if (total_cycles_to_die - current_cycle <= 0)
			total_cycles_to_die += cycles_to_die(JUST_RETURN);
	}
	if (flag == 999)
		return (total_cycles_to_die - current_cycle);
	else
		return (current_cycle);
}

/*
** @desc	set colors in the image struct
** @param	t_win *win			- pointer to window struct
** @param	int offsets[]		- offsets of left upper corner of cursor
** @param	int yx[]			- iterators (offsets) for cursor drawing
** @param	int color			- color of carriage
** @return						- void
*/

static void		set_image(t_win *win, int offsets[], int yx[], int color)
{
	while (yx[0] < 25)
	{
		yx[1] = 0;
		while (yx[1] < 20)
		{
			win->img_data[offsets[1] + offsets[0] + yx[0]
				* win->line_size + yx[1]] = color;
			yx[1]++;
		}
		yx[0]++;
	}
}

/*
** @desc	draw cursors in visualiser window
** @param	t_win *win			- pointer to window struct
** @param	int offsets[]		- offsets of left upper corner of cursor
** @param	int yx[]			- iterators (offsets) for cursor drawing
** @param	int i				- iterator for cursors
** @return	int	i				- amount of carriages in current frame
*/

int				draw_cursors(t_win *win, int offsets[], int yx[], int i)
{
	t_carriage		**c;
	int				color;
	int				*cursor_colors;
	int				nr;

	cursor_colors = CURSOR_CLR;
	c = get_current_frame(NULL, 2)->cursors;
	while (c[i] != NULL)
	{
		yx[0] = 0;
		offsets[0] = 5 + c[i]->current_position % 64 * 25;
		offsets[1] = (3 + c[i]->current_position / 64 * 20)
						* win->line_size;
		nr = (c[i]->r1 > -5 && c[i]->r1 < 0) ? -c[i]->r1 : 0;
		color = cursor_colors[nr];
		if (win->img_data[offsets[1] + offsets[0]] == 0)
			set_image(win, offsets, yx, color);
		if (c[i]->id == get_carriage_id(0)[0]
			&& c[i]->r1 == get_carriage_id(0)[1])
			draw_carriage_info(win, c[i], i + 1);
		i++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	return (i);
}
