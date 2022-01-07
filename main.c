/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:42:13 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/07 17:44:48 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	fill_a(t_list **a, char **list)
{
	long	number;
	int		i;
	t_list *new;

	i = 0;
	while (list[i] != NULL)
	{
		number = ft_atoi(list[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			write(1, "Error\n", 6);
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

int	check_dup(char **argv)
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
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9')
			&& !(argv[i] == '-') && !(argv[i] == ' '))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

void	list_init(t_var *var)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!check_dup(var->list))
	{
		free(var);
		return ;
	}
	if (!fill_a(&a, var->list))
	{
		free(var);
		ft_lstclear(&a);
		return ;
	}
	if (check_sorted(&a))
	{
		free(var);
		ft_lstclear(&a);
		return ;
	}
	sort_list(&a, &b);
}

int	main(int argc, char **argv)
{
	t_list	*tmp;
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
	{
		write(1, "Allocation Error", 16);
		return (0);
	}
	var->str = NULL;
	if (argc > 1)
	{
		if (get_arg(argc, argv, var) == 0)
			return (0);
	}
	else
	{
		write(1, "no argument", 11);
		return (0);
	}
	if (!check_arg(var->str))
	{
		free(var);
		return (0);
	}
	var->list = ft_split(var->str, ' ');
	if (!(var->list))
	{
		free(var);
		write(1, "Allocation Error", 16);
		return (0);
	}
	list_init(var);
	/*	tmp = a;
	while (tmp)
	{	
		printf("%d ",tmp->content);
		tmp = tmp->next;
	}*/
}
