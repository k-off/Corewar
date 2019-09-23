/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VM_H
# define __VM_H

# include "op.h"
# include "libft.h"
# include "mlx.h"

# define A 2
# define B 61
# define C 15
# define D 111
# define E 111
# define F 771
# define G 771
# define H 771
# define I 2
# define J 731
# define K 173
# define L 2
# define M 61
# define N 731
# define O 2
# define P 1
# define Q 10
# define R 20
# define S 25
# define T 800
# define U 50
# define V 1000
# define T_DIR_SIZE	(int[]){0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}
# define OCTAL		(int[]){0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1}
# define ARGS_QTY	(int[]){0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1}
# define ARGS_TYPE	(int[]){0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P}
# define WAIT_TIME	(int[]){0, Q, 5, 5, Q, Q, 6, 6, 6, R, S, S, T, Q, U, V, 2}
# define MAX_ARGS	3
# define SIZE_X		2006
# define SIZE_Y		1286
# define PLAYER_CLR (int[]){0x888888, 0xff0000, 0x00ff00, 0x0000ff, 0xffff00}
# define CURSOR_CLR	(int[]){0xffffff, 0x880000, 0x008800, 0x000088, 0x888800}
# define HEX		"0123456789ABCDEF"

typedef struct		s_player
{
	int				id_p;
	int				id_custom;
	int				pos;
	char			*name;
	char			*comment;
	unsigned char	*exe;
	int				size;
	struct s_player	*next;
}					t_player;

typedef struct		s_operation
{
	int				opcode;
	int				octet;
	int				is_valid;
	int				argument[MAX_ARGS];
	int				argument_type[MAX_ARGS];
	int				argument_size[MAX_ARGS];
	int				op_size;
}					t_operation;

typedef struct		s_cursor
{
	int				id_c;
	int				carry;
	int				pos;
	t_operation		op;
	int				last_alive;
	int				wait;
	int				reg[REG_NUMBER + 2];
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_check
{
	int				cycles_to_die;
	int				next_check;
	int				cur_cycle;
	int				lives_performed;
	int				checks_performed;
}					t_check;

typedef struct		s_hist
{
	int				frame_nr;
	unsigned char	mem[MEM_SIZE];
	int				color_map[MEM_SIZE];
	t_cursor		*cursors;
	struct s_hist	*prev;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_hist			*history;
}					t_win;

typedef struct		s_game
{
	unsigned char	mem[MEM_SIZE];
	t_player		*players;
	int				plr_qty;
	t_cursor		*cursors;
	int				cursors_qty;
	t_check			*check;
	t_win			*win;
	int				dump;
	int				dump_cycle;
	int				game_over;
	t_player		*last_alive;
}					t_game;

/*
** visual_functions.c
*/

t_win				*get_win(int size_x, int size_y, char *win_name);
void				set_colormap(int *color_map, int color_code,
							unsigned char *src, int position);

/*
** visual_events.c
*/

void				handle_events(t_game *game);

/*
** utils.c
*/

void				free_str_arr(char **s, char ***arr, int flag);
t_game				*get_game(t_game *game);
int					get_number(unsigned char *s, int size);
int					read_memory(unsigned char *s, int start_pos, int size);
void				write_memory(unsigned char *dst, unsigned char *src,
						int position,  unsigned total_length);

/*
** play_game.c
*/

int					play(t_game *game);

/*
** operations_4.c
*/

int					operation_lld(t_cursor *cursor, t_game *game);
int					operation_lldi(t_cursor *cursor, t_game *game);
int					operation_lfork(t_cursor *cursor, t_game *game);
int					operation_aff(t_cursor *cursor, t_game *game);

/*
** operations_3.c
*/

int					operation_zjmp(t_cursor *cursor, t_game *game);
int					operation_ldi(t_cursor *cursor, t_game *game);
int					operation_sti(t_cursor *cursor, t_game *game);
int					operation_fork(t_cursor *cursor, t_game *game);

/*
** operations_2.c
*/

int					operation_sub(t_cursor *cursor, t_game *game);
int					operation_and(t_cursor *cursor, t_game *game);
int					operation_or(t_cursor *cursor, t_game *game);
int					operation_xor(t_cursor *cursor, t_game *game);

/*
** operations_1.c
*/

int					operation_live(t_cursor *cursor, t_game *game);
int					operation_ld(t_cursor *cursor, t_game *game);
int					operation_st(t_cursor *cursor, t_game *game);
int					operation_add(t_cursor *cursor, t_game *game);

/*
** output.c
*/

void				final_output(t_player *pl, unsigned char *mem, int wide);
void				introduce_players(t_player *players);
int					print_usage(void);

/*
** get_operation.c
*/

int					get_operation(t_cursor *cursor, t_game *game, int flag);

/*
** game_setup.c
*/

void				game_setup(t_game *game, int ac, char **av);
void				board_setup(t_game *game);

/*
** check_players.c
*/

void				check_players(t_player **players, t_cursor **cursors,
							int plr_qty);

#endif
