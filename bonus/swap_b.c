/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:38:34 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 18:23:25 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_b(t_list *b)
{
	if (ft_lstsize(b) <= 1)
		return ;
	swap(&b->content, &b->next->content);
	write(1, "sb\n", 3);
}
