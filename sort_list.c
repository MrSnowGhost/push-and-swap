/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:22:50 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 13:55:22 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	check_moves(t_list **a, t_list **b, int i, int size)
{
	if (i == 0)
	{
		push_a(a, b);
		return ;
	}
	if (i <= size / 2)
	{
		while (i > 0)
		{
			rb(a, b);
			i--;
		}
		push_a(a, b);
	}
	else if (i > size / 2)
	{
		i = size - i;
		while (i > 0)
		{
			rrb(a, b);
			i--;
		}
		push_a(a, b);
	}
}

int	find_biggest(t_list **b)
{
	int		nbr;
	t_list	*tmp;

	tmp = (*b)->next;
	nbr = (*b)->content;
	while (tmp)
	{
		if (nbr < tmp->content)
		{
			nbr = tmp->content;
		}
		tmp = tmp->next;
	}
	return (nbr);
}

void	check_b(t_list **a, t_list **b)
{
	int		i;
	int		size;
	int		big;
	t_list	*tmp;

	i = 0;
	tmp = *b;
	size = ft_lstsize(*b);
	big = find_biggest(b);
	while (tmp)
	{
		if (tmp->content == big)
		{
			check_moves(a, b, i, size);
			break ;
		}	
		tmp = tmp->next;
		i++;
	}
}

void	midpoint_a(t_list **a, t_list **b, int index)
{
	int	*arr;
	int	mid;
	int	size;

	arr = list_to_arr(a);
	if (!arr)
	{
		write(2, "Allocation Error\n", 17);
		free_list(a, b);
	}
	size = ft_lstsize(*a);
	sort_arr(arr, size);
	mid = arr[size / index];
	free(arr);
	push_smalls(a, b, mid, index);
}

void	sort_list(t_list **a, t_list **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a, b);
	else if (size >= 4 && size <= 250)
		sort_small(a, b, size);
	else if (size > 250)
		sort_big(a, b, size);
	free_list(a, b);
}
