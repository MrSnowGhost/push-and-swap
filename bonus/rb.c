/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:33:47 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 11:38:13 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

void	rb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *b;
	if (ft_lstsize(tmp) == 0)
		return ;
	new = ft_lstnew(tmp->content);
	if (!new)
	{
		write(2, "Allocation Error\n", 17);
		free_list(a, b);
	}
	ft_lstadd_back(b, new);
	*b = tmp->next;
	free(tmp);
}
