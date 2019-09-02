/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# define BUFF_SIZE 4096

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "ldtoa.h"

typedef struct			s_gnl_list
{
	ssize_t				fd;
	ssize_t				str_len;
	char				*str;
	struct s_gnl_list	*next;
}						t_gnl_list;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef	struct			s_line
{
	void				**content;
	size_t				content_size[100];
	int					fd[100];
	int					fin;
	struct s_line		*next;
}						t_line;

void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src, int c,
									size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memdup(const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memrchr(const void *s, int c, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_stracat(char *str1, char *str2);
char					*ft_strcapitalize(char *s);
int						ft_strcasecmp(const char *s1, const char *s2);
char					*ft_strcasestr(const char *big, const char *ltl);
char					*ft_strcat(char *dst, const char *src);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strcntc(char const *str, char c);
int						ft_strcntw(char const *str);
char					*ft_strcpy(char *dest, const char *src);
void					ft_strdel(char **ap);
char					*ft_strdup(const char *s);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strlowcase(char *s);
char					*ft_strmap(char const *src, char (*f)(char));
char					*ft_strmapi(char const *src, char (*f)(unsigned int,
															char));
int						ft_strncasecmp(const char *s1, const char *s2,
										size_t n);
char					*ft_strncat(char *dst, const char *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strndup(const char *s, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(unsigned long int size);
char					*ft_strnstr(const char *big, const char *ltl,
									size_t ln);
char					*ft_strrev(char *s);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					**ft_strsplit_whitespace(char const *s);
char					*ft_strstr(const char *big, const char *ltl);
char					*ft_strsub(char const *s, unsigned int start,
									size_t len);
char					*ft_strtrim(char const *s);
char					*ft_strupcase(char *s);
int						ft_tolower(int n);
int						ft_toupper(int n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isblanc(int c);
int						ft_iscntrl(int c);
int						ft_isdigit(int c);
int						ft_isgraph(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_isxdigit(int c);
int						ft_str_is_alpha(char *str);
int						ft_str_is_lowercase(char *str);
int						ft_str_is_numeric(char *str);
int						ft_str_is_printable(char *str);
int						ft_str_is_uppercase(char *str);
int						ft_atoi(const char *str);
char					*ft_itoa_base(long n, int base, int is_upper);
char					*ft_itoa(long int n);
char					*ft_utoa_base(unsigned long n, int base, int is_upper);
char					*ft_lltoa_base(long long n, int base, int is_upper);
char					*ft_ulltoa_base(unsigned long long n, int base,
										int is_upper);
char					*ft_ldtoa(long double num, int prec);
long double				ft_strtold10(const char *str, char **endnum);
long long int			ft_strtoll(const char *str, char **endptr, int base);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstappend(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
										void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
int						ft_printf(const char *s, ...);
int						ft_printf_fd(int fd, const char *s, ...);
int						ft_sprintf(char **dst, const char *s, ...);
void					ft_putchar_fd(int c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr(int n);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putnstr(char const *s, int n);
void					ft_putnstr_fd(char const *s, int n, int fd);
void					ft_putstr(char const *s);
char					*ft_readfile_fd(int fd);
char					*ft_readfile_name(char *name);
int						get_next_line(const int fd, char **line);

#endif
