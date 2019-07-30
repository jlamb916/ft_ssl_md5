/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:43:52 by jolam             #+#    #+#             */
/*   Updated: 2019/02/15 17:56:37 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_dec(int n)
{
	long	nb;
	char	*s;
	int		len;

	len = 1;
	nb = n < 0 ? -(long)n : n;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	nb = n < 0 ? -(long)n : n;
	while (nb > 9)
	{
		s[--len] = nb % 10 + '0';
		nb /= 10;
	}
	s[--len] = nb % 10 + '0';
	return (s);
}
