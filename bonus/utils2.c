/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:07:03 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 10:09:41 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

char	*get_arg(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	str = ft_strjoin(str, argv[i]);
	if (!str)
	{
		free(str);
		write(2, "Allocation Error\n", 17);
		exit (0);
	}
	i++;
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	return (str);
}

int	push(int nb, t_list **stack)
{
	t_list	*new;

	new = ft_lstnew(nb);
	if (!new)
		return (0);
	if (*stack == NULL)
	{
		ft_lstadd_back(stack, new);
		return (1);
	}
	ft_lstadd_front(stack, new);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) - *(s2 + i) != 0)
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

void	free_list(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	exit (0);
}

void	free_arg(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}
