/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:53:21 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 17:01:17 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_field_width(char *s, t_flags *f)
{
	int		s_len;
	int		pad;
	char	*tmp;

	s_len = ft_strlen(s);
	if ((f->conv == 'd' || f->conv == 'i' || f->conv == 'f')
			&& s[0] != '-' && f->plus == 1 && f->zero == 0)
	{
		tmp = s;
		s = ft_strjoin("+", tmp);
		f->field_width--;
		free(tmp);
	}
	pad = f->field_width - s_len;
	if (s_len < f->field_width)
		s = ft_pad_str(s, f, pad);
	if (f->conv == 'f' && (s_len < f->field_width))
		s = ft_f_width(s);
	return (s);
}

char	*ft_f_width(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			s[i] = '0';
		i++;
	}
	return (s);
}

char	*ft_pad_str(char *s, t_flags *f, int pad)
{
	char *tmp;

	if (f->minus == 1)
	{
		while (pad--)
		{
			tmp = s;
			s = ft_strjoin(tmp, " ");
			free(tmp);
		}
	}
	else
	{
		while (pad--)
		{
			tmp = s;
			s = ft_strjoin(" ", tmp);
			free(tmp);
		}
	}
	return (s);
}
