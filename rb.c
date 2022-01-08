/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:33:47 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 11:12:30 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	rb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *b;
	new = ft_lstnew(tmp->content);
	if (!new)
	{
		write(1, "Allocation Error", 16);
		free_list(a, b);
	}
	ft_lstadd_back(b, new);
	*b = tmp->next;
	free(tmp);
	write(1, "rb\n", 3);
}
