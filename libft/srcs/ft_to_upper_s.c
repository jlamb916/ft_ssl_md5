/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_upper_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:40:03 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:52:21 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_to_upper_s(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 32;
		s++;
	}
}
