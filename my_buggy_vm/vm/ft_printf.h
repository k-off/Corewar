/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct			s_data
{
	char				*print;
	char				*s;
	char				ch;
	long long			lld;
	unsigned long long	uld;
	long double			llf;

	char				conversion;
	long long			width;
	long long			length;
	long long			precision;
	char				no_precision;
	char				pointer_precision;
	char				hh;
	char				h;
	char				l;
	char				ll;
	char				lll;
	char				hash;
	char				zero;
	char				plus;
	char				minus;
	char				space;
	char				dot;

	struct s_data		*next;
}						t_data;

void					check_pointer(char **s, char conv,
									unsigned long long val);
void					fill_str(char *s, char c, long long len);
void					flags_1(t_data *data, const char *s, int *i
								, va_list ap);
void					free_data(t_data **data);
int						get_string(t_data **data, const char *s, va_list ap);
void					handle_hash(t_data *data);
void					handle_modifiers(t_data *data, long long *n,
										unsigned long long *u);
void					handle_precision(t_data *data);
void					handle_space_plus(t_data *data);
void					handle_width(t_data *data);
void					hex_convert(t_data *data);
void					integer_convert(t_data *data);
void					oct_convert(t_data *data);
void					print_data(t_data *data, int *d);
void					print_data_fd(t_data *data, int *d, int fd);
void					string_convert(t_data *data);
void					set_output(char **dst, t_data *data, int *d);
void					unsigned_convert(t_data *data);
void					width_utils(t_data *data, char **t);

#endif
