/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:34:10 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/08 19:33:08 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = dest;
	while (*str)
		++str;
	while (*src && i < nb)
	{
		*str = *src;
		++src;
		++str;
		++i;
	}
	*str = 0;
	return (dest);
}
