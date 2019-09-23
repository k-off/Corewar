/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
 ** @desc	save address of color-map
 ** @param	int *colormap	- address of color-map or null pointer
 ** @return	int *colormap	- address of color-map
 */
/*
int				*save_colormap(void)
{
	static int		*saved_colormap;
	static int		player_colors[] = PLAYER_CLR;
	int			i;

	if (saved_colormap == NULL)
	{
		saved_colormap = (int*)ft_memalloc(sizeof(int) * MEM_SIZE + 1);
		i = 0;
		while (i < MEM_SIZE)
		{
			saved_colormap[i] = player_colors[0];
			i++;
		}
	}
	return (saved_colormap);
}
*/
/*
** @desc	set color-map values depending on player id and source_value
** @param	int *start_position	- address on color-map
** @param	int *id				- id of the cursor or of the player
** @param	char *source_value	- value, written to the arena
** @param	int *amount			- bytes to be written
** @return	void
*/
/*
void			set_colormap(int start_position, int id,
						unsigned char *source_value, int amount)
{
	int				*colormap;
	int				*player_colors;

	player_colors = PLAYER_CLR;
	start_position %= MEM_SIZE;
	colormap = save_colormap();
	if (id < 0)
		id = -id;
	if (amount != 4)
		while (amount > 0)
		{
			amount--;
			colormap[start_position + amount] =
			player_colors[id * (source_value[amount] != 0)];
		}
	else
		while (amount > 0)
		{
			amount--;
			colormap[start_position + 3 - amount] =
			player_colors[id * (source_value[amount] != 0)];
		}
}
*/
/*
** @desc	set window struct for visualizer
** @param	int size_x			- x window size
** @param	int size_y			- y window size
** @param	char *win_name		- window name
** @return	t_win *win			- pointer to window struct
*/

t_win			*get_win(int size_x, int size_y, char *win_name)
{
	static t_win	*win;

	if (!win)
	{
		win = (t_win*)ft_memalloc(sizeof(t_win));
		win->mlx_ptr = mlx_init();
		win->win_ptr = mlx_new_window(win->mlx_ptr, size_x, size_y, win_name);
		win->history = (t_hist*)ft_memalloc(sizeof(t_hist));
		ft_memset(win->history->color_map, PLAYER_CLR[0], MEM_SIZE);
	}
	return (win);
}

void			set_colormap(int *color_map, int color_code, unsigned char *src,
							 int position)
{
	int		cur_pos;
	int		total_length;

	total_length = REG_SIZE;
	while (total_length > 0)
	{
		total_length--;
		cur_pos = (position + total_length) % MEM_SIZE;
		color_map[cur_pos] = src[total_length];
	}
}

/*
** @desc	draw cursors in visualiser window
** @param	t_win *win			- pointer to window struct
** @param	int offsets[]		- offsets of left upper corner of cursor
** @param	int yx[]			- iterators (offsets) for cursor drawing
** @param	int i				- iterator for cursors
** @return	void
*/
/*
static int			draw_cursors(t_win *win, int offsets[], int yx[], int i)
{
	t_carriage		**carriages;
	int				color;
	int				*cursor_colors;

	cursor_colors = CURSOR_CLR;
	carriages = save_carriages(NULL);
	while (carriages[i] != NULL)
	{
		yx[0] = 0;
		offsets[0] = 5 + carriages[i]->current_position % 64 * 25;
		offsets[1] = 3 + carriages[i]->current_position / 64 * 20;
		color = cursor_colors[-(carriages[i]->r1)];
		while (yx[0] < 25)
		{
			yx[1] = 0;
			while (yx[1] < 20)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, offsets[0] + yx[1],
								offsets[1] + yx[0], color);
				yx[1]++;
			}
			yx[0]++;
		}
		draw_carriage_info(win, carriages[i], i + 1);
		i++;
	}
	return(i);
}
*/
/*
** @desc	draw visualiser window
** @param	unsigned char *arena	- pointer to memory of the vm
** @return	int						- 0
*/
/*
int				redraw_window(unsigned char *arena)
{
	t_win			*win;
	int				offsets[2];
	int				i;
	char			output[3];
	int				*colormap;

	win = get_win(SIZE_X, SIZE_Y, "COREWAR");
	colormap = save_colormap();
	arena = save_arena(NULL);
	i = 0;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	output[2] = 0;
	draw_debug(win, draw_cursors(win, (int[]){0, 0}, (int[]){0, 0}, 0));
	while (i < MEM_SIZE)
	{
		offsets[0] = 5 + i % 64 * 25;
		offsets[1] = 3 + i / 64 * 20;
		output[0] = HEX[arena[i] / 16];
		output[1] = HEX[arena[i] % 16];
		mlx_string_put(win->mlx_ptr, win->win_ptr, offsets[0],
			offsets[1], colormap[i], output);
		i++;
	}
	return (0);
}
*/
