/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:42:06 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 11:10:13 by ybensell         ###   ########.fr       */
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
		write(1, "Allocation Error", 16);
		free_list(a, b);
	}
	*b = (*b)->next;
	free(tmmp);
	write(1, "pa\n", 3);
}
