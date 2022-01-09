/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:27:55 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 10:49:38 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

char	**read_instr(char *line)
{
	char	**instr;
	char	*all_lines;

	line = get_next_line(0);
	all_lines = ft_strdup("");
	while (line != NULL)
	{
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		line = get_next_line(0);
	}
	instr = ft_split(all_lines, '\n');
	free(all_lines);
	return (instr);
}

void	list_initia(char **list)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	check_dup(list);
	if (!fill_a(&a, list))
	{
		free_arg(list);
		ft_lstclear(&a);
		exit (0);
	}
	free_arg(list);
	checker(&a, &b);
}

int	main(int argc, char **argv)
{	
	char	*str;
	char	**list;

	if (argc > 1)
		str = get_arg(argc, argv);
	else
	{
		write(2, "no argument\n", 12);
		exit (0);
	}
	check_arg(str);
	list = ft_split(str, ' ');
	if (!list)
	{
		free(str);
		write(2, "Allocation Error\n", 17);
		exit (0);
	}
	free(str);
	list_initia(list);
}
