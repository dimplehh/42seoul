/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhlee <hyunhlee@42seoul.student.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:22:10 by hyunhlee          #+#    #+#             */
/*   Updated: 2022/04/21 14:22:11 by hyunhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sa(struct Node *first)
{
    int temp = 0;
    temp = first->data;
    first->data = first->next->data;
    first->next->data = temp;
    printf("sa\n");
}

void sb(struct Node *first)
{
    int temp = 0;
    temp = first->data;
    first->data = first->next->data;
    first->next->data = temp;
    printf("sa\n");
}