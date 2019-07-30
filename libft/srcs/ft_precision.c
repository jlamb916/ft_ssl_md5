/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:53:25 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:11:53 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_precision(char **fmt, t_flags *f)
{
	int i;

	i = 0;
	if (**fmt == '.')
	{
		f->precision = 0;
		(*fmt)++;
	}
	i = ft_atoi(*fmt);
	*fmt = *fmt + ft_count_digits(*fmt);
	if (i > 0)
	{
		f->precision = i;
		return (1);
	}
	return (0);
}

char	*ft_precision(char *s, t_flags *f)
{
	char	*tmp;
	int		s_len;
	int		p;

	p = f->precision;
	s_len = ft_strlen(s);
	if (p == 0 && *s == '0')
		return (ft_strnew(0));
	while (p-- > s_len)
	{
		tmp = s;
		s = ft_strjoin("0", tmp);
		free(tmp);
	}
	if (f->precision > s_len)
		s = ft_neg_prec(s);
	return (s);
}

char	*ft_neg_prec(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
		{
			s[i] = '0';
			tmp = s;
			s = ft_strjoin("-", tmp);
			free(tmp);
			break ;
		}
		i++;
	}
	return (s);
}
