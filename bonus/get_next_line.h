/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:11 by ybensell          #+#    #+#             */
/*   Updated: 2022/01/09 10:50:59 by ybensell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 3

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
#endif
