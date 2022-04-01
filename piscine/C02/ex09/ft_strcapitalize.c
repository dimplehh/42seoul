/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:46:30 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/05 06:26:04 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	atoz(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			atoz(str, i);
		else
		{
			if (!(number(str[i - 1]) || lower(str[i - 1]) || upper(str[i - 1])))
				atoz(str, i);
		}
		i++;
	}
	return (str);
}
