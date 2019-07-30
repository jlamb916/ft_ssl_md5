/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:11:50 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:33:15 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_conv_o(va_list ap, t_flags *f, t_length *l)
{
	uintmax_t	u;
	char		*s;

	u = ft_parse_unsigned_len(ap, l);
	if (f->precision == 0 && u == 0 && f->hash == 0)
		return (ft_strnew(0));
	else if (f->precision == 0 && u == 0 && f->hash == 1)
	{
		s = ft_strnew(1);
		s[0] = '0';
		return (s);
	}
	if (l->l == 1 | l->ll == 1)
		s = ft_ultoa_base(u, 8);
	else
		s = ft_uitoa_base(u, 8);
	if (f->precision > -1)
		s = ft_precision(s, f);
	return (s);
}
