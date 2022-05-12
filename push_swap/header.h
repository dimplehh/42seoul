/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:41:21 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/03/12 13:41:26 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	struct node	*prev;
	int			data;
	int			index;
	struct node	*next;
}t_node;

typedef struct deque
{
	t_node	*head;
	t_node	*tail;
}t_deque;

char		**m_free(char const **dst, int j);
int			ft_atoi(const char *str);
long long	ft_atol(const char *str);
int			ft_col(char const *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			check2(t_deque *pdeq);
void		sa(t_deque *pdeq);
void		sb(t_deque *pdeq);
void		ss(t_deque *pdeqa, t_deque *pdeqb);
void		pa(t_deque *pdeqa, t_deque *pdeqb);
void		pb(t_deque *pdeqa, t_deque *pdeqb);
void		ra(t_deque *pdeqa);
void		rb(t_deque *pdeqb);
void		rr(t_deque *pdeqa, t_deque *pdeqb);
void		rra(t_deque *pdeqa);
void		rrb(t_deque *pdeqb);
void		rrr(t_deque *pdeqa, t_deque *pdeqb);
void		show(t_deque *pdeq);
int			dq_size(t_deque *pdeq);
int			dq_remove_first(t_deque *pdeq);
void		dq_add_last(t_deque *pdeq, int data);
void		dq_add_first(t_deque *pdeq, int index);
int			dq_is_empty(t_deque *pdeq);
void		deque_init(t_deque *pdeq);
void		sort_small(t_deque *pdeqa, t_deque *pdeqb);
int			check(int argc, char **argv, t_deque *a);

#endif
