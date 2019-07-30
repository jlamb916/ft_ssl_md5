/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:25:04 by jolam             #+#    #+#             */
/*   Updated: 2019/02/20 23:47:46 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_unsigned(uintmax_t n, int base)
{
	uintmax_t	nb;
	long		len;
	char		*s;

	len = 0;
	nb = n;
	while (nb)
	{
		len++;
		nb /= base;
	}
	s = ft_strnew(len);
	s[len] = '\0';
	while (n)
	{
		s[--len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	return (s);
}
