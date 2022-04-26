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

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define CHUNK 15

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

int		ft_atoi(const char *str);
int		ft_col(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
void	sa(t_Deque *pdeq);
void	sb(t_Deque *pdeq);
void	ss(t_Deque *pdeqa, t_Deque *pdeqb);
void	pa(t_Deque *pdeqa, t_Deque *pdeqb);
void	pb(t_Deque *pdeqa, t_Deque *pdeqb);
void	ra(t_Deque *pdeqa);
void	rb(t_Deque *pdeqb);
void	rr(t_Deque *pdeqa, t_Deque *pdeqb);
void	rra(t_Deque *pdeqa);
void	rrb(t_Deque *pdeqb);
void	rrr(t_Deque *pdeqa, t_Deque *pdeqb);
void	show(t_Deque *pdeq);
int		DQsize(t_Deque *pdeq);
int		DQRemoveFirst(t_Deque *pdeq);
void    DQAddFirst(t_Deque *pdeq, int index);
void	DQAddLast(t_Deque *pdeq, int data);
int		DQIsEmpty(t_Deque *pdeq);
void	DequeInit(t_Deque *pdeq);
void	sort_small(t_Deque *pdeqa, t_Deque *pdeqb);
int		check(int argc, char **argv, t_Deque *a);

#endif
