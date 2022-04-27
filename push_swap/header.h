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

typedef struct Node
{
	struct Node	*prev;
	int			data;
	int			index;
	struct Node	*next;
}t_Node;

typedef struct Deque
{
	t_Node	*head;
	t_Node	*tail;
}t_Deque;

char		**m_free(char const **dst, int j);
int			ft_atoi(const char *str);
long long	ft_atol(const char *str);
int			ft_col(char const *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			check2(t_Deque *pdeq);
void		sa(t_Deque *pdeq);
void		sb(t_Deque *pdeq);
void		ss(t_Deque *pdeqa, t_Deque *pdeqb);
void		pa(t_Deque *pdeqa, t_Deque *pdeqb);
void		pb(t_Deque *pdeqa, t_Deque *pdeqb);
void		ra(t_Deque *pdeqa);
void		rb(t_Deque *pdeqb);
void		rr(t_Deque *pdeqa, t_Deque *pdeqb);
void		rra(t_Deque *pdeqa);
void		rrb(t_Deque *pdeqb);
void		rrr(t_Deque *pdeqa, t_Deque *pdeqb);
void		show(t_Deque *pdeq);
int			dq_size(t_Deque *pdeq);
int			dq_remove_first(t_Deque *pdeq);
void		dq_add_last(t_Deque *pdeq, int data);
void		dq_add_first(t_Deque *pdeq, int index);
int			dq_is_empty(t_Deque *pdeq);
void		deque_init(t_Deque *pdeq);
void		sort_small(t_Deque *pdeqa, t_Deque *pdeqb);
int			check(int argc, char **argv, t_Deque *a);

#endif
