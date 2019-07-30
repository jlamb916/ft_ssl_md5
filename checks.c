/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:17:20 by jolam             #+#    #+#             */
/*   Updated: 2019/04/30 17:20:37 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			check_file(t_ssl *s, char *av)
{
	if (open(av, O_DIRECTORY) > 0)
	{
		ft_printf("%s no such file or directory\n", av);
	}
	if ((s->fd = open(av, O_RDWR)) < 0)
	{
		if (s->sha256 == 1)
			ft_printf("ft_ssl: sha256: ");
		else if (s->md5 == 1)
			ft_printf("ft_ssl: md5: ");
		else if (s->sha224 == 1)
			ft_printf("ft_ssl: sha224: ");
		ft_printf("%s: No such file or directory\n", av);
		return (-1);
	}
	return (0);
}

static void	print_error(t_ssl *s, char **av)
{
	if (s->md5)
		ft_printf("ft_ssl: md5: %s: No such file or directory\n", av[s->i]);
	else if (s->sha256)
		ft_printf("ft_ssl: sha256: %s: No such file or directory\n", av[s->i]);
	else if (s->sha224)
		ft_printf("ft_ssl: sha224: %s: No such file or directory\n", av[s->i]);
}

int			check_param(t_ssl *s, char **av)
{
	if (s->file_exists)
	{
		print_error(s, av);
		s->i++;
		if ((!(ft_strcmp(av[s->i - 1], "-s"))))
			print_error(s, av);
		return (1);
	}
	return (0);
}

int			check_flags_loop(t_ssl *s, char **av)
{
	if (av[s->i][0] == '-' && av[s->i][1] == 'p')
	{
		if (check_param(s, av))
			return (1);
		s->p = 1;
		parse_stdin(s);
	}
	else if (!(ft_strcmp(av[s->i], "-q")))
	{
		if (check_param(s, av))
			return (1);
		s->q = 1;
	}
	else if (!(ft_strcmp(av[s->i], "-r")))
	{
		if (check_param(s, av))
			return (1);
		s->r = 1;
	}
	return (0);
}

void		check_flags(t_ssl *s, int ac, char **av)
{
	while (++s->i < ac)
	{
		if (check_flags_loop(s, av))
			continue ;
		if ((!(ft_strcmp(av[s->i], "-q"))) || (!(ft_strcmp(av[s->i], "-p")))
				|| (!(ft_strcmp(av[s->i], "-r"))))
			s->flags = 1;
		else if (av[s->i][0] == '-' && av[s->i][1] == 's')
		{
			if (check_param(s, av))
				continue ;
			s->i++;
			parse_string(av[s->i], s);
		}
		else
		{
			s->file_exists = 1;
			parse_file(av[s->i], s);
		}
	}
	if (!s->p && s->file_exists == 0 && s->s_exists == 0)
		parse_stdin(s);
}
