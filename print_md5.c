/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:06:30 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:30:11 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	print_msg(uint32_t digest)
{
	char *tmp;

	tmp = ft_uitoa32(reverse_uint32(digest), 16);
	append_zero(tmp);
	ft_printf("%s", tmp);
	free(tmp);
}

void		print_md5(t_ssl *s, char *msg)
{
	int len;

	init_md5(s);
	len = ft_strlen(msg);
	if (pad_md5(s, (uint8_t *)msg, len) == -1)
		return ;
	hash_md5(s);
	print_msg(s->a0);
	print_msg(s->b0);
	print_msg(s->c0);
	print_msg(s->d0);
}
