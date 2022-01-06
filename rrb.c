/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:31:24 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/04 08:31:12 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void rrb(t_list **b)
{
	int size;
	int i;
	t_list *tmp;

	i = 0;
	size = ft_lstsize(*b);
	while (i < size - 1)
	{
		tmp = *b;
		ft_lstadd_back(b,ft_lstnew(tmp->content));
		*b = tmp->next;
		free(tmp);
		i++;
	}
	write(1,"rrb\n",4);
}
