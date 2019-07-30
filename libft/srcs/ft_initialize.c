/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jo_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:56:45 by jolam             #+#    #+#             */
/*   Updated: 2019/02/18 21:17:21 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize_flags(t_flags *f, t_length *l)
{
	f->plus = 0;
	f->minus = 0;
	f->hash = 0;
	f->space = 0;
	f->zero = 0;
	f->s_size = 0;
	f->precision = -1;
	f->field_width = -1;
	f->conv = 0;
	l->none = 0;
	l->hh = 0;
	l->h = 0;
	l->l = 0;
	l->ll = 0;
	l->lll = 0;
}
