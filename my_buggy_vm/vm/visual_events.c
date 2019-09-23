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

#include "vm.h"

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

int		get_pause(int flag)
{
	static int	pause = 1;

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

static int		keyboard(int key, t_game *game)
{
	int				res;
	unsigned char	*ptr;

	res = 0;
	if (key == 49)
		get_pause(key);
	else if (get_pause(key) == 1 && key == 48)
		res = play(game);
	else if (key == 53)
		close_win(NULL);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		ptr = 0;
//		get_carriage_id(key);
//		redraw_window(ptr);
	}
	if (res == 0)
		close_win(NULL);
	return (0);
}

/*
 ** @desc	handle visual events such as redraw window, mouse / keyboard input
 ** @param	void **players			- array of players for battle function
 ** @return	void
 */

void			handle_events(t_game *game)
{
	t_win			*win;

	win = get_win(SIZE_X, SIZE_Y, "COREWAR");
	mlx_hook(win->win_ptr, 17, 0, &close_win, (void*)NULL);
	mlx_loop_hook(win->mlx_ptr, &play, (void*)game);
	mlx_hook(win->win_ptr, 2, 0, &keyboard, (void*)game);
	mlx_loop(win->mlx_ptr);
}
