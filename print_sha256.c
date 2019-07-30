/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sha256.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:02:32 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:07:15 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print_hash_val(uint32_t digest)
{
	char *tmp;

	tmp = ft_uitoa32(digest, 16);
	append_zero(tmp);
	ft_printf("%s", tmp);
	free(tmp);
}

static void		print_sha_digests(t_ssl *s)
{
	print_hash_val(s->h0);
	print_hash_val(s->h1);
	print_hash_val(s->h2);
	print_hash_val(s->h3);
	print_hash_val(s->h4);
	print_hash_val(s->h5);
	print_hash_val(s->h6);
	if (s->sha256)
		print_hash_val(s->h7);
}

void			print_sha(t_ssl *s, char *msg)
{
	int len;

	if (s->sha256)
		init_sha256(s);
	else if (s->sha224)
		init_sha224(s);
	len = ft_strlen(msg);
	if (pad_sha(s, msg, len) == -1)
		return ;
	hash_sha(s);
	print_sha_digests(s);
}
