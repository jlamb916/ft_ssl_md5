/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:28:20 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:18:55 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_spec_type(char **fmt, t_flags *f)
{
	if (**fmt != 's' && **fmt != 'd' && **fmt != 'i' &&
		**fmt != 'o' && **fmt != 'p' && **fmt != 'u' &&
		**fmt != 'x' && **fmt != 'X' && **fmt != 'c' &&
		**fmt != 'f' && **fmt != '%')
		return (0);
	f->conv = **fmt;
	return (1);
}

char	*ft_build(va_list ap, t_flags *f, t_length *l)
{
	char *s;

	s = ft_convert(ap, f, l);
	s = ft_flags(s, f);
	return (s);
}

char	*ft_convert(va_list ap, t_flags *f, t_length *l)
{
	if (f->conv == 's')
		return (ft_conv_s(ap, f));
	else if (f->conv == 'i' || f->conv == 'd')
		return (ft_conv_d(ap, f, l));
	else if (f->conv == 'c')
		return (ft_conv_c(ap, f));
	else if (f->conv == 'u')
		return (ft_conv_u(ap, f, l));
	else if (f->conv == 'o')
		return (ft_conv_o(ap, f, l));
	else if (f->conv == 'x' || f->conv == 'X')
		return (ft_conv_x(ap, f, l));
	else if (f->conv == '%')
		return (ft_conv_percent());
	else if (f->conv == 'p')
		return (ft_conv_p(ap, f));
	else if (f->conv == 'f')
		return (ft_conv_f(ap, f, l));
	return (0);
}
