/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:51:06 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/25 16:10:07 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_options		init_option(void)
{
	t_options ret;

	ret.minus = 0;
	ret.zero = 0;
	ret.width = 0;
	ret.dot = -1;
	ret.type = 0;
	return (ret);
}

void			in_while(int i, t_options stat, int len)
{
	if (stat.zero == 1 && stat.dot != -1 && stat.type != 'c')
		stat.zero = 0;
	if (stat.dot < len && stat.type == 's' && stat.dot != -1)
	{
		while ((stat.width - stat.dot++) > 0)
		{
			if (stat.zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
	else
	{
		while ((stat.width - len++) > 0)
		{
			if (stat.zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
	if (stat.zero == 0 && i == 1 && stat.minus == 0)
		write(1, "-", 1);
}

int				buf_len(t_options stat, char *buf)
{
	int len;

	len = 0;
	if (stat.type == 'c' && *buf == 0)
		return (1);
	while (*buf != 0)
	{
		buf++;
		len++;
	}
	if (stat.dot < len && stat.type == 's' && stat.dot != -1)
		return (stat.dot);
	return (len);
}

int				in_write(int i, t_options stat, char **buf, int len)
{
	if ((stat.dot > len) && stat.type != 's' && stat.type != 'c')
	{
		while (stat.dot - len++)
			write(1, "0", 1);
		if (stat.minus == 1)
			len = len - 1;
	}
	if (stat.dot == 0 && **buf == '0' && buf_len(stat, *buf + i) == 1)
	{
		if (stat.width != 0)
			write(1, " ", 1);
	}
	else
		write(1, *buf + i, buf_len(stat, *buf + i));
	return (len);
}

void			in_instr(t_options stat, char **buf, int len)
{
	int i;

	i = 0;
	if (**buf == '-' && (stat.type == 'd' || stat.type == 'i'))
	{
		if ((stat.zero == 1 && stat.dot == -1)
		|| (stat.zero == 0 && stat.minus == 1))
			write(1, "-", 1);
		i = 1;
		len = len - 1;
		stat.width = stat.width - 1;
	}
	if (stat.minus == 1)
	{
		len = in_write(i, stat, buf, len);
		in_while(i, stat, len);
	}
	else
	{
		if (stat.dot > len && stat.type != 's' && stat.type != 'c')
			in_while(i, stat, stat.dot);
		else
			in_while(i, stat, len);
		len = in_write(i, stat, buf, len);
	}
}
