/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 02:09:11 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/07 00:08:56 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *pos;
	char *find;

	if (*to_find == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			pos = str + 1;
			find = to_find + 1;
			while (*find != '\0' && *pos != '\0' && *pos == *find)
			{
				pos++;
				find++;
			}
			if (*find == '\0')
				return (str);
			else if (*pos == '\0')
				break ;
		}
		str++;
	}
	return (0);
}
