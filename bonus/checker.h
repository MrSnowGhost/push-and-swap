/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:31:23 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 18:28:44 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

void	list_initia(char **list);
char	**read_instr(char *s);
int		mv_do(char *lst,t_list **a, t_list **b);
void	checker(t_list **a,t_list **b);
char	*get_next_line(int fd);
void	rr(t_list **a,t_list **b);
void	ss(t_list *a,t_list *b);
void	rrr(t_list **a,t_list **b);
void	check_dup(char **argv);
void	check_arg(char *argv);
int		fill_a(t_list **a, char **list);
char	*get_arg(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
void	free_list(t_list **a, t_list **b);
void	free_arg(char **lst);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	ra(t_list **a, t_list **b);
void	rb(t_list **a, t_list **b);
void	rra(t_list **a, t_list **b);
void	rrb(t_list **a, t_list **b);
void	swap_a(t_list *a);
void	swap_b(t_list *b);
void	swap(int *a, int *b);
int		check_sorted(t_list **a);
int		push(int nb, t_list **stack);

#endif
