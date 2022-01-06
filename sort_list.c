/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:22:50 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/06 16:39:39 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void check_moves(t_list **a,t_list **b,int i,int size)
{
	if (i == 0)
	{
		push_a(a,b);
		return;
	}
	if (i <= size/2)
	{
		while (i > 0)
		{
			rb(b);
			i--;
		}
		push_a(a,b);
	}
	else if(i > size/2)
	{
		i = size - i;
		while (i > 0)
		{
			rrb(b);
			i--;
		}
		push_a(a,b);
	}
}
int find_biggest(t_list **b)
{
	int nbr;
	t_list *tmp;

	tmp = (*b)->next;
	nbr = (*b)->content;
	while (tmp)
	{
		if (nbr < tmp->content )
		{
			nbr = tmp->content;
		}
		tmp = tmp->next;
	}
	return(nbr);
}
void check_b(t_list **a,t_list **b)
{
	int i;
	int size;
	int big;
	t_list *tmp;

	i = 0;
	tmp = *b;
	size = ft_lstsize(*b);
	big = find_biggest(b);
	while (tmp)
	{
		if (tmp->content == big)
		{
			check_moves(a,b,i,size);
			break;
		}	
		tmp=tmp->next;
		i++;
	}
}
void midpoint_a(t_list **a,t_list **b)
{
	int *arr;
	int m_p;
	int size;
	int i;
	t_list *tmp;

	arr = list_to_arr(a);	
	size = ft_lstsize(*a);
	merge_sort(arr,0,size - 1);
	m_p = arr[(size - 1)/5];
	i = 0;
	tmp = *a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	while (i <= (size - 1)/5)
	{	
		if ((*a)->content <= m_p)
		{
			push_b(a,b);
			i++;			
		}
		else if (tmp->content <= m_p)
		{
			rra(a);	
			push_b(a,b);
			i++;
		}
		else if ((*a)->content > m_p)
		{
			ra(a);
		}	
		tmp = *a;	
		while(tmp->next && tmp)
		{
			tmp = tmp->next;
		}
	}
}
void	sort_list(t_list **a,t_list **b)
{
	int	size;
	t_list *tmp;	

	size = ft_lstsize(*a);
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (size > 5)
	{
		midpoint_a(a,b);
		size = ft_lstsize(*a);
	}
	if ( size == 5)
	{
		while (size > 2)
		{
			midpoint_a(a,b);
			size = ft_lstsize(*a);
		}
		if ((*a)->content > (*a)->next->content)	
		{
		swap_a(*a);
		}
	}
	size = ft_lstsize(*b);	
	while (size > 0)
	{
		check_b(a,b);
		size=ft_lstsize(*b);
	}
}
