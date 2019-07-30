/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:41:29 by jolam             #+#    #+#             */
/*   Updated: 2019/02/21 12:16:06 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ftoa(double n, int p)
{
	float	decimals;
	char	*s;
	char	*tmp;
	int		counter;

	counter = 0;
	s = ft_itoa((int)n);
	decimals = n - (int)n;
	if (p > 0)
	{
		while (p-- && counter++ < 7)
			decimals *= 10;
		tmp = s;
		s = ft_strjoin(tmp, ".");
		free(tmp);
		s = ft_join_float(s, (int)decimals);
	}
	if (p > 0)
		s = ft_add_precision_zeros(s, p);
	return (s);
}

char	*ft_join_float(char *s, int decimals)
{
	char	*tmp;
	char	*tmp1;

	tmp1 = ft_itoa((int)decimals);
	tmp = s;
	s = ft_strjoin(tmp, tmp1);
	free(tmp);
	free(tmp1);
	return (s);
}

char	*ft_add_precision_zeros(char *s, int p)
{
	char *tmp;

	while (p-- >= 0)
	{
		tmp = s;
		s = ft_strjoin(tmp, "0");
		free(tmp);
	}
	return (s);
}

char	*ft_zero_float(int p)
{
	char *s;
	char *tmp;

	s = ft_strnew(2);
	s[0] = '0';
	s[1] = '.';
	if (p > 0)
	{
		while (p-- > 0)
		{
			tmp = s;
			s = ft_strjoin(tmp, "0");
			free(tmp);
		}
	}
	return (s);
}
