/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:50:28 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:48:21 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include <strings.h>
# include <stdint.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include "libft/includes/libftprintf.h"

# define F(x, y, z) ((x & y) | (~x & z))
# define G(x, y, z) ((x & z) | (y & ~z))
# define H(x, y, z) (x ^ y ^ z)
# define I(x, y, z) (y ^ (x | ~z))
# define LROT(x, c) ((x << c) | (x >> (32 - c)))
# define RROT(x, c) ((x >> c) | (x << (32 - c)))

typedef struct	s_ssl
{
	int			len;
	int			p;
	int			q;
	int			r;
	int			s;
	int			fd;
	int			file_exists;
	uint32_t	*bitchunk_512;
	char		*bitchunk_128;
	char		*stdin;
	int			i;
	int			md5;
	int			sha256;
	int			sha224;
	int			i_bit;
	int			s_exists;
	int			bit_str;
	int			flags;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	a0;
	uint32_t	b0;
	uint32_t	c0;
	uint32_t	d0;
	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	h4;
	uint32_t	h5;
	uint32_t	h6;
	uint32_t	h7;
	uint32_t	ch;
	uint32_t	maj;
	uint32_t	tmp;
	uint32_t	tmp1;
	uint32_t	tmp2;
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	*w;
	uint32_t	*msg;
}				t_ssl;

int				main(int ac, char **av);
void			parse_file(char *av, t_ssl *s);
void			parse_stdin(t_ssl *s);
void			parse_string(char *av, t_ssl *s);
int				check_file(t_ssl *s, char *av);
int				check_param(t_ssl *s, char **av);
void			check_flags(t_ssl *s, int ac, char **av);
int				check_flags_loop(t_ssl *s, char **av);
void			append_zero(char *s);
char			*get_line(char *line, int fd);
void			print_md5(t_ssl *s, char *msg);
void			print_sha(t_ssl *s, char *msg);
int				pad_sha(t_ssl *s, char *msg, int len);
int				pad_md5(t_ssl *s, unsigned char *msg, int len);
int				hash_md5(t_ssl *s);
int				hash_sha(t_ssl *s);
void			init_flags(t_ssl *s);
void			init_md5(t_ssl *s);
void			init_sha256(t_ssl *s);
void			init_sha224(t_ssl *s);
uint32_t		reverse_uint32(uint32_t n);

#endif
