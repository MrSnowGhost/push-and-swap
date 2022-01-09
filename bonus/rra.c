/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:20:23 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 18:22:41 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	rra(t_list **a, t_list **b)
{
	int		size;
	int		i;
	t_list	*new;
	t_list	*tmp;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size - 1)
	{
		tmp = *a;
		new = ft_lstnew(tmp->content);
		if (!new)
		{
			write(2, "Allocation Error\n", 17);
			free_list(a, b);
		}
		ft_lstadd_back(a, new);
		*a = tmp->next;
		free(tmp);
		i++;
	}
	write(1, "rra\n", 4);
}
