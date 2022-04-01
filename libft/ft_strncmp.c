/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:39:48 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/05/13 20:16:51 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftft_strcmp(const char *st1, const char *st2)
{
	int				i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *)st1;
	ns2 = (unsigned char *)st2;
	i = 0;
	while (ns1[i] != '\0' || ns2[i] != '\0')
	{
		if (ns1[i] > ns2[i] || ns1[i] < ns2[i])
			return ((int)(ns1[i] - ns2[i]));
		i++;
	}
	return ((int)(ns1[i] - ns2[i]));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	else if (n < 0)
		return (ftft_strcmp(s1, s2));
	else
	{
		while ((ns1[i] != '\0' || ns2[i] != '\0') && i < n)
		{
			if (ns1[i] > ns2[i] || ns1[i] < ns2[i])
				return ((int)(ns1[i] - ns2[i]));
			i++;
		}
		return (0);
	}
}
