/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:29:16 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/03/01 13:41:33 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_percent(const char *format, int *i, int *j, va_list ap)
{
	t_format x;

	x = format_deal(format, i, ap);
	if (x.word_count == (-1))
		return (-1);
	if (x.format_char != '\0')
	{
		write_target(ap, &x);
		safe_free(x.format_num);
	}
	if (x.word_count == (-1))
		return (-1);
	*j += x.word_count;
	return (x.word_count);
}

static int	ft_printf_without_percent(const char *format, int *i, int *j)
{
	int tmp;

	if (*i < (int)ft_strlen(format))
		(*j)++;
	tmp = write(1, &format[*i], 1);
	if (tmp == (-1))
		return (-1);
	*i += tmp;
	return (tmp);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			j;
	int			tmp;
	va_list		ap;

	i = 0;
	j = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0' && (size_t)i <= ft_strlen(format))
	{
		tmp = 0;
		if (format[i] == '%')
			tmp = ft_printf_percent(format, &i, &j, ap);
		else
			tmp = ft_printf_without_percent(format, &i, &j);
		if (tmp == (-1))
			return (-1);
	}
	va_end(ap);
	return (j);
}
