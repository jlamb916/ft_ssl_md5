/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:03:17 by jolam             #+#    #+#             */
/*   Updated: 2019/02/21 12:39:11 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_hash(char *s, t_flags *f)
{
	char	*tmp;
	int		s_len;

	s_len = ft_strlen(s);
	if (f->hash == 1 && s[0] != '0' && *s != '\0')
	{
		if (f->conv == 'o' && f->precision < 2)
		{
			tmp = s;
			s = ft_strjoin("0", tmp);
			free(tmp);
		}
		if (f->conv == 'x' || f->conv == 'X')
			s = ft_hash_x(s, f);
	}
	return (s);
}

char	*ft_hash_x(char *s, t_flags *f)
{
	char	*tmp;

	if (f->conv == 'x')
	{
		tmp = s;
		s = ft_strjoin("0x", tmp);
		free(tmp);
	}
	else if (f->conv == 'X')
	{
		tmp = s;
		s = ft_strjoin("0X", tmp);
		free(tmp);
	}
	return (s);
}

char	*ft_hash_zero(char *s, t_flags *f)
{
	int		i;

	i = 0;
	if (s[i] == '0')
	{
		while (s[i] == '0')
		{
			if (s[i] == 'x' || s[i] == 'X')
			{
				s[i] = '0';
				break ;
			}
			if (s[i] == '\0')
				return (s);
			i++;
		}
	}
	if (s[i] == '\0' || s[i] == 'x' || s[i] == 'X')
		s = ft_add_x(s, f, i);
	return (s);
}

char	*ft_add_x(char *s, t_flags *f, int i)
{
	if (f->conv == 'x')
	{
		s[i] = '0';
		s[1] = 'x';
	}
	else if (f->conv == 'X')
	{
		s[i] = '0';
		s[1] = 'X';
	}
	return (s);
}
