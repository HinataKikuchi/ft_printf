/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_sp_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:00:43 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/10 21:10:16 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	safe_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int		write_blank(int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		write(1, " ", 1);
		i++;
	}
	if (num > 0)
		return (num);
	else
		return (0);
}

int		write_zero(int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		write(1, "0", 1);
		i++;
	}
	if (num > 0)
		return (num);
	else
		return (0);
}
