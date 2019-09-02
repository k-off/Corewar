/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldtoa.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LDTOA_H
# define __LDTOA_H

# include "libft.h"
# include <limits.h>
# include <float.h>

void		init(long double *n, int *isneg, int *exp, int *prec);
void		prepare_number(long double n, int exp, long double (*tmp)[]);
char		*ft_ldtoa(long double n, int precision);

#endif
