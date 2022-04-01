/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:27:23 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/08 20:04:53 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;
	char			*str;

	d_len = (unsigned int)ft_strlen(dest);
	s_len = (unsigned int)ft_strlen(src);
	i = 0;
	str = dest;
	while (*src && (i + 1 + d_len < size))
	{
		*str = *src;
		++src;
		++str;
		++i;
	}
	*str = 0;
	if (size < d_len)
		return (s_len + size);
	else
		return (s_len + d_len);
}
