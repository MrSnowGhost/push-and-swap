/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:16:59 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/05 15:54:18 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void push_b(t_list **a,t_list **b)
{
	t_list *tmmp;
	
	if(ft_lstsize(*a) == 0)
		return ;
	tmmp = *a;
	push((*a)->content,b);
	*a = (*a)->next;
	free(tmmp);
	write(1,"pb\n",3);
}
