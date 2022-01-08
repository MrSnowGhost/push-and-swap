/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:50:23 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 10:43:21 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	sort_two(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		swap_a(*a);
	}
}

void	sort_three(t_list **a, t_list **b)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if ((*a)->content < (*a)->next->content)
		{
			if ((*a)->next->content < (*a)->next->next->content)
				return ;
			else if ((*a)->next->content > (*a)->next->next->content
				&& (*a)->content < (*a)->next->next->content)
				swap_a(*a);
			else
				rra(a, b);
		}
		if ((*a)->content > (*a)->next->content)
		{
			if ((*a)->next->next->content > (*a)->content)
				swap_a(*a);
			else
				ra(a, b);
		}
		i++;
	}
}

void	sort_small(t_list **a, t_list **b, int size)
{
	int	index;

	index = 4;
	while (size > 5)
	{
		midpoint_a(a, b, index);
		size = ft_lstsize(*a);
	}
	if (size == 5 || size == 4)
	{
		while (size > 2)
		{
			midpoint_a(a, b, index);
			size = ft_lstsize(*a);
		}
		if ((*a)->content > (*a)->next->content)
			swap_a(*a);
	}	
	size = ft_lstsize(*b);
	while (size > 0)
	{
		check_b(a, b);
		size = ft_lstsize(*b);
	}
}

void	sort_big(t_list **a, t_list **b, int size)
{
	int	index;

	index = 7;
	while (size > 5)
	{
		midpoint_a(a, b, index);
		size = ft_lstsize(*a);
	}
	if (size == 5)
	{
		while (size > 2)
		{
			midpoint_a(a, b, index);
			size = ft_lstsize(*a);
		}
		if ((*a)->content > (*a)->next->content)
			swap_a(*a);
	}
	size = ft_lstsize(*b);
	while (size > 0)
	{
		check_b(a, b);
		size = ft_lstsize(*b);
	}
}

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
