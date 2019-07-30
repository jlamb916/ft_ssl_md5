/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:12:28 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:37:00 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_conv_x(va_list ap, t_flags *f, t_length *l)
{
	uintmax_t	u;
	char		*s;

	u = ft_parse_unsigned_len(ap, l);
	if (f->precision == 0 && u == 0)
		return (ft_strnew(0));
	if (l->l == 1 || l->ll == 1)
		s = ft_ultoa_base(u, 16);
	else
		s = ft_uitoa_base(u, 16);
	if (f->conv == 'X')
		ft_to_upper_s(s);
	if (f->precision > -1)
		s = ft_precision(s, f);
	return (s);
}
