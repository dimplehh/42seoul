/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:37:15 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/04/08 15:39:48 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbrput(char c, char *base, int result)
{
	int b_size;
	int index;

	b_size = 0;
	index = 0;
	while (base[b_size] != '\0')
	{
		if (c == base[b_size])
			index = b_size;
		b_size++;
	}
	result = result * b_size + index % b_size;
	return (result);
}

int	ft_isspace(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '+' || str[i] == '-')
		return (1);
	return (0);
}

int	b_error(char *base)
{
	int i;
	int j;
	int b_size;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (ft_isspace(base, i))
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	b_size = i;
	if (b_size == 0 || b_size == 1)
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (b_error(base))
		return (0);
	while (ft_isspace(str, i))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && ft_isbase(str[i], base))
	{
		result = ft_nbrput(str[i], base, result);
		i++;
	}
	return (result * sign);
}
