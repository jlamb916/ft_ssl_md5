/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jo_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:14:27 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:19:18 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	if (!fmt || !*fmt)
		return (0);
	va_start(ap, fmt);
	i = ft_readformat((char**)&fmt, ap);
	va_end(ap);
	return (i);
}

int		ft_readformat(char **fmt, va_list ap)
{
	t_flags		f;
	t_length	l;

	f.total_size = 0;
	while (**fmt)
	{
		initialize_flags(&f, &l);
		if (**fmt == '%')
		{
			if (!(print_fmt(fmt, ap, &f, &l)))
				return (f.total_size);
		}
		else
		{
			write(1, *fmt, 1);
			f.total_size++;
		}
		(*fmt)++;
	}
	return (f.total_size);
}

int		print_fmt(char **fmt, va_list ap, t_flags *f, t_length *l)
{
	char *s;

	if ((!(s = check_fmt(fmt, ap, f, l))) && (!*fmt))
		return (0);
	f->s_size += ft_strlen(s);
	write(1, s, f->s_size);
	if (s)
		free(s);
	f->total_size += f->s_size;
	return (1);
}

char	*check_fmt(char **fmt, va_list ap, t_flags *f, t_length *l)
{
	(*fmt)++;
	if (!*fmt)
		return (NULL);
	while (!check_spec_type(fmt, f))
	{
		ft_check_length(fmt, l);
		if (ft_check_flags(fmt, f))
			continue ;
		else if (ft_check_field_width(fmt, f))
			continue ;
		else if (ft_check_precision(fmt, f))
			continue ;
		else
			break ;
	}
	invalid_length_mods(fmt, l);
	if (!check_spec_type(fmt, f))
		return (ft_invalid_fmt(fmt, f));
	return (ft_build(ap, f, l));
}
