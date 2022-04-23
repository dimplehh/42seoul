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

void    sort(Deque *pdeqa, Deque *pdeqb)
{

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
    show(&a);
    //sa(&a);
    //sb(&b);
    //ss(&a, &b);
    //pa(&a, &b);
    //rr(&a, &b);
    rrr(&a, &b);
    sort(&a, &b);
    show(&a);
    show(&b);
    return (0);
}
