/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:03:57 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 11:13:28 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

t_list	*last_elem(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	push_smalls(t_list **a, t_list **b, int mid, int index)
{
	t_list	*last;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(*a);
	last = last_elem(a);
	while (i <= size / index)
	{
		if ((*a)->content <= mid)
		{
			push_b(a, b);
			i++;
		}
		else if (last->content <= mid)
		{
			rra(a, b);
			push_b(a, b);
			i++;
		}
		else if ((*a)->content > mid)
			ra(a, b);
		last = last_elem(a);
	}
}

void	free_list(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	exit (0);
}
