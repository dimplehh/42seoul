/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:08:15 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/06 20:50:51 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *st1, char *st2)
{
	int i;

	i = 0;
	while (i < ft_strlen(st1))
	{
		if (st1[i] > st2[i] || st1[i] < st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (st1[i] - st2[i]);
}
