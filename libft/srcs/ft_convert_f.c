/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:08:08 by jolam             #+#    #+#             */
/*   Updated: 2019/02/21 23:59:50 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_conv_f(va_list ap, t_flags *f, t_length *l)
{
	double		d;
	char		*s;
	int			p;
	long double	ld;

	p = f->precision == -1 ? 6 : f->precision;
	l->l == 1 ? l->l = 0 : 0;
	if (l->lll == 1)
	{
		ld = va_arg(ap, long double);
		if (ld == 0.0 && p > 0)
			return (ft_zero_float(p));
	}
	else
	{
		d = va_arg(ap, double);
		if (d == 0.0 && p > 0)
			return (ft_zero_float(p));
	}
	s = l->lll == 1 ? ft_ftoa_ld(ld, p) : ft_ftoa(d, p);
	return (s);
}
