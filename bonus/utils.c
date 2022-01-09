/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:48:48 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 11:05:14 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

void	mv_do(char *lst, t_list **a, t_list **b)
{	
	if (ft_strcmp(lst, "ra") == 0)
		ra(a, b);
	else if (ft_strcmp(lst, "rb") == 0)
		rb(a, b);
	else if (ft_strcmp(lst, "rra") == 0)
		rra(a, b);
	else if (ft_strcmp(lst, "rrb") == 0)
		rrb(a, b);
	else if (ft_strcmp(lst, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(lst, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(lst, "sa") == 0)
		swap_a(*a);
	else if (ft_strcmp(lst, "sb") == 0)
		swap_b(*b);
	else if (ft_strcmp(lst, "ss") == 0)
		ss(*a, *b);
	else if (ft_strcmp(lst, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(lst, "rrr") == 0)
		rrr(a, b);
	else
		return ;
	return ;
}

void	checker(t_list **a, t_list **b)
{
	char	*s;
	int		i;
	char	**str;

	i = 0;
	s = NULL;
	str = read_instr(s);
	while (str[i])
	{
		mv_do(str[i], a, b);
		i++;
	}
	if (check_sorted(a) == 1 && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_arg(str);
	free_list(a, b);
}

void	check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9')
			&& !(argv[i] == '-') && !(argv[i] == ' '))
		{
			write(2, "Error\n", 6);
			free(argv);
			exit(0);
		}
		i++;
	}
}

void	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 1;
		while (argv[i + j])
		{
			if (ft_strcmp(argv[i], argv[i + j]) == 0)
			{
				free(argv);
				write(2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int	fill_a(t_list **a, char **list)
{
	long	number;
	int		i;
	t_list	*new;

	i = 0;
	while (list[i] != NULL)
	{
		number = ft_atoi(list[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		new = ft_lstnew(number);
		if (!new)
			return (0);
		ft_lstadd_back(a, new);
		i++;
	}
	return (1);
}
