/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:48:05 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/06 11:25:04 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void sort_three(t_list **a)
{
	t_list *tmp;
	int i;

	i = 0;
	tmp = (*a)->next;
	while (i < 2)
	{
		if ((*a)->content < tmp->content)
		{
			if (tmp->content < tmp->next->content)
				return;
			else 
				swap_a(*a);
		}
		else 
		{
			if (tmp->next->content > (*a)->content)
				swap_a(*a);
			else
				ra(a);
		}	
		tmp = (*a)->next;
		i++;
	}
}
