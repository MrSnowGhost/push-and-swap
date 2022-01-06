/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:00:53 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/06 17:07:27 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_var
{
	int		max;
	int 	i;
	int		size;
	long	number;
	char	**list;
	char	*str;
	t_list  *a;
	t_list  *b;
		
}		t_var;

void	push(int nb,t_list **stack);
void	swap_a(t_list *a);
void	swap(int *a,int *b);
void	swap_b(t_list *b);
void	ss(t_list *a, t_list *b);
void	push_a(t_list **a,t_list **b);
void	push_b(t_list **a,t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a,t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a,t_list **b);
int		*list_to_arr(t_list **lst);
void	ft_sort_int_tab(int *tab,int size);
void	sort_list(t_list **a,t_list **b);
void	midpoint_a(t_list **a,t_list **b);
void	merge_sort(int *arr,int l,int r);
void	merge(int *arr,int p,int q,int r);
void	quicksort(int array[], int low, int high);
int		partition(int array[], int low, int high);
void	check_b(t_list **a,t_list **b);
int		ft_strcmp(char *s1, char *s2);
void	sort_three(t_list **a);
int		check_greater(t_list **b,int nbr);
void	send_greater(t_list **a,t_list **b);
int		*lis(t_list **a);
void	sort_five(t_list **a,t_list **b);
void	get_arg(int argc, char **argv,t_var *var);

#endif
