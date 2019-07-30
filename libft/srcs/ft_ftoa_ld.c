/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:51:04 by jolam             #+#    #+#             */
/*   Updated: 2019/02/28 23:21:51 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ftoa_ld(long double n, int p)
{
	float	decimals;
	char	*s;
	int		counter;
	char	*tmp;

	counter = 0;
	s = ft_itoa((int)n);
	decimals = n - (int)n;
	if (p > 0)
	{
		while (p-- && counter++ < 9)
			decimals = decimals * 10;
		tmp = s;
		s = ft_strjoin(tmp, ".");
		free(tmp);
		s = ft_join_float(s, (int)decimals);
	}
	if (p > 0)
		s = ft_lll_precision(s, p);
	return (s);
}

char	*ft_join_float_ld(char *s, int decimals)
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

char	*ft_lll_precision(char *s, int p)
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
