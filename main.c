/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:42:13 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/08 11:09:49 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

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
				write(1, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
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
			write(1, "Error\n", 6);
			free(argv);
			exit(0);
		}
		i++;
	}
}

void	list_init(char **list)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	check_dup(list);
	if (!fill_a(&a, list))
	{
		free(list);
		ft_lstclear(&a);
		exit (0);
	}
	free(list);
	if (check_sorted(&a))
	{	
		ft_lstclear(&a);
		exit (0);
	}
	sort_list(&a, &b);
}

int	main(int argc, char **argv)
{
	t_list	*tmp;
	char	*str;
	char	**list;

	if (argc > 1)
		str = get_arg(argc, argv);
	else
	{
		write(1, "no argument", 11);
		exit (0);
	}
	check_arg(str);
	list = ft_split(str, ' ');
	if (!list)
	{
		free(str);
		write(1, "Allocation Error", 16);
		exit (0);
	}
	free(str);
	list_init(list);
}
