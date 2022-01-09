/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:35:42 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 16:41:59 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void rr(t_list **a,t_list **b)
{
	t_list	*tmp;
	t_list	*new;

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
	tmp = *b;
	new = ft_lstnew(tmp->content);
	if (!new)
	{
		write(2, "Allocation Error\n", 17);
		free_list(a, b);
	}
	ft_lstadd_back(b, new);
	*b = tmp->next;
	free(tmp);
	write(1,"rr\n",3);
}
