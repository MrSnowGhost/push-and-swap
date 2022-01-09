/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:33:15 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 17:58:13 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void rra_rrb(t_list **lst1, t_list **lst2)
{
	int		size;
	int		i;
	t_list	*new;
	t_list	*tmp;

	i = 0;
	size = ft_lstsize(*lst1);
	while (i < size - 1)
	{
		tmp = *lst1;
		new = ft_lstnew(tmp->content);
		if (!new)
		{
			write(2, "Allocation Error\n", 17);
			free_list(lst1, lst2);
		}
		ft_lstadd_back(lst1, new);
		*lst1 = tmp->next;
		free(tmp);
		i++;
	}
}

void rrr(t_list **a, t_list **b)
{
	rra_rrb(a, b);
	rra_rrb(b, a);
	write(1, "rrr\n", 4);	
}
