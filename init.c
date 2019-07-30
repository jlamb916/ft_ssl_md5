/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:59:13 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:09:16 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_flags(t_ssl *s)
{
	s->i = 1;
	s->p = 0;
	s->q = 0;
	s->r = 0;
	s->s = 0;
	s->file_exists = 0;
	s->s_exists = 0;
}

void	init_md5(t_ssl *s)
{
	s->a0 = 0x67452301;
	s->b0 = 0xefcdab89;
	s->c0 = 0x98badcfe;
	s->d0 = 0x10325476;
	s->i_bit = 0;
}

void	init_sha256(t_ssl *s)
{
	s->h0 = 0x6a09e667;
	s->h1 = 0xbb67ae85;
	s->h2 = 0x3c6ef372;
	s->h3 = 0xa54ff53a;
	s->h4 = 0x510e527f;
	s->h5 = 0x9b05688c;
	s->h6 = 0x1f83d9ab;
	s->h7 = 0x5be0cd19;
}

void	init_sha224(t_ssl *s)
{
	s->h0 = 0xc1059ed8;
	s->h1 = 0x367cd507;
	s->h2 = 0x3070dd17;
	s->h3 = 0xf70e5939;
	s->h4 = 0xffc00b31;
	s->h5 = 0x68581511;
	s->h6 = 0x64f98fa7;
	s->h7 = 0xbefa4fa4;
}
