/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VISUAL_H
# define __VISUAL_H

# include <math.h>
# include <sys/time.h>
# include <time.h>
# include "mlx.h"

# define SIZE_X		2006
# define SIZE_Y		1286
# define PLAYER_CLR (int[]){0x888888, 0x00cccc, 0xcc00cc, 0xcc0044, 0xcccc00}
# define CURSOR_CLR	(int[]){0xffffff, 0x008888, 0x880088, 0x880022, 0x888800}
# define HEX		"0123456789ABCDEF"
# define HIST_DEPTH	200

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				line_size;
	int				endian;
	int				data_size;
}					t_win;

t_win				*get_win(int size_x, int size_y, char *win_name);
void				set_colormap(int start_position, int id,
							unsigned char *source_value, int amount);
int					*get_colormap(void);
int					get_visual(int flag);
int					get_pause(int flag);
int					*get_carriage_id(int flag);
int					draw_cursors(t_win *win, int offsets[], int yx[], int i);
void				draw_debug(t_win *win);
long				get_current_cycle(int	flag);
int					manage_history(int *flag);

#endif
