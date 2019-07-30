/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 00:50:02 by jolam             #+#    #+#             */
/*   Updated: 2019/04/17 16:55:30 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			zero;
	int			precision;
	int			field_width;
	int			s_size;
	int			total_size;
	char		conv;
}				t_flags;

typedef struct	s_length
{
	int			none;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			lll;
}				t_length;

int				ft_printf(const char *fmt, ...);
int				ft_readformat(char **fmt, va_list ap);
int				print_fmt(char **fmt, va_list ap, t_flags *f, t_length *l);
char			*check_fmt(char **fmt, va_list ap, t_flags *f, t_length *l);
int				check_spec_type(char **fmt, t_flags *f);
char			*ft_build(va_list ap, t_flags *f, t_length *l);
char			*ft_convert(va_list ap, t_flags *f, t_length *l);
char			*ft_invalid_fmt(char **fmt, t_flags *f);

intmax_t		ft_parse_len(va_list ap, t_length *l);
uintmax_t		ft_parse_unsigned_len(va_list ap, t_length *l);

void			initialize_flags(t_flags *f, t_length *l);
int				ft_check_flags(char **fmt, t_flags *f);
void			ft_check_length(char **fmt, t_length *l);
void			ft_check_length_2(char **fmt, t_length *l);
int				ft_check_field_width(char **fmt, t_flags *f);
int				ft_check_precision(char **fmt, t_flags *f);
void			invalid_length_mods(char **fmt, t_length *l);

int				ft_count_flags(char *s);
int				ft_count_digits(char *s);
void			ft_to_upper_s(char *s);
char			*ft_modify_neg(char *s);

char			*ft_field_width(char *s, t_flags *f);
char			*ft_flags(char *s, t_flags *f);
char			*ft_space(char *s, t_flags *f);
char			*ft_hash(char *s, t_flags *f);
char			*ft_hash_zero(char *s, t_flags *f);
char			*ft_zero(char *s, t_flags *f);
void			add_zero(char *s, t_flags *f);
char			*ft_precision(char *s, t_flags *f);
char			*ft_ftoa(double n, int p);
char			*ft_ftoa_ld(long double n, int p);
char			*ft_zero_float(int p);
char			*ft_zero_plus(char *s, t_flags *f, int s_len);
char			*ft_pad_str(char *s, t_flags *f, int pad);
char			*ft_add_precision_zeros(char *s, int p);
char			*ft_lll_precision(char *s, int p);
char			*ft_hash_x(char *s, t_flags *f);
char			*ft_replace_zeros(char *s, t_flags *f);
char			*ft_return_null(t_flags *f);
char			*ft_precision_s(char *tmp, t_flags *f);
char			*ft_neg_prec(char *s);
char			*ft_join_float(char *s, int decimals);
char			*ft_join_float_ld(char *s, int decimals);
char			*ft_add_x(char *s, t_flags *f, int i);
char			*ft_f_width(char *s);

char			*ft_conv_s(va_list ap, t_flags *f);
char			*ft_conv_d(va_list ap, t_flags *f, t_length *l);
char			*ft_conv_c(va_list ap, t_flags *f);
char			*ft_conv_u(va_list ap, t_flags *f, t_length *l);
char			*ft_conv_o(va_list ap, t_flags *f, t_length *l);
char			*ft_conv_x(va_list ap, t_flags *f, t_length *l);
char			*ft_conv_percent(void);
char			*ft_conv_p(va_list ap, t_flags *f);
char			*ft_conv_f(va_list ap, t_flags *f, t_length *l);

#endif
