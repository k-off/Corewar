/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disassembler.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISASSEMBLER_H
# define __DISASSEMBLER_H

# include <unistd.h>
# include <fcntl.h>
# include "op.h"
# include "libft.h"

# define T_DIR_SIZE	(int[]){0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}
# define OCTAL		(int[]){0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1}
# define ARGS_QTY	(int[]){0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1}
# define MAX_ARGS	3

typedef struct			s_operation
{
	char				*name;
	char				**args;
	struct s_operation	*next;
}						t_operation;

typedef struct			s_data
{
	int					fd_r;
	int					fd_w;
	int					total_size;
	char				*name;
	char				*comment;
	t_operation			*op;
}						t_data;

void					free_str_arr(char **s, char ***arr, int flag);
t_data					*get_data(t_data *data);
void					get_instruction(t_data *data, int c, int *data_size);
int						get_number(unsigned char *s, int size);

#endif
