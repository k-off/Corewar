/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_labels.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** @desc	check whether the received string refers to a label or not
** @param	char		*s		- string
** @return	int					- true or false
*/

int			is_label(char *s)
{
	int		i;
	int		len;

	len = (int)ft_strlen(s);
	if (len < 2 || s[len - 1] != LABEL_CHAR)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strchr(LABEL_CHARS, s[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

/*
** @desc	allocate a new label and assign it to the received pointer
** @param	t_label		**tmp	- address of the label pointer
** @param	char		*s		- name of the label
** @param	int			id		- unique id of the label
** @return						- void
*/

static void	set_new_label(t_label **tmp, char *s, int id)
{
	tmp[0] = (t_label*)ft_memalloc(sizeof(t_label));
	tmp[0]->name = ft_strdup(s);
	tmp[0]->unique_id = id;
	tmp[0]->position = -1;
}

/*
** @desc	find and return an existing label struct or allocate a new one
** @param	t_label		**label	- address of the labels linked list
** @param	char		*s		- name of the label
** @return	t_label		*tmp	- pointer to the label being set
*/

t_label		*set_label(t_label **label, char *s)
{
	t_label		*res;
	t_label		*tmp;
	int			id;

	id = 1;
	res = *label;
	if (ft_strlen(s) > 0)
		s[ft_strlen(s) - 1] = 0;
	while (res != NULL && res->next != NULL && ft_strcmp(res->name, s) != 0)
	{
		id++;
		res = res->next;
	}
	if (res != NULL && ft_strcmp(res->name, s) == 0)
		return (res);
	if (res != NULL)
		id++;
	set_new_label(&tmp, s, id);
	if (res == NULL)
		*label = tmp;
	else
		res->next = tmp;
	return (tmp);
}

/*
** @desc	convert label from the received array of strings
** @param	t_data		*data	- pointer to the data structure
** @param	char		**tmp	- array of strings, operation arguments
** @param	int			tmp_len	- amount of received strings
** @return	int					- offset of the operation pointed by the label
**								from the start of champions' executable code
*/

int			get_label(t_data *data, char **tmp, int tmp_len)
{
	t_label	*label;
	char	*s;

	label = set_label(&data->label, tmp[0]);
	if (tmp_len > 1 && is_label(tmp[1]))
		label->position = get_label(data, &tmp[1], tmp_len - 1);
	else if (tmp_len > 1 && is_instruction(tmp[1]))
		label->position = get_instruction(data, &tmp[1],
								is_instruction(tmp[1]), tmp_len - 1);
	else if (tmp_len > 1)
		exit(ft_printf("ERROR: %s at line %d\n", tmp[1], data->line_qty));
	else if (tmp_len < 2)
	{
		while (get_clean_string(data, &s) && ft_strlen(s) < 1)
		{
			data->line_qty++;
			free_str_arr(&s, NULL, 1);
		}
		data->line_qty++;
		label->position = get_labels_instructions(data, s);
		free_str_arr(&s, NULL, 1);
	}
	return (label->position);
}
