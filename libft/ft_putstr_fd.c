/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:39:18 by gberthol          #+#    #+#             */
/*   Updated: 2023/11/09 13:38:06 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		res;

	i = 0;
	while (s[i])
		i++;
	if (!s)
		res = write(fd, "(null)", 6);
	else
		res = write(fd, s, i);
	return (res);
}

/*
int main(int argc, char **argv)
{
	argc = 0;
	ft_putstr_fd(argv[1], 0);
}
*/
