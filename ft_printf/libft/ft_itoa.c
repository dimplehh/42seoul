/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:37:25 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/13 15:04:38 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(long long n, char *newstr)
{
	int					count;
	int					i;
	unsigned	long	newn;

	i = 0;
	count = 0;
	newn = (unsigned long)n;
	if (n < 0)
	{
		newstr[0] = '-';
		newn = -newn;
		i = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	newstr[count] = '\0';
	while (count-- > 0)
	{
		newstr[i + count] = (newn % 10) + '0';
		newn = newn / 10;
	}
	return (newstr);
}

int		ft_len(long long n)
{
	int				len;
	long	long	newn;

	newn = n;
	len = (newn <= 0) ? 1 : 0;
	while (newn != 0)
	{
		newn = newn / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long long n)
{
	char	*newstr;
	int		len;

	len = ft_len(n);
	if (n == 0)
		len = 1;
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	newstr[len] = '\0';
	if (n == 0)
		newstr[0] = '0';
	else
		ft_itoa2(n, newstr);
	return (newstr);
}
