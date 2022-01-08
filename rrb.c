/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:31:24 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 11:02:58 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	rrb(t_list **a, t_list **b)
{
	int		size;
	int		i;
	t_list	*tmp;
	t_list	*new;

	i = 0;
	size = ft_lstsize(*b);
	while (i < size - 1)
	{
		tmp = *b;
		new = ft_lstnew(tmp->content);
		if (!new)
		{
			write(1, "Allocation Error", 1);
			free_list(a, b);
		}
		ft_lstadd_back(b, new);
		*b = tmp->next;
		free(tmp);
		i++;
	}
	write(1, "rrb\n", 4);
}
