/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:39:27 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:54:33 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_conv_p(va_list ap, t_flags *f)
{
	uintmax_t	addr;
	char		*s;
	char		*tmp;

	addr = va_arg(ap, uintmax_t);
	if (f->precision == 0)
		return (ft_strdup("0x"));
	if (addr == 0)
	{
		tmp = ft_strnew(1);
		tmp[0] = '0';
	}
	else
		tmp = ft_itoa_unsigned(addr, 16);
	if (f->precision > ft_intstrlen(tmp))
		tmp = ft_precision(tmp, f);
	s = ft_strjoin("0x", tmp);
	free(tmp);
	return (s);
}

char	*ft_conv_percent(void)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '%';
	return (s);
}
