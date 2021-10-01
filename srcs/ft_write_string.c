/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:24:24 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/11 20:13:14 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_with_mflag(char *s, t_format x, int s_len)
{
	int		res;

	res = 0;
	res += ((x.ac < s_len) && ft_strchr(x.format_num, '.')) ?\
			write(1, s, x.ac) : write(1, s, s_len);
	if (res < x.min)
		res += write_blank(x.min - res);
	return (res);
}

static int	s_without_mflag(char *s, t_format x, int s_len)
{
	int res;

	res = 0;
	if (x.ac < s_len && ft_strchr(x.format_num, '.'))
	{
		if (x.ac < x.min)
			res += (x.zero_flag) ? write_zero(x.min - x.ac) :\
			write_blank(x.min - x.ac);
		res += write(1, s, x.ac);
	}
	else
	{
		if (s_len < x.min)
			res += (x.zero_flag) ? write_zero(x.min - s_len) :\
			write_blank(x.min - s_len);
		res += write(1, s, s_len);
	}
	return (res);
}

void		write_string(va_list ap, t_format *x)
{
	char	*s;
	int		s_len;

	s = va_arg(ap, char*);
	x->word_count = 0;
	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (!x->ac && !x->min && ft_strchr(x->format_num, '.'))
	{
		x->word_count = 0;
		return ;
	}
	if (ft_strchr(x->format_num, '.') && !x->ac)
		s = "";
	if (x->minus_flag)
		x->word_count += s_with_mflag(s, *x, s_len);
	else
		x->word_count += s_without_mflag(s, *x, s_len);
}
