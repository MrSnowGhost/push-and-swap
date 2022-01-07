/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:16 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/07 17:57:18 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	push(int nb, t_list **stack)
{
	t_list	*new;

	new = ft_lstnew(nb);
	if (!new)
		return (0);
	if (*stack == NULL)
	{
		ft_lstadd_back(stack, new);
		return (0);
	}
	ft_lstadd_front(stack, new);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) - *(s2 + i) != 0)
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

int	get_arg(int argc, char **argv, t_var *var)
{
	int	i;

	i = 1;
	var->str = ft_strjoin(var->str, argv[i]);
	if (!(var->str))
	{
		free(var);
		write(1,"Allocation Error", 16);
		return (0);
	}
	i++;
	while (i < argc)
	{
		var->str = ft_strjoin(var->str, " ");
		var->str = ft_strjoin(var->str, argv[i]);
		i++;
	}
	return (1);
}

int	*list_to_arr(t_list **lst)
{
	int		size;
	int		*p;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	size = ft_lstsize(*lst);
	p = malloc(sizeof(int) * size);
	if (!p)
		return (NULL);
	while (i < size)
	{
		*(p + i) = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (p);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (*(arr + j) > *(arr + j + 1))
				swap((arr + j), (arr + j + 1));
			j++;
		}
		i++;
	}
}
