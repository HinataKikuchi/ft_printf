/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_large_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:24:57 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/11 17:21:25 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_lhex(char *h_s, t_format x, size_t hs_len)
{
	int		res;

	res = 0;
	if (x.ac > (int)hs_len)
	{
		if (x.min > x.ac)
			res += write_blank(x.min - x.ac);
		res += write_zero(x.ac - hs_len);
	}
	if ((!(x.ac > (int)hs_len)) && (x.min > (int)hs_len))
		res += (!ft_strchr(x.format_num, '.') && x.zero_flag) ?\
				write_zero(x.min - hs_len) : write_blank(x.min - hs_len);
	res += write(1, h_s, hs_len);
	return (res);
}

static int	write_lhex_with_mflag(char *h_s, t_format x, size_t hs_len)
{
	int res;

	res = 0;
	if ((size_t)x.ac > hs_len)
		res += write_zero(x.ac - hs_len);
	res += write(1, h_s, hs_len);
	if (x.min > res)
		res += write_blank(x.min - res);
	return (res);
}

void		write_large_hex(va_list ap, t_format *x)
{
	unsigned int	h;
	char			*h_s;
	size_t			hs_len;

	x->word_count = 0;
	h = va_arg(ap, unsigned int);
	if (ft_strchr(x->format_num, '.') && !h && !x->min && !x->ac)
		return ;
	h_s = (!x->ac && !h && ft_strchr(x->format_num, '.')) ?\
			ft_strdup("") : ft_large_hex(h);
	if (!h_s)
	{
		x->word_count = (-1);
		return ;
	}
	hs_len = ft_strlen(h_s);
	if (x->minus_flag)
		x->word_count += write_lhex_with_mflag(h_s, *x, hs_len);
	else
		x->word_count += write_lhex(h_s, *x, hs_len);
	free(h_s);
}
