/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:42:13 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/06 17:10:12 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	fill_a(t_list **a,char **list)
{
	long number;
	int i;

	i = 0;
	while (list[i] != NULL)
	{
		number = ft_atoi(list[i]);
			if (number > 2147483647 || number < -2147483648)
			{
				write(1,"Error\n",6);
				return (0);
			}
		ft_lstadd_back(a,ft_lstnew(number));
		i++;
	}
	return (1);
}
int check_dup(char **argv)
{
	int i;
	int j;
	
	i = 0;

	while (argv[i])
	{
		j = 1;
		while (argv[i+j])
		{
			if (ft_strcmp(argv[i],argv[i + j]) == 0)
			{
				write(1,"Error\n",6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_arg(char *argv)
{
 	int i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0'|| argv[i] > '9') && !(argv[i] == '-') && !(argv[i] == ' '))
		{
			write(1,"Error\n",6);
			return(0);
		}
		i++;
	}
	return(1);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_list *tmp;
	t_var	*var;

	var = malloc(sizeof(t_var));
	a = NULL;
	b = NULL;
	var->str = NULL;
	if (argc > 1)
		get_arg(argc,argv,var);	
	else
	{
		write(1,"no arg",6);
		return (0);
	}
	if (!check_arg(var->str))
		return (0);
	var->list = ft_split(var->str,' ');
	if(!check_dup(var->list))
		return (0);
	if (!fill_a(&a,var->list))
		return (0);
	sort_list(&a,&b);
	tmp = a;
	while (tmp)
	{	
		printf("%d ",tmp->content);
		tmp = tmp->next;
	}
}
