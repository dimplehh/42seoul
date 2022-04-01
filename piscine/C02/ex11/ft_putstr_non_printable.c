/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:15:40 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/08 12:52:43 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;
	char	cc;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			c = hex[(unsigned int)str[i] / 16];
			cc = hex[(unsigned int)str[i] % 16];
			write(1, "\\", 1);
			write(1, &c, 1);
			write(1, &cc, 1);
		}
		i++;
	}
}
