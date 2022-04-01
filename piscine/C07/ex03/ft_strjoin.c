/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:06:45 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/13 15:56:33 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_i;
int g_j;
int g_k;
int g_bound;

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *new_str;

	g_i = 0;
	g_j = 0;
	g_k = 0;
	g_bound = 0;
	while (g_i < size)
		g_bound += ft_strlen(strs[g_i++]);
	if (!(new_str = malloc(sizeof(char)
					* (g_bound + (ft_strlen(sep) * size) + 1))))
		return (0);
	g_i = 0;
	while (g_j < size)
	{
		g_k = 0;
		while (g_k < ft_strlen(strs[g_j]))
			new_str[g_i++] = strs[g_j][g_k++];
		g_k = 0;
		while (g_k < ft_strlen(sep) && g_j < size - 1)
			new_str[g_i++] = sep[g_k++];
		g_j++;
	}
	new_str[g_i] = '\0';
	return (new_str);
}
