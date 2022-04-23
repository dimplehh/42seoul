/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:43:31 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/23 13:38:38 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    sort(int count, Deque *pdeqa, Deque *pdeqb)
{
    int num = 0;
    int i = 1;
    while (i < count && pdeqa->head)
    {
        if(pdeqa->head->index <= num)
        {
            pb(pdeqa, pdeqb);
            num++;
        }
        if(pdeqa->head && num < pdeqa->head->index && pdeqa->head->index <= num + CHUNK)
        {
            pb(pdeqa, pdeqb);
            rb(pdeqb);
            num++;
        }
        if(pdeqa->head && num + CHUNK < pdeqa->head->index)
            ra(pdeqa);
        i++;
    }
}

int     main(int argc, char **argv)
{
    Deque a;
    Deque b;
    int i;

    DequeInit(&a);
    DequeInit(&b);
    if (!check(argc, argv))
        return (0);
    i = 1;
    while(i < argc)
        DQAddLast(&a, atoi(argv[i++]));
    sort(argc, &a, &b);
    show(&a);
    show(&b);
    return (0);
}
