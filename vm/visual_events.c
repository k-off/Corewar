/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_events.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc	set or get visualizer status
** @param	int flag					- 1 to set status, 0 to get status
** @return	int status of visualizer	- 1 active, 0 inactive
*/

int				get_visual(int flag)
{
	static int		visualiser = 0;

	if (flag == 1)
		visualiser = 1;
	return (visualiser);
}

/*
** @desc	close visualiser and exit corewar
** @param	void *param					- void pointer
** @return	int 0
*/

static int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int				get_pause(int flag)
{
	static int	pause = 2;

	if (flag == 49)
		pause = (pause + 1) % 2;
	if (flag == 48)
		pause = 2;
	return (pause);
}

/*
** @desc	call functions according to the pressed key
** @param	void **players			- array of players for battle function
** @param	int key					- code of pressed key
** @return	int 0
*/

static int		keyboard(int key)
{
	int			flag;

	flag = 0;
	if (key == 49 || key == 48)
		get_pause(key);
	else if (key == 53)
		close_win(NULL);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		flag = 2;
		get_carriage_id(key);
	}
	else if (key == 43 || key == 47)
		flag = (key == 43) ? -1 : 1;
	manage_history(&flag);
	return (0);
}

/*
** @desc	handle visual events such as redraw window, mouse / keyboard input
** @param	void
** @return	void
*/

void			handle_events(void)
{
	t_win		*win;
	int			flag;

	flag = 0;
	win = get_win(SIZE_X, SIZE_Y, "COREWAR");
	mlx_hook(win->win_ptr, 17, 0, &close_win, (void*)NULL);
	mlx_loop_hook(win->mlx_ptr, &manage_history, (void*)&flag);
	mlx_hook(win->win_ptr, 2, 0, &keyboard, NULL);
	mlx_loop(win->mlx_ptr);
}
