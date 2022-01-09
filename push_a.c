/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:42:06 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 10:24:59 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	push_a(t_list **a, t_list **b)
{	
	t_list	*tmmp;

	if (ft_lstsize(*b) == 0)
		return ;
	tmmp = *b;
	if (!(push((*b)->content, a)))
	{
		write(2, "Allocation Error\n", 17);
		free_list(a, b);
	}
	*b = (*b)->next;
	free(tmmp);
	write(1, "pa\n", 3);
}
