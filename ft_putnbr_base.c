/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 17:06:48 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 16:25:40 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base(unsigned int n, unsigned int base, int maj)
{
	int		ret;

	ret = 0;
	if (n >= base)
	{
		ret += ft_putnbr_base(n / base, base, maj);
		ret += ft_putnbr_base(n % base, base, maj);
	}
	else if (n < 10)
		ret += ft_putchar_int(n + '0');
	else if (!maj)
		ret += ft_putchar_int(n + 'a' - 10);
	else
		ret += ft_putchar_int(n + 'A' - 10);
	return (ret);
}

int		ft_putnbr_long_base(unsigned long n, unsigned long base, int maj)
{
	int		ret;

	ret = 0;
	if (n >= base)
	{
		ret += ft_putnbr_long_base(n / base, base, maj);
		ret += ft_putnbr_long_base(n % base, base, maj);
	}
	else if (n < 10)
		ret += ft_putchar_int(n + '0');
	else if (!maj)
		ret += ft_putchar_int(n + 'a' - 10);
	else
		ret += ft_putchar_int(n + 'A' - 10);
	return (ret);
}
