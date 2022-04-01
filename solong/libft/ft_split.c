/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:30:23 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/01 15:16:05 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_col(char const *s, char c)
{
	unsigned int	i;
	unsigned int	col;

	i = 0;
	col = 0;
	if (*s == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			col++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		col++;
	return (col);
}

int	f_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**m_free(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

char	**ft_split2(char const *s, char **newstr, char c, int col)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < col)
	{
		k = 0;
		while (s[i] == c)
			i++;
		newstr[j] = (char *)malloc(sizeof(char) * f_len(s, c, i) + 1);
		if (!newstr[i])
			return (m_free((char const **)newstr, j));
		while (s[i] != '\0' && s[i] != c)
			newstr[j][k++] = s[i++];
		newstr[j][k] = '\0';
		j++;
	}
	newstr[j] = 0;
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char			**newstr;
	unsigned int	col;

	if (!s)
		return (NULL);
	col = ft_col(s, c);
	newstr = (char **)malloc(sizeof(char *) * (col + 1));
	if (!newstr)
		return (NULL);
	return (ft_split2(s, newstr, c, col));
}
