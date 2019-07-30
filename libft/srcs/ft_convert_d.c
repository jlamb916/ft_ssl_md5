/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:11:11 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:14:14 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_conv_d(va_list ap, t_flags *f, t_length *l)
{
	intmax_t	i;
	char		*s;

	i = ft_parse_len(ap, l);
	if (f->precision == 0 && i == 0)
		return (ft_strnew(0));
	if (l->l == 1 || l->ll == 1)
		s = ft_ltoa(i);
	else
		s = ft_itoa(i);
	if (f->precision > -1)
		s = ft_precision(s, f);
	return (s);
}
