/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkikuchi <hkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:29 by hkikuchi          #+#    #+#             */
/*   Updated: 2021/02/11 19:58:52 by hkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_format
{
	int				minus_flag;
	int				zero_flag;
	char			*format_num;
	int				word_count;
	int				min;
	long long int	ac;
	char			format_char;
}				t_format;

int				ft_printf(const char *format, ...);
int				judge_format(char c);
int				ft_isnum(char c);
void			write_target(va_list ap, t_format *x);
t_format		format_deal(const char *format, int *i, va_list ap);
void			get_min_field(va_list ap, t_format *x);
void			safe_free(void *ptr);
int				write_blank(int num);
int				write_zero(int num);
char			*ft_small_hex(unsigned int h);
char			*ft_large_hex(unsigned int h);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_unsigned_itoa(unsigned int n);
char			*make_string(char *d_s, t_format x);
char			*calc_pointer(unsigned long long p, t_format x);
char			*make_pstring(char *d_s, t_format x);
char			*make_pointer_string(char *d_s);
int				ft_strcmp(const char *s1, const char *s2);
int				write_with_min(char *d_s, t_format x);
void			write_character(va_list ap, t_format *x);
void			write_string(va_list ap, t_format *x);
void			write_pointer(va_list ap, t_format *x);
void			write_digit(va_list ap, t_format *x);
void			write_unsigned(va_list ap, t_format *x);
void			write_small_hex(va_list ap, t_format *x);
void			write_large_hex(va_list ap, t_format *x);
void			deal_ilegular(t_format *x);

#endif
