/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:36:16 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/11 19:35:34 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_hex(unsigned long long h)
{
	int	i;

	i = 0;
	while (h)
	{
		i++;
		h /= 16;
	}
	return (i);
}

char			*ft_small_hex(unsigned int h)
{
	char		*res;
	int			h_size;
	char		*hex_char;

	hex_char = "0123456789abcdef";
	h_size = count_hex(h);
	res = malloc(sizeof(char) * (h_size + 1));
	if (!res)
		return (NULL);
	res[h_size] = '\0';
	if (!h_size)
	{
		free(res);
		return (ft_strdup("0"));
	}
	--h_size;
	while (h)
	{
		res[h_size] = hex_char[h % 16];
		h /= 16;
		h_size--;
	}
	return (res);
}

char			*ft_large_hex(unsigned int h)
{
	char		*res;
	int			h_size;
	char		*hex_char;

	hex_char = "0123456789ABCDEF";
	h_size = count_hex(h);
	res = malloc(sizeof(char) * (h_size + 1));
	if (!res)
		return (NULL);
	res[h_size] = '\0';
	if (!h_size)
	{
		free(res);
		return (ft_strdup("0"));
	}
	--h_size;
	while (h)
	{
		res[h_size] = hex_char[h % 16];
		h /= 16;
		h_size--;
	}
	return (res);
}

char			*calc_pointer(unsigned long long p, t_format x)
{
	char		*res;
	int			p_size;
	char		*hex_char;

	if (!x.ac && !p && ft_strchr(x.format_num, '.'))
		return (ft_strdup(""));
	hex_char = "0123456789abcdef";
	p_size = count_hex(p);
	if (!p_size)
		return (ft_strdup("0"));
	else
		res = calloc((p_size + 1), sizeof(char));
	if (!res)
		return (NULL);
	res[p_size] = '\0';
	while (p)
	{
		p_size--;
		res[p_size] = hex_char[p % 16];
		p /= 16;
	}
	return (res);
}
