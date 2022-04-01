/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:37:25 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/12/04 13:42:14 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(int n, char *newstr)
{
	int					count;
	int					i;
	unsigned long		newn;

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

int	ft_len(int n)
{
	int	len;
	int	newn;

	newn = n;
	len = 0;
	if (newn <= 0)
		len = 1;
	while (newn != 0)
	{
		newn = newn / 10;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!newstr)
		return (0);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		len;

	len = ft_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		newstr = (char *)malloc(sizeof(char) * (len + 1));
		if (!newstr)
			return (0);
		newstr[len] = '\0';
	}
	ft_itoa2(n, newstr);
	return (newstr);
}
