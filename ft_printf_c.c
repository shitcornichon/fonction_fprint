/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_c.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:15:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:25:05 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(t_field *current, va_list *va)
{
	char		c;
	int			ret;

	ret = 0;
	if (current)
	{
		c = va_arg(*va, int);
		ret = ft_putchar_int((unsigned char)c);
	}
	return (ret);
}

int		ft_printf_C(t_field *current, va_list *va)
{
	wchar_t		wc;
	int			ret;

	ret = 0;
	if (current)
	{
		wc = va_arg(*va, int);
		ret = ft_putwchar(wc);
	}
	return (ret);
}
