/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:33 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/11 20:23:20 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_p_with_min(t_format x, size_t ps_len)
{
	int	res;

	res = 0;
	if ((size_t)x.min > ps_len + 2)
	{
		if (!ft_strchr(x.format_num, '.') && x.zero_flag)
		{
			res += write(1, "0x", 2);
			res += write_zero(x.min - (ps_len + 2));
		}
		else
		{
			res += write_blank(x.min - (ps_len + 2));
			res += write(1, "0x", 2);
		}
	}
	else
		res += write(1, "0x", 2);
	return (res);
}

static int	write_p(char *p_s, t_format x, size_t ps_len)
{
	int res;

	res = 0;
	if ((size_t)x.ac > ps_len)
	{
		if (x.min > x.ac)
			res += write_blank(x.min - (x.ac + 2));
		res += write(1, "0x", 2);
		res += write_zero(x.ac - ps_len);
	}
	else
		res += write_p_with_min(x, ps_len);
	res += write(1, p_s, ps_len);
	return (res);
}

static int	write_p_with_mflag(char *p_s, t_format x, size_t ps_len)
{
	int res;

	res = 0;
	res += write(1, "0x", 2);
	if ((size_t)x.ac > ps_len)
		res += write_zero(x.ac - ps_len);
	res += write(1, p_s, ps_len);
	if (x.min > res)
		res += write_blank(x.min - res);
	return (res);
}

void		write_pointer(va_list ap, t_format *x)
{
	void	*p;
	char	*p_s;
	size_t	ps_len;

	x->word_count = 0;
	p = va_arg(ap, void*);
	if (ft_strchr(x->format_num, '.') && !p && !x->ac && !x->min)
	{
		x->word_count += write(1, "0x", 2);
		return ;
	}
	p_s = calc_pointer((unsigned long long)p, *x);
	if (!p_s)
	{
		x->word_count = -1;
		return ;
	}
	ps_len = ft_strlen(p_s);
	if (x->minus_flag)
		x->word_count += write_p_with_mflag(p_s, *x, ps_len);
	else
		x->word_count += write_p(p_s, *x, ps_len);
	safe_free(p_s);
}
