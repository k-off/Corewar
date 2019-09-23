/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_debug.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		draw_carriage_info6(t_win *win, t_carriage *carriage, int color)
{
	char		*s;
	char		*text;
	int			ctd;

	text = "R14: ";
	s = ft_lltoa_base(carriage->r14, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 260, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 260, color, s);
	free(s);
	text = "R15: ";
	s = ft_lltoa_base(carriage->r15, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 260, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 260, color, s);
	free(s);
	text = "R16: ";
	s = ft_lltoa_base(carriage->r16, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 280, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 280, color, s);
	free(s);
	ctd = (int)get_current_cycle(999);
	text = "Next check in: ";
	s = ft_lltoa_base(ctd, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1810, 0, 0xffff00, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1960, 0, 0xffff00, s);
	free(s);
}

static void		draw_carriage_info5(t_win *win, t_carriage *carriage, int color)
{
	char		*s;
	char		*text;

	text = "R10: ";
	s = ft_lltoa_base(carriage->r10, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 220, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 220, color, s);
	free(s);
	text = "R11: ";
	s = ft_lltoa_base(carriage->r11, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 220, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 220, color, s);
	free(s);
	text = "R12: ";
	s = ft_lltoa_base(carriage->r12, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 240, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 240, color, s);
	free(s);
	text = "R13: ";
	s = ft_lltoa_base(carriage->r13, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 240, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 240, color, s);
	free(s);
	draw_carriage_info6(win, carriage, color);
}

static void		draw_carriage_info4(t_win *win, t_carriage *carriage, int color)
{
	char		*s;
	char		*text;

	text = "R6: ";
	s = ft_lltoa_base(carriage->r6, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 180, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 180, color, s);
	free(s);
	text = "R7: ";
	s = ft_lltoa_base(carriage->r7, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 180, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 180, color, s);
	free(s);
	text = "R8: ";
	s = ft_lltoa_base(carriage->r8, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 200, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 200, color, s);
	free(s);
	text = "R9: ";
	s = ft_lltoa_base(carriage->r9, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 200, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 200, color, s);
	free(s);
	draw_carriage_info5(win, carriage, color);
}

static void		draw_carriage_info3(t_win *win, t_carriage *carriage, int color)
{
	char		*s;
	char		*text;

	text = "R2: ";
	s = ft_lltoa_base(carriage->r2, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 140, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 140, color, s);
	free(s);
	text = "R3: ";
	s = ft_lltoa_base(carriage->r3, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 140, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 140, color, s);
	free(s);
	text = "R4: ";
	s = ft_lltoa_base(carriage->r4, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 160, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1650, 160, color, s);
	free(s);
	text = "R5: ";
	s = ft_lltoa_base(carriage->r5, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 160, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1850, 160, color, s);
	free(s);
	draw_carriage_info4(win, carriage, color);
}

void			draw_carriage_info2(t_win *win, t_carriage *carriage, int color)
{
	char		*s;
	char		*text;

	text = "Wait cycles: ";
	s = ft_lltoa_base(carriage->cycles_before_execution, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1820, 80, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1940, 80, color, s);
	free(s);
	text = "Last alive: ";
	s = ft_lltoa_base(carriage->cycle_live_reported, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1820, 100, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1940, 100, color, s);
	free(s);
	text = "Jump: ";
	s = ft_lltoa_base(carriage->jump, 10, 0);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1606, 320, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1670, 320, color, s);
	free(s);
	s = (char[]){'0', '\0'};
	text = "Carry: ";
	s[0] += carriage->carry;
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1806, 320, color, text);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 1870, 320, color, s);
	draw_carriage_info3(win, carriage, color);
}
