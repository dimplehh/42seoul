/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:06:03 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/25 16:08:40 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			in_str(t_options stat, va_list ap)
{
	char	*buf;
	int		len;

	len = 0;
	if (!(buf = malloc(sizeof(char) * MAX_BUF_SIZE)))
		return (0);
	ft_bzero(buf, MAX_BUF_SIZE);
	if (stat.type == 'c')
		printf_c(&buf, va_arg(ap, int));
	if (stat.type == 's' || stat.type == 'p')
		printf_sp(stat.type, stat.dot, &buf, va_arg(ap, char*));
	if (stat.type == 'd' || stat.type == 'i' || stat.type == 'u')
		printf_diu(stat.type, &buf, va_arg(ap, int));
	if (stat.type == 'x' || stat.type == 'X')
		printf_x(stat.type, &buf, va_arg(ap, int));
	if (stat.type == '%')
		stat.type = printf_c(&buf, '%');
	while (buf[len] != 0)
		len++;
	if (buf[0] == 0 && stat.type == 'c')
		len = 1;
	in_instr(stat, &buf, len);
	len = ft_buflen(buf, stat);
	free(buf);
	return (len);
}

int			width(const char **str, va_list ap)
{
	int	stat;
	int minus;

	stat = 0;
	minus = 1;
	if (**str == '-')
	{
		minus = -1;
		(*str)++;
	}
	if (**str == '*')
	{
		stat = va_arg(ap, int);
		(*str)++;
		return (stat);
	}
	while ('0' <= **str && **str <= '9')
	{
		stat *= 10;
		stat += **str - '0';
		(*str)++;
	}
	return (stat * minus);
}

t_options	check_stat(t_options t)
{
	if (!(t.type == 'c' || t.type == 'd' || t.type == 'i' || t.type == 's'
		|| t.type == '%' || t.type == 'x' || t.type == 'X' || t.type == 'u'
		|| t.type == 'p'))
		t.zero = -1;
	if (t.width < 0)
	{
		t.minus = 1;
		t.width = -t.width;
	}
	if (t.dot <= -2)
	{
		if (t.type == 'c')
		{
			t.minus = 1;
			t.width = -t.dot;
		}
		t.dot = -1;
	}
	if (t.zero == 1 && t.minus == 1)
		t.zero = 0;
	return (t);
}

int			set_stat(t_options stat, const char **str, va_list ap)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			stat.minus = 1;
		else
			stat.zero = 1;
		(*str)++;
	}
	if (('1' <= **str && **str <= '9') || **str == '*')
		stat.width = width(str, ap);
	if (**str == '.')
	{
		(*str)++;
		stat.dot = width(str, ap);
	}
	if (**str == 'c' || **str == 'd' || **str == 'i' || **str == 's'
	|| **str == '%' || **str == 'x' || **str == 'X'
	|| **str == 'u' || **str == 'p')
		stat.type = *(*str)++;
	stat = check_stat(stat);
	if (stat.zero == -1)
		return (0);
	return (in_str(stat, ap));
}

int			ft_printf(const char *str, ...)
{
	va_list			ap;
	char			p;
	t_options		stat;
	int				len;

	len = 0;
	stat = init_option();
	va_start(ap, str);
	while (*str)
	{
		p = *str++;
		if (p == '%')
			len = len + set_stat(stat, &str, ap);
		else
		{
			write(1, &p, 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
