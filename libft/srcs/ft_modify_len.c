/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:17:07 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:48:22 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

intmax_t	ft_parse_len(va_list ap, t_length *l)
{
	if (l->none == 1)
		return (va_arg(ap, int));
	if (l->l == 1)
		return ((long)va_arg(ap, intmax_t));
	else if (l->ll == 1)
		return ((long long)va_arg(ap, intmax_t));
	else if (l->h == 1)
		return ((short)va_arg(ap, intmax_t));
	else if (l->hh == 1)
		return ((signed char)va_arg(ap, intmax_t));
	return (va_arg(ap, int));
}

uintmax_t	ft_parse_unsigned_len(va_list ap, t_length *l)
{
	if (l->none == 1)
		return (va_arg(ap, unsigned int));
	if (l->l == 1)
		return ((unsigned long)va_arg(ap, uintmax_t));
	else if (l->ll == 1)
		return ((unsigned long long)va_arg(ap, uintmax_t));
	else if (l->h == 1)
		return ((unsigned short)va_arg(ap, uintmax_t));
	else if (l->hh == 1)
		return ((unsigned char)va_arg(ap, uintmax_t));
	return (va_arg(ap, unsigned int));
}
