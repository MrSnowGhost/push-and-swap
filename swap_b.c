/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:38:34 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/04 08:30:09 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	swap(int *a,int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
void swap_b(t_list *b)
{
	if (ft_lstsize(b) <= 1)
		return;
	swap(&b->content,&b->next->content);
	write(1,"sb\n",3);
}
