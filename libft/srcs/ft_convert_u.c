/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:12:12 by jolam             #+#    #+#             */
/*   Updated: 2019/02/20 11:32:38 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_conv_u(va_list ap, t_flags *f, t_length *l)
{
	uintmax_t	u;
	char		*s;

	u = ft_parse_unsigned_len(ap, l);
	if (f->precision == 0 && u == 0)
		return (ft_strnew(0));
	if (l->l == 1 | l->ll == 1)
		s = ft_ultoa_base(u, 10);
	else
		s = ft_uitoa(u);
	if (f->precision > -1)
		s = ft_precision(s, f);
	return (s);
}
