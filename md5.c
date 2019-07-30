/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:04:23 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:27:26 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const uint32_t	g_g[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	7, 12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5,
	9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11,
	16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static const uint32_t	g_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

int			pad_md5(t_ssl *s, unsigned char *msg, int len)
{
	s->len = len + 1;
	while (s->len % 64 != 56)
		s->len++;
	if (!(s->bitchunk_128 = malloc(s->len + 64)))
		return (-1);
	s->bitchunk_128 = ft_bzero(s->bitchunk_128, s->len + 64);
	ft_strcpy((char *)s->bitchunk_128, (const char *)msg);
	*(uint32_t*)(s->bitchunk_128 + len) = 0x80;
	*(uint32_t*)(s->bitchunk_128 + s->len) = (uint32_t)(len * 8);
	return (0);
}

static void	run_hash(t_ssl *s, int i)
{
	if (i >= 0 && i <= 15)
	{
		s->f = F(s->b, s->c, s->d);
		s->g = i;
	}
	else if (i >= 16 && i <= 31)
	{
		s->f = G(s->b, s->c, s->d);
		s->g = (5 * i + 1) % 16;
	}
	else if (i >= 32 && i <= 47)
	{
		s->f = H(s->b, s->c, s->d);
		s->g = (3 * i + 5) % 16;
	}
	else
	{
		s->f = I(s->b, s->c, s->d);
		s->g = (7 * i) % 16;
	}
	s->tmp = s->d;
	s->d = s->c;
	s->c = s->b;
	s->b = s->b + LROT((s->a + s->f + g_k[i] + s->msg[s->g]), g_g[i]);
	s->a = s->tmp;
}

int			hash_md5(t_ssl *s)
{
	int i;

	while (s->i_bit < s->len)
	{
		i = -1;
		s->msg = (uint32_t *)(s->bitchunk_128 + s->i_bit);
		s->a = s->a0;
		s->b = s->b0;
		s->c = s->c0;
		s->d = s->d0;
		while (++i < 64)
			run_hash(s, i);
		s->a0 += s->a;
		s->b0 += s->b;
		s->c0 += s->c;
		s->d0 += s->d;
		s->i_bit += 64;
	}
	free(s->bitchunk_128);
	return (0);
}
