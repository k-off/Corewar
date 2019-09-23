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

#include "../includes/header.h"

/*
** @desc	save address of color-map
** @param	int *colormap	- address of color-map or null pointer
** @return	int *colormap	- address of color-map
*/

int				*get_colormap(void)
{
	static int		*saved_colormap;
	static int		player_colors[] = PLAYER_CLR;
	int				i;

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

/*
** @desc	set color-map values depending on player id and source_value
** @param	int *start_position	- address on color-map
** @param	int *id				- id of the cursor or of the player
** @param	char *source_value	- value, written to the arena
** @param	int *amount			- bytes to be written
** @return	void
*/

void			set_colormap(int start_position, int id,
						unsigned char *source_value, int amount)
{
	int				*colormap;
	int				*player_colors;

	player_colors = PLAYER_CLR;
	start_position %= MEM_SIZE;
	colormap = get_colormap();
	id = (id < 0) ? -id : id;
	id = (id > 4) ? 0 : id;
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
		win->img_ptr = mlx_new_image(win->mlx_ptr, size_x - 400, size_y);
		win->img_data = (int*)mlx_get_data_addr(win->img_ptr, &win->bpp,
									&win->line_size, &win->endian);
		win->data_size = win->line_size * size_y;
		win->line_size /= 4;
	}
	ft_memset(win->img_data, 0, win->data_size);
	return (win);
}

/*
** @desc	draw visualiser window
** @param	unsigned char *arena	- pointer to memory of the vm
** @return	int						- 0
*/

int				redraw_window(t_hist *display_frame)
{
	t_win			*win;
	int				offsets[2];
	int				i;
	char			output[3];

	win = get_win(SIZE_X, SIZE_Y, "COREWAR");
	i = 0;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	output[2] = 0;
	draw_debug(win);
	while (i < MEM_SIZE)
	{
		offsets[0] = 5 + i % 64 * 25;
		offsets[1] = 3 + i / 64 * 20;
		output[0] = HEX[display_frame->mem[i] / 16];
		output[1] = HEX[display_frame->mem[i] % 16];
		mlx_string_put(win->mlx_ptr, win->win_ptr, offsets[0],
			offsets[1], display_frame->color_map[i], output);
		i++;
	}
	return (0);
}
