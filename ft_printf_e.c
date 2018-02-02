/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_e.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:29:57 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 08:47:59 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_e(t_field *current, va_list *va)
{
	char		c;
	int			ret;

	ret = 0;
	if (current)
	{
		c = va_arg(*va, int);
//		ret = ft_putchar_int((unsigned char)c);
	}
	return (ret);
}

int		ft_printf_ee(t_field *current, va_list *va)
{
	wchar_t		wc;
	int			ret;

	ret = 0;
	if (current)
	{
		wc = va_arg(*va, int);
//		ret = ft_putwchar(wc);
	}
	return (ret);
}
