/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:01:15 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/10 21:13:50 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_digits(unsigned int n)
{
	int	j;

	j = 0;
	while (n)
	{
		n /= 10;
		j++;
	}
	return (j);
}

static void		ft_in_to_a(char *ans, unsigned int tmp1, int j)
{
	unsigned int		tmp2;
	char				tmp;

	while (tmp1)
	{
		tmp2 = tmp1 % 10;
		tmp1 = tmp1 / 10;
		tmp = tmp2 + '0';
		*(ans + j - 1) = tmp;
		j--;
	}
}

char			*ft_unsigned_itoa(unsigned int n)
{
	char			*ans;
	int				j;
	unsigned int	tmp1;
	size_t			n_len;

	if (!n)
		return (ft_strdup("0"));
	n_len = ft_count_digits(n);
	ans = ft_calloc((n_len + 1), sizeof(char));
	if (!ans)
		return (NULL);
	ans[0] = '0';
	tmp1 = n;
	j = n_len;
	ft_in_to_a(ans, tmp1, j);
	ans[n_len] = '\0';
	return (ans);
}
