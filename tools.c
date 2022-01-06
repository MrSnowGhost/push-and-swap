/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:16 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/06 17:05:03 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void push(int nb,t_list **stack)
{
	if(*stack == NULL)
	{
		ft_lstadd_back(stack,ft_lstnew(nb));
		return ;
	}
	ft_lstadd_front(stack,ft_lstnew(nb));
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
void get_arg(int argc, char **argv,t_var *var)
{
	int i;

	i = 1;
	var->str = ft_strjoin(var->str,argv[i]);
	i++;
	while (i < argc)
	{
		var->str = ft_strjoin(var->str," ");
		var->str = ft_strjoin(var->str,argv[i]);
		i++;
	}
}
int *list_to_arr(t_list **lst)
{
	int size;
	int *p;
	int i;
	t_list *tmp;

	i = 0;
	tmp = *lst;
	size =ft_lstsize(*lst);
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
