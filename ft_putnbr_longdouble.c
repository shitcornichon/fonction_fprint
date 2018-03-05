/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_longdouble.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:24:45 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 16:13:31 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_double		*ft_longdouble_info(long double d)
{
	unsigned short			*ptr1;
	unsigned long int		*ptr2;
	t_double				*d_info;

	if ((d_info = (t_double*)malloc(sizeof(t_double))) == NULL)
		return (NULL);
	ptr2 = (unsigned long int*)&d;
	ptr1 = (unsigned short*)(ptr2 + 1);
	d_info->s = *ptr1 >> 15;
	d_info->e = *ptr1 & 0x7fff;
	d_info->e -= 16384;
	d_info->m = *ptr2;
	return (d_info);
}

static char		*ft_char_longdouble2(char *res, int preci)
{
	char	*buf;

	buf = ft_round(res, preci);
	ft_memdel((void**)&res);
	return (buf);
}

char			*ft_char_longdouble(t_double *d, int preci)
{
	char	*res;
	char	*buf;
	char	*sum;
	char	*pow;
	int		i;

	res = NULL;
	pow = ft_two_pow(d->e - 63);
	i = -1;
	while (++i < 64)
	{
		buf = ft_sum(pow, pow, 0);
		ft_memdel((void**)&pow);
		if ((d->m >> i) % 2)
		{
			sum = ft_sum(res, buf, 0);
			ft_memdel((void**)&res);
			res = ft_strdup(sum);
			ft_memdel((void**)&sum);
		}
		pow = ft_strdup(buf);
		ft_memdel((void**)&buf);
	}
	ft_memdel((void**)&pow);
	return (ft_char_longdouble2(res, preci));
}

int				ft_putnbr_longdouble(t_double *d, t_field *cur)
{
	int		ret;
	char	*buf;

	ret = 0;
	if (d->e == 16385 && d->m == 0)
		ret += (cur->type & F_MAJ) ? ft_putstr_size("INF") :
			ft_putstr_size("inf");
	else if (d->e == 16385)
		ret += (cur->type & F_MAJ) ? ft_putstr_size("NAN") :
			ft_putstr_size("nan");
	else if (d->e == -16384 && d->m == 0)
	{
		ret += ft_putnbr_size(0);
		ret += (cur->preci) ? ft_putchar_size('.') : 0;
		ret += (cur->preci) ? ft_putchar_sizel('0', cur->preci) : 0;
	}
	else
	{
		buf = ft_char_longdouble(d, cur->preci);
		ret += ft_putstr_size(buf);
		ft_memdel((void**)&buf);
	}
	return (ret);
}

int				ft_longdoublelen(t_double *d, int preci)
{
	int		ret;
	char	*buf;

	ret = 0;
	if (d->e == 16385)
		ret = 3;
	else if (d->e == -16384 && d->m == 0)
		ret = (preci) ? preci + 2 : 1;
	else
	{
		buf = ft_char_longdouble(d, preci);
		ret += ft_strlen(buf);
		ft_memdel((void**)&buf);
	}
	return (ret);
}
