/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:16:59 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 10:24:47 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmmp;

	if (ft_lstsize(*a) == 0)
		return ;
	tmmp = *a;
	if (!(push((*a)->content, b)))
	{
		write(2, "Allocation Error\n", 17);
		free_list(a, b);
	}
	*a = (*a)->next;
	free(tmmp);
}
