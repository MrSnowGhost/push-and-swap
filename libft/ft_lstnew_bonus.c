/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:22:54 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/07 17:41:56 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	if (a == 0)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}
