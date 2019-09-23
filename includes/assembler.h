/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assembler.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASSEMBLER_H
# define __ASSEMBLER_H

# include <unistd.h>
# include <fcntl.h>
# include "op.h"
# include "libft.h"

# define A 200
# define B 610
# define C 150
# define D 111
# define E 111
# define F 771
# define G 771
# define H 771
# define I 200
# define J 731
# define K 173
# define L 200
# define M 610
# define N 731
# define O 200
# define P 100
# define ALT_COMMENT_CHAR    ';'
# define T_DIR_SIZE	(int[]){0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}
# define OCTAL		(int[]){0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1}
# define ARGS_QTY	(int[]){0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1}
# define ARGS_TYPES	(int[]){0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P}
# define ALLOWED_ARG_CHARS	"abcdefghijklmnopqrstuvwxyz_0123456789-:%"
# define ALLOWED_DIR_CHARS	"0123456789-"
# define MAX_ARGS	3

typedef struct			s_operation
{
	int					unique_id;
	int					instruction_id;
	int					position;
	int					octet;
	int					argument[MAX_ARGS];
	int					argument_type[MAX_ARGS];
	int					arg_is_label[MAX_ARGS];
	int					argument_size[MAX_ARGS];
	int					size;
	struct s_operation	*next;
}						t_operation;

typedef struct			s_label
{
	int					unique_id;
	int					position;
	char				*name;
	struct s_label		*next;
}						t_label;

typedef struct			s_data
{
	int					fd_r;
	int					fd_w;
	int					total_size;
	char				*name;
	char				*comment;
	unsigned			line_qty;
	t_operation			*op;
	t_label				*label;
}						t_data;

char					*add_spaces(char **s);
void					check(t_data *data);
void					free_str_arr(char **s, char ***arr, int flag);
int						get_arguments(t_operation *op, char **argv,
							int argc, t_data *data);
int						get_clean_string(t_data *data, char **dst);
t_data					*get_data(t_data *data);
int						get_instruction(t_data *data, char **tmp,
							int inst_id, int tmp_len);
int						get_labels_instructions(t_data *data, char *s);
int						get_label(t_data *data, char **tmp, int tmp_len);
void					get_name_comment(t_data *data, char *s, int flag);
int						set_arguments(t_operation *op, char **clean_args,
							int allowed_types, int args_qty);
int						is_instruction(char *s);
int						is_label(char *s);
int						only_allowed_chars(char *allowed, char *arg);
t_label					*set_label(t_label **label, char *s);
void					write_data(t_data *data);

#endif
