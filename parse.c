/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:52 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:01:25 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	parse_file(char *av, t_ssl *s)
{
	if (check_file(s, av) == -1)
		return ;
	s->stdin = get_line(s->stdin, s->fd);
	if (!s->q && !s->r)
	{
		if (s->md5)
			ft_printf("MD5 (%s) = ", av);
		else if (s->sha256)
			ft_printf("SHA256 (%s) = ", av);
		else if (s->sha224)
			ft_printf("SHA224 (%s) = ", av);
	}
	if (s->md5 == 1)
		print_md5(s, s->stdin);
	else if (s->sha256 == 1 | s->sha224 == 1)
		print_sha(s, s->stdin);
	if (s->r && !s->q)
		ft_printf(" %s", av);
	ft_printf("\n");
	free(s->stdin);
	close(s->fd);
}

void	parse_stdin(t_ssl *s)
{
	char	*tmp;

	tmp = get_line(s->stdin, 0);
	if (s->p)
		ft_printf("%s", tmp);
	if (s->md5 == 1)
		print_md5(s, tmp);
	else if (s->sha256 == 1 || s->sha224 == 1)
		print_sha(s, tmp);
	ft_printf("\n");
}

void	parse_string(char *av, t_ssl *s)
{
	s->s_exists = 1;
	if (!av)
		ft_printf("ft_ssl: md5: option requires an argument -- s\n");
	if (!s->q && !s->r)
	{
		if (s->md5 == 1)
			ft_printf("MD5 (\"%s\") = ", av);
		else if (s->sha256 == 1)
			ft_printf("SHA256 (\"%s\") = ", av);
		else if (s->sha224 == 1)
			ft_printf("SHA224 (\"%s\") = ", av);
	}
	if (s->md5)
		print_md5(s, av);
	else if (s->sha224 || s->sha256)
		print_sha(s, av);
	if (s->r && !s->q)
		ft_printf(" \"%s\"", av);
	printf("\n");
}
