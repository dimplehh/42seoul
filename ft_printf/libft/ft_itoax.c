/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:18:27 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/07/02 20:20:23 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa3(long long n, char *newstr, int count, char p)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		newstr[0] = '-';
		n = -n;
		i = 1;
	}
	newstr[count] = '\0';
	while (count-- > 0)
	{
		if ((n % 16) <= 9)
			newstr[i + count] = (n % 16) + '0';
		if ((n % 16) >= 10)
		{
			if (p == 'x')
				newstr[i + count] = (n % 16) + 87;
			if (p == 'X')
				newstr[i + count] = (n % 16) + 55;
		}
		n = n / 16;
	}
	return (newstr);
}

int		ft_len2(long long n)
{
	int				len;
	long	long	newn;

	newn = n;
	len = (newn <= 0) ? 1 : 0;
	while (newn != 0)
	{
		newn = newn / 16;
		len++;
	}
	return (len);
}

char	*ft_itoax(long long n, char p)
{
	char	*newstr;
	int		len;

	len = ft_len2(n);
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		newstr[len] = '\0';
	}
	ft_itoa3(n, newstr, len, p);
	return (newstr);
}
