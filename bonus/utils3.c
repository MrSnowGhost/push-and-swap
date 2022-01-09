/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:24:47 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 09:50:40 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

int	check_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = (*a);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
