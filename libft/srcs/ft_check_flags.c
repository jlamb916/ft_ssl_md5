/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:15:34 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:12:52 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_length(char **fmt, t_length *l)
{
	if (**fmt == 'h')
	{
		(*fmt)++;
		if (**fmt == 'h')
		{
			l->hh = 1;
			(*fmt)++;
		}
		else
			l->h = 1;
	}
	else if (**fmt == 'l')
		ft_check_length_2(fmt, l);
	else if (**fmt == 'L')
	{
		l->lll = 1;
		(*fmt)++;
	}
}

void	ft_check_length_2(char **fmt, t_length *l)
{
	(*fmt)++;
	if (**fmt == 'l')
	{
		l->ll = 1;
		(*fmt)++;
	}
	else
		l->l = 1;
}

int		ft_check_flags(char **fmt, t_flags *f)
{
	int i;

	i = ft_count_flags(*fmt);
	if (i == 0)
		return (0);
	while (i-- > 0)
	{
		if (**fmt == '-')
			f->minus = 1;
		else if (**fmt == '+')
			f->plus = 1;
		else if (**fmt == ' ')
			f->space = 1;
		else if (**fmt == '#')
			f->hash = 1;
		else if (**fmt == '0')
			f->zero = 1;
		(*fmt)++;
	}
	return (1);
}

int		ft_check_field_width(char **fmt, t_flags *f)
{
	int i;

	i = ft_atoi(*fmt);
	*fmt = *fmt + ft_count_digits(*fmt);
	if (i > 0)
	{
		f->field_width = i;
		return (1);
	}
	return (0);
}

void	invalid_length_mods(char **fmt, t_length *l)
{
	while (**fmt == 'l' || **fmt == 'h' || **fmt == 'L')
	{
		(*fmt)++;
		l->none = 1;
	}
}
