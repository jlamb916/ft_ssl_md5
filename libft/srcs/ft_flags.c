/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:00:39 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:38:23 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

char	*ft_flags(char *s, t_flags *f)
{
	s = ft_hash(s, f);
	s = ft_field_width(s, f);
	if (f->zero == 1)
	{
		s = ft_zero(s, f);
		s = ft_modify_neg(s);
	}
	if (f->space == 1)
		s = ft_space(s, f);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_zero(char *s, t_flags *f)
{
	int i;
	int s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (f->minus == 0 && (f->precision == -1 || f->precision == 0 ||
				f->precision > f->field_width))
	{
		while (s[i])
		{
			if (s[i] == ' ')
				s[i] = '0';
			i++;
		}
	}
	if (f->hash == 1 && (f->conv == 'x' || f->conv == 'X'))
		return (ft_hash_zero(s, f));
	if (f->plus == 1 && (f->conv == 'd' || f->conv == 'i' ||
				f->conv == 'f'))
		s = ft_zero_plus(s, f, s_len);
	return (s);
}

char	*ft_zero_plus(char *s, t_flags *f, int s_len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			break ;
		i++;
	}
	if (s[i] == '\0')
	{
		if ((f->precision < f->field_width) && f->precision != -1)
			s[0] = '+';
		else if (f->field_width == s_len && s[0] == '0')
			s[0] = '+';
		else
		{
			tmp = s;
			s = ft_strjoin("+", tmp);
			free(tmp);
		}
	}
	return (s);
}

char	*ft_space(char *s, t_flags *f)
{
	char	*tmp;

	if (f->plus == 0 && s[0] != '-' && f->field_width == -1 &&
			(f->conv == 'd' || f->conv == 'i' || f->conv == 'f'))
	{
		tmp = s;
		s = ft_strjoin(" ", tmp);
		free(tmp);
	}
	if (f->zero == 1 && (f->conv == 'd' || f->conv == 'i' || f->conv == 'f') &&
			f->minus == 0 && s[0] != '-')
		s[0] = ' ';
	return (s);
}

char	*ft_modify_neg(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
		{
			s[i] = '0';
			s[0] = '-';
			break ;
		}
		i++;
	}
	return (s);
}
