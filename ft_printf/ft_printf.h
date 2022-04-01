/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:05:27 by hyunhlee          #+#    #+#             */
/*   Updated: 2021/06/24 16:07:51 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define MAX_BUF_SIZE 10000

typedef	struct	s_options
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			type;
}				t_options;

int				ft_printf(const char *str, ...);
void			printf_sp(char p, char d, char **buf, char *arg);
char			printf_c(char **buf, int arg);
void			printf_diu(char p, char **buf, int arg);
void			printf_x(char p, char **buf, int arg);
void			in_instr(t_options stat, char **buf, int len);
int				ft_buflen(char *buf, t_options stat);
t_options		init_option(void);

#endif
