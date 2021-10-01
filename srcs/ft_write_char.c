/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:24:21 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/10 21:02:50 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_character(va_list ap, t_format *x)
{
	char	c;

	x->word_count = 0;
	c = '%';
	if (x->format_char != '%')
		c = va_arg(ap, int);
	if (x->minus_flag)
	{
		x->word_count += write(1, &c, 1);
		x->word_count += write_blank(x->min - 1);
		return ;
	}
	else if (x->zero_flag)
		x->word_count += write_zero(x->min - 1);
	else
		x->word_count += write_blank(x->min - 1);
	x->word_count += write(1, &c, 1);
}
