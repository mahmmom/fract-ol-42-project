/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:16 by mohamoha          #+#    #+#             */
/*   Updated: 2023/10/10 19:18:36 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void    putstr_fd(char *s, int fd)
{
    if (s == NULL || fd < 0)
        return;
    if(*s != '\0')
    {
        write(fd, s, 1);
        putstr_fd(s+1, fd);
    }
}
