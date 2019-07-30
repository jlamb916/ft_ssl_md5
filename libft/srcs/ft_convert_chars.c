/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:07:13 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:16:00 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_conv_c(va_list ap, t_flags *f)
{
	char c;
	char *s;

	c = va_arg(ap, int);
	if (!c)
	{
		f->field_width--;
		f->s_size++;
		return (ft_strnew(1));
	}
	s = ft_strnew(1);
	s[0] = c;
	return (s);
}

char	*ft_conv_s(va_list ap, t_flags *f)
{
	char	*s;
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = va_arg(ap, char*)))
		s = ft_return_null(f);
	else if (f->precision > -1)
		s = ft_precision_s(tmp, f);
	else
		s = ft_strdup(tmp);
	return (s);
}

char	*ft_precision_s(char *tmp, t_flags *f)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(f->precision);
	while (f->precision-- && tmp[i])
	{
		s[i] = tmp[i];
		i++;
	}
	return (s);
}

char	*ft_return_null(t_flags *f)
{
	char	*null_s;
	int		i;
	char	*s;

	i = 0;
	null_s = "(null)";
	if (f->precision == 0)
		return (ft_strnew(0));
	if (f->precision > 0 && f->precision < 6)
	{
		s = ft_strnew(f->precision);
		while (f->precision--)
		{
			s[i] = null_s[i];
			i++;
		}
	}
	else
		s = ft_strdup("(null)");
	return (s);
}
