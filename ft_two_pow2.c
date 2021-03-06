/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_two_pow2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 13:19:34 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 13:38:44 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_two_divide(char *dividend)
{
	int		len_quotient;
	char	*quotient;
	int		i;
	int		carry;

	len_quotient = ft_strlen(dividend) + 1;
	if ((quotient = ft_strnew(len_quotient)) == NULL)
		return (NULL);
	quotient[0] = '0';
	quotient[1] = '.';
	i = 1;
	carry = 0;
	while (++i < len_quotient)
	{
		if (i == len_quotient - 1)
			quotient[i] = '5';
		else
			quotient[i] = ((dividend[i] - '0' + carry * 10) / 2) + '0';
		if ((dividend[i] - '0') % 2)
			carry = 1;
		else
			carry = 0;
	}
	return (quotient);
}

char			*ft_two_pow_minus(int pow)
{
	char	*result;
	char	*buff;
	int		i;
	int		end;

	result = ft_strdup(ft_two_pow_minus_data(pow));
	i = (pow <= -2000) ? pow + 1000 : pow % 100;
	end = (pow > -100) ? -1 : 0;
	while (++i <= end)
	{
		buff = ft_strdup(result);
		ft_memdel((void**)&result);
		if ((result = ft_two_divide(buff)) == NULL)
			return (result);
		ft_memdel((void**)&buff);
	}
	return (result);
}
