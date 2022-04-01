/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:54:42 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/24 15:57:02 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		if_null(char p, char d, char **buf, char *arg)
{
	if (arg == NULL)
	{
		if (p == 'p')
		{
			if (d == -1)
				ft_memcpy(*buf, "0x0", 3);
			if (d == 0)
				ft_memcpy(*buf, "0x", 2);
			return (0);
		}
		if (p == 's')
			ft_memcpy(*buf, "(null)", 6);
	}
	else if (arg != NULL && p == 's')
		ft_memcpy(*buf, arg, ft_strlen(arg));
	return (1);
}

void	printf_sp(char p, char d, char **buf, char *arg)
{
	char			*newstr;
	long	long	ladd;

	while (**buf != 0)
		(*buf)++;
	if (p == 'p')
	{
		if (if_null('p', d, buf, arg) == 0)
			return ;
		ladd = (long long)(arg);
		newstr = ft_itoax(ladd, 'x');
		if (d == -1)
			printf_sp('s', -1, buf, "0x0");
		if (d == 0)
			printf_sp('s', 0, buf, "0x");
		ft_memcpy(*buf + 2, newstr, ft_strlen(newstr));
		free(newstr);
	}
	if (p == 's')
		if_null('s', 0, buf, arg);
}
