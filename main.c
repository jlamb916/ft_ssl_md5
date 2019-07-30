/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:17:19 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:29:05 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	check_arg(t_ssl *s, char *av)
{
	s->md5 = 0;
	s->sha224 = 0;
	s->sha256 = 0;
	if (!(strcmp(av, "md5")))
		s->md5 = 1;
	else if (!(strcmp(av, "sha256")))
		s->sha256 = 1;
	else if (!(strcmp(av, "sha224")))
		s->sha224 = 1;
	else
		return (1);
	return (0);
}

char		*get_line(char *line, int fd)
{
	char	*s;
	char	*tmp;
	char	buff[2];
	int		ret;

	buff[1] = '\0';
	ret = 100;
	s = ft_strdup("");
	while ((ret = read(fd, buff, 1)) > 0)
	{
		if (ret == 0)
			break ;
		tmp = s;
		s = ft_strjoin(tmp, buff);
		free(tmp);
	}
	line = s;
	return (line);
}

int			main(int ac, char **av)
{
	t_ssl s;

	if (ac == 1)
		ft_error("usage: ft_ssl command [command opts] [command args]");
	if (ac > 1)
	{
		if (check_arg(&s, av[1]))
		{
			ft_printf("ft_ssl:Error : '%s' is an invalid command.\n", av[1]);
			ft_printf("\nStandard commands:\n\n");
			ft_printf("Message Digest commands:\n");
			ft_error("md5\nsha256\nsha224");
		}
		if (s.md5 == 1 || s.sha256 == 1 || s.sha224 == 1)
		{
			init_flags(&s);
			check_flags(&s, ac, av);
		}
	}
	return (0);
}
