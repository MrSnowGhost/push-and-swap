/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 08:20:23 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/04 08:33:08 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void rra(t_list **a)
{
	int size;
	int i;

	t_list *tmp;
	i = 0;
	size = ft_lstsize(*a);
	while (i < size - 1)
	{
		tmp = *a;
		ft_lstadd_back(a,ft_lstnew(tmp->content));
		*a = tmp->next;
		free(tmp);
		i++;
	}
	write(1,"rra\n",4);
}
