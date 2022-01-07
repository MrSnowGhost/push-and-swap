/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:00:53 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/07 17:50:35 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_var
{
	char	**list;
	char	*str;	
}		t_var;

int		push(int nb, t_list **stack);
void	swap_a(t_list *a);
void	swap(int *a, int *b);
void	swap_b(t_list *b);
void	ss(t_list *a, t_list *b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		*list_to_arr(t_list **lst);
void	ft_sort_int_tab(int *tab, int size);
void	sort_list(t_list **a, t_list **b);
void	midpoint_a(t_list **a, t_list **b, int index);
void	check_b(t_list **a, t_list **b);
int		ft_strcmp(char *s1, char *s2);
void	sort_three(t_list **a);
int		check_greater(t_list **b, int nbr);
void	send_greater(t_list **a, t_list **b);
int		get_arg(int argc, char **argv, t_var *var);
void	sort_arr(int *arr, int size);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_small(t_list **a, t_list **b, int size);
void	sort_big(t_list **a, t_list **b, int size);
int		check_sorted(t_list **a);
void	list_init(t_var *var);
void	push_smalls(t_list **a, t_list **b, int mid, int index);
t_list	*last_elem(t_list **a);
#endif
