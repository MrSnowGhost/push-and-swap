/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:16 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 13:42:03 by ybensell         ###   ########.fr       */
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
	check_empty(str, argv[i]);
	i++;
	while (i < argc)
	{
		str = ft_strjoin(str, " ");
		check_empty(str, argv[i]);
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	return (str);
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
