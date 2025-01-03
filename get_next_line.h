/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duslu <duslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:26:38 by duslu             #+#    #+#             */
/*   Updated: 2025/01/01 00:26:38 by duslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int ft_strlen(char *str);
int	ft_strchr(char *str);

char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
#endif