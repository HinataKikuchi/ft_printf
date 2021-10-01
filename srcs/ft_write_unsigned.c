/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 00:02:48 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/11 17:28:08 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_ud(char *ud_s, t_format x, size_t uds_len)
{
	int		res;

	res = 0;
	if (x.ac > (int)uds_len)
	{
		if (x.min > x.ac)
			res += write_blank(x.min - x.ac);
		res += write_zero(x.ac - uds_len);
		res += write(1, ud_s, uds_len);
	}
	else
	{
		if (x.min > (int)uds_len)
			res += (!ft_strchr(x.format_num, '.') && x.zero_flag) ?\
					write_zero(x.min - uds_len) : write_blank(x.min - uds_len);
		res += write(1, ud_s, uds_len);
	}
	return (res);
}

static int	write_ud_with_mflag(char *ud_s, t_format x, size_t uds_len)
{
	int	res;

	res = 0;
	if (x.ac > (int)uds_len)
		res += write_zero(x.ac - uds_len);
	res += write(1, ud_s, uds_len);
	if (x.min > res)
		res += write_blank(x.min - res);
	return (res);
}

void		write_unsigned(va_list ap, t_format *x)
{
	unsigned int	ud;
	char			*ud_s;
	size_t			uds_len;

	ud = va_arg(ap, unsigned int);
	x->word_count = 0;
	if (!ud && !x->min && !x->ac && ft_strchr(x->format_num, '.'))
		return ;
	ud_s = (!x->ac && !ud && ft_strchr(x->format_num, '.')) ?\
			ft_strdup("") : ft_unsigned_itoa(ud);
	if (!ud_s)
	{
		x->word_count = -1;
		return ;
	}
	uds_len = ft_strlen(ud_s);
	if (x->minus_flag)
		x->word_count += write_ud_with_mflag(ud_s, *x, uds_len);
	else
		x->word_count += write_ud(ud_s, *x, uds_len);
	safe_free(ud_s);
}
