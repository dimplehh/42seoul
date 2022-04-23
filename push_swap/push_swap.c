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

int main(int argc, char **argv)
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
    i = 1;
    while(i < argc)
        DQAddLast(&b, atoi(argv[i++]));
    show(&a);
    rrr(&a, &b);
    show(&a);
    show(&b);
    return (0);
}
