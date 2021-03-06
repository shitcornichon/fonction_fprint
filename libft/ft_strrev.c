/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:35:47 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:35:49 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	a;

	i = -1;
	j = ft_strlen(str);
	while (++i < --j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
	return (str);
}
